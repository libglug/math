#include <CUnit/Basic.h>
#include <CUnit/Assert.h>

#include <float.h>
#include <suites/create_suite.h>
#include <asserts/asserts.h>

#include <glug/math/line2.h>

static void test_from_points(void)
{
    struct glug_vec2 a = { 0.f, 1.f };
    struct glug_vec2 b = { 1.f, 3.f };
    struct glug_line2 l;
    glug_line2_from_points(&l, &a, &b);
    struct glug_line2 exp = { { 1.f, 2.f }, { 0.f, 1.f } };

    ASSERT_LINE2_EQUAL(&l, &exp, 0.f);
}

static void test_from_slope(void)
{
    float m = 2.f, b = 1.f;
    struct glug_line2 l;
    glug_line2_from_slope(&l, m, b);
    struct glug_line2 exp = { { 1.f, 2.f }, { 0.f, 1.f } };

    ASSERT_LINE2_EQUAL(&l, &exp, 0.f);

    m = INFINITY;
    exp.v.x = 0.f;
    exp.v.y = 1.f;
    exp.r0.x = b;
    exp.r0.y = 0;
    glug_line2_from_slope(&l, m, b);
    ASSERT_LINE2_EQUAL(&l, &exp, 0.f);
}

static void test_at_t(void)
{
    struct glug_line2 l = { { 1.f, 2.f }, { 0.f, 1.f } };
    float t = 0;
    struct glug_vec2 exp = { 0.f, 1.f };

    struct glug_vec2 r;
    glug_line2_at_t(&l, t, &r);
    ASSERT_VEC2_EQUAL(&r, &exp, 0.f);

    t = -1.f;
    exp.x = -1.f;
    exp.y = -1.f;

    glug_line2_at_t(&l, t, &r);
    ASSERT_VEC2_EQUAL(&r, &exp, 0.f);

    t = 2.5f;
    exp.x = 2.5f;
    exp.y = 6.f;

    glug_line2_at_t(&l, t, &r);
    ASSERT_VEC2_EQUAL(&r, &exp, 0.f);
}

static void test_distance(void)
{
    struct glug_line2 l = { { 1.f, 2.f }, { 0.f, 1.f } };
    struct glug_vec2 p = { 1.f, 1.f };
    float exp = 0.89442f;
    float dist = glug_line2_distance_to_point(&l, &p);

    CU_ASSERT_DOUBLE_EQUAL(dist, exp, 0.00001f);
}

static void test_project_point(void)
{
    struct glug_line2 l = { { 1.f, 2.f }, { 0.f, 1.f } };
    struct glug_vec2 dst = { 1.f, 1.f };
    struct glug_vec2 exp = { 0.17888f, 1.35777f };

    glug_line2_project_point(&l, &dst);
    ASSERT_VEC2_EQUAL(&dst, &exp, 0.00001f);
}

int main(void)
{
    CU_pSuite line2_suite = create_suite("line2", NULL, NULL);
    if (!line2_suite) return CU_get_error();

    ADD_TEST(line2_suite, from_points);
    ADD_TEST(line2_suite, from_slope);
    ADD_TEST(line2_suite, at_t);
    ADD_TEST(line2_suite, distance);
    ADD_TEST(line2_suite, project_point);

    return run_tests(CU_BRM_VERBOSE);
}
