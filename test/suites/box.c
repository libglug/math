#include <CUnit/Assert.h>
#include <CUnit/Basic.h>
#include <glug/math/box.h>

#define ADD_TEST(suite, name, fcn) if (!CU_add_test((suite), (name), (fcn))) return NULL;

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

    int intersect = glug_box_contains_point(&b, &p);
    CU_ASSERT_TRUE(intersect);

    p.x = p.z = -2.f;
    intersect = glug_box_contains_point(&b, &p);
    CU_ASSERT_FALSE(intersect);
}

static void test_expansion(void)
{
    struct glug_box b = { { 1.f, 2.f, 3.f }, { 2.f, 3.f, 4.f } };
    struct glug_vec3 p = { 0.f, 0.f, 0.f };
    struct glug_box exp = { { 0.f, 0.f, 0.f }, { 2.f, 3.f, 4.f } };

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
}

static void test_expand(void)
{
    struct glug_box dst = { { 1.f, 2.f, 3.f }, { 2.f, 3.f, 4.f } };
    struct glug_vec3 p = { 0.f, 0.f, 0.f };
    struct glug_box exp = { { 0.f, 0.f, 0.f }, { 2.f, 3.f, 4.f } };

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
}

static void test_intersects(void)
{
    // box intersects at a point
    struct glug_box b1 = { { 1.f, 1.f, 1.f }, { 4.f, 4.f, 4.f } };
    struct glug_box b2 = { { 0.5f, 0.5f, 0.5f }, { 1.f, 1.f, 1.f } };
    int intersect = glug_box_intersects_box(&b1, &b2);

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
}

static void test_intersection(void)
{
    struct glug_box b1 = { { 1.f, 2.f, 3.f }, { 5.f, 6.f, 7.f } };
    struct glug_box b2 = { { -2.f, -1.f, 0.f }, { 3.f, 4.f, 5.f } };
    struct glug_box exp = { { 1.f, 2.f, 3.f }, { 3.f, 4.f, 5.f } };

    struct glug_box dst = glug_box_intersection(&b1, &b2);
    CU_ASSERT_DOUBLE_EQUAL(dst.min.x, exp.min.x, 0.f);
    CU_ASSERT_DOUBLE_EQUAL(dst.min.y, exp.min.y, 0.f);
    CU_ASSERT_DOUBLE_EQUAL(dst.min.z, exp.min.z, 0.f);
    CU_ASSERT_DOUBLE_EQUAL(dst.max.x, exp.max.x, 0.f);
    CU_ASSERT_DOUBLE_EQUAL(dst.max.y, exp.max.y, 0.f);
    CU_ASSERT_DOUBLE_EQUAL(dst.max.z, exp.max.z, 0.f);
}

static void test_intersect(void)
{
    struct glug_box dst = { { 1.f, 2.f, 3.f }, { 5.f, 6.f, 7.f } };
    struct glug_box b2 = { { -2.f, -1.f, 0.f }, { 3.f, 4.f, 5.f } };
    struct glug_box exp = { { 1.f, 2.f, 3.f }, { 3.f, 4.f, 5.f } };

    glug_box_intersect(&dst, &b2);
    CU_ASSERT_DOUBLE_EQUAL(dst.min.x, exp.min.x, 0.f);
    CU_ASSERT_DOUBLE_EQUAL(dst.min.y, exp.min.y, 0.f);
    CU_ASSERT_DOUBLE_EQUAL(dst.min.z, exp.min.z, 0.f);
    CU_ASSERT_DOUBLE_EQUAL(dst.max.x, exp.max.x, 0.f);
    CU_ASSERT_DOUBLE_EQUAL(dst.max.y, exp.max.y, 0.f);
    CU_ASSERT_DOUBLE_EQUAL(dst.max.z, exp.max.z, 0.f);
}

