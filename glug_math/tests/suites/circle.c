#include <CUnit/Basic.h>
#include <CUnit/Assert.h>

#include <suites/create_suite.h>
#include <asserts/asserts.h>

#include <glug/math/circle.h>

static void test_contains_pt(void)
{
    struct glug_circle c = { { 0.f, 1.f }, 1.5f };
    struct glug_vec2 p = { 1.f, 1.f };
    int contains = glug_circle_contains_point(&c, &p);

    CU_ASSERT_TRUE(contains);

    p.y = -1.f;
    contains = glug_circle_contains_point(&c, &p);
    CU_ASSERT_FALSE(contains);
}

static void test_expand(void)
{
    struct glug_circle c;
    struct glug_vec2 p;
    struct glug_circle exp;

    c = (struct glug_circle){ { 2.f, 2.f }, 2.f };
    p = (struct glug_vec2){ 3.f, 3.f };
    exp = c;

    glug_circle_expand_to(&c, &p);
    ASSERT_CIRC_EQUAL(&c, &exp, 0.f);

    c = (struct glug_circle){ { 1.f, 0.f }, 1.f };
    p = (struct glug_vec2){ 3.f, 0.f };
    exp = (struct glug_circle){ { 1.5f, 0.f }, 1.5f };
    glug_circle_expand_to(&c, &p);
    ASSERT_CIRC_EQUAL(&c, &exp, 0.0001f);


    c = (struct glug_circle){ { 1.f, 0.5f }, 1.5f };
    p = (struct glug_vec2){ 1.f, 5.f };
    exp = (struct glug_circle){ { 1.f, 2.f }, 3.f };

    glug_circle_expand_to(&c, &p);
    ASSERT_CIRC_EQUAL(&c, &exp, 0.f);
}

static void test_intersects(void)
{
    struct glug_circle c1 = { { 0.f, 1.f }, 2.5f };
    struct glug_circle c2 = { { -1.f, -2.f }, 0.5f };

    int intersect = glug_circle_intersects_circle(&c1, &c2);
    CU_ASSERT_FALSE(intersect);

    c2.radius = 0.67f;
    intersect = glug_circle_intersects_circle(&c1, &c2);
    CU_ASSERT_TRUE(intersect);
}

static void test_union(void)
{
    struct glug_circle dst = { { 0.f, 0.f }, 1.f };
    struct glug_circle c1 = { { 0.f, 0.f }, 0.5f };
    struct glug_circle c2 = { { 0.f, 0.f }, 1.f };
    struct glug_circle exp = { { 0.f, 0.f }, 1.f };

    // dst fully encompasses c1
    glug_circle_union(&dst, &c1);
    ASSERT_CIRC_EQUAL(&dst, &exp, 0.f);

    // dst fully encompassed by c2
    dst = c1;
    glug_circle_union(&dst, &c2);
    ASSERT_CIRC_EQUAL(&dst, &exp, 0.f);

    dst.center.x = -0.5f;
    dst.center.y = 1.f;
    c2.center.x = 1.f;
    c2.center.y = 1.5f;
    exp.center.x = 1.9486f;
    exp.center.y = 1.8162f;
    exp.radius = 1.7905f;

    glug_circle_union(&dst, &c2);
    ASSERT_CIRC_EQUAL(&dst, &exp, 0.0001f);
}

static void test_clamp(void)
{
    struct glug_circle c = { { 2.5f, 7.f }, 2.5f };
    struct glug_vec2 p = { 3.5f, 10.f };
    struct glug_vec2 exp = { 3.290f, 9.371f };

    glug_circle_clamp_point(&c, &p);
    ASSERT_VEC2_EQUAL(&p, &exp, 0.001f);
}

int main(void)
{
    CU_pSuite circ_suite = create_suite("circle", NULL, NULL);
    if (!circ_suite) return CU_get_error();

    ADD_TEST(circ_suite, contains_pt);
    ADD_TEST(circ_suite, expand);
    ADD_TEST(circ_suite, intersects);
    ADD_TEST(circ_suite, union);
    ADD_TEST(circ_suite, clamp);

    return run_tests(CU_BRM_VERBOSE);
}
