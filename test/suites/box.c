#include <CUnit/Assert.h>
#include <CUnit/Basic.h>
#include <glug/math/box.h>
#include "add_test.h"

static void test_set(void)
{
    struct glug_box b = { { 1.5, 1.5f, 1.5f }, { 4.f, 3.f, 2.f } };
    struct glug_vec3 min = { 0.5f, 0.3f, 0.1f };
    struct glug_vec3 max = { 3.14f, 2.718f, 1.618f };

    glug_box_set(&b, &min, &max);

    CU_ASSERT_DOUBLE_EQUAL(b.min.x, min.x, 0.f);
    CU_ASSERT_DOUBLE_EQUAL(b.min.y, min.y, 0.f);
    CU_ASSERT_DOUBLE_EQUAL(b.min.z, min.z, 0.f);
    CU_ASSERT_DOUBLE_EQUAL(b.max.x, max.x, 0.f);
    CU_ASSERT_DOUBLE_EQUAL(b.max.y, max.y, 0.f);
    CU_ASSERT_DOUBLE_EQUAL(b.max.z, max.z, 0.f);
}

static void test_copy(void)
{
    struct glug_box b1 = { { 1.5, 1.5f, 1.5f }, { 4.f, 3.f, 2.f } };
    struct glug_box b2 = { { 0.5f, 0.3f, 0.1f }, { 3.14f, 2.718f, 1.618f } };

    glug_box_copy(&b1, &b2);

    CU_ASSERT_DOUBLE_EQUAL(b1.min.x, b2.min.x, 0.f);
    CU_ASSERT_DOUBLE_EQUAL(b1.min.y, b2.min.y, 0.f);
    CU_ASSERT_DOUBLE_EQUAL(b1.min.z, b2.min.z, 0.f);
    CU_ASSERT_DOUBLE_EQUAL(b1.max.x, b2.max.x, 0.f);
    CU_ASSERT_DOUBLE_EQUAL(b1.max.y, b2.max.y, 0.f);
    CU_ASSERT_DOUBLE_EQUAL(b1.max.z, b2.max.z, 0.f);
}

static void test_equal(void)
{

}

static void test_is_empty(void)
{
    struct glug_box b2, b1 = { { 1.5, 1.5f, 1.5f }, { 4.f, 3.f, 2.f } };
    int empty = glug_box_is_empty(&b1);
    CU_ASSERT_FALSE(empty);

    b2.max = b1.min;
    b2.min = b1.max;
    empty = glug_box_is_empty(&b2);
    CU_ASSERT_TRUE(empty);
}

static void test_contains_pt(void)
{
    struct glug_box b = { { -1.f, -2.f, -3.f }, { 2.f, 3.f, 4.f } };
    struct glug_vec3 p = { 0.f, 0.f, 0.f };
    struct glug_box empty = { b.max, b.min };

    int intersect = glug_box_contains_point(&b, &p);
    CU_ASSERT_TRUE(intersect);

    p.x = p.z = -2.f;
    intersect = glug_box_contains_point(&b, &p);
    CU_ASSERT_FALSE(intersect);

    p.x = 0.f;
    intersect = glug_box_contains_point(&empty, &p);

    CU_ASSERT_FALSE(intersect);
}

