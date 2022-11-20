#include <CUnit/Basic.h>
#include <CUnit/Assert.h>

#include <suites/create_suite.h>
#include <asserts/asserts.h>

#include <glug/math/mat2.h>

static void test_identity(void)
{
    struct glug_mat2 i;
    struct glug_mat2 exp = { { { 1.f, 0.f }, { 0.f, 1.f } } };
    glug_mat2_identity(&i);

    ASSERT_MAT2_EQUAL(&i, &exp, 0.f);
}

static void test_equal(void)
{

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

static void test_transpose(void)
{
    struct glug_mat2 dst = { { { 2.f, 5.f }, { -1.f, 3.f } } };
    struct glug_mat2 exp = { { { 2.f, -1.f }, { 5.f, 3.f } } };
    glug_mat2_transpose(&dst);

    ASSERT_MAT2_EQUAL(&dst, &exp, 0.f);
}

static void test_invert(void)
{
    struct glug_mat2 dst = { { { 2.f, 5.f }, { -1.f, 3.f } } };
    struct glug_mat2 exp = { { { 3.f/11.f, -5.f/11.f }, { 1.f/11.f, 2.f/11.f } } };
    glug_mat2_invert(&dst);

    ASSERT_MAT2_EQUAL(&dst, &exp, 0.f);
}

static void test_mulv(void)
{
    struct glug_mat2 m = { { { 1.f, 2.f }, { 3.f, 4.f } } };
    struct glug_vec2 dst = { 1.f, 5.f };
    struct glug_vec2 exp = { 11.f, 23.f };

    glug_mat2_mulv(&m, &dst);
    ASSERT_VEC2_EQUAL(&dst, &exp, 0.f);

    exp = dst;
    glug_mat2_identity(&m);
    glug_mat2_mulv(&m, &dst);
    ASSERT_VEC2_EQUAL(&dst, &exp, 0.f);
}

int main(void)
{
    CU_pSuite mat2_suite = create_suite("mat2", NULL, NULL);
    if (!mat2_suite) return CU_get_error();

    ADD_TEST(mat2_suite, identity);
    ADD_TEST(mat2_suite, add);
    ADD_TEST(mat2_suite, sub);
    ADD_TEST(mat2_suite, mul);
    ADD_TEST(mat2_suite, div);
    ADD_TEST(mat2_suite, premulm);
    ADD_TEST(mat2_suite, postmulm);
    ADD_TEST(mat2_suite, elements);
    ADD_TEST(mat2_suite, nelements);
    ADD_TEST(mat2_suite, determinant);
    ADD_TEST(mat2_suite, transpose);
    ADD_TEST(mat2_suite, invert);
    ADD_TEST(mat2_suite, mulv);

    return run_tests(CU_BRM_VERBOSE);
}
