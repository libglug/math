#include <CUnit/Assert.h>
#include <CUnit/Basic.h>
#include <glug/math/vec3.h>
#include "add_test.h"

static void test_set(void)
{
    struct glug_vec3 v3;
    float x = 5.f, y = 6.f, z = 7.f;
    glug_vec3_set(&v3, x, y, z);

    CU_ASSERT_DOUBLE_EQUAL(v3.x, x, 0.f);
    CU_ASSERT_DOUBLE_EQUAL(v3.y, y, 0.f);
    CU_ASSERT_DOUBLE_EQUAL(v3.z, z, 0.f);
}

static void test_copy(void)
{
    struct glug_vec3 v1;
    struct glug_vec3 v2 = { 4.f, 5.f, 10.f };
    glug_vec3_copy(&v1, &v2);

    CU_ASSERT_DOUBLE_EQUAL(v1.x, v2.x, 0.f);
    CU_ASSERT_DOUBLE_EQUAL(v1.y, v2.y, 0.f);
    CU_ASSERT_DOUBLE_EQUAL(v1.z, v2.z, 0.f);
}

static void test_equal(void)
{

}

static void test_sum(void)
{
    struct glug_vec3 v1 = { 1.f, 8.9f, 10.f };
    struct glug_vec3 v2 = { -1.01f, -5.5f, 19.1f };
    struct glug_vec3 exp = { -0.01f, 3.4f, 29.1f };
    struct glug_vec3 sum = glug_vec3_sum(&v1, &v2);

    CU_ASSERT_DOUBLE_EQUAL(sum.x, exp.x, 0.001f);
    CU_ASSERT_DOUBLE_EQUAL(sum.y, exp.y, 0.001f);
    CU_ASSERT_DOUBLE_EQUAL(sum.z, exp.z, 0.001f);
}

static void test_diff(void)
{
    struct glug_vec3 v1 = { 17.17f, 19.8f, 79.f };
    struct glug_vec3 v2 = { 8.f, 9.f, 18.697f };
    struct glug_vec3 exp = { 9.17f, 10.8f, 60.303f };
    struct glug_vec3 diff = glug_vec3_diff(&v1, &v2);

    CU_ASSERT_DOUBLE_EQUAL(diff.x, exp.x, .001f);
    CU_ASSERT_DOUBLE_EQUAL(diff.y, exp.y, .001f);
    CU_ASSERT_DOUBLE_EQUAL(diff.z, exp.z, .0001f);
}

static void test_prod(void)
{
    struct glug_vec3 v = { 4.f, 5.f, 10.f };
    float scalar = 4.1f;
    struct glug_vec3 exp = { 16.4f, 20.5f, 41.f };
    struct glug_vec3 prod = glug_vec3_prod(&v, scalar);

    CU_ASSERT_DOUBLE_EQUAL(prod.x, exp.x, 0.01f);
    CU_ASSERT_DOUBLE_EQUAL(prod.y, exp.y, 0.01f);
    CU_ASSERT_DOUBLE_EQUAL(prod.z, exp.z, 0.01f);
}

static void test_quot(void)
{
    struct glug_vec3 v = { 3.142f, 2.718f, 1.618f };
    float scalar = 1.414f;
    struct glug_vec3 exp = { 2.222065f, 1.922206f, 1.144271f };
    struct glug_vec3 quot = glug_vec3_quot(&v, scalar);

    CU_ASSERT_DOUBLE_EQUAL(quot.x, exp.x, 0.000001f);
    CU_ASSERT_DOUBLE_EQUAL(quot.y, exp.y, 0.000001f);
    CU_ASSERT_DOUBLE_EQUAL(quot.z, exp.z, 0.000001f);
}

static void test_add(void)
{
    struct glug_vec3 dst = { 1.f, 8.9f, 10.f };
    struct glug_vec3 v2 = { -1.01f, -5.5f, 19.1f };
    struct glug_vec3 exp = { -0.01f, 3.4f, 29.1f };
    glug_vec3_add(&dst, &v2);

    CU_ASSERT_DOUBLE_EQUAL(dst.x, exp.x, 0.001f);
    CU_ASSERT_DOUBLE_EQUAL(dst.y, exp.y, 0.001f);
    CU_ASSERT_DOUBLE_EQUAL(dst.z, exp.z, 0.001f);
}