static void test_expansion(void)
{
    struct glug_box b = { { 1.f, 2.f, 3.f }, { 2.f, 3.f, 4.f } };
    struct glug_vec3 p = { 0.f, 0.f, 0.f };
    struct glug_box exp = { { 0.f, 0.f, 0.f }, { 2.f, 3.f, 4.f } };
    struct glug_box empty = { b.max, b.min };

    struct glug_box dst = glug_box_expansion(&b, &p);
    CU_ASSERT_DOUBLE_EQUAL(dst.min.x, exp.min.x, 0.f);
    CU_ASSERT_DOUBLE_EQUAL(dst.min.y, exp.min.y, 0.f);
    CU_ASSERT_DOUBLE_EQUAL(dst.min.z, exp.min.z, 0.f);
    CU_ASSERT_DOUBLE_EQUAL(dst.max.x, exp.max.x, 0.f);
    CU_ASSERT_DOUBLE_EQUAL(dst.max.y, exp.max.y, 0.f);
    CU_ASSERT_DOUBLE_EQUAL(dst.max.z, exp.max.z, 0.f);

    p.x = exp.min.x = -2.f;
    p.y = exp.max.y = 5.f;
    p.z = exp.min.z = -10.f;
    dst = glug_box_expansion(&dst, &p);
    CU_ASSERT_DOUBLE_EQUAL(dst.min.x, exp.min.x, 0.f);
    CU_ASSERT_DOUBLE_EQUAL(dst.min.y, exp.min.y, 0.f);
    CU_ASSERT_DOUBLE_EQUAL(dst.min.z, exp.min.z, 0.f);
    CU_ASSERT_DOUBLE_EQUAL(dst.max.x, exp.max.x, 0.f);
    CU_ASSERT_DOUBLE_EQUAL(dst.max.y, exp.max.y, 0.f);
    CU_ASSERT_DOUBLE_EQUAL(dst.max.z, exp.max.z, 0.f);

    dst = glug_box_expansion(&empty, &p);
    CU_ASSERT_DOUBLE_EQUAL(dst.min.x, empty.min.x, 0.f);
    CU_ASSERT_DOUBLE_EQUAL(dst.min.y, empty.min.y, 0.f);
    CU_ASSERT_DOUBLE_EQUAL(dst.min.z, empty.min.z, 0.f);
    CU_ASSERT_DOUBLE_EQUAL(dst.max.x, empty.max.x, 0.f);
    CU_ASSERT_DOUBLE_EQUAL(dst.max.y, empty.max.y, 0.f);
    CU_ASSERT_DOUBLE_EQUAL(dst.max.z, empty.max.z, 0.f);
}

static void test_expand(void)
{
    struct glug_box dst = { { 1.f, 2.f, 3.f }, { 2.f, 3.f, 4.f } };
    struct glug_vec3 p = { 0.f, 0.f, 0.f };
    struct glug_box exp = { { 0.f, 0.f, 0.f }, { 2.f, 3.f, 4.f } };
    struct glug_box empty;

    glug_box_expand_to(&dst, &p);
    CU_ASSERT_DOUBLE_EQUAL(dst.min.x, exp.min.x, 0.f);
    CU_ASSERT_DOUBLE_EQUAL(dst.min.y, exp.min.y, 0.f);
    CU_ASSERT_DOUBLE_EQUAL(dst.min.z, exp.min.z, 0.f);
    CU_ASSERT_DOUBLE_EQUAL(dst.max.x, exp.max.x, 0.f);
    CU_ASSERT_DOUBLE_EQUAL(dst.max.y, exp.max.y, 0.f);
    CU_ASSERT_DOUBLE_EQUAL(dst.max.z, exp.max.z, 0.f);

    p.x = exp.min.x = -2.f;
    p.y = exp.max.y = 5.f;
    p.z = exp.min.z = -10.f;
    glug_box_expand_to(&dst, &p);
    CU_ASSERT_DOUBLE_EQUAL(dst.min.x, exp.min.x, 0.f);
    CU_ASSERT_DOUBLE_EQUAL(dst.min.y, exp.min.y, 0.f);
    CU_ASSERT_DOUBLE_EQUAL(dst.min.z, exp.min.z, 0.f);
    CU_ASSERT_DOUBLE_EQUAL(dst.max.x, exp.max.x, 0.f);
    CU_ASSERT_DOUBLE_EQUAL(dst.max.y, exp.max.y, 0.f);
    CU_ASSERT_DOUBLE_EQUAL(dst.max.z, exp.max.z, 0.f);

    empty.min = dst.max;
    empty.max = dst.min;
    glug_box_expand_to(&empty, &p);
    CU_ASSERT_DOUBLE_EQUAL(empty.min.x, dst.max.x, 0.f);
    CU_ASSERT_DOUBLE_EQUAL(empty.min.y, dst.max.y, 0.f);
    CU_ASSERT_DOUBLE_EQUAL(empty.min.z, dst.max.z, 0.f);
    CU_ASSERT_DOUBLE_EQUAL(empty.max.x, dst.min.x, 0.f);
    CU_ASSERT_DOUBLE_EQUAL(empty.max.y, dst.min.y, 0.f);
    CU_ASSERT_DOUBLE_EQUAL(empty.max.z, dst.min.z, 0.f);
}

