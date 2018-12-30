#include <CUnit/Assert.h>
#include <CUnit/Basic.h>
#include <glug/math/rect.h>

#define ADD_TEST(suite, name, fcn) if (!CU_add_test((suite), (name), (fcn))) return NULL;

static void test_set(void)
{
    struct glug_rect r = { { 1.5, 1.5f }, { 4.f, 3.f } };
    struct glug_vec2 min = { 0.5f, 0.3f };
    struct glug_vec2 max = { 3.14f, 2.718f };

    glug_rect_set(&r, &min, &max);

    CU_ASSERT_DOUBLE_EQUAL(r.min.x, min.x, 0.f);
    CU_ASSERT_DOUBLE_EQUAL(r.min.y, min.y, 0.f);
    CU_ASSERT_DOUBLE_EQUAL(r.max.x, max.x, 0.f);
    CU_ASSERT_DOUBLE_EQUAL(r.max.y, max.y, 0.f);
}

static void test_copy(void)
{
    struct glug_rect r1 = { { 1.5, 1.5f }, { 4.f, 3.f } };
    struct glug_rect r2 = { { 0.5f, 0.3f }, { 3.14f, 2.718f } };

    glug_rect_copy(&r1, &r2);

    CU_ASSERT_DOUBLE_EQUAL(r1.min.x, r2.min.x, 0.f);
    CU_ASSERT_DOUBLE_EQUAL(r1.min.y, r2.min.y, 0.f);
    CU_ASSERT_DOUBLE_EQUAL(r1.max.x, r2.max.x, 0.f);
    CU_ASSERT_DOUBLE_EQUAL(r1.max.y, r2.max.y, 0.f);
}

static void test_equal(void)
{

}

static void test_contains_pt(void)
{
    struct glug_rect r = { { -1.f, -2.f }, { 2.f, 3.f } };
    struct glug_vec2 p = { 0.f, 0.f };

    int intersect = glug_rect_contains_point(&r, &p);
    CU_ASSERT_TRUE(intersect);

    p.x = -2.f;
    intersect = glug_rect_contains_point(&r, &p);
    CU_ASSERT_FALSE(intersect);
}

static void test_expansion(void)
{
    struct glug_rect r = { { 1.f, 2.f }, { 2.f, 3.f } };
    struct glug_vec2 p = { 0.f, 0.f };
    struct glug_rect exp = { { 0.f, 0.f }, { 2.f, 3.f } };

    struct glug_rect dst = glug_rect_expansion(&r, &p);
    CU_ASSERT_DOUBLE_EQUAL(dst.min.x, exp.min.x, 0.f);
    CU_ASSERT_DOUBLE_EQUAL(dst.min.y, exp.min.y, 0.f);
    CU_ASSERT_DOUBLE_EQUAL(dst.max.x, exp.max.x, 0.f);
    CU_ASSERT_DOUBLE_EQUAL(dst.max.y, exp.max.y, 0.f);

    p.x = exp.min.x = -2.f;
    p.y = exp.max.y = 5.f;
    dst = glug_rect_expansion(&dst, &p);
    CU_ASSERT_DOUBLE_EQUAL(dst.min.x, exp.min.x, 0.f);
    CU_ASSERT_DOUBLE_EQUAL(dst.min.y, exp.min.y, 0.f);
    CU_ASSERT_DOUBLE_EQUAL(dst.max.x, exp.max.x, 0.f);
    CU_ASSERT_DOUBLE_EQUAL(dst.max.y, exp.max.y, 0.f);
}

static void test_expand(void)
{
    struct glug_rect dst = { { 1.f, 2.f }, { 2.f, 3.f } };
    struct glug_vec2 p = { 0.f, 0.f };
    struct glug_rect exp = { { 0.f, 0.f }, { 2.f, 3.f } };

    glug_rect_expand_to(&dst, &p);
    CU_ASSERT_DOUBLE_EQUAL(dst.min.x, exp.min.x, 0.f);
    CU_ASSERT_DOUBLE_EQUAL(dst.min.y, exp.min.y, 0.f);
    CU_ASSERT_DOUBLE_EQUAL(dst.max.x, exp.max.x, 0.f);
    CU_ASSERT_DOUBLE_EQUAL(dst.max.y, exp.max.y, 0.f);

    p.x = exp.min.x = -2.f;
    p.y = exp.max.y = 5.f;
    glug_rect_expand_to(&dst, &p);
    CU_ASSERT_DOUBLE_EQUAL(dst.min.x, exp.min.x, 0.f);
    CU_ASSERT_DOUBLE_EQUAL(dst.min.y, exp.min.y, 0.f);
    CU_ASSERT_DOUBLE_EQUAL(dst.max.x, exp.max.x, 0.f);
    CU_ASSERT_DOUBLE_EQUAL(dst.max.y, exp.max.y, 0.f);
}

static void test_intersects(void)
{
    // rect intersects at a point
    struct glug_rect r1 = { { 1.f, 1.f }, { 4.f, 4.f } };
    struct glug_rect r2 = { { 0.5f, 0.5f }, { 1.f, 1.f } };
    int intersect = glug_rect_intersects_rect(&r1, &r2);

    CU_ASSERT_TRUE(intersect);

    // no intersection
    r2.max.x = r2.max.y = 0.9f;
    intersect = glug_rect_intersects_rect(&r1, &r2);
    CU_ASSERT_FALSE(intersect);

    // r2 fully encompasses r1
    r2.max.x = r2.max.y = 5.f;
    intersect = glug_rect_intersects_rect(&r1, &r2);
    CU_ASSERT_TRUE(intersect);

    // "standard" overlap
    r2.min.x = r2.min.y = 3.f;
    intersect = glug_rect_intersects_rect(&r1, &r2);
    CU_ASSERT_TRUE(intersect);

    // equal rectangles
    r2 = r1;
    intersect = glug_rect_intersects_rect(&r1, &r2);
    CU_ASSERT_TRUE(intersect);
}

