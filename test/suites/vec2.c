#include <CUnit/Assert.h>
#include <CUnit/Basic.h>
#include <glug/math/vec2.h>
#include "add_test.h"

static void test_set(void)
{
    struct glug_vec2 v2;
    float x = 5.f, y = 6.f;
    glug_vec2_set(&v2, x, y);

    CU_ASSERT_DOUBLE_EQUAL(v2.x, x, 0.f);
    CU_ASSERT_DOUBLE_EQUAL(v2.y, y, 0.f);
}

static void test_copy(void)
{
    struct glug_vec2 v1;
    struct glug_vec2 v2 = { 4.f, 5.f };
    glug_vec2_copy(&v1, &v2);

    CU_ASSERT_DOUBLE_EQUAL(v1.x, v2.x, 0.f);
    CU_ASSERT_DOUBLE_EQUAL(v1.y, v2.y, 0.f);
}

static void test_equal(void)
{

}

static void test_sum(void)
{
    struct glug_vec2 v1 = { 1.f, 8.9f };
    struct glug_vec2 v2 = { -1.01f, -5.5f };
    struct glug_vec2 exp = { -0.01f, 3.4f };
    struct glug_vec2 sum = glug_vec2_sum(&v1, &v2);

    CU_ASSERT_DOUBLE_EQUAL(sum.x, exp.x, 0.001f);
    CU_ASSERT_DOUBLE_EQUAL(sum.y, exp.y, 0.001f);
}

static void test_diff(void)
{
    struct glug_vec2 v1 = { 17.17f, 19.8f };
    struct glug_vec2 v2 = { 8.f, 9.f };
    struct glug_vec2 exp = { 9.17f, 10.8f };
    struct glug_vec2 diff = glug_vec2_diff(&v1, &v2);

    CU_ASSERT_DOUBLE_EQUAL(diff.x, exp.x, .001f);
    CU_ASSERT_DOUBLE_EQUAL(diff.y, exp.y, .001f);
}

static void test_prod(void)
{
    struct glug_vec2 v = { 4.f, 5.f };
    float scalar = 4.1f;
    struct glug_vec2 exp = { 16.4f, 20.5f };
    struct glug_vec2 prod = glug_vec2_prod(&v, scalar);

    CU_ASSERT_DOUBLE_EQUAL(prod.x, exp.x, 0.01f);
    CU_ASSERT_DOUBLE_EQUAL(prod.y, exp.y, 0.01f);
}

static void test_quot(void)
{
    struct glug_vec2 v = { 3.142f, 2.718f };
    float scalar = 1.414f;
    struct glug_vec2 exp = { 2.222065f, 1.922206f };
    struct glug_vec2 quot = glug_vec2_quot(&v, scalar);

    CU_ASSERT_DOUBLE_EQUAL(quot.x, exp.x, 0.000001f);
    CU_ASSERT_DOUBLE_EQUAL(quot.y, exp.y, 0.000001f);
}

static void test_add(void)
{
    struct glug_vec2 dst = { 1.f, 8.9f };
    struct glug_vec2 v2 = { -1.01f, -5.5f };
    struct glug_vec2 exp = { -0.01f, 3.4f };
    glug_vec2_add(&dst, &v2);

    CU_ASSERT_DOUBLE_EQUAL(dst.x, exp.x, 0.001f);
    CU_ASSERT_DOUBLE_EQUAL(dst.y, exp.y, 0.001f);
}

static void test_sub(void)
{
    struct glug_vec2 dst = { 17.17f, 19.8f };
    struct glug_vec2 v2 = { 8.f, 9.f };
    struct glug_vec2 exp = { 9.17f, 10.8f };
    glug_vec2_sub(&dst, &v2);

    CU_ASSERT_DOUBLE_EQUAL(dst.x, exp.x, 0.001f);
    CU_ASSERT_DOUBLE_EQUAL(dst.y, exp.y, 0.001f);
}

