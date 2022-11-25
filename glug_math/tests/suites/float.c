#include <CUnit/Assert.h>

#include <suites/create_suite.h>
#include <glug/math/float.h>

static void test_equal(void)
{
    CU_ASSERT_TRUE(glug_float_equal_strict(1.f, 1.f));
    CU_ASSERT_TRUE(glug_float_equal_strict(-1.f, -1.f));
    CU_ASSERT_FALSE(glug_float_equal_strict(1.f, 2.f));
    CU_ASSERT_FALSE(glug_float_equal_strict(1.f, -1.f));
}

static void test_equal_approx(void)
{
    CU_ASSERT_TRUE(glug_float_equal_approx(1.f, 1.1f, 0.11f));
    CU_ASSERT_TRUE(glug_float_equal_approx(0.f, 0.5f, 0.51f));
    CU_ASSERT_TRUE(glug_float_equal_approx(-1.f, 1.f, 2.01f));
}

static void test_equal_ulps(void)
{
    float next = glug_float_next(1.f);
    float prev = glug_float_prev(1.f);
    CU_ASSERT_TRUE(glug_float_equal_ulps(1.f, next, 1));
    CU_ASSERT_TRUE(glug_float_equal_ulps(1.f, prev, 1));

    next = glug_float_next(glug_float_next(next));
    prev = glug_float_prev(glug_float_prev(prev));
    CU_ASSERT_FALSE(glug_float_equal_ulps(1.f, next, 2));
    CU_ASSERT_FALSE(glug_float_equal_ulps(1.f, prev, 2));
    CU_ASSERT_TRUE(glug_float_equal_ulps(1.f, next, 3));
    CU_ASSERT_TRUE(glug_float_equal_ulps(1.f, prev, 3));

    CU_ASSERT_FALSE(glug_float_equal_ulps(-1.f, next, 3));

    next = glug_float_next(-1.f);
    prev = glug_float_prev(-1.f);
    CU_ASSERT_TRUE(glug_float_equal_ulps(-1.f, next, 1));
    CU_ASSERT_TRUE(glug_float_equal_ulps(-1.f, prev, 1));

    next = glug_float_next(glug_float_next(next));
    prev = glug_float_prev(glug_float_prev(prev));
    CU_ASSERT_FALSE(glug_float_equal_ulps(-1.f, next, 2));
    CU_ASSERT_FALSE(glug_float_equal_ulps(-1.f, prev, 2));
    CU_ASSERT_TRUE(glug_float_equal_ulps(-1.f, next, 3));
    CU_ASSERT_TRUE(glug_float_equal_ulps(-1.f, prev, 3));

    CU_ASSERT_FALSE(glug_float_equal_ulps(1.f, prev, 3));
}

static void test_next(void)
{
    CU_ASSERT_TRUE(glug_float_next(0.f)  > 0.f);
    CU_ASSERT_TRUE(glug_float_next(1.f)  > 1.f);
    CU_ASSERT_TRUE(glug_float_next(-1.f) > -1.f);
}

static void test_prev(void)
{
    CU_ASSERT_TRUE(glug_float_prev(0.f)  < 0.f);
    CU_ASSERT_TRUE(glug_float_prev(1.f)  < 1.f);
    CU_ASSERT_TRUE(glug_float_prev(-1.f) < -1.f);
}

static void test_rand(void)
{
    float rando = glug_float_rand(-2.f, 3.f);
    CU_ASSERT_TRUE(rando >= -2.f);
    CU_ASSERT_TRUE(rando <= 3.f);

    rando = glug_float_rand(10, 20);
    CU_ASSERT_TRUE(rando >= 10.f);
    CU_ASSERT_TRUE(rando <= 20.f);
}

static void test_swap(void)
{
    float f1 = 1.f, f2 = 2.f;

    glug_float_swap(&f1, &f2);

    CU_ASSERT_EQUAL(f1, 2.f);
    CU_ASSERT_EQUAL(f2, 1.f);
}

static void test_sign(void)
{
    CU_ASSERT_TRUE(glug_float_sign(2.f) > 0.f);
    CU_ASSERT_TRUE(glug_float_sign(-2.f) < 0.f);

    CU_ASSERT_EQUAL(glug_float_sign(0.f), 0.f);
    CU_ASSERT_EQUAL(glug_float_sign(-0.f), 0.f);
}

static void test_integral(void)
{
    CU_ASSERT_EQUAL(glug_float_integral(3.14159f), 3.f);
    CU_ASSERT_EQUAL(glug_float_integral(-2.71828f), -2.f);
}

static void test_frac(void)
{
    CU_ASSERT_DOUBLE_EQUAL(glug_float_frac(3.14159f), 0.14159f, 0.000001f);
    CU_ASSERT_DOUBLE_EQUAL(glug_float_frac(-2.71828f), -0.71828f, 0.000001f);
}

static void test_decompose(void)
{
    float pi_i, pi_frac, e_i, e_frac;

    glug_float_decomp(-3.14159f, &pi_i, &pi_frac);
    CU_ASSERT_DOUBLE_EQUAL(pi_i, -3.f, 0.000001f);
    CU_ASSERT_DOUBLE_EQUAL(pi_frac, -0.14159f, 0.000001f);

    glug_float_decomp(2.71828f, &e_i, &e_frac);
    CU_ASSERT_DOUBLE_EQUAL(e_i, 2.f, 0.000001f);
    CU_ASSERT_DOUBLE_EQUAL(e_frac, 0.71828f, 0.000001f);
}

