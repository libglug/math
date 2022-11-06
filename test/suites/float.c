#include <CUnit/Assert.h>

#include <suites/create_suite.h>
#include <suites/add_test.h>

#include <glug/math/float.h>

static void test_swap(void)
{
    float f1 = 1.f, f2 = 2.f;

    glug_float_swap(&f1, &f2);

    CU_ASSERT_EQUAL(f1, 2.f);
    CU_ASSERT_EQUAL(f2, 1.f);
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
}

int main(void)
{
    CU_pSuite float_suite = create_suite("float", NULL, NULL);
    if (!float_suite) return CU_get_error();

    ADD_TEST(float_suite, swap);
    ADD_TEST(float_suite, next);
    ADD_TEST(float_suite, prev);
    ADD_TEST(float_suite, equal);
    ADD_TEST(float_suite, equal_approx);
    ADD_TEST(float_suite, equal_ulps);

    return run_tests(CU_BRM_VERBOSE);
}