static void test_mul(void)
{
    struct glug_vec2 dst = { 4.f, 5.f };
    float scalar = 4.1f;
    struct glug_vec2 exp = { 16.4f, 20.5f };
    glug_vec2_mul(&dst, scalar);

    CU_ASSERT_DOUBLE_EQUAL(dst.x, exp.x, 0.01f);
    CU_ASSERT_DOUBLE_EQUAL(dst.y, exp.y, 0.01f);
}

static void test_div(void)
{
    struct glug_vec2 dst = { 3.142f, 2.718f };
    float scalar = 1.414f;
    struct glug_vec2 exp = { 2.222065f, 1.922206f };
    glug_vec2_div(&dst, scalar);

    CU_ASSERT_DOUBLE_EQUAL(dst.x, exp.x, 0.000001f);
    CU_ASSERT_DOUBLE_EQUAL(dst.y, exp.y, 0.000001f);
}

static void test_max(void)
{
    struct glug_vec2 v1 = { -2.f, 2.f };
    struct glug_vec2 v2 = { 1.f, -1.f };
    struct glug_vec2 exp = { 1.f, 2.f };

    struct glug_vec2 dst = glug_vec2_max(&v1, &v2);

    CU_ASSERT_DOUBLE_EQUAL(dst.x, exp.x, 0.f);
    CU_ASSERT_DOUBLE_EQUAL(dst.y, exp.y, 0.f);

    dst = glug_vec2_max(&v2, &v1);
    CU_ASSERT_DOUBLE_EQUAL(dst.x, exp.x, 0.f);
    CU_ASSERT_DOUBLE_EQUAL(dst.y, exp.y, 0.f);
}

static void test_min(void)
{
    struct glug_vec2 v1 = { -2.f, 2.f };
    struct glug_vec2 v2 = { 1.f, -1.f };
    struct glug_vec2 exp = { -2.f, -1.f };

    struct glug_vec2 dst = glug_vec2_min(&v1, &v2);
    CU_ASSERT_DOUBLE_EQUAL(dst.x, exp.x, 0.f);
    CU_ASSERT_DOUBLE_EQUAL(dst.y, exp.y, 0.f);

    dst = glug_vec2_min(&v2, &v1);
    CU_ASSERT_DOUBLE_EQUAL(dst.x, exp.x, 0.f);
    CU_ASSERT_DOUBLE_EQUAL(dst.y, exp.y, 0.f);
}

static void test_clamped(void)
{
    struct glug_vec2 v1 = { -2.f, 2.f };
    struct glug_vec2 min = { -1.f, -1.f };
    struct glug_vec2 max = { 1.f, 1.f };
    struct glug_vec2 exp = { -1.f, 1.f };

    struct glug_vec2 dst = glug_vec2_clamped(&v1, &min, &max);
    CU_ASSERT_DOUBLE_EQUAL(dst.x, exp.x, 0.f);
    CU_ASSERT_DOUBLE_EQUAL(dst.y, exp.y, 0.f);
}

static void test_maximize(void)
{
    struct glug_vec2 v1 = { -2.f, 2.f };
    struct glug_vec2 v2 = { 1.f, -1.f };
    struct glug_vec2 dst = v1;
    struct glug_vec2 exp = { 1.f, 2.f };

    glug_vec2_maximize(&dst, &v2);
    CU_ASSERT_DOUBLE_EQUAL(dst.x, exp.x, 0.f);
    CU_ASSERT_DOUBLE_EQUAL(dst.y, exp.y, 0.f);

    dst = v2;
    glug_vec2_maximize(&dst, &v1);
    CU_ASSERT_DOUBLE_EQUAL(dst.x, exp.x, 0.f);
    CU_ASSERT_DOUBLE_EQUAL(dst.y, exp.y, 0.f);
}

