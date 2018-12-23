#include <CUnit/Assert.h>
#include <CUnit/Basic.h>
#include <glug/math/vec4.h>

#define ADD_TEST(add_test, suite, name, fcn) if (!add_test((suite), (name), (fcn))) return NULL;

static void test_set(void)
{
    struct glug_vec4 v3;
    float x = 5.f, y = 6.f, z = 7.f, w= 8.f;
    glug_vec4_set(&v3, x, y, z, w);

    CU_ASSERT_DOUBLE_EQUAL(v3.x, x, 0.f);
    CU_ASSERT_DOUBLE_EQUAL(v3.y, y, 0.f);
    CU_ASSERT_DOUBLE_EQUAL(v3.z, z, 0.f);
    CU_ASSERT_DOUBLE_EQUAL(v3.w, w, 0.f);
}

static void test_copy(void)
{
    struct glug_vec4 v1 = { 0, 0, 0 };
    struct glug_vec4 v2 = { 4.f, 5.f, 10.f, 13.f };
    glug_vec4_copy(&v1, &v2);

    CU_ASSERT_DOUBLE_EQUAL(v1.x, v2.x, 0.f);
    CU_ASSERT_DOUBLE_EQUAL(v1.y, v2.y, 0.f);
    CU_ASSERT_DOUBLE_EQUAL(v1.z, v2.z, 0.f);
    CU_ASSERT_DOUBLE_EQUAL(v1.w, v2.w, 0.f);
}

static void test_equal(void)
{

}

static void test_sum(void)
{
    struct glug_vec4 v1 = { 1.f, 8.9f, 10.f, 0.7f };
    struct glug_vec4 v2 = { -1.01f, -5.5f, 19.1f, -3.3f };
    struct glug_vec4 exp = { -0.01f, 3.4f, 29.1f, -2.6f };
    struct glug_vec4 sum = glug_vec4_sum(&v1, &v2);

    CU_ASSERT_DOUBLE_EQUAL(sum.x, exp.x, 0.001f);
    CU_ASSERT_DOUBLE_EQUAL(sum.y, exp.y, 0.001f);
    CU_ASSERT_DOUBLE_EQUAL(sum.z, exp.z, 0.001f);
    CU_ASSERT_DOUBLE_EQUAL(sum.w, exp.w, 0.001f);
}

static void test_diff(void)
{
    struct glug_vec4 v1 = { 17.17f, 19.8f, 79.f, 32.f };
    struct glug_vec4 v2 = { 8.f, 9.f, 18.697f, -7.9f };
    struct glug_vec4 exp = { 9.17f, 10.8f, 60.303f, 39.9f };
    struct glug_vec4 diff = glug_vec4_diff(&v1, &v2);

    CU_ASSERT_DOUBLE_EQUAL(diff.x, exp.x, .001f);
    CU_ASSERT_DOUBLE_EQUAL(diff.y, exp.y, .001f);
    CU_ASSERT_DOUBLE_EQUAL(diff.z, exp.z, .0001f);
    CU_ASSERT_DOUBLE_EQUAL(diff.w, exp.w, .0001f);
}

static void test_prod(void)
{
    struct glug_vec4 v = { 4.f, 5.f, 10.f, -33.f };
    float scalar = 4.1f;
    struct glug_vec4 exp = { 16.4f, 20.5f, 41.f, -135.3f };
    struct glug_vec4 prod = glug_vec4_prod(&v, scalar);

    CU_ASSERT_DOUBLE_EQUAL(prod.x, exp.x, 0.01f);
    CU_ASSERT_DOUBLE_EQUAL(prod.y, exp.y, 0.01f);
    CU_ASSERT_DOUBLE_EQUAL(prod.z, exp.z, 0.01f);
    CU_ASSERT_DOUBLE_EQUAL(prod.w, exp.w, 0.01f);
}

