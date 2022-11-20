#include <CUnit/Basic.h>
#include <CUnit/Assert.h>

#include <suites/create_suite.h>
#include <asserts/asserts.h>

#include <glug/math/triangle3.h>

static void test_equal(void)
{

}

static void test_from_barycentric(void)
{
    struct glug_triangle3 t = { { -0.5f, -0.5f, 0.25f }, { 0.5f, -0.5f, 0.5f }, { 0.f, 0.5f, 0.75f } };
    struct glug_vec3 bary = { 1.f, 0.f, 0.f };
    struct glug_vec3 exp = t.a;

    struct glug_vec3 p = glug_triangle3_barycentric(&t, &bary);
    ASSERT_VEC3_EQUAL(&p, &exp, 0.f);

    bary.x = 0.f;
    bary.y = 1.f;
    bary.z = 0.f;
    exp = t.b;
    p = glug_triangle3_barycentric(&t, &bary);
    ASSERT_VEC3_EQUAL(&p, &exp, 0.f);

    bary.x = 0.f;
    bary.y = 0.f;
    bary.z = 1.f;
    exp = t.c;
    p = glug_triangle3_barycentric(&t, &bary);
    ASSERT_VEC3_EQUAL(&p, &exp, 0.f);

    bary.x = 0.5f;
    bary.y = 0.25f;
    bary.z = 0.25f;
    exp.x = -0.125f;
    exp.y = -0.25f;
    exp.z = 0.4375f;
    p = glug_triangle3_barycentric(&t, &bary);
    ASSERT_VEC3_EQUAL(&p, &exp, 0.f);
}

static void test_from_trilinear(void)
{
    struct glug_triangle3 t = { { -1.f, 1.f, 0.5f }, { -1.f, 2.f, -0.5f }, { -2.f, 1.f, 0.5f } };
    struct glug_vec3 tril = { 2.f, 2.f, 2.f };
    struct glug_vec3 exp = { -1.34108f, 1.24118f, 0.25881f };

    struct glug_vec3 p = glug_triangle3_trilinear(&t, &tril);
    ASSERT_VEC3_EQUAL(&p, &exp, 0.00001f);

    tril.x = 0;
    tril.y = 1;
    tril.z = 1;
    exp.x = -1.58578f;
    exp.y =  1.41421f;
    exp.z =  0.08578f;

    p = glug_triangle3_trilinear(&t, &tril);
    ASSERT_VEC3_EQUAL(&p, &exp, 0.00001f);
}

static void test_to_barycentric(void)
{
    struct glug_triangle3 t = { { -0.5f, -0.5f, 0.25f }, { 0.5f, -0.5f, 0.5f }, { 0.f, 0.5f, 0.75f } };
    struct glug_vec3 p = t.a;
    struct glug_vec3 exp =  { 1.f, 0.f, 0.f };

    struct glug_vec3 bary = glug_triangle3_to_barycentric(&t, &p);
    ASSERT_VEC3_EQUAL(&bary, &exp, 0.f);

    p = t.b;
    exp.x = 0.f;
    exp.y = 1.f;
    exp.z = 0.f;
    bary = glug_triangle3_to_barycentric(&t, &p);
    ASSERT_VEC3_EQUAL(&bary, &exp, 0.f);

    exp.x = 0.f;
    exp.y = 0.f;
    exp.z = 1.f;
    p = t.c;
    bary = glug_triangle3_to_barycentric(&t, &p);
    ASSERT_VEC3_EQUAL(&bary, &exp, 0.f);

    exp.x = 0.5f;
    exp.y = 0.25f;
    exp.z = 0.25f;
    p.x = -0.125f;
    p.y = -0.25f;
    p.z = 0.4375f;
    bary = glug_triangle3_to_barycentric(&t, &p);
    ASSERT_VEC3_EQUAL(&bary, &exp, 0.f);
}

static void test_to_trilinear(void)
{
    struct glug_triangle3 t = { { -1.f, 1.f, 0.5f }, { -1.f, 2.f, -0.5f }, { -2.f, 1.f, 0.5f } };
    struct glug_vec3 p = { -1.34108f, 1.24118f, 0.25881f };

    struct glug_vec3 tril = glug_triangle3_to_trilinear(&t, &p);

    CU_ASSERT_DOUBLE_EQUAL(tril.x / tril.y, 1.f, 0.0001f);
    CU_ASSERT_DOUBLE_EQUAL(tril.y / tril.z, 1.f, 0.0001f);
}

