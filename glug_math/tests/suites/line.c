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

static void test_distance(void)
{
    struct glug_line l = { { 1.f, 2.f, -1.f }, { 0.f, 1.f, 1.f } };
    struct glug_vec3 p = { 1.f, 1.f, 1.f };
    float exp = 0.91287f;
    float dist = glug_line_distance_to_point(&l, &p);

    CU_ASSERT_DOUBLE_EQUAL(dist, exp, 0.00001f);
}

static void test_project_point(void)
{
    struct glug_line l = { { 1.f, 2.f, -1.f }, { 0.f, 1.f, 1.f } };
    struct glug_vec3 dst = { 1.f, 1.f, 1.f };
    struct glug_vec3 exp = { 0.15214f, 1.30429f, 0.84785f };

    glug_line_project_point(&l, &dst);
    ASSERT_VEC3_EQUAL(&dst, &exp, 0.00001f);
}

int main(void)
{
    CU_pSuite line_suite = create_suite("line", NULL, NULL);
    if (!line_suite) return CU_get_error();

    ADD_TEST(line_suite, from_points);
    ADD_TEST(line_suite, at_t);
    ADD_TEST(line_suite, distance);
    ADD_TEST(line_suite, project_point);

    return run_tests(CU_BRM_VERBOSE);
}