static void test_intersects(void)
{
    // box intersects at a point
    struct glug_box b1 = { { 1.f, 1.f, 1.f }, { 4.f, 4.f, 4.f } };
    struct glug_box b2 = { { 0.5f, 0.5f, 0.5f }, { 1.f, 1.f, 1.f } };
    int intersect = glug_box_intersects_box(&b1, &b2);
    struct glug_box empty = { b1.max, b1.min };

    CU_ASSERT_TRUE(intersect);

    // no intersection
    b2.max.x = b2.max.y = b2.max.z = 0.9f;
    intersect = glug_box_intersects_box(&b1, &b2);
    CU_ASSERT_FALSE(intersect);

    // b2 fully encompasses b1
    b2.max.x = b2.max.y = b2.max.z = 5.f;
    intersect = glug_box_intersects_box(&b1, &b2);
    CU_ASSERT_TRUE(intersect);

    // "standard" overlap
    b2.min.x = b2.min.y = b2.min.z = 3.f;
    intersect = glug_box_intersects_box(&b1, &b2);
    CU_ASSERT_TRUE(intersect);

    // equal box
    b2 = b1;
    intersect = glug_box_intersects_box(&b1, &b2);
    CU_ASSERT_TRUE(intersect);

    intersect = glug_box_intersects_box(&empty, &b2);
    CU_ASSERT_FALSE(intersect);
}

static void test_intersection(void)
{
    struct glug_box b1 = { { 1.f, 2.f, 3.f }, { 5.f, 6.f, 7.f } };
    struct glug_box b2 = { { -2.f, -1.f, 0.f }, { 3.f, 4.f, 5.f } };
    struct glug_box exp = { { 1.f, 2.f, 3.f }, { 3.f, 4.f, 5.f } };
    struct glug_box empty = { b1.max, b1.min };

    struct glug_box dst = glug_box_intersection(&b1, &b2);
    CU_ASSERT_DOUBLE_EQUAL(dst.min.x, exp.min.x, 0.f);
    CU_ASSERT_DOUBLE_EQUAL(dst.min.y, exp.min.y, 0.f);
    CU_ASSERT_DOUBLE_EQUAL(dst.min.z, exp.min.z, 0.f);
    CU_ASSERT_DOUBLE_EQUAL(dst.max.x, exp.max.x, 0.f);
    CU_ASSERT_DOUBLE_EQUAL(dst.max.y, exp.max.y, 0.f);
    CU_ASSERT_DOUBLE_EQUAL(dst.max.z, exp.max.z, 0.f);

    dst = glug_box_intersection(&empty, &b2);
    CU_ASSERT_DOUBLE_EQUAL(empty.min.x, b1.max.x, 0.f);
    CU_ASSERT_DOUBLE_EQUAL(empty.min.y, b1.max.y, 0.f);
    CU_ASSERT_DOUBLE_EQUAL(empty.min.z, b1.max.z, 0.f);
    CU_ASSERT_DOUBLE_EQUAL(empty.max.x, b1.min.x, 0.f);
    CU_ASSERT_DOUBLE_EQUAL(empty.max.y, b1.min.y, 0.f);
    CU_ASSERT_DOUBLE_EQUAL(empty.max.z, b1.min.z, 0.f);
}

