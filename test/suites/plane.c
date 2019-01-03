#include <CUnit/Assert.h>
#include <CUnit/Basic.h>
#include <glug/math/plane.h>
#include "add_test.h"

static void test_from_points(void)
{
    struct glug_vec3 o = { 0.f, 0.f, 0.f };
    struct glug_vec3 x = { 1.f, 0.f, 0.f };
    struct glug_vec3 y = { 0.f, 1.f, 0.f };
    struct glug_plane p = glug_plane_from_points(&o, &x, &y);
    struct glug_plane exp = { { 0.f, 0.f, 1.f }, 0.f };

    CU_ASSERT_DOUBLE_EQUAL(p.n.x, exp.n.x, 0.f);
    CU_ASSERT_DOUBLE_EQUAL(p.n.y, exp.n.y, 0.f);
    CU_ASSERT_DOUBLE_EQUAL(p.n.z, exp.n.z, 0.f);
    CU_ASSERT_DOUBLE_EQUAL(p.d, exp.d, 0.f);

    p = glug_plane_from_points(&o, &y, &x);
    exp.n.z = -1.f;

    CU_ASSERT_DOUBLE_EQUAL(p.n.x, exp.n.x, 0.f);
    CU_ASSERT_DOUBLE_EQUAL(p.n.y, exp.n.y, 0.f);
    CU_ASSERT_DOUBLE_EQUAL(p.n.z, exp.n.z, 0.f);
    CU_ASSERT_DOUBLE_EQUAL(p.d, exp.d, 0.f);
}

static void test_from_normal(void)
{
    struct glug_vec3 n = { 1.f, 2.f, -1.f };
    struct glug_vec3 r = { -2.f, 0.5f, 5.f };
    struct glug_plane p = glug_plane_from_normal(&n, &r);
    struct glug_plane exp = { { 0.4082f, 0.81649f, -0.4082f  }, - 2.4494f };

    CU_ASSERT_DOUBLE_EQUAL(p.n.x, exp.n.x, 0.0001f);
    CU_ASSERT_DOUBLE_EQUAL(p.n.y, exp.n.y, 0.0001f);
    CU_ASSERT_DOUBLE_EQUAL(p.n.z, exp.n.z, 0.0001f);
    CU_ASSERT_DOUBLE_EQUAL(p.d, exp.d, 0.0001f);
}

static void test_set_by_points(void)
{
    struct glug_vec3 o = { 0.f, 0.f, 0.f };
    struct glug_vec3 x = { 1.f, 0.f, 0.f };
    struct glug_vec3 y = { 0.f, 1.f, 0.f };
    struct glug_plane dst;
    struct glug_plane exp = { { 0.f, 0.f, 1.f }, 0.f };

    glug_plane_set_by_points(&dst, &o, &x, &y);
    CU_ASSERT_DOUBLE_EQUAL(dst.n.x, exp.n.x, 0.f);
    CU_ASSERT_DOUBLE_EQUAL(dst.n.y, exp.n.y, 0.f);
    CU_ASSERT_DOUBLE_EQUAL(dst.n.z, exp.n.z, 0.f);
    CU_ASSERT_DOUBLE_EQUAL(dst.d, exp.d, 0.f);

    glug_plane_set_by_points(&dst, &o, &y, &x);
    exp.n.z = -1.f;

    CU_ASSERT_DOUBLE_EQUAL(dst.n.x, exp.n.x, 0.f);
    CU_ASSERT_DOUBLE_EQUAL(dst.n.y, exp.n.y, 0.f);
    CU_ASSERT_DOUBLE_EQUAL(dst.n.z, exp.n.z, 0.f);
    CU_ASSERT_DOUBLE_EQUAL(dst.d, exp.d, 0.f);
}