static void test_minimize(void)
{
    struct glug_vec2 v1 = { -2.f, 2.f };
    struct glug_vec2 v2 = { 1.f, -1.f };
    struct glug_vec2 dst = v1;
    struct glug_vec2 exp = { -2.f, -1.f };

    glug_vec2_minimize(&dst, &v2);
    CU_ASSERT_DOUBLE_EQUAL(dst.x, exp.x, 0.f);
    CU_ASSERT_DOUBLE_EQUAL(dst.y, exp.y, 0.f);

    dst = v2;
    glug_vec2_minimize(&dst, &v1);
    CU_ASSERT_DOUBLE_EQUAL(dst.x, exp.x, 0.f);
    CU_ASSERT_DOUBLE_EQUAL(dst.y, exp.y, 0.f);
}

static void test_clamp(void)
{
    struct glug_vec2 dst = { -2.f, 2.f };
    struct glug_vec2 min = { -1.f, -1.f };
    struct glug_vec2 max = { 1.f, 1.f };
    struct glug_vec2 exp = { -1.f, 1.f };

    glug_vec2_clamp(&dst, &min, &max);
    CU_ASSERT_DOUBLE_EQUAL(dst.x, exp.x, 0.f);
    CU_ASSERT_DOUBLE_EQUAL(dst.y, exp.y, 0.f);
}

static void test_dot(void)
{
    struct glug_vec2 v1 = { -5.6f, -7.5f };
    struct glug_vec2 v2 = { -0.3f, 5.8f };
    float exp = -41.82f;
    float dot = glug_vec2_dot(&v1, &v2);

    CU_ASSERT_DOUBLE_EQUAL(dot, exp, 0.01f);
}

static void test_len(void)
{
    struct glug_vec2 v = { -5.f, 3.f };
    struct glug_vec2 v2 = { 6.f, -10.f };
    float len = glug_vec2_len(&v);
    float len2 = glug_vec2_len(&v2);
    float exp = 5.830f;
    float exp2 = 11.661f;

    CU_ASSERT_DOUBLE_EQUAL(len, exp, 0.001f);
    CU_ASSERT_DOUBLE_EQUAL(len2, exp2, 0.001f);
}

static void test_len_sq(void)
{
    struct glug_vec2 v = { -5.f, 3.f };
    struct glug_vec2 v2 = { 6.f, -10.f };
    float len = glug_vec2_len_squared(&v);
    float len2 = glug_vec2_len_squared(&v2);
    float exp = 34.f;
    float exp2 = 136.f;

    CU_ASSERT_DOUBLE_EQUAL(len, exp, 0.1f);
    CU_ASSERT_DOUBLE_EQUAL(len2, exp2, 0.1f);
}

static void test_len_mh(void)
{
    struct glug_vec2 v = { -5.f, 3.f };
    struct glug_vec2 v2 = { 6.f, -10.f };
    float len = glug_vec2_len_manhattan(&v);
    float len2 = glug_vec2_len_manhattan(&v2);
    float exp = 8.f;
    float exp2 = 16.f;

    CU_ASSERT_DOUBLE_EQUAL(len, exp, 0.1f);
    CU_ASSERT_DOUBLE_EQUAL(len2, exp2, 0.1f);
}

static void test_set_len(void)
{
    struct glug_vec2 v = { 0.8f, -1.f };
    float newlen = 2.3f;
    struct glug_vec2 exp = { 1.436f, -1.795f };
    glug_vec2_set_len(&v, newlen);

    CU_ASSERT_DOUBLE_EQUAL(v.x, exp.x, 0.001f);
    CU_ASSERT_DOUBLE_EQUAL(v.y, exp.y, 0.001f);
}

static void test_is_norm(void)
{

}

static void test_normal(void)
{
    struct glug_vec2 v = { 3.f, 3.f };
    struct glug_vec2 n = glug_vec2_normal(&v);
    struct glug_vec2 exp = { 0.7071f, 0.7071f };

    CU_ASSERT_DOUBLE_EQUAL(glug_vec2_len(&n), 1.f, 0.0001f);
    CU_ASSERT_DOUBLE_EQUAL(n.x, exp.x, 0.00001f);
    CU_ASSERT_DOUBLE_EQUAL(n.y, exp.y, 0.00001f);
}

