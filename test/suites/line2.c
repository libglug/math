#include <CUnit/Assert.h>
#include <CUnit/Basic.h>
#include <glug/math/line2.h>
#include "add_test.h"

#include <float.h>

static void test_from_points(void)
{
    struct glug_vec2 a = { 0.f, 1.f };
    struct glug_vec2 b = { 1.f, 3.f };
    struct glug_line2 l = glug_line2_from_points(&a, &b);
    struct glug_line2 exp = { { 1.f, 2.f }, { 0.f, 1.f } };

    CU_ASSERT_DOUBLE_EQUAL(l.v.x, exp.v.x, 0.f);
    CU_ASSERT_DOUBLE_EQUAL(l.v.y, exp.v.y, 0.f);
    CU_ASSERT_DOUBLE_EQUAL(l.r0.x, exp.r0.x, 0.f);
    CU_ASSERT_DOUBLE_EQUAL(l.r0.y, exp.r0.y, 0.f);
}

static void test_from_slope(void)
{
    float m = 2.f, b = 1.f;
    struct glug_line2 l = glug_line2_from_slope(m, b);
    struct glug_line2 exp = { { 1.f, 2.f }, { 0.f, 1.f } };

    CU_ASSERT_DOUBLE_EQUAL(l.v.x, exp.v.x, 0.f);
    CU_ASSERT_DOUBLE_EQUAL(l.v.y, exp.v.y, 0.f);
    CU_ASSERT_DOUBLE_EQUAL(l.r0.x, exp.r0.x, 0.f);
    CU_ASSERT_DOUBLE_EQUAL(l.r0.y, exp.r0.y, 0.f);

    m = INFINITY;
    l = glug_line2_from_slope(m, b);
    exp.v.x = 0.f;
    exp.v.y = 1.f;
    exp.r0.x = b;
    exp.r0.y = 0;

    CU_ASSERT_DOUBLE_EQUAL(l.v.x, exp.v.x, 0.f);
    CU_ASSERT_DOUBLE_EQUAL(l.v.y, exp.v.y, 0.f);
    CU_ASSERT_DOUBLE_EQUAL(l.r0.x, exp.r0.x, 0.f);
    CU_ASSERT_DOUBLE_EQUAL(l.r0.y, exp.r0.y, 0.f);
}

static void test_set_by_points(void)
{
    struct glug_vec2 a = { 0.f, 1.f };
    struct glug_vec2 b = { 1.f, 3.f };
    struct glug_line2 dst;
    glug_line2_set_by_points(&dst, &a, &b);
    struct glug_line2 exp = { { 1.f, 2.f }, { 0.f, 1.f } };

    CU_ASSERT_DOUBLE_EQUAL(dst.v.x, exp.v.x, 0.f);
    CU_ASSERT_DOUBLE_EQUAL(dst.v.y, exp.v.y, 0.f);
    CU_ASSERT_DOUBLE_EQUAL(dst.r0.x, exp.r0.x, 0.f);
    CU_ASSERT_DOUBLE_EQUAL(dst.r0.y, exp.r0.y, 0.f);
}

static void test_set_by_slope(void)
{
    float m = 2.f, b = 1.f;
    struct glug_line2 dst;
    struct glug_line2 exp = { { 1.f, 2.f }, { 0.f, 1.f } };
    glug_line2_set_by_slope(&dst, m, b);

    CU_ASSERT_DOUBLE_EQUAL(dst.v.x, exp.v.x, 0.f);
    CU_ASSERT_DOUBLE_EQUAL(dst.v.y, exp.v.y, 0.f);
    CU_ASSERT_DOUBLE_EQUAL(dst.r0.x, exp.r0.x, 0.f);
    CU_ASSERT_DOUBLE_EQUAL(dst.r0.y, exp.r0.y, 0.f);

    m = INFINITY;
    dst = glug_line2_from_slope(m, b);
    exp.v.x = 0.f;
    exp.v.y = 1.f;
    exp.r0.x = b;
    exp.r0.y = 0;

    CU_ASSERT_DOUBLE_EQUAL(dst.v.x, exp.v.x, 0.f);
    CU_ASSERT_DOUBLE_EQUAL(dst.v.y, exp.v.y, 0.f);
    CU_ASSERT_DOUBLE_EQUAL(dst.r0.x, exp.r0.x, 0.f);
    CU_ASSERT_DOUBLE_EQUAL(dst.r0.y, exp.r0.y, 0.f);
}

static void test_at_t(void)
{
    struct glug_line2 l = { { 1.f, 2.f }, { 0.f, 1.f } };
    float t = 0;
    struct glug_vec2 exp = { 0.f, 1.f };

    struct glug_vec2 r = glug_line2_at_t(&l, t);
    CU_ASSERT_DOUBLE_EQUAL(r.x, exp.x, 0.f);
    CU_ASSERT_DOUBLE_EQUAL(r.y, exp.y, 0.f);

    t = -1.f;
    exp.x = -1.f;
    exp.y = -1.f;

    r = glug_line2_at_t(&l, t);
    CU_ASSERT_DOUBLE_EQUAL(r.x, exp.x, 0.f);
    CU_ASSERT_DOUBLE_EQUAL(r.y, exp.y, 0.f);

    t = 2.5f;
    exp.x = 2.5f;
    exp.y = 6.f;

    r = glug_line2_at_t(&l, t);
    CU_ASSERT_DOUBLE_EQUAL(r.x, exp.x, 0.f);
    CU_ASSERT_DOUBLE_EQUAL(r.y, exp.y, 0.f);
}

static void test_distance(void)
{
    struct glug_line2 l = { { 1.f, 2.f }, { 0.f, 1.f } };
    struct glug_vec2 p = { 1.f, 1.f };
    float exp = 0.89442f;
    float dist = glug_line2_distance_to_point(&l, &p);

    CU_ASSERT_DOUBLE_EQUAL(dist, exp, 0.00001f);
}

static void test_closest_point(void)
{
    struct glug_line2 l = { { 1.f, 2.f }, { 0.f, 1.f } };
    struct glug_vec2 p = { 1.f, 1.f };
    struct glug_vec2 exp = { 0.17888f, 1.35777f };
    struct glug_vec2 r = glug_line2_closest_point(&l, &p);

    CU_ASSERT_DOUBLE_EQUAL(r.x, exp.x, 0.00001f);
    CU_ASSERT_DOUBLE_EQUAL(r.y, exp.y, 0.00001f);
}

static void test_project_point(void)
{
    struct glug_line2 l = { { 1.f, 2.f }, { 0.f, 1.f } };
    struct glug_vec2 dst = { 1.f, 1.f };
    struct glug_vec2 exp = { 0.17888f, 1.35777f };

    glug_line2_project_point(&l, &dst);
    CU_ASSERT_DOUBLE_EQUAL(dst.x, exp.x, 0.00001f);
    CU_ASSERT_DOUBLE_EQUAL(dst.y, exp.y, 0.00001f);
}

CU_pSuite create_line2_suite()
{
    CU_pSuite line2_suite = CU_add_suite("line", NULL, NULL);
    if (!line2_suite) return NULL;

    ADD_TEST(line2_suite, from_points);
    ADD_TEST(line2_suite, from_slope);
    ADD_TEST(line2_suite, set_by_points);
    ADD_TEST(line2_suite, set_by_slope);
    ADD_TEST(line2_suite, at_t);
    ADD_TEST(line2_suite, distance);
    ADD_TEST(line2_suite, closest_point);
    ADD_TEST(line2_suite, project_point);

    return line2_suite;
}
