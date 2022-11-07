#include <CUnit/Basic.h>
#include <CUnit/Assert.h>

#include <suites/create_suite.h>
#include <suites/add_test.h>
#include <asserts/asserts.h>

#include <glug/math/box.h>

static void test_set(void)
{
    struct glug_box b = { { 1.5, 1.5f, 1.5f }, { 4.f, 3.f, 2.f } };
    struct glug_vec3 min = { 0.5f, 0.3f, 0.1f };
    struct glug_vec3 max = { 3.14f, 2.718f, 1.618f };
    struct glug_box exp = { min, max };

    glug_box_set(&b, &min, &max);
    ASSERT_BOX_EQUAL(&b, &exp, 0.f);
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
    ASSERT_BOX_EQUAL(&dst, &exp, 0.f);

    p.x = exp.min.x = -2.f;
    p.y = exp.max.y = 5.f;
    p.z = exp.min.z = -10.f;
    dst = glug_box_expansion(&dst, &p);
    ASSERT_BOX_EQUAL(&dst, &exp, 0.f);

    dst = glug_box_expansion(&empty, &p);
    ASSERT_BOX_EQUAL(&dst, &empty, 0.f);
}

static void test_expand(void)
{
    struct glug_box dst = { { 1.f, 2.f, 3.f }, { 2.f, 3.f, 4.f } };
    struct glug_vec3 p = { 0.f, 0.f, 0.f };
    struct glug_box exp = { { 0.f, 0.f, 0.f }, { 2.f, 3.f, 4.f } };
    struct glug_box empty;

    glug_box_expand_to(&dst, &p);
    ASSERT_BOX_EQUAL(&dst, &exp, 0.f);

    p.x = exp.min.x = -2.f;
    p.y = exp.max.y = 5.f;
    p.z = exp.min.z = -10.f;
    glug_box_expand_to(&dst, &p);
    ASSERT_BOX_EQUAL(&dst, &exp, 0.f);

    empty.min = dst.max;
    empty.max = dst.min;
    glug_box_expand_to(&empty, &p);
    ASSERT_VEC3_EQUAL(&dst.max, &empty.min, 0.f);
    ASSERT_VEC3_EQUAL(&dst.min, &empty.max, 0.f);
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
    ASSERT_BOX_EQUAL(&dst, &exp, 0.f);

    dst = glug_box_intersection(&empty, &b2);
    ASSERT_VEC3_EQUAL(&b1.max, &empty.min, 0.f);
    ASSERT_VEC3_EQUAL(&b1.min, &empty.max, 0.f);
}

static void test_intersect(void)
{
    struct glug_box dst = { { 1.f, 2.f, 3.f }, { 5.f, 6.f, 7.f } };
    struct glug_box b2 = { { -2.f, -1.f, 0.f }, { 3.f, 4.f, 5.f } };
    struct glug_box exp = { { 1.f, 2.f, 3.f }, { 3.f, 4.f, 5.f } };
    struct glug_box empty = { b2.max, b2.min };

    glug_box_intersect(&dst, &b2);
    ASSERT_BOX_EQUAL(&dst, &exp, 0.f);

    glug_box_intersect(&empty, &b2);
    ASSERT_VEC3_EQUAL(&b2.max, &empty.min, 0.f);
    ASSERT_VEC3_EQUAL(&b2.min, &empty.max, 0.f);
}

static void test_union(void)
{
    struct glug_box b1 = { { 1.f, 2.f, 3.f }, { 5.f, 6.f, 7.f } };
    struct glug_box b2 = { { -2.f, -1.f, 0.f }, { 3.f, 4.f, 5.f } };
    struct glug_box exp = { { -2.f, -1.f, 0.f }, { 5.f, 6.f, 7.f } };
    struct glug_box empty = { b1.max, b1.min };

    struct glug_box dst = glug_box_union(&b1, &b2);
    ASSERT_BOX_EQUAL(&dst, &exp, 0.f);

    dst = glug_box_union(&empty, &b2);
    ASSERT_VEC3_EQUAL(&b1.max, &empty.min, 0.f);
    ASSERT_VEC3_EQUAL(&b1.min, &empty.max, 0.f);
}

static void test_unionize(void)
{
    struct glug_box dst = { { 1.f, 2.f, 3.f }, { 5.f, 6.f, 7.f } };
    struct glug_box b2 = { { -2.f, -1.f, 0.f }, { 3.f, 4.f, 5.f } };
    struct glug_box exp = { { -2.f, -1.f, 0.f }, { 5.f, 6.f, 7.f } };
    struct glug_box empty = { b2.max, b2.min };

    glug_box_unionize(&dst, &b2);
    ASSERT_BOX_EQUAL(&dst, &exp, 0.f);

    glug_box_unionize(&empty, &b2);
    ASSERT_VEC3_EQUAL(&b2.max, &empty.min, 0.f);
    ASSERT_VEC3_EQUAL(&b2.min, &empty.max, 0.f);
}

static void test_clamped(void)
{
    struct glug_box b = { { 1.f, 2.f, 3.f }, { 2.f, 3.f, 4.f } };
    struct glug_vec3 p = { 0.f, 0.f, 0.f };
    struct glug_vec3 exp = b.min;
    struct glug_box empty = { b.max, b.min };

    struct glug_vec3 dst = glug_box_clamped_point(&b, &p);
    ASSERT_VEC3_EQUAL(&dst, &exp, 0.f);

    dst = glug_box_clamped_point(&empty, &p);
    ASSERT_VEC3_EQUAL(&dst, &p, 0.f);
}

static void test_clamp(void)
{
    struct glug_box b = { { 1.f, 2.f, 3.f }, { 2.f, 3.f, 4.f } };
    struct glug_vec3 dst = { 0.f, 0.f, 0.f };
    struct glug_vec3 exp = b.min;
    struct glug_box empty = { b.max, b.min };

    glug_box_clamp_point(&b, &dst);
    ASSERT_VEC3_EQUAL(&dst, &exp, 0.f);

    glug_box_clamp_point(&empty, &dst);
    ASSERT_VEC3_EQUAL(&dst, &exp, 0.f);
}

int main(void)
{
    CU_pSuite box_suite = create_suite("box", NULL, NULL);
    if (!box_suite) return CU_get_error();

    ADD_TEST(box_suite, set);
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

    return run_tests(CU_BRM_VERBOSE);
}
