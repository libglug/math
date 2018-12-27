#include <CUnit/Assert.h>
#include <CUnit/Basic.h>
#include <glug/math/sphere.h>

#define ADD_TEST(suite, name, fcn) if (!CU_add_test((suite), (name), (fcn))) return NULL;

static void test_set(void)
{
    struct glug_sphere cir;
    float r = 1.74f;
    struct glug_vec3 c = { 7.77f, 9.12f, -5.21f };

    glug_sphere_set(&cir, &c, r);

    CU_ASSERT_DOUBLE_EQUAL(cir.r, r, 0.f);
    CU_ASSERT_DOUBLE_EQUAL(cir.c.x, c.x, 0.f);
    CU_ASSERT_DOUBLE_EQUAL(cir.c.y, c.y, 0.f);
    CU_ASSERT_DOUBLE_EQUAL(cir.c.z, c.z, 0.f);
}

static void test_copy(void)
{
    struct glug_sphere cir1 = { { 1.f, 1.f, 1.f }, 1.f };
    struct glug_sphere cir2 = { { 7.77f, 9.12f, -5.21f }, 1.74f };
    glug_sphere_copy(&cir1, &cir2);

    CU_ASSERT_DOUBLE_EQUAL(cir1.r, cir2.r, 0.f);
    CU_ASSERT_DOUBLE_EQUAL(cir1.c.x, cir2.c.x, 0.f);
    CU_ASSERT_DOUBLE_EQUAL(cir1.c.y, cir2.c.y, 0.f);
    CU_ASSERT_DOUBLE_EQUAL(cir1.c.z, cir2.c.z, 0.f);
}

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

static void test_expansion(void)
{
    struct glug_sphere c = { { 0.f, 0.f, 0.f }, 0.f };
    struct glug_vec3 p = { 1.f, 1.f, 1.f };
    struct glug_sphere exp = { { 0.5f, 0.5f, 0.5f }, 0.8660f };

    struct glug_sphere expanded = glug_sphere_expansion(&c, &p);

    CU_ASSERT_DOUBLE_EQUAL(expanded.c.x, exp.c.x, 0.0001f);
    CU_ASSERT_DOUBLE_EQUAL(expanded.c.y, exp.c.y, 0.0001f);
    CU_ASSERT_DOUBLE_EQUAL(expanded.c.z, exp.c.z, 0.0001f);
    CU_ASSERT_DOUBLE_EQUAL(expanded.r, exp.r, 0.0001f);

    c.c.x = exp.c.x = 0.5f;
    c.c.y = exp.c.y = 1.f;
    c.c.z = exp.c.z = 1.5f;
    c.r = exp.r = 2.f;
    expanded = glug_sphere_expansion(&c, &p);

    CU_ASSERT_DOUBLE_EQUAL(expanded.c.x, exp.c.x, 0.f);
    CU_ASSERT_DOUBLE_EQUAL(expanded.c.y, exp.c.y, 0.f);
    CU_ASSERT_DOUBLE_EQUAL(expanded.c.z, exp.c.z, 0.0f);
    CU_ASSERT_DOUBLE_EQUAL(expanded.r, exp.r, 0.f);

    p.x = 5.f;
    p.y = 1.f;
    p.z = -2.f;
    exp.c.x = 1.9606f;
    exp.c.y = 1.f;
    exp.c.z = 0.3639f;
    exp.r = 3.8504f;
    expanded = glug_sphere_expansion(&c, &p);

    CU_ASSERT_DOUBLE_EQUAL(expanded.c.x, exp.c.x, 0.0001f);
    CU_ASSERT_DOUBLE_EQUAL(expanded.c.y, exp.c.y, 0.0001f);
    CU_ASSERT_DOUBLE_EQUAL(expanded.c.z, exp.c.z, 0.0001f);
    CU_ASSERT_DOUBLE_EQUAL(expanded.r, exp.r, 0.0001f);
}

