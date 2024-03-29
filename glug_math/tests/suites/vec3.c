#include <CUnit/Basic.h>
#include <CUnit/Assert.h>

#include <suites/create_suite.h>
#include <asserts/asserts.h>

#include <glug/math/vec3.h>

static void test_equal(void)
{

}

static void test_add(void)
{
    struct glug_vec3 dst = { 1.f, 8.9f, 10.f };
    struct glug_vec3 v2 = { -1.01f, -5.5f, 19.1f };
    struct glug_vec3 exp = { -0.01f, 3.4f, 29.1f };

    glug_vec3_add(&dst, &v2);
    ASSERT_VEC3_EQUAL(&dst, &exp, 0.001f);
}

static void test_sub(void)
{
    struct glug_vec3 dst = { 17.17f, 19.8f, 79.f };
    struct glug_vec3 v2 = { 8.f, 9.f, 18.697f };
    struct glug_vec3 exp = { 9.17f, 10.8f, 60.303f };

    glug_vec3_sub(&dst, &v2);
    ASSERT_VEC3_EQUAL(&dst, &exp, 0.001f);
}

static void test_mul(void)
{
    struct glug_vec3 dst = { 4.f, 5.f, 10.f };
    float scalar = 4.1f;
    struct glug_vec3 exp = { 16.4f, 20.5f, 41.f };

    glug_vec3_mul(&dst, scalar);
    ASSERT_VEC3_EQUAL(&dst, &exp, 0.01f);
}

static void test_div(void)
{
    struct glug_vec3 dst = { 3.142f, 2.718f, 1.618f };
    float scalar = 1.414f;
    struct glug_vec3 exp = { 2.222065f, 1.922206f, 1.144271f };

    glug_vec3_div(&dst, scalar);
    ASSERT_VEC3_EQUAL(&dst, &exp, 0.000001f);
}

static void test_mul_cw(void)
{
    struct glug_vec3 v1 = { 1.5f, 2.f, 4.f };
    struct glug_vec3 v2 = { 2.f, 1.f, 0.25f };
    struct glug_vec3 exp;

    glug_vec3_mul_cw(&v1, &v1, &v2);
    exp = (struct glug_vec3){ 3.f, 2.f, 1.f };
    ASSERT_VEC3_EQUAL(&v1, &exp, 0.0001f);
}

static void test_div_cw(void)
{
    struct glug_vec3 v1 = { 3.f, 2.f, 9.f };
    struct glug_vec3 v2 = { 1.5f, 1.f, 3.f };
    struct glug_vec3 exp;

    glug_vec3_div_cw(&v1, &v1, &v2);
    exp = (struct glug_vec3){ 2.f, 2.f, 3.f };
    ASSERT_VEC3_EQUAL(&v1, &exp, 0.0001f);
}

static void test_sign(void)
{
    struct glug_vec3 dst = { -13.7123f, 0.f, 5.2972f };
    struct glug_vec3 exp = { -1.f, 0.f, 1.f };

    glug_vec3_sign(&dst, &dst);
    ASSERT_VEC3_EQUAL(&dst, &exp, 0.f);
}

static void test_integral(void)
{
    struct glug_vec3 dst = { -13.7123f, 0.f, 5.2972f };
    struct glug_vec3 exp = { -13.f, 0.f, 5.f };

    glug_vec3_integral(&dst, &dst);
    ASSERT_VEC3_EQUAL(&dst, &exp, 0.f);
}

static void test_frac(void)
{
    struct glug_vec3 dst = { -13.7123f, 0.f, 5.2972f };
    struct glug_vec3 exp = { -0.7123f,  0.f, 0.2972f };

    glug_vec3_frac(&dst, &dst);
    ASSERT_VEC3_EQUAL(&dst, &exp, 0.00001f);
}

static void test_max(void)
{
    struct glug_vec3 v1 = { -2.f, 2.f, -2.f };
    struct glug_vec3 v2 = { 1.f, -1.f, 1.f };
    struct glug_vec3 dst = v1;
    struct glug_vec3 exp = { 1.f, 2.f, 1.f };

    glug_vec3_max(&dst, &v2);
    ASSERT_VEC3_EQUAL(&dst, &exp, 0.f);

    dst = v2;
    glug_vec3_max(&dst, &v1);
    ASSERT_VEC3_EQUAL(&dst, &exp, 0.f);
}

