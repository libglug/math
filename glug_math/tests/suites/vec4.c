#include <CUnit/Basic.h>
#include <CUnit/Assert.h>

#include <suites/create_suite.h>
#include <asserts/asserts.h>

#include <glug/math/vec4.h>

static void test_equal(void)
{

}

static void test_add(void)
{
    struct glug_vec4 dst = { 1.f, 8.9f, 10.f, 0.7f };
    struct glug_vec4 v2 = { -1.01f, -5.5f, 19.1f, -3.3f };
    struct glug_vec4 exp = { -0.01f, 3.4f, 29.1f, -2.6f };

    glug_vec4_add(&dst, &v2);
    ASSERT_VEC4_EQUAL(&dst, &exp, 0.001f);
}

static void test_sub(void)
{
    struct glug_vec4 dst = { 17.17f, 19.8f, 79.f, 32.f };
    struct glug_vec4 v2 = { 8.f, 9.f, 18.697f, -7.9f };
    struct glug_vec4 exp = { 9.17f, 10.8f, 60.303f, 39.9f };

    glug_vec4_sub(&dst, &v2);
    ASSERT_VEC4_EQUAL(&dst, &exp, 0.001f);
}

static void test_mul(void)
{
    struct glug_vec4 dst = { 4.f, 5.f, 10.f, -33.f };
    float scalar = 4.1f;
    struct glug_vec4 exp = { 16.4f, 20.5f, 41.f, -135.3f };

    glug_vec4_mul(&dst, scalar);
    ASSERT_VEC4_EQUAL(&dst, &exp, 0.001f);
}

static void test_div(void)
{
    struct glug_vec4 dst = { 3.142f, 2.718f, 1.618f, -5.412f };
    float scalar = 1.414f;
    struct glug_vec4 exp = { 2.222065f, 1.922206f, 1.144271f, -3.827439f };

    glug_vec4_div(&dst, scalar);
    ASSERT_VEC4_EQUAL(&dst, &exp, 0.000001f);
}

static void test_sign(void)
{
    struct glug_vec4 dst = { -13.7123f, 0.f, 5.2972f, 1.4142f };
    struct glug_vec4 exp = { -1.f, 0.f, 1.f, 1.f };

    glug_vec4_sign(&dst, &dst);
    ASSERT_VEC4_EQUAL(&dst, &exp, 0.f);
}

static void test_integral(void)
{
    struct glug_vec4 dst = { -13.7123f, 0.f, 5.2972f, 1.4142f };
    struct glug_vec4 exp = { -13.f, 0.f, 5.f, 1.f };

    glug_vec4_integral(&dst, &dst);
    ASSERT_VEC4_EQUAL(&dst, &exp, 0.f);
}

static void test_frac(void)
{
    struct glug_vec4 dst = { -13.7123f, 0.f, 5.2972f, 1.4142f };
    struct glug_vec4 exp = { -0.7123f,  0.f, 0.2972f, 0.4142f };

    glug_vec4_frac(&dst, &dst);
    ASSERT_VEC4_EQUAL(&dst, &exp, 0.00001f);
}

static void test_max(void)
{
    struct glug_vec4 v1 = { -2.f, 2.f, -2.f, 2.f };
    struct glug_vec4 v2 = { 1.f, -1.f, 1.f, -1.f };
    struct glug_vec4 dst = v1;
    struct glug_vec4 exp = { 1.f, 2.f, 1.f, 2.f };

    glug_vec4_max(&dst, &v2);
    ASSERT_VEC4_EQUAL(&dst, &exp, 0.f);

    dst = v2;
    glug_vec4_max(&dst, &v1);
    ASSERT_VEC4_EQUAL(&dst, &exp, 0.f);
}

static void test_min(void)
{
    struct glug_vec4 v1 = { -2.f, 2.f, -2.f, 2.f };
    struct glug_vec4 v2 = { 1.f, -1.f, 1.f, -1.f };
    struct glug_vec4 dst = v1;
    struct glug_vec4 exp = { -2.f, -1.f, -2.f, -1.f };

    glug_vec4_min(&dst, &v2);
    ASSERT_VEC4_EQUAL(&dst, &exp, 0.f);

    dst = v2;
    glug_vec4_min(&dst, &v1);
    ASSERT_VEC4_EQUAL(&dst, &exp, 0.f);
}

static void test_clamp(void)
{
    struct glug_vec4 dst = { -2.f, 2.f, -2.f, 2.f };
    struct glug_vec4 min = { -1.f, -1.f, -1.f, -1.f };
    struct glug_vec4 max = { 1.f, 1.f, 1.f, 1.f };
    struct glug_vec4 exp = { -1.f, 1.f, -1.f, 1.f };

    glug_vec4_clamp(&dst, &min, &max);
    ASSERT_VEC4_EQUAL(&dst, &exp, 0.f);
}

static void test_floor(void)
{
    struct glug_vec4 dst = { -13.7123f, 0.f, 5.2972f, 1.4142f };
    struct glug_vec4 exp = { -14.f, 0.f, 5.f, 1.f };

    glug_vec4_floor(&dst, &dst);
    ASSERT_VEC4_EQUAL(&dst, &exp, 0.f);
}

