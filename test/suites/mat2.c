#include <CUnit/Assert.h>
#include <CUnit/Basic.h>
#include <glug/math/mat2.h>
#include "add_test.h"
#include "asserts.h"

static void test_identity(void)
{
    struct glug_mat2 i = glug_mat2_identity();
    struct glug_mat2 exp = { { { 1.f, 0.f }, { 0.f, 1.f } } };

    ASSERT_MAT2_EQUAL(&i, &exp, 0.f);
}

static void test_to_identity(void)
{
    struct glug_mat2 i;
    struct glug_mat2 exp = { { { 1.f, 0.f }, { 0.f, 1.f } } };
    glug_mat2_to_identity(&i);

    ASSERT_MAT2_EQUAL(&i, &exp, 0.f);
}

static void test_set(void)
{
    struct glug_mat2 dst;
    struct glug_mat2 exp = { { { 1.f, 3.f }, { 2.f, 4.f } } };

    glug_mat2_set(&dst, 1.f, 2.f, 3.f, 4.f);
    ASSERT_MAT2_EQUAL(&dst, &exp, 0.f);
}

static void test_equal(void)
{

}

static void test_sum(void)
{
    struct glug_mat2 m1 = { { { 1.f, 2.f }, { 3.f, 4.f } } };
    struct glug_mat2 m2 = { { { 2.f, 3.f }, { 4.f, 5.f } } };
    struct glug_mat2 exp = { { { 3.f, 5.f }, { 7.f, 9.f } } };
    struct glug_mat2 dst = glug_mat2_sum(&m1, &m2);

    ASSERT_MAT2_EQUAL(&dst, &exp, 0.f);
}

static void test_diff(void)
{
    struct glug_mat2 m1 = { { { 1.f, 2.f }, { 3.f, 4.f } } };
    struct glug_mat2 m2 = { { { 2.f, 4.f }, { 6.f, 8.f } } };
    struct glug_mat2 exp = { { { -1.f, -2.f }, { -3.f, -4.f } } };
    struct glug_mat2 dst = glug_mat2_diff(&m1, &m2);

    ASSERT_MAT2_EQUAL(&dst, &exp, 0.f);
}

static void test_prod(void)
{
    struct glug_mat2 m = { { { 1.f, 2.f }, { 3.f, 4.f } } };
    struct glug_mat2 dst = glug_mat2_prod(&m, 2.1f);
    struct glug_mat2 exp = { { { 2.1f, 4.2f }, { 6.3f, 8.4f } } };

    ASSERT_MAT2_EQUAL(&dst, &exp, 0.000001f);
}

static void test_quot(void)
{
    struct glug_mat2 m = { { { 2.1f, 4.2f }, { 6.3f, 8.4f } } };
    struct glug_mat2 dst = glug_mat2_quot(&m, 2.1f);
    struct glug_mat2 exp = { { { 1.f, 2.f }, { 3.f, 4.f } } };

    ASSERT_MAT2_EQUAL(&dst, &exp, 0.000001f);
}

static void test_prodm(void)
{
    struct glug_mat2 m1 = { { { 2.f, 5.f }, { -1.f, 3.f } } };
    struct glug_mat2 m2 = { { { 1.f, 2.f }, { 3.f, 4.f } } };
    struct glug_mat2 exp = { { { 0.f, 11.f }, { 2.f, 27.f } } };
    struct glug_mat2 dst = glug_mat2_prodm(&m1, &m2);

    ASSERT_MAT2_EQUAL(&dst, &exp, 0.f);
}

static void test_add(void)
{
    struct glug_mat2 dst = { { { 1.f, 2.f }, { 3.f, 4.f } } };
    struct glug_mat2 m2  = { { { 2.f, 3.f }, { 4.f, 5.f } } };
    struct glug_mat2 exp = { { { 3.f, 5.f }, { 7.f, 9.f } } };
    glug_mat2_add(&dst, &m2);

    ASSERT_MAT2_EQUAL(&dst, &exp, 0.f);
}

static void test_sub(void)
{
    struct glug_mat2 dst = { { { 1.f, 2.f }, { 3.f, 4.f } } };
    struct glug_mat2 m2  = { { { 2.f, 4.f }, { 6.f, 8.f } } };
    struct glug_mat2 exp = { { { -1.f, -2.f }, { -3.f, -4.f } } };
    glug_mat2_sub(&dst, &m2);

    ASSERT_MAT2_EQUAL(&dst, &exp, 0.f);
}

static void test_mul(void)
{
    struct glug_mat2 dst = { { { 1.f, 2.f }, { 3.f, 4.f } } };
    struct glug_mat2 exp = { { { 2.1f, 4.2f }, { 6.3f, 8.4f } } };
    glug_mat2_mul(&dst, 2.1f);

    ASSERT_MAT2_EQUAL(&dst, &exp, 0.000001f);
}

static void test_div(void)
{
    struct glug_mat2 dst = { { { 2.1f, 4.2f }, { 6.3f, 8.4f } } };
    struct glug_mat2 exp = { { { 1.f, 2.f }, { 3.f, 4.f } } };
    glug_mat2_div(&dst, 2.1f);

    ASSERT_MAT2_EQUAL(&dst, &exp, 0.000001f);
}

static void test_premulm(void)
{
    struct glug_mat2 dst = { { { 2.f, 5.f }, { -1.f, 3.f } } };
    struct glug_mat2 m2 = { { { 1.f, 2.f }, { 3.f, 4.f } } };
    struct glug_mat2 exp = { { { 17.f, 24.f }, { 8.f, 10.f } } };
    glug_mat2_premulm(&dst, &m2);

    ASSERT_MAT2_EQUAL(&dst, &exp, 0.f);
}