static void test_min(void)
{
    struct glug_vec3 v1 = { -2.f, 2.f, -2.f };
    struct glug_vec3 v2 = { 1.f, -1.f, 1.f };
    struct glug_vec3 dst = v1;
    struct glug_vec3 exp = { -2.f, -1.f, -2.f };

    glug_vec3_min(&dst, &v2);
    ASSERT_VEC3_EQUAL(&dst, &exp, 0.f);

    dst = v2;
    glug_vec3_min(&dst, &v1);
    ASSERT_VEC3_EQUAL(&dst, &exp, 0.f);
}

static void test_clamp(void)
{
    struct glug_vec3 dst = { -2.f, 2.f, -2.f };
    struct glug_vec3 min = { -1.f, -1.f, -1.f };
    struct glug_vec3 max = { 1.f, 1.f, 1.f };
    struct glug_vec3 exp = { -1.f, 1.f, -1.f };

    glug_vec3_clamp(&dst, &min, &max);
    ASSERT_VEC3_EQUAL(&dst, &exp, 0.f);
}

static void test_floor(void)
{
    struct glug_vec3 dst = { -13.7123f, 0.f, 5.2972f };
    struct glug_vec3 exp = { -14.f, 0.f, 5.f };

    glug_vec3_floor(&dst, &dst);
    ASSERT_VEC3_EQUAL(&dst, &exp, 0.f);
}

static void test_ceil(void)
{
    struct glug_vec3 dst = { -13.7123f, 0.f, 5.2972f };
    struct glug_vec3 exp = { -13.f, 0.f, 6.f };

    glug_vec3_ceil(&dst, &dst);
    ASSERT_VEC3_EQUAL(&dst, &exp, 0.00001f);
}

static void test_round(void)
{
    struct glug_vec3 dst = { -13.7123f, 0.f, 5.2972f };
    struct glug_vec3 exp = { -14.f, 0.f, 5.f };

    glug_vec3_round(&dst, &dst);
    ASSERT_VEC3_EQUAL(&dst, &exp, 0.00001f);
}

static void test_round_zero(void)
{
    struct glug_vec3 dst = { -13.7123f, 0.f, 5.2972f };
    struct glug_vec3 exp = { -13.f, 0.f, 5.f };

    glug_vec3_round_zero(&dst, &dst);
    ASSERT_VEC3_EQUAL(&dst, &exp, 0.00001f);
}

static void test_dot(void)
{
    struct glug_vec3 v1 = { -5.6f, -7.5f, 9.3f };
    struct glug_vec3 v2 = { -0.3f, 5.8f, 4.9f };
    float exp = 3.75f;
    float dot = glug_vec3_dot(&v1, &v2);

    CU_ASSERT_DOUBLE_EQUAL(dot, exp, 0.01f);
}

static void test_cross(void)
{
    struct glug_vec3 a = { -1.0f, 0.f, 0.f };
    struct glug_vec3 b = { 0.f, 1.f, 0.f };
    struct glug_vec3 c;
    glug_vec3_cross(&c, &a, &b);
    struct glug_vec3 exp = { 0.f, 0.f, -1.f };

    ASSERT_VEC3_EQUAL(&c, &exp, 0.f);

    exp.x = 1.f;
    exp.y = 0.f;
    exp.z = 0.f;
    glug_vec3_cross(&a, &c, &b);
    ASSERT_VEC3_EQUAL(&a, &exp, 0.f);
}

static void test_triple_product(void)
{
    struct glug_vec3 v1 = { -2.f, 3.f, 1.f };
    struct glug_vec3 v2 = {  0.f, 4.f, 0.f };
    struct glug_vec3 v3 = { -1.f, 3.f, 3.f };

    float tp = glug_vec3_triple_product(&v1, &v2, &v3);
    CU_ASSERT_DOUBLE_EQUAL(tp, -20, 0.0001f);
}

