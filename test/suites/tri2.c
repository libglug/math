#include <CUnit/Assert.h>
#include <CUnit/Basic.h>
#include <glug/math/triangle2.h>
#include "add_test.h"
#include "asserts.h"

static void test_set(void)
{
    struct glug_triangle2 dst;
    struct glug_vec2 a = { -0.5f, -0.5f }, b = { 0.5f, -0.5f }, c = { 0.f, 0.5f };
    struct glug_triangle2 exp = { a, b, c };

    glug_triangle2_set(&dst, &a, &b, &c);
    ASSERT_TRI2_EQUAL(&dst, &exp, 0.f);
}

static void test_equal(void)
{

}

static void test_from_barycentric(void)
{
    struct glug_triangle2 t = { { -0.5f, -0.5f }, { 0.5f, -0.5f }, { 0.f, 0.5f } };
    struct glug_vec3 bary = { 1.f, 0.f, 0.f };
    struct glug_vec2 exp = t.a;

    struct glug_vec2 p = glug_triangle2_barycentric(&t, &bary);
    ASSERT_VEC2_EQUAL(&p, &exp, 0.f);

    bary.x = 0.f;
    bary.y = 1.f;
    bary.z = 0.f;
    exp = t.b;
    p = glug_triangle2_barycentric(&t, &bary);
    ASSERT_VEC2_EQUAL(&p, &exp, 0.f);

    bary.x = 0.f;
    bary.y = 0.f;
    bary.z = 1.f;
    exp = t.c;
    p = glug_triangle2_barycentric(&t, &bary);
    ASSERT_VEC2_EQUAL(&p, &exp, 0.f);

    bary.x = 0.5f;
    bary.y = 0.5f;
    bary.z = 0.f;
    exp.x = 0.f;
    exp.y = -0.5f;
    p = glug_triangle2_barycentric(&t, &bary);
    ASSERT_VEC2_EQUAL(&p, &exp, 0.f);
}

static void test_from_trilinear(void)
{
    struct glug_triangle2 t = { { -1.f, 1.f }, { -1.f, 2.f }, { -2.f, 1.f } };
    struct glug_vec3 tril = { 2.f, 2.f, 2.f };
    struct glug_vec2 exp = { -1.29289f, 1.29289f };

    struct glug_vec2 p = glug_triangle2_trilinear(&t, &tril);
    ASSERT_VEC2_EQUAL(&p, &exp, 0.00001f);

    tril.x = 0;
    tril.y = 1;
    tril.z = 1;
    exp.x = -1.5f;
    exp.y =  1.5;

    p = glug_triangle2_trilinear(&t, &tril);
    ASSERT_VEC2_EQUAL(&p, &exp, 0.f);

}

static void test_to_barycentric(void)
{
    struct glug_triangle2 t = { { -0.5f, -0.5f }, { 0.5f, -0.5f }, { 0.f, 0.5f } };
    struct glug_vec2 p = t.a;
    struct glug_vec3 exp =  { 1.f, 0.f, 0.f };

    struct glug_vec3 bary = glug_triangle2_to_barycentric(&t, &p);
    ASSERT_VEC3_EQUAL(&bary, &exp, 0.f);

    p = t.b;
    exp.x = 0.f;
    exp.y = 1.f;
    exp.z = 0.f;
    bary = glug_triangle2_to_barycentric(&t, &p);
    ASSERT_VEC3_EQUAL(&bary, &exp, 0.f);

    exp.x = 0.f;
    exp.y = 0.f;
    exp.z = 1.f;
    p = t.c;
    bary = glug_triangle2_to_barycentric(&t, &p);
    ASSERT_VEC3_EQUAL(&bary, &exp, 0.f);

    exp.x = 0.5f;
    exp.y = 0.5f;
    exp.z = 0.f;
    p.x = 0.f;
    p.y = -0.5f;
    bary = glug_triangle2_to_barycentric(&t, &p);
    ASSERT_VEC3_EQUAL(&bary, &exp, 0.f);
}