static void test_set_by_normal(void)
{
    struct glug_vec3 n = { 1.f, 2.f, -1.f };
    struct glug_vec3 r = { -2.f, 0.5f, 5.f };
    struct glug_plane dst;
    struct glug_plane exp = { { 0.4082f, 0.81649f, -0.4082f  }, - 2.4494f };
    glug_plane_set_by_normal(&dst, &n, &r);

    CU_ASSERT_DOUBLE_EQUAL(dst.n.x, exp.n.x, 0.0001f);
    CU_ASSERT_DOUBLE_EQUAL(dst.n.y, exp.n.y, 0.0001f);
    CU_ASSERT_DOUBLE_EQUAL(dst.n.z, exp.n.z, 0.0001f);
    CU_ASSERT_DOUBLE_EQUAL(dst.d, exp.d, 0.0001f);
}

static void test_set(void)
{
    struct glug_plane p = { { 1.f, 1.f, 1.f }, 1.f };
    struct glug_vec3 n = { 7.77f, 9.12f, 10.2f };
    float d = -1.2f;
    glug_plane_set(&p, &n, d);

    CU_ASSERT_DOUBLE_EQUAL(p.n.x, n.x, 0.f);
    CU_ASSERT_DOUBLE_EQUAL(p.n.y, n.y, 0.f);
    CU_ASSERT_DOUBLE_EQUAL(p.n.z, n.z, 0.f);
    CU_ASSERT_DOUBLE_EQUAL(p.d, d, 0.f);
}

static void test_copy(void)
{
    struct glug_plane p1 = { { 1.f, 1.f, 1.f }, 1.f };
    struct glug_plane p2 = { { 7.77f, 9.12f, 10.2f }, 1.74f };
    glug_plane_copy(&p1, &p2);

    CU_ASSERT_DOUBLE_EQUAL(p1.n.x, p2.n.x, 0.f);
    CU_ASSERT_DOUBLE_EQUAL(p1.n.y, p2.n.y, 0.f);
    CU_ASSERT_DOUBLE_EQUAL(p1.n.z, p2.n.z, 0.f);
    CU_ASSERT_DOUBLE_EQUAL(p1.d, p2.d, 0.f);
}

static void test_equal(void)
{

}

static void test_contains_point(void)
{

}

static void test_closest_point(void)
{
    struct glug_plane p = { { 0.4242f, -0.5656f, 0.7071f }, 3.5f };
    struct glug_vec3 r = { 5.f, 6.f, 7.f };
    struct glug_vec3 exp = { 4.9249f, 6.1001f, 6.8748f };

    struct glug_vec3 dst = glug_plane_closest_point(&p, &r);

    CU_ASSERT_DOUBLE_EQUAL(dst.x, exp.x, 0.0001f);
    CU_ASSERT_DOUBLE_EQUAL(dst.y, exp.y, 0.0001f);
    CU_ASSERT_DOUBLE_EQUAL(dst.z, exp.z, 0.0001f);
}

static void test_project_point(void)
{
    struct glug_plane p = { { 0.4242f, -0.5656f, 0.7071f }, 3.5f };
    struct glug_vec3 dst = { 5.f, 6.f, 7.f };
    struct glug_vec3 exp = { 4.9249f, 6.1001f, 6.8748f };

    glug_plane_project_point(&p, &dst);

    CU_ASSERT_DOUBLE_EQUAL(dst.x, exp.x, 0.0001f);
    CU_ASSERT_DOUBLE_EQUAL(dst.y, exp.y, 0.0001f);
    CU_ASSERT_DOUBLE_EQUAL(dst.z, exp.z, 0.0001f);
}

CU_pSuite create_plane_suite()
{
    CU_pSuite plane_suite = CU_add_suite("plane", NULL, NULL);
    if (!plane_suite) return NULL;

    ADD_TEST(plane_suite, from_points);
    ADD_TEST(plane_suite, from_normal);
    ADD_TEST(plane_suite, set_by_points);
    ADD_TEST(plane_suite, set_by_normal);
    ADD_TEST(plane_suite, set);
    ADD_TEST(plane_suite, copy);
    ADD_TEST(plane_suite, equal);
    ADD_TEST(plane_suite, contains_point);
    ADD_TEST(plane_suite, closest_point);
    ADD_TEST(plane_suite, project_point);

    return plane_suite;
}