static void test_normalize(void)
{
    struct glug_vec2 dst = { 3.f, 3.f };
    struct glug_vec2 exp = { 0.7071f, 0.7071f };
    glug_vec2_normalize(&dst);

    CU_ASSERT_DOUBLE_EQUAL(glug_vec2_len(&dst), 1.f, 0.0001f);
    CU_ASSERT_DOUBLE_EQUAL(dst.x, exp.x, 0.00001f);
    CU_ASSERT_DOUBLE_EQUAL(dst.y, exp.y, 0.00001f);
}

static void test_dist(void)
{
    struct glug_vec2 a = { -1.2f, 1.9f };
    struct glug_vec2 b = { -0.8f, 1.f };
    float dist = glug_vec2_dist(&a, &b);
    float exp = 0.9848f;

    CU_ASSERT_DOUBLE_EQUAL(dist, exp, 0.0001f);
}

static void test_dist_sq(void)
{
    struct glug_vec2 a = { -1.2f, 1.9f };
    struct glug_vec2 b = { -0.8f, 1.f };
    float dist = glug_vec2_dist_squared(&a, &b);
    float exp = 0.97f;

    CU_ASSERT_DOUBLE_EQUAL(dist, exp, 0.0001f);
}

static void test_dist_mh(void)
{
    struct glug_vec2 a = { -1.2f, 1.9f };
    struct glug_vec2 b = { -0.8f, 1.f };
    float dist = glug_vec2_dist_manhattan(&a, &b);
    float exp = 1.3f;

    CU_ASSERT_DOUBLE_EQUAL(dist, exp, 0.0001f);
}

static void test_angle_to(void)
{
    struct glug_vec2 a = { -1.0f, 0.f };
    struct glug_vec2 b = { 0.f, 1.f };
    float dist = glug_vec2_angle_btw(&a, &b);
    float exp = 1.5707f;

    CU_ASSERT_DOUBLE_EQUAL(dist, exp, 0.0001f);
}

static void test_projection(void)
{
    struct glug_vec2 a = { 3.f, 3.f };
    struct glug_vec2 b = { 1.f, -2.f };
    struct glug_vec2 proj = glug_vec2_projection(&a, &b);
    struct glug_vec2 exp = { -0.6f, 1.2f };

    CU_ASSERT_DOUBLE_EQUAL(proj.x, exp.x, 0.001f);
    CU_ASSERT_DOUBLE_EQUAL(proj.y, exp.y, 0.001f);
}

static void test_rejection(void)
{
    struct glug_vec2 a = { 3.f, 3.f };
    struct glug_vec2 b = { 1.f, -2.f };
    struct glug_vec2 rej = glug_vec2_rejection(&a, &b);
    struct glug_vec2 exp = { 3.6f, 1.8f };

    CU_ASSERT_DOUBLE_EQUAL(rej.x, exp.x, 0.00001f);
    CU_ASSERT_DOUBLE_EQUAL(rej.y, exp.y, 0.00001f);
}

static void test_reflection(void)
{
    struct glug_vec2 a = { 3.f, 3.f };
    struct glug_vec2 b = { 1.f, -2.f };
    struct glug_vec2 ref = glug_vec2_reflection(&a, &b);
    struct glug_vec2 exp = { -4.2f, -0.6f };

    CU_ASSERT_DOUBLE_EQUAL(ref.x, exp.x, 0.00001f);
    CU_ASSERT_DOUBLE_EQUAL(ref.y, exp.y, 0.00001f);
}

static void test_refraction(void)
{
    struct glug_vec2 inc = { 3.f, 3.f };
    struct glug_vec2 n = { 1.f, -2.f };
    struct glug_vec2 ref = glug_vec2_refraction(&inc, &n, 1.f, 2.f);
    struct glug_vec2 exp = { 0.12967f, 4.24065f };

    CU_ASSERT_DOUBLE_EQUAL(ref.x, exp.x, 0.00001f);
    CU_ASSERT_DOUBLE_EQUAL(ref.y, exp.y, 0.00001f);
}