static void test_to_trilinear(void)
{
    struct glug_triangle2 t = { { -1.f, 1.f }, { -1.f, 2.f }, { -2.f, 1.f } };
    struct glug_vec2 p = { -1.29289f, 1.29289f };

    struct glug_vec3 tril = glug_triangle2_to_trilinear(&t, &p);

    CU_ASSERT_DOUBLE_EQUAL(tril.x / tril.y, 1.f, 0.0001f);
    CU_ASSERT_DOUBLE_EQUAL(tril.y / tril.z, 1.f, 0.0001f);
}

static void test_centroid(void)
{
    struct glug_triangle2 t = { { -0.5f, -0.5f }, { 0.75f, -0.5f }, { 0.1f, 0.8f } };
    struct glug_vec2 exp = { 0.11666f, -0.06666f };
    struct glug_vec2 c = glug_triangle2_centroid(&t);

    ASSERT_VEC2_EQUAL(&c, &exp, 0.00001f);
}

static void test_incenter(void)
{
    struct glug_triangle2 t = { { -0.5f, -0.5f }, { 0.5f, -0.5f }, { 0.f, 0.5f } };
    struct glug_vec2 exp = { 0.f, -0.19098f };
    struct glug_vec2 c = glug_triangle2_incenter(&t);

    ASSERT_VEC2_EQUAL(&c, &exp, 0.00001f);
}

static void test_contains_point(void)
{
    struct glug_triangle2 t = { { -1.f, 1.f }, { -1.f, 2.f }, { -2.f, 1.f } };
    struct glug_vec2 p = { -1.29289f, 1.29289f };

    int contains = glug_triangle2_contains_point(&t, &p);
    CU_ASSERT_TRUE(contains);

    p.x = 100.f;
    contains = glug_triangle2_contains_point(&t, &p);
    CU_ASSERT_FALSE(contains);
}

static void test_distance(void)
{
    struct glug_triangle2 t = { { -1.f, 1.f }, { -1.f, 2.f }, { -2.f, 1.f } };
    struct glug_vec2 p = { -3.f, 1.f };
    float exp = 1.f;
    float dist = glug_triangle2_distance_to_point(&t, &p);
    CU_ASSERT_DOUBLE_EQUAL(dist, exp, 0.f);

    p.x = -1.2f;
    p.y =  1.2f;
    exp = 0.f;
    dist = glug_triangle2_distance_to_point(&t, &p);
    CU_ASSERT_DOUBLE_EQUAL(dist, exp, 0.f);
}

static void test_closest_point(void)
{
    struct glug_triangle2 t = { { -1.f, 1.f }, { -1.f, 2.f }, { -2.f, 1.f } };
    struct glug_vec2 p = { -3.f, 1.f };
    struct glug_vec2 exp = { -2.f, 1.f };

    struct glug_vec2 dst = glug_triangle2_closest_point(&t, &p);
    ASSERT_VEC2_EQUAL(&dst, &exp, 0.f);

    p.x = -1.2f;
    p.y =  1.2f;
    exp = p;
    dst = glug_triangle2_closest_point(&t, &p);
    ASSERT_VEC2_EQUAL(&dst, &exp, 0.f);
}

static void test_project_point(void)
{
    struct glug_triangle2 t = { { -1.f, 1.f }, { -1.f, 2.f }, { -2.f, 1.f } };
    struct glug_vec2 dst = { -3.f, 1.f };
    struct glug_vec2 exp = { -2.f, 1.f };

    glug_triangle2_project_point(&t, &dst);
    ASSERT_VEC2_EQUAL(&dst, &exp, 0.f);
}

CU_pSuite create_tri2_suite()
{
    CU_pSuite tri2_suite = CU_add_suite("triangle2", NULL, NULL);
    if (!tri2_suite) return NULL;

    ADD_TEST(tri2_suite, set);
    ADD_TEST(tri2_suite, equal);
    ADD_TEST(tri2_suite, from_barycentric);
    ADD_TEST(tri2_suite, from_trilinear);
    ADD_TEST(tri2_suite, to_barycentric);
    ADD_TEST(tri2_suite, to_trilinear);
    ADD_TEST(tri2_suite, distance);
    ADD_TEST(tri2_suite, centroid);
    ADD_TEST(tri2_suite, incenter);
    ADD_TEST(tri2_suite, contains_point);
    ADD_TEST(tri2_suite, closest_point);
    ADD_TEST(tri2_suite, project_point);

    return tri2_suite;
}