static void test_len(void)
{
    struct glug_vec3 v = { -5.f, 3.f, -4.f };
    struct glug_vec3 v2 = { 6.f, -10.f, 2.f };
    float len = glug_vec3_len(&v);
    float len2 = glug_vec3_len(&v2);
    float exp = 7.071f;
    float exp2 = 11.832f;

    CU_ASSERT_DOUBLE_EQUAL(len, exp, 0.001f);
    CU_ASSERT_DOUBLE_EQUAL(len2, exp2, 0.001f);
}

static void test_len_sq(void)
{
    struct glug_vec3 v = { -5.f, 3.f, -4.f };
    struct glug_vec3 v2 = { 6.f, -10.f, 2.f };
    float len = glug_vec3_len_squared(&v);
    float len2 = glug_vec3_len_squared(&v2);
    float exp = 50.f;
    float exp2 = 140.f;

    CU_ASSERT_DOUBLE_EQUAL(len, exp, 0.1f);
    CU_ASSERT_DOUBLE_EQUAL(len2, exp2, 0.1f);
}

static void test_len_taxi(void)
{
    struct glug_vec3 v = { -5.f, 3.f, -4.f };
    struct glug_vec3 v2 = { 6.f, -10.f, 2.f };
    float len = glug_vec3_len_taxi(&v);
    float len2 = glug_vec3_len_taxi(&v2);
    float exp = 12.f;
    float exp2 = 18.f;

    CU_ASSERT_DOUBLE_EQUAL(len, exp, 0.1f);
    CU_ASSERT_DOUBLE_EQUAL(len2, exp2, 0.1f);
}

static void test_set_len(void)
{
    struct glug_vec3 v = { 0.8f, -1.f, -0.1f };
    float newlen = 2.3f;
    struct glug_vec3 exp = { 1.432f, -1.790f, -0.1790f };

    glug_vec3_set_len(&v, newlen);
    ASSERT_VEC3_EQUAL(&v, &exp, 0.001f);
    CU_ASSERT_DOUBLE_EQUAL(glug_vec3_len(&v), newlen, 0.001f);
}

static void test_clamp_len(void)
{
    struct glug_vec3 v = { 1.5f, -1.5f, 1.5f };

    glug_vec3_clamp_len(&v, 1.f, 5.f);
    CU_ASSERT_DOUBLE_EQUAL(glug_vec3_len(&v), sqrtf(6.75f), 0.0001f);

    glug_vec3_clamp_len(&v, 1.f, 2.f);
    CU_ASSERT_DOUBLE_EQUAL(glug_vec3_len(&v), 2.f, 0.0001f);

    glug_vec3_clamp_len(&v, 5.f, 10.f);
    CU_ASSERT_DOUBLE_EQUAL(glug_vec3_len(&v), 5.f, 0.0001f);
}

static void test_is_norm(void)
{

}

static void test_normalize(void)
{
    struct glug_vec3 dst = { 3.f, 3.f, -3.f };
    struct glug_vec3 exp = { 0.57735f, 0.57735f, -0.57735f };
    glug_vec3_normalize(&dst);

    CU_ASSERT_DOUBLE_EQUAL(glug_vec3_len(&dst), 1.f, 0.0001f);
    ASSERT_VEC3_EQUAL(&dst, &exp, 0.00001f);
}

static void test_dist(void)
{
    struct glug_vec3 a = { -1.2f, 1.9f, -0.5f };
    struct glug_vec3 b = { -0.8f, 1.f, -0.3f };
    float dist = glug_vec3_dist(&a, &b);
    float exp = 1.0049f;

    CU_ASSERT_DOUBLE_EQUAL(dist, exp, 0.0001f);
}

static void test_dist_sq(void)
{
    struct glug_vec3 a = { -1.2f, 1.9f, -0.5f };
    struct glug_vec3 b = { -0.8f, 1.f, -0.3f };
    float dist = glug_vec3_dist_squared(&a, &b);
    float exp = 1.01f;

    CU_ASSERT_DOUBLE_EQUAL(dist, exp, 0.0001f);
}

static void test_dist_taxi(void)
{
    struct glug_vec3 a = { -1.2f, 1.9f, -0.5f };
    struct glug_vec3 b = { -0.8f, 1.f, -0.3f };
    float dist = glug_vec3_dist_taxi(&a, &b);
    float exp = 1.5f;

    CU_ASSERT_DOUBLE_EQUAL(dist, exp, 0.0001f);
}