static void test_intersect(void)
{
    struct glug_box dst = { { 1.f, 2.f, 3.f }, { 5.f, 6.f, 7.f } };
    struct glug_box b2 = { { -2.f, -1.f, 0.f }, { 3.f, 4.f, 5.f } };
    struct glug_box exp = { { 1.f, 2.f, 3.f }, { 3.f, 4.f, 5.f } };
    struct glug_box empty = { b2.max, b2.min };

    glug_box_intersect(&dst, &b2);
    CU_ASSERT_DOUBLE_EQUAL(dst.min.x, exp.min.x, 0.f);
    CU_ASSERT_DOUBLE_EQUAL(dst.min.y, exp.min.y, 0.f);
    CU_ASSERT_DOUBLE_EQUAL(dst.min.z, exp.min.z, 0.f);
    CU_ASSERT_DOUBLE_EQUAL(dst.max.x, exp.max.x, 0.f);
    CU_ASSERT_DOUBLE_EQUAL(dst.max.y, exp.max.y, 0.f);
    CU_ASSERT_DOUBLE_EQUAL(dst.max.z, exp.max.z, 0.f);

    glug_box_intersect(&empty, &b2);
    CU_ASSERT_DOUBLE_EQUAL(empty.min.x, b2.max.x, 0.f);
    CU_ASSERT_DOUBLE_EQUAL(empty.min.y, b2.max.y, 0.f);
    CU_ASSERT_DOUBLE_EQUAL(empty.min.z, b2.max.z, 0.f);
    CU_ASSERT_DOUBLE_EQUAL(empty.max.x, b2.min.x, 0.f);
    CU_ASSERT_DOUBLE_EQUAL(empty.max.y, b2.min.y, 0.f);
    CU_ASSERT_DOUBLE_EQUAL(empty.max.z, b2.min.z, 0.f);
}

static void test_union(void)
{
    struct glug_box b1 = { { 1.f, 2.f, 3.f }, { 5.f, 6.f, 7.f } };
    struct glug_box b2 = { { -2.f, -1.f, 0.f }, { 3.f, 4.f, 5.f } };
    struct glug_box exp = { { -2.f, -1.f, 0.f }, { 5.f, 6.f, 7.f } };
    struct glug_box empty = { b1.max, b1.min };

    struct glug_box dst = glug_box_union(&b1, &b2);
    CU_ASSERT_DOUBLE_EQUAL(dst.min.x, exp.min.x, 0.f);
    CU_ASSERT_DOUBLE_EQUAL(dst.min.y, exp.min.y, 0.f);
    CU_ASSERT_DOUBLE_EQUAL(dst.min.z, exp.min.z, 0.f);
    CU_ASSERT_DOUBLE_EQUAL(dst.max.x, exp.max.x, 0.f);
    CU_ASSERT_DOUBLE_EQUAL(dst.max.y, exp.max.y, 0.f);
    CU_ASSERT_DOUBLE_EQUAL(dst.max.z, exp.max.z, 0.f);

    dst = glug_box_union(&empty, &b2);
    CU_ASSERT_DOUBLE_EQUAL(empty.min.x, b1.max.x, 0.f);
    CU_ASSERT_DOUBLE_EQUAL(empty.min.y, b1.max.y, 0.f);
    CU_ASSERT_DOUBLE_EQUAL(empty.min.z, b1.max.z, 0.f);
    CU_ASSERT_DOUBLE_EQUAL(empty.max.x, b1.min.x, 0.f);
    CU_ASSERT_DOUBLE_EQUAL(empty.max.y, b1.min.y, 0.f);
    CU_ASSERT_DOUBLE_EQUAL(empty.max.z, b1.min.z, 0.f);
}