static void test_sub(void)
{
    struct glug_vec3 dst = { 17.17f, 19.8f, 79.f };
    struct glug_vec3 v2 = { 8.f, 9.f, 18.697f };
    struct glug_vec3 exp = { 9.17f, 10.8f, 60.303f };
    glug_vec3_sub(&dst, &v2);

    CU_ASSERT_DOUBLE_EQUAL(dst.x, exp.x, 0.001f);
    CU_ASSERT_DOUBLE_EQUAL(dst.y, exp.y, 0.001f);
    CU_ASSERT_DOUBLE_EQUAL(dst.z, exp.z, 0.001f);
}

static void test_mul(void)
{
    struct glug_vec3 dst = { 4.f, 5.f, 10.f };
    float scalar = 4.1f;
    struct glug_vec3 exp = { 16.4f, 20.5f, 41.f };
    glug_vec3_mul(&dst, scalar);

    CU_ASSERT_DOUBLE_EQUAL(dst.x, exp.x, 0.01f);
    CU_ASSERT_DOUBLE_EQUAL(dst.y, exp.y, 0.01f);
    CU_ASSERT_DOUBLE_EQUAL(dst.z, exp.z, 0.01f);
}

static void test_div(void)
{
    struct glug_vec3 dst = { 3.142f, 2.718f, 1.618f };
    float scalar = 1.414f;
    struct glug_vec3 exp = { 2.222065f, 1.922206f, 1.144271f };
    glug_vec3_div(&dst, scalar);

    CU_ASSERT_DOUBLE_EQUAL(dst.x, exp.x, 0.000001f);
    CU_ASSERT_DOUBLE_EQUAL(dst.y, exp.y, 0.000001f);
    CU_ASSERT_DOUBLE_EQUAL(dst.z, exp.z, 0.000001f);
}

static void test_max(void)
{
    struct glug_vec3 v1 = { -2.f, 2.f, -2.f };
    struct glug_vec3 v2 = { 1.f, -1.f, 1.f };
    struct glug_vec3 exp = { 1.f, 2.f, 1.f };

    struct glug_vec3 dst = glug_vec3_max(&v1, &v2);

    CU_ASSERT_DOUBLE_EQUAL(dst.x, exp.x, 0.f);
    CU_ASSERT_DOUBLE_EQUAL(dst.y, exp.y, 0.f);
    CU_ASSERT_DOUBLE_EQUAL(dst.z, exp.z, 0.f);

    dst = glug_vec3_max(&v2, &v1);
    CU_ASSERT_DOUBLE_EQUAL(dst.x, exp.x, 0.f);
    CU_ASSERT_DOUBLE_EQUAL(dst.y, exp.y, 0.f);
    CU_ASSERT_DOUBLE_EQUAL(dst.z, exp.z, 0.f);
}

static void test_min(void)
{
    struct glug_vec3 v1 = { -2.f, 2.f, -2.f };
    struct glug_vec3 v2 = { 1.f, -1.f, 1.f };
    struct glug_vec3 exp = { -2.f, -1.f, -2.f };

    struct glug_vec3 dst = glug_vec3_min(&v1, &v2);
    CU_ASSERT_DOUBLE_EQUAL(dst.x, exp.x, 0.f);
    CU_ASSERT_DOUBLE_EQUAL(dst.y, exp.y, 0.f);
    CU_ASSERT_DOUBLE_EQUAL(dst.z, exp.z, 0.f);

    dst = glug_vec3_min(&v2, &v1);
    CU_ASSERT_DOUBLE_EQUAL(dst.x, exp.x, 0.f);
    CU_ASSERT_DOUBLE_EQUAL(dst.y, exp.y, 0.f);
    CU_ASSERT_DOUBLE_EQUAL(dst.z, exp.z, 0.f);
}

static void test_clamped(void)
{
    struct glug_vec3 v1 = { -2.f, 2.f, -2.f };
    struct glug_vec3 min = { -1.f, -1.f, -1.f };
    struct glug_vec3 max = { 1.f, 1.f, 1.f };
    struct glug_vec3 exp = { -1.f, 1.f, -1.f };

    struct glug_vec3 dst = glug_vec3_clamped(&v1, &min, &max);
    CU_ASSERT_DOUBLE_EQUAL(dst.x, exp.x, 0.f);
    CU_ASSERT_DOUBLE_EQUAL(dst.y, exp.y, 0.f);
    CU_ASSERT_DOUBLE_EQUAL(dst.z, exp.z, 0.f);
}

