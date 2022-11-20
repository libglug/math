#include <CUnit/Basic.h>
#include <CUnit/Assert.h>

#include <suites/create_suite.h>
#include <asserts/asserts.h>

#include <glug/math/plane.h>

static void test_from_points(void)
{
    struct glug_vec3 o = { 0.f, 0.f, 0.f };
    struct glug_vec3 x = { 1.f, 0.f, 0.f };
    struct glug_vec3 y = { 0.f, 1.f, 0.f };
    struct glug_plane dst;
    struct glug_plane exp = { { 0.f, 0.f, 1.f }, 0.f };

    glug_plane_from_points(&dst, &o, &x, &y);
    ASSERT_PLANE_EQUAL(&dst, &exp, 0.f);

    exp.normal.z = -1.f;
    glug_plane_from_points(&dst, &o, &y, &x);
    ASSERT_PLANE_EQUAL(&dst, &exp, 0.f);
}

static void test_from_normal(void)
{
    struct glug_vec3 n = { 1.f, 2.f, -1.f };
    struct glug_vec3 r = { -2.f, 0.5f, 5.f };
    struct glug_plane dst;
    struct glug_plane exp = { { 0.4082f, 0.81649f, -0.4082f  }, - 2.4494f };

    glug_plane_from_normal(&dst, &n, &r);
    ASSERT_PLANE_EQUAL(&dst, &exp, 0.0001f);
}

static void test_equal(void)
{

}

static void test_normalize(void)
{
    struct glug_plane dst = { { 3.f, -4.f, 5.f }, 24.7487f };
    struct glug_plane exp = { { 0.4242f, -0.5656f, 0.7071f }, 3.5f };

    glug_plane_normalize(&dst);
    ASSERT_PLANE_EQUAL(&dst, &exp, 0.0001f);
}

static void test_contains_point(void)
{

}

static void test_distance(void)
{
    struct glug_plane p = { { 0.4242f, -0.5656f, 0.7071f }, 3.5f };
    struct glug_vec3 r = { 5.f, 6.f, 7.f };
    float exp = 0.1770f;

    float d = glug_plane_distance_to_point(&p, &r);

    CU_ASSERT_DOUBLE_EQUAL(d, exp, 0.0001f);
}

static void test_project_point(void)
{
    struct glug_plane p = { { 0.4242f, -0.5656f, 0.7071f }, 3.5f };
    struct glug_vec3 dst = { 5.f, 6.f, 7.f };
    struct glug_vec3 exp = { 4.9249f, 6.1001f, 6.8748f };

    glug_plane_project_point(&p, &dst);
    ASSERT_VEC3_EQUAL(&dst, &exp, 0.0001f);
}

int main(void)
{
    CU_pSuite plane_suite = create_suite("plane", NULL, NULL);
    if (!plane_suite) return CU_get_error();

    ADD_TEST(plane_suite, from_points);
    ADD_TEST(plane_suite, from_normal);
    ADD_TEST(plane_suite, equal);
    ADD_TEST(plane_suite, normalize);
    ADD_TEST(plane_suite, contains_point);
    ADD_TEST(plane_suite, distance);
    ADD_TEST(plane_suite, project_point);

    return run_tests(CU_BRM_VERBOSE);
}
