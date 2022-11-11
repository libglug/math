#include <CUnit/Basic.h>
#include <CUnit/Assert.h>

#include <suites/create_suite.h>
#include <asserts/asserts.h>

#include <glug/math/sphere.h>

static void test_contains_pt(void)
{
    struct glug_sphere c = { { 0.f, 1.f, 2.f }, 1.5f };
    struct glug_vec3 p = { 1.f, 1.f, 1.f };
    int contains = glug_sphere_contains_point(&c, &p);

    CU_ASSERT_TRUE(contains);

    p.z = -1.f;
    contains = glug_sphere_contains_point(&c, &p);
    CU_ASSERT_FALSE(contains);
}

static void test_expand(void)
{ 
    struct glug_sphere c = { { 0.f, 0.f, 0.f }, 0.f };
    struct glug_vec3 p = { 1.f, 1.f, 1.f };
    struct glug_sphere exp = { { 0.5f, 0.5f, 0.5f }, 0.8660f };

    glug_sphere_expand_to(&c, &p);
    ASSERT_SPHERE_EQUAL(&c, &exp, 0.0001f);

    c.center.x = exp.center.x = 0.5f;
    c.center.y = exp.center.y = 1.f;
    c.center.z = exp.center.z = 1.5f;
    c.radius = exp.radius = 2.f;
    glug_sphere_expand_to(&c, &p);
    ASSERT_SPHERE_EQUAL(&c, &exp, 0.f);

    p.x = 5.f;
    p.y = 1.f;
    p.z = -2.f;
    exp.center.x = 1.9606f;
    exp.center.y = 1.f;
    exp.center.z = 0.3639f;
    exp.radius = 3.8504f;
    glug_sphere_expand_to(&c, &p);
    ASSERT_SPHERE_EQUAL(&c, &exp, 0.0001f);

    c.center.x = c.center.y = c.center.z = 0.f;
    c.radius = 1.f;
    p.x = -2.f;
    p.y = 0.f;
    p.z = 0.f;
    exp.center.x = -0.5f;
    exp.center.y = 0.f;
    exp.center.z = 0.f;
    exp.radius = 1.5f;
    glug_sphere_expand_to(&c, &p);
    ASSERT_SPHERE_EQUAL(&c, &exp, 0.f);
}

static void test_intersects(void)
{
    struct glug_sphere c1 = { { 0.f, 1.f, 2.f }, 2.5f };
    struct glug_sphere c2 = { { -1.f, -2.f, -3.f }, 0.75f };

    int intersect = glug_sphere_intersects_sphere(&c1, &c2);
    CU_ASSERT_FALSE(intersect);

    c2.radius = 3.42f;
    intersect = glug_sphere_intersects_sphere(&c1, &c2);
    CU_ASSERT_TRUE(intersect);
}

static void test_union(void)
{
    struct glug_sphere dst = { { 0.f, 0.f, 0.f }, 1.f };
    struct glug_sphere c1 = { { 0.f, 0.f, 0.f }, 0.5f };
    struct glug_sphere c2 = { { 0.f, 0.f, 0.f }, 1.f };
    struct glug_sphere exp = { { 0.f, 0.f, 0.f }, 1.f };

    // dst fully encompasses c1
    glug_sphere_union(&dst, &c1);
    ASSERT_SPHERE_EQUAL(&dst, &exp, 0.f);

    // dst fully encompassed by c2
    dst = c1;
    glug_sphere_union(&dst, &c2);
    ASSERT_SPHERE_EQUAL(&dst, &exp, 0.f);

    dst.center.x = -0.5f;
    dst.center.y = 1.f;
    dst.center.z = 3.f;
    c2.center.x = 1.f;
    c2.center.y = 1.5f;
    c2.center.z = -0.5f;
    exp.center.x = 1.3905f;
    exp.center.y = 1.6301f;
    exp.center.z = -1.4113f;
    exp.radius = 2.9202f;

    glug_sphere_union(&dst, &c2);
    ASSERT_SPHERE_EQUAL(&dst, &exp, 0.0001f);
}

static void test_clamp(void)
{
    struct glug_sphere c = { { 2.5f, 7.f, -3.14f }, 2.5f };
    struct glug_vec3 p = { 3.5f, 10.f, 2.f };
    struct glug_vec3 exp = { 2.914f, 8.242f, -1.010f };

    glug_sphere_clamp_point(&c, &p);
    ASSERT_VEC3_EQUAL(&p, &exp, 0.001f);
}

int main(void)
{
    CU_pSuite sphr_suite = create_suite("sphere", NULL, NULL);
    if (!sphr_suite) return CU_get_error();

    ADD_TEST(sphr_suite, contains_pt);
    ADD_TEST(sphr_suite, expand);
    ADD_TEST(sphr_suite, intersects);
    ADD_TEST(sphr_suite, union);
    ADD_TEST(sphr_suite, clamp);

    return run_tests(CU_BRM_VERBOSE);
}