static void test_project(void)
{
    struct glug_vec2 dst = { 3.f, 3.f };
    struct glug_vec2 b = { 1.f, -2.f };
    glug_vec2_project(&dst, &b);
    struct glug_vec2 exp = { -0.6f, 1.2f };

    CU_ASSERT_DOUBLE_EQUAL(dst.x, exp.x, 0.00001f);
    CU_ASSERT_DOUBLE_EQUAL(dst.y, exp.y, 0.00001f);
}

static void test_reject(void)
{
    struct glug_vec2 dst = { 3.f, 3.f };
    struct glug_vec2 b = { 1.f, -2.f };
    glug_vec2_reject(&dst, &b);
    struct glug_vec2 exp = { 3.6f, 1.8f };

    CU_ASSERT_DOUBLE_EQUAL(dst.x, exp.x, 0.00001f);
    CU_ASSERT_DOUBLE_EQUAL(dst.y, exp.y, 0.00001f);
}

static void test_reflect(void)
{
    struct glug_vec2 dst = { 3.f, 3.f };
    struct glug_vec2 b = { 1.f, -2.f };
    glug_vec2_reflect(&dst, &b);
    struct glug_vec2 exp = { -4.2f, -0.6f };

    CU_ASSERT_DOUBLE_EQUAL(dst.x, exp.x, 0.00001f);
    CU_ASSERT_DOUBLE_EQUAL(dst.y, exp.y, 0.00001f);
}

static void test_refract(void)
{
    struct glug_vec2 dst = { 3.f, 3.f };
    struct glug_vec2 n = { 1.f, -2.f };
    glug_vec2_refract(&dst, &n, 1.f, 2.f);
    struct glug_vec2 exp = { 0.12967f, 4.24065f };

    CU_ASSERT_DOUBLE_EQUAL(dst.x, exp.x, 0.00001f);
    CU_ASSERT_DOUBLE_EQUAL(dst.y, exp.y, 0.00001f);
}

CU_pSuite create_vec2_suite()
{
    CU_pSuite vec2_suite = CU_add_suite("vec2f", NULL, NULL);
    if (!vec2_suite) return NULL;

    ADD_TEST(vec2_suite, set);
    ADD_TEST(vec2_suite, copy);
    ADD_TEST(vec2_suite, equal);
    ADD_TEST(vec2_suite, sum);
    ADD_TEST(vec2_suite, diff);
    ADD_TEST(vec2_suite, prod);
    ADD_TEST(vec2_suite, quot);
    ADD_TEST(vec2_suite, add);
    ADD_TEST(vec2_suite, sub);
    ADD_TEST(vec2_suite, mul);
    ADD_TEST(vec2_suite, div);
    ADD_TEST(vec2_suite, dot);
    ADD_TEST(vec2_suite, max);
    ADD_TEST(vec2_suite, min);
    ADD_TEST(vec2_suite, clamped);
    ADD_TEST(vec2_suite, maximize);
    ADD_TEST(vec2_suite, minimize);
    ADD_TEST(vec2_suite, clamp);
    ADD_TEST(vec2_suite, len);
    ADD_TEST(vec2_suite, len_sq);
    ADD_TEST(vec2_suite, len_mh);
    ADD_TEST(vec2_suite, set_len);
    ADD_TEST(vec2_suite, is_norm);
    ADD_TEST(vec2_suite, normal);
    ADD_TEST(vec2_suite, normalize);
    ADD_TEST(vec2_suite, dist);
    ADD_TEST(vec2_suite, dist_sq);
    ADD_TEST(vec2_suite, dist_mh);
    ADD_TEST(vec2_suite, angle_to);
    ADD_TEST(vec2_suite, projection);
    ADD_TEST(vec2_suite, rejection);
    ADD_TEST(vec2_suite, reflection);
    ADD_TEST(vec2_suite, refraction);
    ADD_TEST(vec2_suite, project);
    ADD_TEST(vec2_suite, reject);
    ADD_TEST(vec2_suite, reflect);
    ADD_TEST(vec2_suite, refract);

    return vec2_suite;
}