static void test_quot(void)
{
    struct glug_vec4 v = { 3.142f, 2.718f, 1.618f, -5.412f };
    float scalar = 1.414f;
    struct glug_vec4 exp = { 2.222065f, 1.922206f, 1.144271f, -3.827439f };
    struct glug_vec4 quot = glug_vec4_quot(&v, scalar);

    CU_ASSERT_DOUBLE_EQUAL(quot.x, exp.x, 0.000001f);
    CU_ASSERT_DOUBLE_EQUAL(quot.y, exp.y, 0.000001f);
    CU_ASSERT_DOUBLE_EQUAL(quot.z, exp.z, 0.000001f);
    CU_ASSERT_DOUBLE_EQUAL(quot.w, exp.w, 0.000001f);
}

static void test_add(void)
{
    struct glug_vec4 dst = { 1.f, 8.9f, 10.f, 0.7f };
    struct glug_vec4 v2 = { -1.01f, -5.5f, 19.1f, -3.3f };
    struct glug_vec4 exp = { -0.01f, 3.4f, 29.1f, -2.6f };
    glug_vec4_add(&dst, &v2);

    CU_ASSERT_DOUBLE_EQUAL(dst.x, exp.x, 0.001f);
    CU_ASSERT_DOUBLE_EQUAL(dst.y, exp.y, 0.001f);
    CU_ASSERT_DOUBLE_EQUAL(dst.z, exp.z, 0.001f);
    CU_ASSERT_DOUBLE_EQUAL(dst.w, exp.w, 0.001f);
}

static void test_sub(void)
{
    struct glug_vec4 dst = { 17.17f, 19.8f, 79.f, 32.f };
    struct glug_vec4 v2 = { 8.f, 9.f, 18.697f, -7.9f };
    struct glug_vec4 exp = { 9.17f, 10.8f, 60.303f, 39.9f };
    glug_vec4_sub(&dst, &v2);

    CU_ASSERT_DOUBLE_EQUAL(dst.x, exp.x, 0.001f);
    CU_ASSERT_DOUBLE_EQUAL(dst.y, exp.y, 0.001f);
    CU_ASSERT_DOUBLE_EQUAL(dst.z, exp.z, 0.001f);
    CU_ASSERT_DOUBLE_EQUAL(dst.w, exp.w, 0.001f);
}

static void test_mul(void)
{
    struct glug_vec4 dst = { 4.f, 5.f, 10.f, -33.f };
    float scalar = 4.1f;
    struct glug_vec4 exp = { 16.4f, 20.5f, 41.f, -135.3f };
    glug_vec4_mul(&dst, scalar);

    CU_ASSERT_DOUBLE_EQUAL(dst.x, exp.x, 0.01f);
    CU_ASSERT_DOUBLE_EQUAL(dst.y, exp.y, 0.01f);
    CU_ASSERT_DOUBLE_EQUAL(dst.z, exp.z, 0.01f);
    CU_ASSERT_DOUBLE_EQUAL(dst.w, exp.w, 0.001f);
}