static void test_expand(void)
{ 
    struct glug_sphere c = { { 0.f, 0.f, 0.f }, 0.f };
    struct glug_vec3 p = { 1.f, 1.f, 1.f };
    struct glug_sphere exp = { { 0.5f, 0.5f, 0.5f }, 0.8660f };

    glug_sphere_expand_to(&c, &p);

    CU_ASSERT_DOUBLE_EQUAL(c.c.x, exp.c.x, 0.0001f);
    CU_ASSERT_DOUBLE_EQUAL(c.c.y, exp.c.y, 0.0001f);
    CU_ASSERT_DOUBLE_EQUAL(c.c.z, exp.c.z, 0.0001f);
    CU_ASSERT_DOUBLE_EQUAL(c.r, exp.r, 0.0001f);

    c.c.x = exp.c.x = 0.5f;
    c.c.y = exp.c.y = 1.f;
    c.c.z = exp.c.z = 1.5f;
    c.r = exp.r = 2.f;
    glug_sphere_expand_to(&c, &p);

    CU_ASSERT_DOUBLE_EQUAL(c.c.x, exp.c.x, 0.f);
    CU_ASSERT_DOUBLE_EQUAL(c.c.y, exp.c.y, 0.f);
    CU_ASSERT_DOUBLE_EQUAL(c.c.z, exp.c.z, 0.f);
    CU_ASSERT_DOUBLE_EQUAL(c.r, exp.r, 0.f);

    p.x = 5.f;
    p.y = 1.f;
    p.z = -2.f;
    exp.c.x = 1.9606f;
    exp.c.y = 1.f;
    exp.c.z = 0.3639f;
    exp.r = 3.8504f;
    glug_sphere_expand_to(&c, &p);

    CU_ASSERT_DOUBLE_EQUAL(c.c.x, exp.c.x, 0.0001f);
    CU_ASSERT_DOUBLE_EQUAL(c.c.y, exp.c.y, 0.0001f);
    CU_ASSERT_DOUBLE_EQUAL(c.c.z, exp.c.z, 0.0001f);
    CU_ASSERT_DOUBLE_EQUAL(c.r, exp.r, 0.0001f);

    c.c.x = c.c.y = c.c.z = 0.f;
    c.r = 1.f;
    p.x = -2.f;
    p.y = 0.f;
    p.z = 0.f;
    glug_sphere_expand_to(&c, &p);

    CU_ASSERT_DOUBLE_EQUAL(c.c.x, -0.5f, 0.f);
    CU_ASSERT_DOUBLE_EQUAL(c.c.y, 0.f, 0.f);
    CU_ASSERT_DOUBLE_EQUAL(c.c.z, 0.f, 0.f);
    CU_ASSERT_DOUBLE_EQUAL(c.r, 1.5f, 0.f);
}

static void test_intersects(void)
{
    struct glug_sphere c1 = { { 0.f, 1.f, 2.f }, 2.5f };
    struct glug_sphere c2 = { { -1.f, -2.f, -3.f }, 0.75f };

    int intersect = glug_sphere_intersects_sphere(&c1, &c2);
    CU_ASSERT_FALSE(intersect);

    c2.r = 3.42f;
    intersect = glug_sphere_intersects_sphere(&c1, &c2);
    CU_ASSERT_TRUE(intersect);
}

static void test_union(void)
{
    struct glug_sphere c1 = { { 0.f, 0.f, 0.f }, 0.5f };
    struct glug_sphere c2 = { { 0.f, 0.f, 0.f }, 1.f };
    struct glug_sphere exp = { { 0.f, 0.f, 0.f }, 1.f };

    // c1 fully encompassed by c2
    struct glug_sphere dst = glug_sphere_union(&c1, &c2);

    CU_ASSERT_DOUBLE_EQUAL(dst.c.x, exp.c.x, 0.f);
    CU_ASSERT_DOUBLE_EQUAL(dst.c.y, exp.c.y, 0.f);
    CU_ASSERT_DOUBLE_EQUAL(dst.c.z, exp.c.z, 0.f);

    c1.c.x = -0.5f;
    c1.c.y = 1.f;
    c1.c.z = 3.f;
    c1.r = 1.f;
    c2.c.x = 1.f;
    c2.c.y = 1.5f;
    c2.c.z = -0.5f;
    exp.c.x = 1.3905f;
    exp.c.y = 1.6301f;
    exp.c.z = -1.4113f;
    exp.r = 2.9202f;

    dst = glug_sphere_union(&c1, &c2);
    CU_ASSERT_DOUBLE_EQUAL(dst.c.x, exp.c.x, 0.0001f);
    CU_ASSERT_DOUBLE_EQUAL(dst.c.y, exp.c.y, 0.0001f);
    CU_ASSERT_DOUBLE_EQUAL(dst.c.z, exp.c.z, 0.0001f);
}