static void test_ceil(void)
{
    struct glug_vec4 dst = { -13.7123f, 0.f, 5.2972f, 1.4142f };
    struct glug_vec4 exp = { -13.f, 0.f, 6.f, 2.f };

    glug_vec4_ceil(&dst, &dst);
    ASSERT_VEC4_EQUAL(&dst, &exp, 0.00001f);
}

static void test_round(void)
{
    struct glug_vec4 dst = { -13.7123f, 0.f, 5.2972f, 1.4142f };
    struct glug_vec4 exp = { -14.f, 0.f, 5.f, 1.f };

    glug_vec4_round(&dst, &dst);
    ASSERT_VEC4_EQUAL(&dst, &exp, 0.00001f);
}

static void test_round_zero(void)
{
    struct glug_vec4 dst = { -13.7123f, 0.f, 5.2972f, 1.4142f };
    struct glug_vec4 exp = { -13.f, 0.f, 5.f, 1.f };

    glug_vec4_round_zero(&dst, &dst);
    ASSERT_VEC4_EQUAL(&dst, &exp, 0.00001f);
}

static void test_dot(void)
{
    struct glug_vec4 v1 = { -5.6f, -7.5f, 9.3f, -9.4f };
    struct glug_vec4 v2 = { -0.3f, 5.8f, 4.9f, -6.f };
    float exp = 60.15f;
    float dot = glug_vec4_dot(&v1, &v2);

    CU_ASSERT_DOUBLE_EQUAL(dot, exp, 0.01f);
}

static void test_len(void)
{
    struct glug_vec4 v = { -5.f, 3.f, -4.f, 8.2f };
    struct glug_vec4 v2 = { 6.f, -10.f, 2.f, -2.f };
    float len = glug_vec4_len(&v);
    float len2 = glug_vec4_len(&v2);
    float exp = 10.827f;
    float exp2 = 12.000f;

    CU_ASSERT_DOUBLE_EQUAL(len, exp, 0.001f);
    CU_ASSERT_DOUBLE_EQUAL(len2, exp2, 0.001f);
}

static void test_len_sq(void)
{
    struct glug_vec4 v = { -5.f, 3.f, -4.f, 8.2f };
    struct glug_vec4 v2 = { 6.f, -10.f, 2.f, -2.f };
    float len = glug_vec4_len_squared(&v);
    float len2 = glug_vec4_len_squared(&v2);
    float exp = 117.24f;
    float exp2 = 144.f;

    CU_ASSERT_DOUBLE_EQUAL(len, exp, 0.1f);
    CU_ASSERT_DOUBLE_EQUAL(len2, exp2, 0.1f);
}

static void test_len_taxi(void)
{
    struct glug_vec4 v = { -5.f, 3.f, -4.f, 8.2f };
    struct glug_vec4 v2 = { 6.f, -10.f, 2.f, -2.f };
    float len = glug_vec4_len_taxi(&v);
    float len2 = glug_vec4_len_taxi(&v2);
    float exp = 20.2f;
    float exp2 = 20.f;

    CU_ASSERT_DOUBLE_EQUAL(len, exp, 0.1f);
    CU_ASSERT_DOUBLE_EQUAL(len2, exp2, 0.1f);
}

static void test_set_len(void)
{
    struct glug_vec4 v = { 0.8f, -1.f, -0.1f, 3.5f };
    float newlen = 2.3f;
    struct glug_vec4 exp = { 0.493f, -0.616f, -0.0616f, 2.159f };

    glug_vec4_set_len(&v, newlen);
    ASSERT_VEC4_EQUAL(&v, &exp, 0.001f);
    CU_ASSERT_DOUBLE_EQUAL(glug_vec4_len(&v), newlen, 0.001f);
}

static void test_clamp_len(void)
{
    struct glug_vec4 v = { 1.5f, -1.5f, 1.5f, -1.5f };

    glug_vec4_clamp_len(&v, 1.f, 5.f);
    CU_ASSERT_DOUBLE_EQUAL(glug_vec4_len(&v), 3.f, 0.0001f);

    glug_vec4_clamp_len(&v, 1.f, 2.f);
    CU_ASSERT_DOUBLE_EQUAL(glug_vec4_len(&v), 2.f, 0.0001f);

    glug_vec4_clamp_len(&v, 5.f, 10.f);
    CU_ASSERT_DOUBLE_EQUAL(glug_vec4_len(&v), 5.f, 0.0001f);
}

static void test_is_norm(void)
{

}

static void test_normalize(void)
{
    struct glug_vec4 dst = { 3.f, 3.f, -3.f, -3.f };
    struct glug_vec4 exp = { 0.5f, 0.5f, -0.5f, -0.5f };
    glug_vec4_normalize(&dst);

    CU_ASSERT_DOUBLE_EQUAL(glug_vec4_len(&dst), 1.f, 0.0001f);
    ASSERT_VEC4_EQUAL(&dst, &exp, 0.00001f);
}