static void test_mod(void)
{
    float pi = 3.14159f, e = 2.71828f;
    float m = glug_float_mod(2 * pi, e);

    CU_ASSERT_DOUBLE_EQUAL(m, 2 * pi - 2 * e, 0.1f);
}

static void test_min(void)
{
    CU_ASSERT_EQUAL(glug_float_min(1.f, 2.f), 1.f);
    CU_ASSERT_EQUAL(glug_float_min(0.f, 1.f), 0.f);
    CU_ASSERT_EQUAL(glug_float_min(-1.f, 2.f), -1.f);
    CU_ASSERT_EQUAL(glug_float_min(-1.f, -2.f), -2.f);
}

static void test_max(void)
{
    CU_ASSERT_EQUAL(glug_float_max(1.f, 2.f), 2.f);
    CU_ASSERT_EQUAL(glug_float_max(0.f, 1.f), 1.f);
    CU_ASSERT_EQUAL(glug_float_max(-1.f, 2.f), 2.f);
    CU_ASSERT_EQUAL(glug_float_max(-1.f, -2.f), -1.f);
}

static void test_clamp(void)
{
    CU_ASSERT_EQUAL(glug_float_clamp(1.f, 0.f, 2.f), 1.f);
    CU_ASSERT_EQUAL(glug_float_clamp(0.f, 1.f, 2.f), 1.f);
    CU_ASSERT_EQUAL(glug_float_clamp(-1.f, 0.f, 2.f), 0.f);
    CU_ASSERT_EQUAL(glug_float_clamp(-1.f, -3.f, -2.f), -2.f);
}

static void test_rescale(void)
{
    CU_ASSERT_DOUBLE_EQUAL(glug_float_rescale(2.f, 1.f, 5.f, -1.f, 1.f), -0.5f, 0.0001f);
    CU_ASSERT_DOUBLE_EQUAL(glug_float_rescale(4.f, 1.f, 4.f, 0.f, 1.f), 1.f, 0.00001f);
    CU_ASSERT_DOUBLE_EQUAL(glug_float_rescale(2.f, 2.f, 10.f, 0.f, 5.f), 0.f, 0.00001f);
    CU_ASSERT_DOUBLE_EQUAL(glug_float_rescale(2.f, 0.f, 1.f, -1.f, 1.f), 3.f, 0.00001f);
}

static void test_floor(void)
{
    CU_ASSERT_EQUAL(glug_float_floor(22.3f), 22.f);
    CU_ASSERT_EQUAL(glug_float_floor(-15.6f), -16.f);
    CU_ASSERT_EQUAL(glug_float_floor(1.f), 1.f);
    CU_ASSERT_EQUAL(glug_float_floor(0.f), 0.f);
}

static void test_ceil(void)
{
    CU_ASSERT_EQUAL(glug_float_ceil(22.3f), 23.f);
    CU_ASSERT_EQUAL(glug_float_ceil(-15.6f), -15.f);
    CU_ASSERT_EQUAL(glug_float_ceil(1.f), 1.f);
    CU_ASSERT_EQUAL(glug_float_ceil(0.f), 0.f);
}

static void test_round(void)
{
    CU_ASSERT_EQUAL(glug_float_round(22.3f), 22.f);
    CU_ASSERT_EQUAL(glug_float_round(19.5f), 20.f);
    CU_ASSERT_EQUAL(glug_float_round(-15.6f), -16.f);
    CU_ASSERT_EQUAL(glug_float_round(-12.45f), -12.f);
    CU_ASSERT_EQUAL(glug_float_round(1.f), 1.f);
    CU_ASSERT_EQUAL(glug_float_round(0.f), 0.f);
}

static void test_round_zero(void)
{
    CU_ASSERT_EQUAL(glug_float_round_zero(22.3f), 22.f);
    CU_ASSERT_EQUAL(glug_float_round_zero(3.8f), 3.f);
    CU_ASSERT_EQUAL(glug_float_round_zero(-11.1f), -11.f);
    CU_ASSERT_EQUAL(glug_float_round_zero(-4.9f), -4.f);
    CU_ASSERT_EQUAL(glug_float_round_zero(1.f), 1.f);
    CU_ASSERT_EQUAL(glug_float_round_zero(-1.f), -1.f);
    CU_ASSERT_EQUAL(glug_float_round_zero(0.f), 0.f);
}

int main(void)
{
    CU_pSuite float_suite = create_suite("float", NULL, NULL);
    if (!float_suite) return CU_get_error();

    ADD_TEST(float_suite, equal);
    ADD_TEST(float_suite, equal_approx);
    ADD_TEST(float_suite, equal_ulps);
    ADD_TEST(float_suite, next);
    ADD_TEST(float_suite, prev);
    ADD_TEST(float_suite, rand);
    ADD_TEST(float_suite, swap);
    ADD_TEST(float_suite, sign);
    ADD_TEST(float_suite, integral);
    ADD_TEST(float_suite, frac);
    ADD_TEST(float_suite, decompose);
    ADD_TEST(float_suite, mod);
    ADD_TEST(float_suite, min);
    ADD_TEST(float_suite, max);
    ADD_TEST(float_suite, clamp);
    ADD_TEST(float_suite, rescale);
    ADD_TEST(float_suite, floor);
    ADD_TEST(float_suite, ceil);
    ADD_TEST(float_suite, round);
    ADD_TEST(float_suite, round_zero);

    return run_tests(CU_BRM_VERBOSE);
}