static void test_angle_to(void)
{
    struct glug_vec3 a = { -1.0f, 0.f, 0.f };
    struct glug_vec3 b = { 0.f, 1.f, 0.f };
    float ang = glug_vec3_angle_btw(&a, &b);
    float exp = 1.5707f;

    CU_ASSERT_DOUBLE_EQUAL(ang, exp, 0.0001f);
}

static void test_project(void)
{
    struct glug_vec3 v = { 3.f, 6.f, -4.f };
    struct glug_vec3 onto = { 2.f, -3.f, 5.f };
    struct glug_vec3 exp = { -1.6842f, 2.5263f, -4.2105f };

    glug_vec3_project(&v, &v, &onto);
    ASSERT_VEC3_EQUAL(&v, &exp, 0.0001f);
}

static void test_reject(void)
{
    struct glug_vec3 v = { 3.f, 6.f, -4.f };
    struct glug_vec3 from = { 2.f, -3.f, 5.f };
    struct glug_vec3 exp = { 4.6842f, 3.4737f, 0.2105f };

    glug_vec3_reject(&v, &v, &from);
    ASSERT_VEC3_EQUAL(&v, &exp, 0.0001f);
}

static void test_reflect(void)
{
    struct glug_vec3 dst = { 3.f, 3.f, 3.f };
    struct glug_vec3 b = { 1.f, -2.f, 0.f };
    struct glug_vec3 exp = { -4.2f, -0.6f, -3.f };

    glug_vec3_reflect(&dst, &b);
    ASSERT_VEC3_EQUAL(&dst, &exp, 0.00001f);
}

static void test_refract(void)
{
    struct glug_vec3 dst = { 3.f, 3.f, 3.f };
    struct glug_vec3 n = { 1.f, -2.f, 0.f };
    struct glug_vec3 exp = { -0.23469f, 4.96939f, 1.49999f };

    glug_vec3_refract(&dst, &n, 1.f, 2.f);
    ASSERT_VEC3_EQUAL(&dst, &exp, 0.00001f);
}

int main(void)
{
    CU_pSuite vec3_suite = create_suite("vec3", NULL, NULL);
    if (!vec3_suite) return CU_get_error();

    ADD_TEST(vec3_suite, equal);
    ADD_TEST(vec3_suite, add);
    ADD_TEST(vec3_suite, sub);
    ADD_TEST(vec3_suite, mul);
    ADD_TEST(vec3_suite, div);
    ADD_TEST(vec3_suite, mul_cw);
    ADD_TEST(vec3_suite, div_cw);
    ADD_TEST(vec3_suite, sign);
    ADD_TEST(vec3_suite, integral);
    ADD_TEST(vec3_suite, frac);
    ADD_TEST(vec3_suite, max);
    ADD_TEST(vec3_suite, min);
    ADD_TEST(vec3_suite, clamp);
    ADD_TEST(vec3_suite, floor);
    ADD_TEST(vec3_suite, ceil);
    ADD_TEST(vec3_suite, round);
    ADD_TEST(vec3_suite, round_zero);
    ADD_TEST(vec3_suite, dot);
    ADD_TEST(vec3_suite, cross);
    ADD_TEST(vec3_suite, triple_product);
    ADD_TEST(vec3_suite, len_sq);
    ADD_TEST(vec3_suite, len_taxi);
    ADD_TEST(vec3_suite, set_len);
    ADD_TEST(vec3_suite, clamp_len);
    ADD_TEST(vec3_suite, is_norm);
    ADD_TEST(vec3_suite, normalize);
    ADD_TEST(vec3_suite, dist);
    ADD_TEST(vec3_suite, dist_sq);
    ADD_TEST(vec3_suite, dist_taxi);
    ADD_TEST(vec3_suite, angle_to);
    ADD_TEST(vec3_suite, project);
    ADD_TEST(vec3_suite, reject);
    ADD_TEST(vec3_suite, reflect);
    ADD_TEST(vec3_suite, refract);

    return run_tests(CU_BRM_VERBOSE);
}