static void test_maximize(void)
{
    struct glug_vec3 v1 = { -2.f, 2.f, -2.f };
    struct glug_vec3 v2 = { 1.f, -1.f, 1.f };
    struct glug_vec3 dst = v1;
    struct glug_vec3 exp = { 1.f, 2.f, 1.f };

    glug_vec3_maximize(&dst, &v2);
    CU_ASSERT_DOUBLE_EQUAL(dst.x, exp.x, 0.f);
    CU_ASSERT_DOUBLE_EQUAL(dst.y, exp.y, 0.f);
    CU_ASSERT_DOUBLE_EQUAL(dst.z, exp.z, 0.f);

    dst = v2;
    glug_vec3_maximize(&dst, &v1);
    CU_ASSERT_DOUBLE_EQUAL(dst.x, exp.x, 0.f);
    CU_ASSERT_DOUBLE_EQUAL(dst.y, exp.y, 0.f);
    CU_ASSERT_DOUBLE_EQUAL(dst.z, exp.z, 0.f);
}

static void test_minimize(void)
{
    struct glug_vec3 v1 = { -2.f, 2.f, -2.f };
    struct glug_vec3 v2 = { 1.f, -1.f, 1.f };
    struct glug_vec3 dst = v1;
    struct glug_vec3 exp = { -2.f, -1.f, -2.f };

    glug_vec3_minimize(&dst, &v2);
    CU_ASSERT_DOUBLE_EQUAL(dst.x, exp.x, 0.f);
    CU_ASSERT_DOUBLE_EQUAL(dst.y, exp.y, 0.f);
    CU_ASSERT_DOUBLE_EQUAL(dst.z, exp.z, 0.f);

    dst = v2;
    glug_vec3_minimize(&dst, &v1);
    CU_ASSERT_DOUBLE_EQUAL(dst.x, exp.x, 0.f);
    CU_ASSERT_DOUBLE_EQUAL(dst.y, exp.y, 0.f);
    CU_ASSERT_DOUBLE_EQUAL(dst.z, exp.z, 0.f);
}