static void test_postmulm(void)
{
    struct glug_mat2 dst = { { { 2.f, 5.f }, { -1.f, 3.f } } };
    struct glug_mat2 m2 = { { { 1.f, 2.f }, { 3.f, 4.f } } };
    struct glug_mat2 exp = { { { 0.f, 11.f }, { 2.f, 27.f } } };
    glug_mat2_postmulm(&dst, &m2);

    ASSERT_MAT2_EQUAL(&dst, &exp, 0.f);
}

static void test_elements(void)
{
    struct glug_mat2 m = { { { 2.f, 5.f }, { -1.f, 3.f } } };
    float *els = glug_mat2_elements(&m);

    CU_ASSERT_DOUBLE_EQUAL(els[0], m.els[0][0], 0.f);
    CU_ASSERT_DOUBLE_EQUAL(els[1], m.els[0][1], 0.f);
    CU_ASSERT_DOUBLE_EQUAL(els[2], m.els[1][0], 0.f);
    CU_ASSERT_DOUBLE_EQUAL(els[3], m.els[1][1], 0.f);
}

static void test_nelements(void)
{
    CU_ASSERT_EQUAL(glug_mat2_nelements(), 4);
}

static void test_determinant(void)
{
    struct glug_mat2 m = { { { 2.f, 5.f }, { -1.f, 3.f } } };
    CU_ASSERT_DOUBLE_EQUAL(glug_mat2_determinant(&m), 11.f, 0.f);
}

static void test_get_transpose(void)
{
    struct glug_mat2 m = { { { 2.f, 5.f }, { -1.f, 3.f } } };
    struct glug_mat2 dst = glug_mat2_get_transpose(&m);
    struct glug_mat2 exp = { { { 2.f, -1.f }, { 5.f, 3.f } } };

    ASSERT_MAT2_EQUAL(&dst, &exp, 0.f);
}

static void test_transpose(void)
{
    struct glug_mat2 dst = { { { 2.f, 5.f }, { -1.f, 3.f } } };
    struct glug_mat2 exp = { { { 2.f, -1.f }, { 5.f, 3.f } } };
    glug_mat2_transpose(&dst);

    ASSERT_MAT2_EQUAL(&dst, &exp, 0.f);
}

static void test_inverse(void)
{
    struct glug_mat2 m = { { { 2.f, 5.f }, { -1.f, 3.f } } };
    struct glug_mat2 dst = glug_mat2_inverse(&m);
    struct glug_mat2 exp = { { { 3.f/11.f, -5.f/11.f }, { 1.f/11.f, 2.f/11.f } } };

    ASSERT_MAT2_EQUAL(&dst, &exp, 0.f);
}

static void test_invert(void)
{
    struct glug_mat2 dst = { { { 2.f, 5.f }, { -1.f, 3.f } } };
    struct glug_mat2 exp = { { { 3.f/11.f, -5.f/11.f }, { 1.f/11.f, 2.f/11.f } } };
    glug_mat2_invert(&dst);

    ASSERT_MAT2_EQUAL(&dst, &exp, 0.f);
}

static void test_prodv(void)
{
    struct glug_mat2 m;
    struct glug_vec2 v = { 1.f, 5.f };
    struct glug_vec2 exp = { 11.f, 23.f };
    struct glug_vec2 dst;

    glug_mat2_set(&m, 1.f, 2.f, 3.f, 4.f);
    dst = glug_mat2_prodv(&m, &v);
    ASSERT_VEC2_EQUAL(&dst, &exp, 0.f);

    exp = v;
    glug_mat2_to_identity(&m);
    dst = glug_mat2_prodv(&m, &v);
    ASSERT_VEC2_EQUAL(&dst, &exp, 0.f);
}

static void test_mulv(void)
{
    struct glug_mat2 m;
    struct glug_vec2 dst = { 1.f, 5.f };
    struct glug_vec2 exp = { 11.f, 23.f };

    glug_mat2_set(&m, 1.f, 2.f, 3.f, 4.f);
    glug_mat2_mulv(&m, &dst);
    ASSERT_VEC2_EQUAL(&dst, &exp, 0.f);

    exp = dst;
    glug_mat2_to_identity(&m);
    glug_mat2_mulv(&m, &dst);
    ASSERT_VEC2_EQUAL(&dst, &exp, 0.f);
}

CU_pSuite create_mat2_suite()
{
    CU_pSuite mat2_suite = CU_add_suite("mat2", NULL, NULL);
    if (!mat2_suite) return NULL;

    ADD_TEST(mat2_suite, identity);
    ADD_TEST(mat2_suite, to_identity);
    ADD_TEST(mat2_suite, set);
    ADD_TEST(mat2_suite, sum);
    ADD_TEST(mat2_suite, sum);
    ADD_TEST(mat2_suite, diff);
    ADD_TEST(mat2_suite, prod);
    ADD_TEST(mat2_suite, quot);
    ADD_TEST(mat2_suite, prodm);
    ADD_TEST(mat2_suite, add);
    ADD_TEST(mat2_suite, sub);
    ADD_TEST(mat2_suite, mul);
    ADD_TEST(mat2_suite, div);
    ADD_TEST(mat2_suite, premulm);
    ADD_TEST(mat2_suite, postmulm);
    ADD_TEST(mat2_suite, elements);
    ADD_TEST(mat2_suite, nelements);
    ADD_TEST(mat2_suite, determinant);
    ADD_TEST(mat2_suite, get_transpose);
    ADD_TEST(mat2_suite, transpose);
    ADD_TEST(mat2_suite, inverse);
    ADD_TEST(mat2_suite, invert);
    ADD_TEST(mat2_suite, mulv);
    ADD_TEST(mat2_suite, prodv);

    return mat2_suite;
}