static void test_intersection(void)
{
    struct glug_rect r1 = { { 1.f, 2.f }, { 5.f, 6.f } };
    struct glug_rect r2 = { { -2.f, -1.f }, { 3.f, 4.f } };
    struct glug_rect exp = { { 1.f, 2.f }, { 3.f, 4.f } };

    struct glug_rect dst = glug_rect_intersection(&r1, &r2);
    CU_ASSERT_DOUBLE_EQUAL(dst.min.x, exp.min.x, 0.f);
    CU_ASSERT_DOUBLE_EQUAL(dst.min.y, exp.min.y, 0.f);
    CU_ASSERT_DOUBLE_EQUAL(dst.max.x, exp.max.x, 0.f);
    CU_ASSERT_DOUBLE_EQUAL(dst.max.y, exp.max.y, 0.f);
}

static void test_intersect(void)
{
    struct glug_rect dst = { { 1.f, 2.f }, { 5.f, 6.f } };
    struct glug_rect r2 = { { -2.f, -1.f }, { 3.f, 4.f } };
    struct glug_rect exp = { { 1.f, 2.f }, { 3.f, 4.f } };

    glug_rect_intersect(&dst, &r2);
    CU_ASSERT_DOUBLE_EQUAL(dst.min.x, exp.min.x, 0.f);
    CU_ASSERT_DOUBLE_EQUAL(dst.min.y, exp.min.y, 0.f);
    CU_ASSERT_DOUBLE_EQUAL(dst.max.x, exp.max.x, 0.f);
    CU_ASSERT_DOUBLE_EQUAL(dst.max.y, exp.max.y, 0.f);
}

static void test_union(void)
{
    struct glug_rect r1 = { { 3.f, 4.f }, { 5.f, 6.f } };
    struct glug_rect r2 = { { -2.f, -1.f }, { 1.f, 2.f } };
    struct glug_rect exp = { { -2.f, -1.f }, { 5.f, 6.f } };

    struct glug_rect dst = glug_rect_union(&r1, &r2);
    CU_ASSERT_DOUBLE_EQUAL(dst.min.x, exp.min.x, 0.f);
    CU_ASSERT_DOUBLE_EQUAL(dst.min.y, exp.min.y, 0.f);
    CU_ASSERT_DOUBLE_EQUAL(dst.max.x, exp.max.x, 0.f);
    CU_ASSERT_DOUBLE_EQUAL(dst.max.y, exp.max.y, 0.f);
}

static void test_unionize(void)
{
    struct glug_rect dst = { { 3.f, 4.f }, { 5.f, 6.f } };
    struct glug_rect r2 = { { -2.f, -1.f }, { 1.f, 2.f } };
    struct glug_rect exp = { { -2.f, -1.f }, { 5.f, 6.f } };

    glug_rect_unionize(&dst, &r2);
    CU_ASSERT_DOUBLE_EQUAL(dst.min.x, exp.min.x, 0.f);
    CU_ASSERT_DOUBLE_EQUAL(dst.min.y, exp.min.y, 0.f);
    CU_ASSERT_DOUBLE_EQUAL(dst.max.x, exp.max.x, 0.f);
    CU_ASSERT_DOUBLE_EQUAL(dst.max.y, exp.max.y, 0.f);
}

static void test_clamped(void)
{
    struct glug_rect r = { { 1.f, 2.f }, { 2.f, 3.f } };
    struct glug_vec2 p = { 0.f, 0.f };
    struct glug_vec2 exp = r.min;

    struct glug_vec2 dst = glug_rect_clamped_point(&r, &p);
    CU_ASSERT_DOUBLE_EQUAL(dst.x, exp.x, 0.f);
    CU_ASSERT_DOUBLE_EQUAL(dst.y, exp.y, 0.f);
}

static void test_clamp(void)
{
    struct glug_rect r = { { 1.f, 2.f }, { 2.f, 3.f } };
    struct glug_vec2 dst = { 0.f, 0.f };
    struct glug_vec2 exp = r.min;

    glug_rect_clamp_point(&r, &dst);
    CU_ASSERT_DOUBLE_EQUAL(dst.x, exp.x, 0.f);
    CU_ASSERT_DOUBLE_EQUAL(dst.y, exp.y, 0.f);
}

CU_pSuite create_rect_suite()
{
    CU_pSuite rect_suite = CU_add_suite("rect", NULL, NULL);
    if (!rect_suite) return NULL;

    ADD_TEST(rect_suite, "set", test_set);
    ADD_TEST(rect_suite, "copy", test_copy);
    ADD_TEST(rect_suite, "equal", test_equal);
    ADD_TEST(rect_suite, "contains", test_contains_pt);
    ADD_TEST(rect_suite, "expansion", test_expansion);
    ADD_TEST(rect_suite, "expand", test_expand);
    ADD_TEST(rect_suite, "intersects", test_intersects);
    ADD_TEST(rect_suite, "intersection", test_intersection);
    ADD_TEST(rect_suite, "intersect", test_intersect);
    ADD_TEST(rect_suite, "union", test_union);
    ADD_TEST(rect_suite, "unionize", test_unionize);
    ADD_TEST(rect_suite, "clamped pt", test_clamped);
    ADD_TEST(rect_suite, "clamp pt", test_clamp);

    return rect_suite;
}