static void test_clamp(void)
{
    struct glug_vec3 dst = { -2.f, 2.f, -2.f };
    struct glug_vec3 min = { -1.f, -1.f, -1.f };
    struct glug_vec3 max = { 1.f, 1.f, 1.f };
    struct glug_vec3 exp = { -1.f, 1.f, -1.f };

    glug_vec3_clamp(&dst, &min, &max);
    CU_ASSERT_DOUBLE_EQUAL(dst.x, exp.x, 0.f);
    CU_ASSERT_DOUBLE_EQUAL(dst.y, exp.y, 0.f);
    CU_ASSERT_DOUBLE_EQUAL(dst.z, exp.z, 0.f);
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
    struct glug_vec3 c = glug_vec3_cross(&a, &b);

    CU_ASSERT_DOUBLE_EQUAL(c.x, 0.f, 0.f);
    CU_ASSERT_DOUBLE_EQUAL(c.y, 0.f, 0.f);
    CU_ASSERT_DOUBLE_EQUAL(c.z, -1.f, 0.f);

    a = glug_vec3_cross(&c, &b);

    CU_ASSERT_DOUBLE_EQUAL(a.x, 1.f, 0.f);
    CU_ASSERT_DOUBLE_EQUAL(a.y, 0.f, 0.f);
    CU_ASSERT_DOUBLE_EQUAL(a.z, 0.f, 0.f);
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

static void test_len_mh(void)
{
    struct glug_vec3 v = { -5.f, 3.f, -4.f };
    struct glug_vec3 v2 = { 6.f, -10.f, 2.f };
    float len = glug_vec3_len_manhattan(&v);
    float len2 = glug_vec3_len_manhattan(&v2);
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

    CU_ASSERT_DOUBLE_EQUAL(v.x, exp.x, 0.001f);
    CU_ASSERT_DOUBLE_EQUAL(v.y, exp.y, 0.001f);
    CU_ASSERT_DOUBLE_EQUAL(v.z, exp.z, 0.001f);
    CU_ASSERT_DOUBLE_EQUAL(glug_vec3_len(&v), newlen, 0.001f);
}

static void test_is_norm(void)
{

}

static void test_normal(void)
{
    struct glug_vec3 v = { 3.f, 3.f, -3.f };
    struct glug_vec3 n = glug_vec3_normal(&v);
    struct glug_vec3 exp = { 0.57735f, 0.57735f, -0.57735f };

    CU_ASSERT_DOUBLE_EQUAL(glug_vec3_len(&n), 1.f, 0.0001f);
    CU_ASSERT_DOUBLE_EQUAL(n.x, exp.x, 0.00001f);
    CU_ASSERT_DOUBLE_EQUAL(n.y, exp.y, 0.00001f);
    CU_ASSERT_DOUBLE_EQUAL(n.z, exp.z, 0.00001f);
}

static void test_normalize(void)
{
    struct glug_vec3 dst = { 3.f, 3.f, -3.f };
    struct glug_vec3 exp = { 0.57735f, 0.57735f, -0.57735f };
    glug_vec3_normalize(&dst);

    CU_ASSERT_DOUBLE_EQUAL(glug_vec3_len(&dst), 1.f, 0.0001f);
    CU_ASSERT_DOUBLE_EQUAL(dst.x, exp.x, 0.00001f);
    CU_ASSERT_DOUBLE_EQUAL(dst.y, exp.y, 0.00001f);
    CU_ASSERT_DOUBLE_EQUAL(dst.z, exp.z, 0.00001f);
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

static void test_dist_mh(void)
{
    struct glug_vec3 a = { -1.2f, 1.9f, -0.5f };
    struct glug_vec3 b = { -0.8f, 1.f, -0.3f };
    float dist = glug_vec3_dist_manhattan(&a, &b);
    float exp = 1.5f;

    CU_ASSERT_DOUBLE_EQUAL(dist, exp, 0.0001f);
}

static void test_angle_to(void)
{
    struct glug_vec3 a = { -1.0f, 0.f, 0.f };
    struct glug_vec3 b = { 0.f, 1.f, 0.f };
    float dist = glug_vec3_angle_btw(&a, &b);
    float exp = 1.5707f;

    CU_ASSERT_DOUBLE_EQUAL(dist, exp, 0.0001f);
}

static void test_projection(void)
{
    struct glug_vec3 a = { 3.f, 3.f, 3.f };
    struct glug_vec3 b = { 1.f, -2.f, 0.f };
    struct glug_vec3 proj = glug_vec3_projection(&a, &b);
    struct glug_vec3 exp = { -0.6f, 1.2f, 0.f };

    CU_ASSERT_DOUBLE_EQUAL(proj.x, exp.x, 0.00001f);
    CU_ASSERT_DOUBLE_EQUAL(proj.y, exp.y, 0.00001f);
    CU_ASSERT_DOUBLE_EQUAL(proj.z, exp.z, 0.00001f);
}

static void test_rejection(void)
{
    struct glug_vec3 a = { 3.f, 3.f, 3.f };
    struct glug_vec3 b = { 1.f, -2.f, 0.f };
    struct glug_vec3 rej = glug_vec3_rejection(&a, &b);
    struct glug_vec3 exp = { 3.6f, 1.8f, 3.f };

    CU_ASSERT_DOUBLE_EQUAL(rej.x, exp.x, 0.00001f);
    CU_ASSERT_DOUBLE_EQUAL(rej.y, exp.y, 0.00001f);
    CU_ASSERT_DOUBLE_EQUAL(rej.z, exp.z, 0.00001f);
}

static void test_reflection(void)
{
    struct glug_vec3 a = { 3.f, 3.f, 3.f };
    struct glug_vec3 b = { 1.f, -2.f, 0.f };
    struct glug_vec3 ref = glug_vec3_reflection(&a, &b);
    struct glug_vec3 exp = { -4.2f, -0.6f, -3.f };

    CU_ASSERT_DOUBLE_EQUAL(ref.x, exp.x, 0.00001f);
    CU_ASSERT_DOUBLE_EQUAL(ref.y, exp.y, 0.00001f);
    CU_ASSERT_DOUBLE_EQUAL(ref.z, exp.z, 0.00001f);
}

static void test_refraction(void)
{
    struct glug_vec3 a = { 3.f, 3.f, 3.f };
    struct glug_vec3 b = { 1.f, -2.f, 0.f };
    struct glug_vec3 ref = glug_vec3_refraction(&a, &b, 1.f, 2.f);
    struct glug_vec3 exp = { -0.23469f, 4.96939f, 1.49999f };

    CU_ASSERT_DOUBLE_EQUAL(ref.x, exp.x, 0.00001f);
    CU_ASSERT_DOUBLE_EQUAL(ref.y, exp.y, 0.00001f);
    CU_ASSERT_DOUBLE_EQUAL(ref.z, exp.z, 0.00001f);
}

static void test_project(void)
{
    struct glug_vec3 dst = { 3.f, 3.f, 3.f };
    struct glug_vec3 b = { 1.f, -2.f, 0.f };
    glug_vec3_project(&dst, &b);
    struct glug_vec3 exp = { -0.6f, 1.2f, 0.f };

    CU_ASSERT_DOUBLE_EQUAL(dst.x, exp.x, 0.00001f);
    CU_ASSERT_DOUBLE_EQUAL(dst.y, exp.y, 0.00001f);
    CU_ASSERT_DOUBLE_EQUAL(dst.z, exp.z, 0.00001f);
}

static void test_reject(void)
{
    struct glug_vec3 dst = { 3.f, 3.f, 3.f };
    struct glug_vec3 b = { 1.f, -2.f, 0.f };
    glug_vec3_reject(&dst, &b);
    struct glug_vec3 exp = { 3.6f, 1.8f, 3.f };

    CU_ASSERT_DOUBLE_EQUAL(dst.x, exp.x, 0.00001f);
    CU_ASSERT_DOUBLE_EQUAL(dst.y, exp.y, 0.00001f);
    CU_ASSERT_DOUBLE_EQUAL(dst.z, exp.z, 0.00001f);
}

static void test_reflect(void)
{
    struct glug_vec3 dst = { 3.f, 3.f, 3.f };
    struct glug_vec3 b = { 1.f, -2.f, 0.f };
    glug_vec3_reflect(&dst, &b);
    struct glug_vec3 exp = { -4.2f, -0.6f, -3.f };

    CU_ASSERT_DOUBLE_EQUAL(dst.x, exp.x, 0.00001f);
    CU_ASSERT_DOUBLE_EQUAL(dst.y, exp.y, 0.00001f);
    CU_ASSERT_DOUBLE_EQUAL(dst.z, exp.z, 0.00001f);
}

static void test_refract(void)
{
    struct glug_vec3 dst = { 3.f, 3.f, 3.f };
    struct glug_vec3 n = { 1.f, -2.f, 0.f };
    glug_vec3_refract(&dst, &n, 1.f, 2.f);
    struct glug_vec3 exp = { -0.23469f, 4.96939f, 1.49999f };

    CU_ASSERT_DOUBLE_EQUAL(dst.x, exp.x, 0.00001f);
    CU_ASSERT_DOUBLE_EQUAL(dst.y, exp.y, 0.00001f);
    CU_ASSERT_DOUBLE_EQUAL(dst.z, exp.z, 0.00001f);
}

CU_pSuite create_vec3_suite()
{
    CU_pSuite vec3_suite = CU_add_suite("vec3f", NULL, NULL);
    if (!vec3_suite) return NULL;

    ADD_TEST(vec3_suite, set);
    ADD_TEST(vec3_suite, copy);
    ADD_TEST(vec3_suite, equal);
    ADD_TEST(vec3_suite, sum);
    ADD_TEST(vec3_suite, diff);
    ADD_TEST(vec3_suite, prod);
    ADD_TEST(vec3_suite, quot);
    ADD_TEST(vec3_suite, add);
    ADD_TEST(vec3_suite, sub);
    ADD_TEST(vec3_suite, mul);
    ADD_TEST(vec3_suite, div);
    ADD_TEST(vec3_suite, max);
    ADD_TEST(vec3_suite, min);
    ADD_TEST(vec3_suite, clamped);
    ADD_TEST(vec3_suite, maximize);
    ADD_TEST(vec3_suite, minimize);
    ADD_TEST(vec3_suite, clamp);
    ADD_TEST(vec3_suite, dot);
    ADD_TEST(vec3_suite, cross);
    ADD_TEST(vec3_suite, len);
    ADD_TEST(vec3_suite, len_sq);
    ADD_TEST(vec3_suite, len_mh);
    ADD_TEST(vec3_suite, set_len);
    ADD_TEST(vec3_suite, is_norm);
    ADD_TEST(vec3_suite, normal);
    ADD_TEST(vec3_suite, normalize);
    ADD_TEST(vec3_suite, dist);
    ADD_TEST(vec3_suite, dist_sq);
    ADD_TEST(vec3_suite, dist_mh);
    ADD_TEST(vec3_suite, angle_to);
    ADD_TEST(vec3_suite, projection);
    ADD_TEST(vec3_suite, rejection);
    ADD_TEST(vec3_suite, reflection);
    ADD_TEST(vec3_suite, refraction);
    ADD_TEST(vec3_suite, project);
    ADD_TEST(vec3_suite, reject);
    ADD_TEST(vec3_suite, reflect);
    ADD_TEST(vec3_suite, refract);

    return vec3_suite;
}
