#include <CUnit/Basic.h>
#include <CUnit/Assert.h>

#include <suites/create_suite.h>
#include <asserts/asserts.h>

#include <glug/math/line.h>

static void test_from_points(void)
{
    struct glug_vec3 a = { 0.f, 1.f, 2.f };
    struct glug_vec3 b = { 1.f, 3.f, 5.f };

    struct glug_line l;
    glug_line_from_points(&l, &a, &b);
    struct glug_line exp = { { 1.f, 2.f, 3.f }, { 0.f, 1.f, 2.f } };

    ASSERT_LINE_EQUAL(&l, &exp, 0.f);
}

static void test_at_t(void)
{
    struct glug_line l = { { 1.f, 2.f, -1.f }, { 0.f, 1.f, 1.f } };
    float t = 0;
    struct glug_vec3 exp = { 0.f, 1.f, 1.f };

    struct glug_vec3 r;
    glug_line_at_t(&l, t, &r);
    ASSERT_VEC3_EQUAL(&r, &exp, 0.f);

    t = -1.f;
    exp.x = -1.f;
    exp.y = -1.f;
    exp.z = 2.f;

    glug_line_at_t(&l, t, &r);
    ASSERT_VEC3_EQUAL(&r, &exp, 0.f);

    t = 2.5f;
    exp.x = 2.5f;
    exp.y = 6.f;
    exp.z = -1.5f;

    glug_line_at_t(&l, t, &r);
    ASSERT_VEC3_EQUAL(&r, &exp, 0.f);
}

static void test_distance_to(void)
{
    struct glug_line l1 = { .v = { 8.f, 3.f, 4.f }, .r0 = { 1.f, 2.f, 3.f } };
    struct glug_line l2 = { .v = { 5.f, 4.f, 3.f }, .r0 = { 2.f, 3.f, 4.f } };

    float d = glug_line_distance_to(&l1, &l2);
    CU_ASSERT_DOUBLE_EQUAL(d, 0.31889, 0.0001f);

    l1.v = (struct glug_vec3){ 5.f, 4.f, 3.f };
    d = glug_line_distance_to(&l1, &l2);
    CU_ASSERT_DOUBLE_EQUAL(d, 0.3464f, 0.0001f);
}

static void test_closests_pts(void)
{
    struct glug_line l1 = { .v = { 8.f, 3.f, 4.f }, .r0 = { 1.f, 2.f, 3.f } };
    struct glug_line l2 = { .v = { 5.f, 4.f, 3.f }, .r0 = { 2.f, 3.f, 4.f } };
    struct glug_vec3 p1, p2, exp;

    glug_line_closest_points(&l1, &l2, &p1, &p2);
    exp = (struct glug_vec3){ 0.5932f, 1.8474f, 2.7966f };
    ASSERT_VEC3_EQUAL(&p1, &exp, 0.0001f);
    exp = (struct glug_vec3){ 0.4745f, 1.7796f, 3.0847f };
    ASSERT_VEC3_EQUAL(&p2, &exp, 0.0001f);

    l1.v = (struct glug_vec3){ 5.f, 4.f, 3.f };
    glug_line_closest_points(&l1, &l2, &p1, &p2);
    ASSERT_VEC3_EQUAL(&p1, &l1.r0, 0.0001f);
    exp = (struct glug_vec3){ 0.7999f, 2.0399, 3.2799f };
    ASSERT_VEC3_EQUAL(&p2, &exp, 0.0001f);
}

static void test_distance_to_pt(void)
{
    struct glug_line l = { { 0.f, 1.f, 0.f }, { 0.f, 0.f, 0.f } };
    struct glug_vec3 p = { 1.f, 2.f, 1.f };
    struct glug_vec3 exp = { 0.f, 2.f, 0.f };

    float d = glug_line_distance_to_point(&l, &p);
    CU_ASSERT_DOUBLE_EQUAL(d, sqrtf(2), 0.00001f);
}

static void test_project_point(void)
{
    struct glug_line l = { { 0.f, 1.f, 0.f }, { 0.f, 0.f, 0.f } };
    struct glug_vec3 p = { 1.f, 2.f, 1.f };
    struct glug_vec3 exp = { 0.f, 2.f, 0.f };

    glug_line_project_point(&l, &p);
    ASSERT_VEC3_EQUAL(&p, &exp, 0.00001f);
}

int main(void)
{
    CU_pSuite line_suite = create_suite("line", NULL, NULL);
    if (!line_suite) return CU_get_error();

    ADD_TEST(line_suite, from_points);
    ADD_TEST(line_suite, at_t);
    ADD_TEST(line_suite, distance_to);
    ADD_TEST(line_suite, closests_pts);
    ADD_TEST(line_suite, distance_to_pt);
    ADD_TEST(line_suite, project_point);

    return run_tests(CU_BRM_VERBOSE);
}