static void test_normal(void)
{
    struct glug_triangle3 t = { { -1.f, 0.f, -1.f }, { 1.f, 0.f, -1.f }, { -1.f, 0.f, 1.f } };
    struct glug_vec3 exp = { 0.f, -1.f, 0.f };
    struct glug_vec3 n = glug_triangle3_normal(&t);

    ASSERT_VEC3_EQUAL(&n, &exp, 0.00001f);
}

static void test_centroid(void)
{
    struct glug_triangle3 t = { { -0.5f, -0.5f, -0.5f }, { 0.75f, -0.5f, 1.f }, { 0.1f, 0.8f, 2.f } };
    struct glug_vec3 exp = { 0.11666f, -0.06666f, 0.83333f };
    struct glug_vec3 c = glug_triangle3_centroid(&t);

    ASSERT_VEC3_EQUAL(&c, &exp, 0.00001f);
}

static void test_incenter(void)
{
    struct glug_triangle3 t = { { -0.5f, -0.5f, -0.5f }, { 0.5f, -0.5f, 0.5f }, { 0.f, 0.5f, 0.5f } };
    struct glug_vec3 exp = { 0.04736f, -0.14927f, 0.22272f };
    struct glug_vec3 c = glug_triangle3_incenter(&t);

    ASSERT_VEC3_EQUAL(&c, &exp, 0.00001f);
}

static void test_contains_point(void)
{
    struct glug_triangle3 t = { { -1.f, 1.f, 1.f }, { -1.f, 2.f, 1.f }, { -2.f, 1.f, -1.f } };
    struct glug_vec3 p = { -1.17588f, 1.39328f, 0.64823f };

    struct glug_vec3 c = { 1.f, 1.f, 1.f };
    struct glug_vec3 inc = glug_triangle3_trilinear(&t, &c);

    int contains = glug_triangle3_contains_point(&t, &p);
    CU_ASSERT_TRUE(contains);

    p.x = 100.f;
    contains = glug_triangle3_contains_point(&t, &p);
    CU_ASSERT_FALSE(contains);
}

static void test_distance(void)
{
    struct glug_triangle3 t = { { -1.f, 1.f, 1.f }, { -1.f, 2.f, 1.f }, { -2.f, 1.f, -1.f } };
    struct glug_vec3 p = { -1.f, 1.f, 2.f };
    float exp = 1.f;
    float dist = glug_triangle3_distance_to_point(&t, &p);
    CU_ASSERT_DOUBLE_EQUAL(dist, exp, 0.f);

    p.x = -1.17588f;
    p.y =  1.39328f;
    p.z = 0.64823f;
    exp = 0.f;
    dist = glug_triangle3_distance_to_point(&t, &p);
    CU_ASSERT_DOUBLE_EQUAL(dist, exp, 0.f);
}

static void test_project_point(void)
{
    struct glug_triangle3 t = { { -1.f, 1.f, 1.f }, { -1.f, 2.f, 1.f }, { -2.f, 1.f, -1.f } };
    struct glug_vec3 dst = { -1.f, 1.f, 2.f };
    struct glug_vec3 exp = { -1.f, 1.f, 1.f };

    glug_triangle3_project_point(&t, &dst);
    ASSERT_VEC3_EQUAL(&dst, &exp, 0.f);
}

int main(void)
{
    CU_pSuite tri3_suite = create_suite("tri3", NULL, NULL);
    if (!tri3_suite) return CU_get_error();

    ADD_TEST(tri3_suite, equal);
    ADD_TEST(tri3_suite, from_barycentric);
    ADD_TEST(tri3_suite, from_trilinear);
    ADD_TEST(tri3_suite, to_barycentric);
    ADD_TEST(tri3_suite, to_trilinear);
    ADD_TEST(tri3_suite, normal);
    ADD_TEST(tri3_suite, centroid);
    ADD_TEST(tri3_suite, incenter);
    ADD_TEST(tri3_suite, contains_point);
    ADD_TEST(tri3_suite, distance);
    ADD_TEST(tri3_suite, project_point);

    return run_tests(CU_BRM_VERBOSE);
}