static void test_unionize(void)
{
    struct glug_sphere dst = { { 0.f, 0.f, 0.f }, 1.f };
    struct glug_sphere c1 = { { 0.f, 0.f, 0.f }, 0.5f };
    struct glug_sphere c2 = { { 0.f, 0.f, 0.f }, 1.f };
    struct glug_sphere exp = { { 0.f, 0.f, 0.f }, 1.f };

    // dst fully encompasses c1
    glug_sphere_unionize(&dst, &c1);

    CU_ASSERT_DOUBLE_EQUAL(dst.c.x, exp.c.x, 0.f);
    CU_ASSERT_DOUBLE_EQUAL(dst.c.y, exp.c.y, 0.f);
    CU_ASSERT_DOUBLE_EQUAL(dst.c.z, exp.c.z, 0.f);

    // dst fully encompassed by c2
    glug_sphere_copy(&dst, &c1);
    glug_sphere_unionize(&dst, &c2);

    CU_ASSERT_DOUBLE_EQUAL(dst.c.x, exp.c.x, 0.f);
    CU_ASSERT_DOUBLE_EQUAL(dst.c.y, exp.c.y, 0.f);
    CU_ASSERT_DOUBLE_EQUAL(dst.c.z, exp.c.z, 0.f);

    dst.c.x = -0.5f;
    dst.c.y = 1.f;
    dst.c.z = 3.f;
    c2.c.x = 1.f;
    c2.c.y = 1.5f;
    c2.c.z = -0.5f;
    exp.c.x = 1.3905f;
    exp.c.y = 1.6301f;
    exp.c.z = -1.4113f;
    exp.r = 2.9202f;

    glug_sphere_unionize(&dst, &c2);
    CU_ASSERT_DOUBLE_EQUAL(dst.c.x, exp.c.x, 0.0001f);
    CU_ASSERT_DOUBLE_EQUAL(dst.c.y, exp.c.y, 0.0001f);
    CU_ASSERT_DOUBLE_EQUAL(dst.c.z, exp.c.z, 0.0001f);
}

static void test_clamped(void)
{
    struct glug_sphere c = { { 2.5f, 7.f, -3.14f }, 2.5f };
    struct glug_vec3 p = { 3.5f, 10.f, 2.f };
    struct glug_vec3 exp = { 2.914f, 8.242f, -1.010f };

    struct glug_vec3 cp = glug_sphere_clamped_point(&c, &p);

    CU_ASSERT_DOUBLE_EQUAL(cp.x, exp.x, 0.001f);
    CU_ASSERT_DOUBLE_EQUAL(cp.y, exp.y, 0.001f);
    CU_ASSERT_DOUBLE_EQUAL(cp.z, exp.z, 0.001f);
}

static void test_clamp(void)
{
    struct glug_sphere c = { { 2.5f, 7.f, -3.14f }, 2.5f };
    struct glug_vec3 p = { 3.5f, 10.f, 2.f };
    struct glug_vec3 exp = { 2.914f, 8.242f, -1.010f };

    glug_sphere_clamp_point(&c, &p);

    CU_ASSERT_DOUBLE_EQUAL(p.x, exp.x, 0.001f);
    CU_ASSERT_DOUBLE_EQUAL(p.y, exp.y, 0.001f);
    CU_ASSERT_DOUBLE_EQUAL(p.z, exp.z, 0.001f);
}

CU_pSuite create_sphr_suite()
{
    CU_pSuite sphr_suite = CU_add_suite("sphere", NULL, NULL);
    if (!sphr_suite) return NULL;

    ADD_TEST(sphr_suite, "set", test_set);
    ADD_TEST(sphr_suite, "copy", test_copy);
    ADD_TEST(sphr_suite, "contains", test_contains_pt);
    ADD_TEST(sphr_suite, "expansion", test_expansion);
    ADD_TEST(sphr_suite, "expand", test_expand);
    ADD_TEST(sphr_suite, "intersects", test_intersects);
    ADD_TEST(sphr_suite, "union", test_union);
    ADD_TEST(sphr_suite, "unionize", test_unionize);
    ADD_TEST(sphr_suite, "clamped pt", test_clamped);
    ADD_TEST(sphr_suite, "clamp pt", test_clamp);

    return sphr_suite;
}