static void test_dist(void)
{
    struct glug_vec4 a = { -1.2f, 1.9f, -0.5f, -0.9f };
    struct glug_vec4 b = { -0.8f, 1.f, -0.3f, 0.6f };
    float dist = glug_vec4_dist(&a, &b);
    float exp = 1.8055f;

    CU_ASSERT_DOUBLE_EQUAL(dist, exp, 0.0001f);
}

static void test_dist_sq(void)
{
    struct glug_vec4 a = { -1.2f, 1.9f, -0.5f, -0.9f };
    struct glug_vec4 b = { -0.8f, 1.f, -0.3f, 0.6f };
    float dist = glug_vec4_dist_squared(&a, &b);
    float exp = 3.26f;

    CU_ASSERT_DOUBLE_EQUAL(dist, exp, 0.0001f);
}

static void test_dist_taxi(void)
{
    struct glug_vec4 a = { -1.2f, 1.9f, -0.5f, -0.9f };
    struct glug_vec4 b = { -0.8f, 1.f, -0.3f, 0.6f };
    float dist = glug_vec4_dist_taxi(&a, &b);
    float exp = 3.f;

    CU_ASSERT_DOUBLE_EQUAL(dist, exp, 0.0001f);
}

static void test_angle_to(void)
{
    struct glug_vec4 a = { -1.0f, 0.f, 0.f, 0.f };
    struct glug_vec4 b = { 0.f, 0.f, 0.f, 1.f };
    float ang = glug_vec4_angle_btw(&a, &b);
    float exp = 1.5707f;

    CU_ASSERT_DOUBLE_EQUAL(ang, exp, 0.0001f);
}


static void test_project(void)
{
    struct glug_vec4 dst = { 3.f, 3.f, 3.f, -2.f };
    struct glug_vec4 b = { 1.f, -2.f, 0.f, -2.f };
    struct glug_vec4 exp = { 0.11111f, -0.22222f, 0, -0.22222f };

    glug_vec4_project(&dst, &b);
    ASSERT_VEC4_EQUAL(&dst, &exp, 0.00001f);
}

static void test_reject(void)
{
    struct glug_vec4 dst = { 3.f, 3.f, 3.f, -2.f };
    struct glug_vec4 b = { 1.f, -2.f, 0.f, -2.f };
    struct glug_vec4 exp = { 2.88888f, 3.22222f, 3.f, -1.77777f };

    glug_vec4_reject(&dst, &b);
    ASSERT_VEC4_EQUAL(&dst, &exp, 0.00001f);
}

static void test_reflect(void)
{
    struct glug_vec4 dst = { 3.f, 3.f, 3.f, -2.f };
    struct glug_vec4 b = { 1.f, -2.f, 0.f, -2.f };
    struct glug_vec4 exp = { -2.77777f, -3.44444f, -3.f, 1.55555f };

    glug_vec4_reflect(&dst, &b);
    ASSERT_VEC4_EQUAL(&dst, &exp, 0.00001f);
}

static void test_refract(void)
{
    struct glug_vec4 dst = { 3.f, 3.f, 3.f, -2.f };
    struct glug_vec4 n = { 1.f, -2.f, 0.f, -2.f };
    struct glug_vec4 exp = { -0.16379f, 4.82758f, 1.50000f, 2.32758f };

    glug_vec4_refract(&dst, &n, 1.f, 2.f);
    ASSERT_VEC4_EQUAL(&dst, &exp, 0.00001f);
}

int main(void)
{
    CU_pSuite vec4_suite = create_suite("vec4", NULL, NULL);
    if (!vec4_suite) return CU_get_error();

    ADD_TEST(vec4_suite, equal);
    ADD_TEST(vec4_suite, add);
    ADD_TEST(vec4_suite, sub);
    ADD_TEST(vec4_suite, mul);
    ADD_TEST(vec4_suite, div);
    ADD_TEST(vec4_suite, sign);
    ADD_TEST(vec4_suite, integral);
    ADD_TEST(vec4_suite, frac);
    ADD_TEST(vec4_suite, max);
    ADD_TEST(vec4_suite, min);
    ADD_TEST(vec4_suite, clamp);
    ADD_TEST(vec4_suite, floor);
    ADD_TEST(vec4_suite, ceil);
    ADD_TEST(vec4_suite, round);
    ADD_TEST(vec4_suite, round_zero);
    ADD_TEST(vec4_suite, dot);
    ADD_TEST(vec4_suite, len);
    ADD_TEST(vec4_suite, len_sq);
    ADD_TEST(vec4_suite, len_taxi);
    ADD_TEST(vec4_suite, set_len);
    ADD_TEST(vec4_suite, clamp_len);
    ADD_TEST(vec4_suite, is_norm);
    ADD_TEST(vec4_suite, normalize);
    ADD_TEST(vec4_suite, dist);
    ADD_TEST(vec4_suite, dist_sq);
    ADD_TEST(vec4_suite, dist_taxi);
    ADD_TEST(vec4_suite, angle_to);
    ADD_TEST(vec4_suite, project);
    ADD_TEST(vec4_suite, reject);
    ADD_TEST(vec4_suite, reflect);
    ADD_TEST(vec4_suite, refract);

    return run_tests(CU_BRM_VERBOSE);
}