static void test_unionize(void)
{
    struct glug_box dst = { { 1.f, 2.f, 3.f }, { 5.f, 6.f, 7.f } };
    struct glug_box b2 = { { -2.f, -1.f, 0.f }, { 3.f, 4.f, 5.f } };
    struct glug_box exp = { { -2.f, -1.f, 0.f }, { 5.f, 6.f, 7.f } };
    struct glug_box empty = { b2.max, b2.min };

    glug_box_unionize(&dst, &b2);
    CU_ASSERT_DOUBLE_EQUAL(dst.min.x, exp.min.x, 0.f);
    CU_ASSERT_DOUBLE_EQUAL(dst.min.y, exp.min.y, 0.f);
    CU_ASSERT_DOUBLE_EQUAL(dst.min.z, exp.min.z, 0.f);
    CU_ASSERT_DOUBLE_EQUAL(dst.max.x, exp.max.x, 0.f);
    CU_ASSERT_DOUBLE_EQUAL(dst.max.y, exp.max.y, 0.f);
    CU_ASSERT_DOUBLE_EQUAL(dst.max.z, exp.max.z, 0.f);

    glug_box_unionize(&empty, &b2);
    CU_ASSERT_DOUBLE_EQUAL(empty.min.x, b2.max.x, 0.f);
    CU_ASSERT_DOUBLE_EQUAL(empty.min.y, b2.max.y, 0.f);
    CU_ASSERT_DOUBLE_EQUAL(empty.min.z, b2.max.z, 0.f);
    CU_ASSERT_DOUBLE_EQUAL(empty.max.x, b2.min.x, 0.f);
    CU_ASSERT_DOUBLE_EQUAL(empty.max.y, b2.min.y, 0.f);
    CU_ASSERT_DOUBLE_EQUAL(empty.max.z, b2.min.z, 0.f);
}

static void test_clamped(void)
{
    struct glug_box b = { { 1.f, 2.f, 3.f }, { 2.f, 3.f, 4.f } };
    struct glug_vec3 p = { 0.f, 0.f, 0.f };
    struct glug_vec3 exp = b.min;
    struct glug_box empty = { b.max, b.min };

    struct glug_vec3 dst = glug_box_clamped_point(&b, &p);
    CU_ASSERT_DOUBLE_EQUAL(dst.x, exp.x, 0.f);
    CU_ASSERT_DOUBLE_EQUAL(dst.y, exp.y, 0.f);
    CU_ASSERT_DOUBLE_EQUAL(dst.z, exp.z, 0.f);

    dst = glug_box_clamped_point(&empty, &p);
    CU_ASSERT_DOUBLE_EQUAL(dst.x, p.x, 0.f);
    CU_ASSERT_DOUBLE_EQUAL(dst.y, p.y, 0.f);
    CU_ASSERT_DOUBLE_EQUAL(dst.z, p.z, 0.f);
}

static void test_clamp(void)
{
    struct glug_box b = { { 1.f, 2.f, 3.f }, { 2.f, 3.f, 4.f } };
    struct glug_vec3 dst = { 0.f, 0.f, 0.f };
    struct glug_vec3 exp = b.min;
    struct glug_box empty = { b.max, b.min };

    glug_box_clamp_point(&b, &dst);
    CU_ASSERT_DOUBLE_EQUAL(dst.x, exp.x, 0.f);
    CU_ASSERT_DOUBLE_EQUAL(dst.y, exp.y, 0.f);
    CU_ASSERT_DOUBLE_EQUAL(dst.z, exp.z, 0.f);

    glug_box_clamp_point(&empty, &dst);
    CU_ASSERT_DOUBLE_EQUAL(dst.x, exp.x, 0.f);
    CU_ASSERT_DOUBLE_EQUAL(dst.y, exp.y, 0.f);
    CU_ASSERT_DOUBLE_EQUAL(dst.z, exp.z, 0.f);
}

CU_pSuite create_box_suite()
{
    CU_pSuite box_suite = CU_add_suite("box", NULL, NULL);
    if (!box_suite) return NULL;

    ADD_TEST(box_suite, set);
    ADD_TEST(box_suite, copy);
    ADD_TEST(box_suite, equal);
    ADD_TEST(box_suite, is_empty);
    ADD_TEST(box_suite, contains_pt);
    ADD_TEST(box_suite, expansion);
    ADD_TEST(box_suite, expand);
    ADD_TEST(box_suite, intersects);
    ADD_TEST(box_suite, intersection);
    ADD_TEST(box_suite, intersect);
    ADD_TEST(box_suite, union);
    ADD_TEST(box_suite, unionize);
    ADD_TEST(box_suite, clamped);
    ADD_TEST(box_suite, clamp);

    return box_suite;
}