static void test_union(void)
{
    struct glug_box b1 = { { 1.f, 2.f, 3.f }, { 5.f, 6.f, 7.f } };
    struct glug_box b2 = { { -2.f, -1.f, 0.f }, { 3.f, 4.f, 5.f } };
    struct glug_box exp = { { -2.f, -1.f, 0.f }, { 5.f, 6.f, 7.f } };

    struct glug_box dst = glug_box_union(&b1, &b2);
    CU_ASSERT_DOUBLE_EQUAL(dst.min.x, exp.min.x, 0.f);
    CU_ASSERT_DOUBLE_EQUAL(dst.min.y, exp.min.y, 0.f);
    CU_ASSERT_DOUBLE_EQUAL(dst.min.z, exp.min.z, 0.f);
    CU_ASSERT_DOUBLE_EQUAL(dst.max.x, exp.max.x, 0.f);
    CU_ASSERT_DOUBLE_EQUAL(dst.max.y, exp.max.y, 0.f);
    CU_ASSERT_DOUBLE_EQUAL(dst.max.z, exp.max.z, 0.f);
}

static void test_unionize(void)
{
    struct glug_box dst = { { 1.f, 2.f, 3.f }, { 5.f, 6.f, 7.f } };
    struct glug_box b2 = { { -2.f, -1.f, 0.f }, { 3.f, 4.f, 5.f } };
    struct glug_box exp = { { -2.f, -1.f, 0.f }, { 5.f, 6.f, 7.f } };

    glug_box_unionize(&dst, &b2);
    CU_ASSERT_DOUBLE_EQUAL(dst.min.x, exp.min.x, 0.f);
    CU_ASSERT_DOUBLE_EQUAL(dst.min.y, exp.min.y, 0.f);
    CU_ASSERT_DOUBLE_EQUAL(dst.min.z, exp.min.z, 0.f);
    CU_ASSERT_DOUBLE_EQUAL(dst.max.x, exp.max.x, 0.f);
    CU_ASSERT_DOUBLE_EQUAL(dst.max.y, exp.max.y, 0.f);
    CU_ASSERT_DOUBLE_EQUAL(dst.max.z, exp.max.z, 0.f);
}

static void test_clamped(void)
{
    struct glug_box b = { { 1.f, 2.f, 3.f }, { 2.f, 3.f, 4.f } };
    struct glug_vec3 p = { 0.f, 0.f, 0.f };
    struct glug_vec3 exp = b.min;

    struct glug_vec3 dst = glug_box_clamped_point(&b, &p);
    CU_ASSERT_DOUBLE_EQUAL(dst.x, exp.x, 0.f);
    CU_ASSERT_DOUBLE_EQUAL(dst.y, exp.y, 0.f);
    CU_ASSERT_DOUBLE_EQUAL(dst.z, exp.z, 0.f);
}

static void test_clamp(void)
{
    struct glug_box b = { { 1.f, 2.f, 3.f }, { 2.f, 3.f, 4.f } };
    struct glug_vec3 dst = { 0.f, 0.f, 0.f };
    struct glug_vec3 exp = b.min;

    glug_box_clamp_point(&b, &dst);
    CU_ASSERT_DOUBLE_EQUAL(dst.x, exp.x, 0.f);
    CU_ASSERT_DOUBLE_EQUAL(dst.y, exp.y, 0.f);
    CU_ASSERT_DOUBLE_EQUAL(dst.z, exp.z, 0.f);
}

CU_pSuite create_box_suite()
{
    CU_pSuite box_suite = CU_add_suite("box", NULL, NULL);
    if (!box_suite) return NULL;

    ADD_TEST(box_suite, "set", test_set);
    ADD_TEST(box_suite, "copy", test_copy);
    ADD_TEST(box_suite, "equal", test_equal);
    ADD_TEST(box_suite, "is empty", test_is_empty);
    ADD_TEST(box_suite, "contains", test_contains_pt);
    ADD_TEST(box_suite, "expansion", test_expansion);
    ADD_TEST(box_suite, "expand", test_expand);
    ADD_TEST(box_suite, "intersects", test_intersects);
    ADD_TEST(box_suite, "intersection", test_intersection);
    ADD_TEST(box_suite, "intersect", test_intersect);
    ADD_TEST(box_suite, "union", test_union);
    ADD_TEST(box_suite, "unionize", test_unionize);
    ADD_TEST(box_suite, "clamped pt", test_clamped);
    ADD_TEST(box_suite, "clamp pt", test_clamp);

    return box_suite;
}
