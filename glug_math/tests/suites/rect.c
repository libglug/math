#include <CUnit/Basic.h>
#include <CUnit/Assert.h>

#include <suites/create_suite.h>
#include <asserts/asserts.h>

#include <glug/math/rect.h>

static void test_equal(void)
{

}

static void test_is_empty(void)
{
    struct glug_rect r2, r1 = { { 1.5, 1.5f }, { 4.f, 3.f } };

    int empty = glug_rect_is_empty(&r1);
    CU_ASSERT_FALSE(empty);

    r2.max = r1.min;
    r2.min = r1.max;
    empty = glug_rect_is_empty(&r2);
    CU_ASSERT_TRUE(empty);
}

static void test_contains_pt(void)
{
    struct glug_rect r = { { -1.f, -2.f }, { 2.f, 3.f } };
    struct glug_vec2 p = { 0.f, 0.f };
    struct glug_rect empty = { r.max, r.min };

    int intersect = glug_rect_contains_point(&r, &p);
    CU_ASSERT_TRUE(intersect);

    p.x = -2.f;
    intersect = glug_rect_contains_point(&r, &p);
    CU_ASSERT_FALSE(intersect);

    p.x = 0.f;
    intersect = glug_rect_contains_point(&empty, &p);

    CU_ASSERT_FALSE(intersect);
}

static void test_expand(void)
{
    struct glug_rect dst = { { 1.f, 2.f }, { 2.f, 3.f } };
    struct glug_vec2 p = { 0.f, 0.f };
    struct glug_rect exp = { { 0.f, 0.f }, { 2.f, 3.f } };
    struct glug_rect empty;

    glug_rect_expand_to(&dst, &p);
    ASSERT_RECT_EQUAL(&dst, &exp, 0.f);

    p.x = exp.min.x = -2.f;
    p.y = exp.max.y = 5.f;
    glug_rect_expand_to(&dst, &p);
    ASSERT_RECT_EQUAL(&dst, &exp, 0.f);

    empty.min = dst.max;
    empty.max = dst.min;
    glug_rect_expand_to(&empty, &p);
    ASSERT_VEC2_EQUAL(&dst.max, &empty.min, 0.f);
    ASSERT_VEC2_EQUAL(&dst.min, &empty.max, 0.f);
}

static void test_intersects(void)
{
    // rect intersects at a point
    struct glug_rect r1 = { { 1.f, 1.f }, { 4.f, 4.f } };
    struct glug_rect r2 = { { 0.5f, 0.5f }, { 1.f, 1.f } };
    int intersect = glug_rect_intersects_rect(&r1, &r2);
    struct glug_rect empty = { r1.max, r1.min };

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

    intersect = glug_rect_intersects_rect(&empty, &r2);
    CU_ASSERT_FALSE(intersect);
}

static void test_intersect(void)
{
    struct glug_rect dst = { { 1.f, 2.f }, { 5.f, 6.f } };
    struct glug_rect r2 = { { -2.f, -1.f }, { 3.f, 4.f } };
    struct glug_rect exp = { { 1.f, 2.f }, { 3.f, 4.f } };
    struct glug_rect empty = { r2.max, r2.min };

    glug_rect_intersect(&dst, &r2);
    ASSERT_RECT_EQUAL(&dst, &exp, 0.f);

    glug_rect_intersect(&empty, &r2);
    ASSERT_VEC2_EQUAL(&r2.max, &empty.min, 0.f);
    ASSERT_VEC2_EQUAL(&r2.min, &empty.max, 0.f);
}

static void test_union(void)
{
    struct glug_rect dst = { { 3.f, 4.f }, { 5.f, 6.f } };
    struct glug_rect r2 = { { -2.f, -1.f }, { 1.f, 2.f } };
    struct glug_rect exp = { { -2.f, -1.f }, { 5.f, 6.f } };
    struct glug_rect empty = { r2.max, r2.min };

    glug_rect_union(&dst, &r2);
    ASSERT_RECT_EQUAL(&dst, &exp, 0.f);

    glug_rect_union(&empty, &r2);
    ASSERT_VEC2_EQUAL(&r2.max, &empty.min, 0.f);
    ASSERT_VEC2_EQUAL(&r2.min, &empty.max, 0.f);
}

static void test_clamp(void)
{
    struct glug_rect r = { { 1.f, 2.f }, { 2.f, 3.f } };
    struct glug_vec2 dst = { 0.f, 0.f };
    struct glug_vec2 exp = r.min;
    struct glug_rect empty = { r.max, r.min };

    glug_rect_clamp_point(&r, &dst);
    ASSERT_VEC2_EQUAL(&dst, &exp, 0.f);

    glug_rect_clamp_point(&empty, &dst);
    ASSERT_VEC2_EQUAL(&dst, &exp, 0.f);
}

int main(void)
{
    CU_pSuite rect_suite = create_suite("rect", NULL, NULL);
    if (!rect_suite) return CU_get_error();

    ADD_TEST(rect_suite, equal);
    ADD_TEST(rect_suite, is_empty);
    ADD_TEST(rect_suite, contains_pt);
    ADD_TEST(rect_suite, expand);
    ADD_TEST(rect_suite, intersects);
    ADD_TEST(rect_suite, intersect);
    ADD_TEST(rect_suite, union);
    ADD_TEST(rect_suite, clamp);

    return run_tests(CU_BRM_VERBOSE);
}
