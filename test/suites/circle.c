#include <CUnit/Assert.h>
#include <CUnit/Basic.h>
#include <glug/math/circle.h>

#define ADD_TEST(suite, name, fcn) if (!CU_add_test((suite), (name), (fcn))) return NULL;

static void test_set(void)
{
    struct glug_circle cir;
    float r = 1.74f;
    struct glug_vec2 c = { 7.77f, 9.12f };

    glug_circle_set(&cir, &c, r);

    CU_ASSERT_DOUBLE_EQUAL(cir.r, r, 0.f);
    CU_ASSERT_DOUBLE_EQUAL(cir.c.x, c.x, 0.f);
    CU_ASSERT_DOUBLE_EQUAL(cir.c.y, c.y, 0.f);
}

static void test_copy(void)
{
    struct glug_circle cir1 = { { 1.f, 1.f }, 1.f };
    struct glug_circle cir2 = { { 7.77f, 9.12f }, 1.74f };
    glug_circle_copy(&cir1, &cir2);

    CU_ASSERT_DOUBLE_EQUAL(cir1.r, cir2.r, 0.f);
    CU_ASSERT_DOUBLE_EQUAL(cir1.c.x, cir2.c.x, 0.f);
    CU_ASSERT_DOUBLE_EQUAL(cir1.c.y, cir2.c.y, 0.f);
}

static void test_contains_pt(void)
{
    struct glug_circle c = { { 0.f, 1.f }, 1.5f };
    struct glug_vec2 p = { 1.f, 1.f };
    int contains = glug_circle_contains_point(&c, &p);

    CU_ASSERT_TRUE(contains);
}

static void test_expansion(void)
{
    struct glug_circle c = { { 0.f, 0.f }, 0.f };
    struct glug_vec2 p = { 1.f, 1.f };
    struct glug_circle exp = { { 0.5f, 0.5f }, 0.7071f };

    struct glug_circle expanded = glug_circle_expansion(&c, &p);

    CU_ASSERT_DOUBLE_EQUAL(expanded.c.x, exp.c.x, 0.0001f);
    CU_ASSERT_DOUBLE_EQUAL(expanded.c.y, exp.c.x, 0.0001f);
    CU_ASSERT_DOUBLE_EQUAL(expanded.r, exp.r, 0.0001f);

    c.c.x = exp.c.x = 0.5f;
    c.c.y = exp.c.y = 1.f;
    c.r = exp.r = 1.5f;
    expanded = glug_circle_expansion(&c, &p);

    CU_ASSERT_DOUBLE_EQUAL(expanded.c.x, exp.c.x, 0.f);
    CU_ASSERT_DOUBLE_EQUAL(expanded.c.y, exp.c.y, 0.f);
    CU_ASSERT_DOUBLE_EQUAL(expanded.r, exp.r, 0.f);

    p.x = 5.f;
    p.y = 1.f;
    exp.c.x = 2.f;
    exp.c.y = 1.f;
    exp.r = 3.f;
    expanded = glug_circle_expansion(&c, &p);

    CU_ASSERT_DOUBLE_EQUAL(expanded.c.x, exp.c.x, 0.f);
    CU_ASSERT_DOUBLE_EQUAL(expanded.c.y, exp.c.y, 0.f);
    CU_ASSERT_DOUBLE_EQUAL(expanded.r, exp.r, 0.f);
}

static void test_expand(void)
{
    struct glug_circle c = { { 0.f, 0.f }, 0.f };
    struct glug_vec2 p = { 1.f, 1.f };
    struct glug_circle exp = { { 0.5f, 0.5f }, 0.7071f };

    glug_circle_expand_to(&c, &p);

    CU_ASSERT_DOUBLE_EQUAL(c.c.x, exp.c.x, 0.0001f);
    CU_ASSERT_DOUBLE_EQUAL(c.c.y, exp.c.x, 0.0001f);
    CU_ASSERT_DOUBLE_EQUAL(c.r, exp.r, 0.0001f);

    c.c.x = exp.c.x = 0.5f;
    c.c.y = exp.c.y = 1.f;
    c.r = exp.r = 1.5f;
    glug_circle_expand_to(&c, &p);

    CU_ASSERT_DOUBLE_EQUAL(c.c.x, exp.c.x, 0.f);
    CU_ASSERT_DOUBLE_EQUAL(c.c.y, exp.c.y, 0.f);
    CU_ASSERT_DOUBLE_EQUAL(c.r, exp.r, 0.f);

    p.x = 5.f;
    p.y = 1.f;
    exp.c.x = 2.f;
    exp.c.y = 1.f;
    exp.r = 3.f;
    glug_circle_expand_to(&c, &p);

    CU_ASSERT_DOUBLE_EQUAL(c.c.x, exp.c.x, 0.f);
    CU_ASSERT_DOUBLE_EQUAL(c.c.y, exp.c.y, 0.f);
    CU_ASSERT_DOUBLE_EQUAL(c.r, exp.r, 0.f);
}

static void test_clamped(void)
{
    struct glug_circle c = { { 2.5f, 7.f }, 2.5f };
    struct glug_vec2 p = { 3.5f, 10.f };
    struct glug_vec2 exp = { 3.290f, 9.371f };

    struct glug_vec2 cp = glug_circle_clamped_point(&c, &p);

    CU_ASSERT_DOUBLE_EQUAL(cp.x, exp.x, 0.001f);
    CU_ASSERT_DOUBLE_EQUAL(cp.y, exp.y, 0.001f);
}

static void test_clamp(void)
{
    struct glug_circle c = { { 2.5f, 7.f }, 2.5f };
    struct glug_vec2 p = { 3.5f, 10.f };
    struct glug_vec2 exp = { 3.290f, 9.371f };

    glug_circle_clamp_point(&c, &p);

    CU_ASSERT_DOUBLE_EQUAL(p.x, exp.x, 0.001f);
    CU_ASSERT_DOUBLE_EQUAL(p.y, exp.y, 0.001f);
}

CU_pSuite create_cir_suite()
{
    CU_pSuite cir_suite = CU_add_suite("circle", NULL, NULL);
    if (!cir_suite) return NULL;

    ADD_TEST(cir_suite, "set", test_set);
    ADD_TEST(cir_suite, "copy", test_copy);
    ADD_TEST(cir_suite, "contains", test_contains_pt);
    ADD_TEST(cir_suite, "expansion", test_expansion);
    ADD_TEST(cir_suite, "expand", test_expand);
    ADD_TEST(cir_suite, "clamped pt", test_clamped);
    ADD_TEST(cir_suite, "clamp pt", test_clamp);

    return cir_suite;
}