static void test_div(void)
{
    struct glug_vec4 dst = { 3.142f, 2.718f, 1.618f, -5.412f };
    float scalar = 1.414f;
    struct glug_vec4 exp = { 2.222065f, 1.922206f, 1.144271f, -3.827439f };
    glug_vec4_div(&dst, scalar);

    CU_ASSERT_DOUBLE_EQUAL(dst.x, exp.x, 0.000001f);
    CU_ASSERT_DOUBLE_EQUAL(dst.y, exp.y, 0.000001f);
    CU_ASSERT_DOUBLE_EQUAL(dst.z, exp.z, 0.000001f);
    CU_ASSERT_DOUBLE_EQUAL(dst.w, exp.w, 0.000001f);
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

static void test_len_mh(void)
{
    struct glug_vec4 v = { -5.f, 3.f, -4.f, 8.2f };
    struct glug_vec4 v2 = { 6.f, -10.f, 2.f, -2.f };
    float len = glug_vec4_len_manhattan(&v);
    float len2 = glug_vec4_len_manhattan(&v2);
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

    CU_ASSERT_DOUBLE_EQUAL(v.x, exp.x, 0.001f);
    CU_ASSERT_DOUBLE_EQUAL(v.y, exp.y, 0.001f);
    CU_ASSERT_DOUBLE_EQUAL(v.z, exp.z, 0.001f);
    CU_ASSERT_DOUBLE_EQUAL(v.w, exp.w, 0.001f);
    CU_ASSERT_DOUBLE_EQUAL(glug_vec4_len(&v), newlen, 0.001f);
}

static void test_is_norm(void)
{

}

static void test_normal(void)
{
    struct glug_vec4 v = { 3.f, 3.f, -3.f, -3.f };
    struct glug_vec4 n = glug_vec4_normal(&v);
    struct glug_vec4 exp = { 0.5f, 0.5f, -0.5f, -0.5f };

    CU_ASSERT_DOUBLE_EQUAL(glug_vec4_len(&n), 1.f, 0.0001f);
    CU_ASSERT_DOUBLE_EQUAL(n.x, exp.x, 0.00001f);
    CU_ASSERT_DOUBLE_EQUAL(n.y, exp.y, 0.00001f);
    CU_ASSERT_DOUBLE_EQUAL(n.z, exp.z, 0.00001f);
    CU_ASSERT_DOUBLE_EQUAL(n.w, exp.w, 0.00001f);
}

static void test_normalize(void)
{
    struct glug_vec4 dst = { 3.f, 3.f, -3.f, -3.f };
    struct glug_vec4 exp = { 0.5f, 0.5f, -0.5f, -0.5f };
    glug_vec4_normalize(&dst);

    CU_ASSERT_DOUBLE_EQUAL(glug_vec4_len(&dst), 1.f, 0.0001f);
    CU_ASSERT_DOUBLE_EQUAL(dst.x, exp.x, 0.00001f);
    CU_ASSERT_DOUBLE_EQUAL(dst.y, exp.y, 0.00001f);
    CU_ASSERT_DOUBLE_EQUAL(dst.z, exp.z, 0.00001f);
    CU_ASSERT_DOUBLE_EQUAL(dst.w, exp.w, 0.00001f);
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

static void test_dist_mh(void)
{
    struct glug_vec4 a = { -1.2f, 1.9f, -0.5f, -0.9f };
    struct glug_vec4 b = { -0.8f, 1.f, -0.3f, 0.6f };
    float dist = glug_vec4_dist_manhattan(&a, &b);
    float exp = 3.f;

    CU_ASSERT_DOUBLE_EQUAL(dist, exp, 0.0001f);
}

static void test_angle_to(void)
{
    struct glug_vec4 a = { -1.0f, 0.f, 0.f, 0.f };
    struct glug_vec4 b = { 0.f, 0.f, 0.f, 1.f };
    float dist = glug_vec4_angle_btw(&a, &b);
    float exp = 1.5707f;

    CU_ASSERT_DOUBLE_EQUAL(dist, exp, 0.0001f);
}

static void test_projection(void)
{
    struct glug_vec4 a = { 3.f, 3.f, 3.f, -2.f };
    struct glug_vec4 b = { 1.f, -2.f, 0.f, -2.f };
    struct glug_vec4 proj = glug_vec4_projection(&a, &b);
    struct glug_vec4 exp = { 0.11111f, -0.22222f, 0, -0.22222f };

    CU_ASSERT_DOUBLE_EQUAL(proj.x, exp.x, 0.00001f);
    CU_ASSERT_DOUBLE_EQUAL(proj.y, exp.y, 0.00001f);
    CU_ASSERT_DOUBLE_EQUAL(proj.z, exp.z, 0.00001f);
    CU_ASSERT_DOUBLE_EQUAL(proj.w, exp.w, 0.00001f);
}

static void test_rejection(void)
{
    struct glug_vec4 a = { 3.f, 3.f, 3.f, -2.f };
    struct glug_vec4 b = { 1.f, -2.f, 0.f, -2.f };
    struct glug_vec4 rej = glug_vec4_rejection(&a, &b);
    struct glug_vec4 exp = { 2.88888f, 3.22222f, 3.f, -1.77777f };

    CU_ASSERT_DOUBLE_EQUAL(rej.x, exp.x, 0.00001f);
    CU_ASSERT_DOUBLE_EQUAL(rej.y, exp.y, 0.00001f);
    CU_ASSERT_DOUBLE_EQUAL(rej.z, exp.z, 0.00001f);
    CU_ASSERT_DOUBLE_EQUAL(rej.w, exp.w, 0.0001f);
}

static void test_reflection(void)
{
    struct glug_vec4 a = { 3.f, 3.f, 3.f, -2.f };
    struct glug_vec4 b = { 1.f, -2.f, 0.f, -2.f };
    struct glug_vec4 ref = glug_vec4_reflection(&a, &b);
    struct glug_vec4 exp = { -2.77777f, -3.44444f, -3.f, 1.55555f };

    CU_ASSERT_DOUBLE_EQUAL(ref.x, exp.x, 0.0001f);
    CU_ASSERT_DOUBLE_EQUAL(ref.y, exp.y, 0.0001f);
    CU_ASSERT_DOUBLE_EQUAL(ref.z, exp.z, 0.0001f);
    CU_ASSERT_DOUBLE_EQUAL(ref.w, exp.w, 0.0001f);
}

static void test_refraction(void)
{
    struct glug_vec4 inc = { 3.f, 3.f, 3.f, -2.f };
    struct glug_vec4 n = { 1.f, -2.f, 0.f, -2.f };
    struct glug_vec4 ref = glug_vec4_refraction(&inc, &n, 1.f, 2.f);
    struct glug_vec4 exp = { -0.16379f, 4.82758f, 1.50000f, 2.32758f };

    CU_ASSERT_DOUBLE_EQUAL(ref.x, exp.x, 0.00001f);
    CU_ASSERT_DOUBLE_EQUAL(ref.y, exp.y, 0.00001f);
    CU_ASSERT_DOUBLE_EQUAL(ref.z, exp.z, 0.00001f);
    CU_ASSERT_DOUBLE_EQUAL(ref.w, exp.w, 0.00001f);
}

static void test_project(void)
{
    struct glug_vec4 dst = { 3.f, 3.f, 3.f, -2.f };
    struct glug_vec4 b = { 1.f, -2.f, 0.f, -2.f };
    glug_vec4_project(&dst, &b);
    struct glug_vec4 exp = { 0.11111f, -0.22222f, 0, -0.22222f };

    CU_ASSERT_DOUBLE_EQUAL(dst.x, exp.x, 0.00001f);
    CU_ASSERT_DOUBLE_EQUAL(dst.y, exp.y, 0.00001f);
    CU_ASSERT_DOUBLE_EQUAL(dst.z, exp.z, 0.00001f);
    CU_ASSERT_DOUBLE_EQUAL(dst.w, exp.w, 0.00001f);
}

static void test_reject(void)
{
    struct glug_vec4 dst = { 3.f, 3.f, 3.f, -2.f };
    struct glug_vec4 b = { 1.f, -2.f, 0.f, -2.f };
    glug_vec4_reject(&dst, &b);
    struct glug_vec4 exp = { 2.88888f, 3.22222f, 3.f, -1.77777f };

    CU_ASSERT_DOUBLE_EQUAL(dst.x, exp.x, 0.00001f);
    CU_ASSERT_DOUBLE_EQUAL(dst.y, exp.y, 0.00001f);
    CU_ASSERT_DOUBLE_EQUAL(dst.z, exp.z, 0.00001f);
    CU_ASSERT_DOUBLE_EQUAL(dst.w, exp.w, 0.0001f);
}

static void test_reflect(void)
{
    struct glug_vec4 dst = { 3.f, 3.f, 3.f, -2.f };
    struct glug_vec4 b = { 1.f, -2.f, 0.f, -2.f };
    glug_vec4_reflect(&dst, &b);
    struct glug_vec4 exp = { -2.77777f, -3.44444f, -3.f, 1.55555f };

    CU_ASSERT_DOUBLE_EQUAL(dst.x, exp.x, 0.0001f);
    CU_ASSERT_DOUBLE_EQUAL(dst.y, exp.y, 0.0001f);
    CU_ASSERT_DOUBLE_EQUAL(dst.z, exp.z, 0.0001f);
    CU_ASSERT_DOUBLE_EQUAL(dst.w, exp.w, 0.0001f);
}

static void test_refract(void)
{
    struct glug_vec4 dst = { 3.f, 3.f, 3.f, -2.f };
    struct glug_vec4 n = { 1.f, -2.f, 0.f, -2.f };
    glug_vec4_refract(&dst, &n, 1.f, 2.f);
    struct glug_vec4 exp = { -0.16379f, 4.82758f, 1.50000f, 2.32758f };

    CU_ASSERT_DOUBLE_EQUAL(dst.x, exp.x, 0.00001f);
    CU_ASSERT_DOUBLE_EQUAL(dst.y, exp.y, 0.00001f);
    CU_ASSERT_DOUBLE_EQUAL(dst.z, exp.z, 0.00001f);
    CU_ASSERT_DOUBLE_EQUAL(dst.w, exp.w, 0.00001f);
}

CU_pSuite create_vec4_suite()
{
    CU_pSuite vec4_suite = CU_add_suite("vec4f", NULL, NULL);
    if (!vec4_suite) return NULL;

    ADD_TEST(CU_add_test, vec4_suite, "set", test_set);
    ADD_TEST(CU_add_test, vec4_suite, "copy", test_copy);
    ADD_TEST(CU_add_test, vec4_suite, "equal", test_equal);
    ADD_TEST(CU_add_test, vec4_suite, "sum", test_sum);
    ADD_TEST(CU_add_test, vec4_suite, "difference", test_diff);
    ADD_TEST(CU_add_test, vec4_suite, "product", test_prod);
    ADD_TEST(CU_add_test, vec4_suite, "quotient", test_quot);
    ADD_TEST(CU_add_test, vec4_suite, "add", test_add);
    ADD_TEST(CU_add_test, vec4_suite, "subtract", test_sub);
    ADD_TEST(CU_add_test, vec4_suite, "multiply", test_mul);
    ADD_TEST(CU_add_test, vec4_suite, "divide", test_div);
    ADD_TEST(CU_add_test, vec4_suite, "dot", test_dot);
    ADD_TEST(CU_add_test, vec4_suite, "length", test_len);
    ADD_TEST(CU_add_test, vec4_suite, "square length", test_len_sq);
    ADD_TEST(CU_add_test, vec4_suite, "manhattan length", test_len_mh);
    ADD_TEST(CU_add_test, vec4_suite, "set length", test_set_len);
    ADD_TEST(CU_add_test, vec4_suite, "is normal", test_is_norm);
    ADD_TEST(CU_add_test, vec4_suite, "normal", test_normal);
    ADD_TEST(CU_add_test, vec4_suite, "normalize", test_normalize);
    ADD_TEST(CU_add_test, vec4_suite, "distance", test_dist);
    ADD_TEST(CU_add_test, vec4_suite, "square distance", test_dist_sq);
    ADD_TEST(CU_add_test, vec4_suite, "manhattan distance", test_dist_mh);
    ADD_TEST(CU_add_test, vec4_suite, "angle between", test_angle_to);
    ADD_TEST(CU_add_test, vec4_suite, "projection", test_projection);
    ADD_TEST(CU_add_test, vec4_suite, "rejection", test_rejection);
    ADD_TEST(CU_add_test, vec4_suite, "reflection", test_reflection);
    ADD_TEST(CU_add_test, vec4_suite, "refraction", test_refraction);
    ADD_TEST(CU_add_test, vec4_suite, "project", test_project);
    ADD_TEST(CU_add_test, vec4_suite, "reject", test_reject);
    ADD_TEST(CU_add_test, vec4_suite, "reflect", test_reflect);
    ADD_TEST(CU_add_test, vec4_suite, "refract", test_refract);

    return vec4_suite;
}
