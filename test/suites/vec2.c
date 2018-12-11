#include <CUnit/Assert.h>
#include <CUnit/Basic.h>
#include <glug/math/vec2.h>

#include <float.h>

#define ADD_TEST(add_test, suite, name, fcn) if (!add_test((suite), (name), (fcn))) return NULL;

static void test_set(void);
static void test_copy(void);
static void test_sum(void);
static void test_diff(void);
static void test_prod(void);
static void test_quot(void);

CU_pSuite create_vec2_suite()
{
    CU_pSuite vec2_suite = CU_add_suite("vec2f", NULL, NULL);
    if (!vec2_suite) return NULL;

    ADD_TEST(CU_add_test, vec2_suite, "set", test_set);
    ADD_TEST(CU_add_test, vec2_suite, "copy", test_copy);
    ADD_TEST(CU_add_test, vec2_suite, "sum", test_sum);
    ADD_TEST(CU_add_test, vec2_suite, "diff", test_diff);
    ADD_TEST(CU_add_test, vec2_suite, "prod", test_prod);
    ADD_TEST(CU_add_test, vec2_suite, "quot", test_quot);

    return vec2_suite;
}

void test_set(void)
{
    struct glug_vec2 v2 = { .x = 0, .y = 0 };
    float x = 5.f, y = 6.f;
    glug_vec2_set(&v2, x, y);

    CU_ASSERT_DOUBLE_EQUAL(v2.x, x, x * FLT_EPSILON);
    CU_ASSERT_DOUBLE_EQUAL(v2.y, y, y * FLT_EPSILON);
}

void test_copy(void)
{
    struct glug_vec2 v1 = { .x = 0, .y = 0 };
    struct glug_vec2 v2 = { .x = 4.f, .y = 5.f };
    glug_vec2_copy(&v1, &v2);

    CU_ASSERT_DOUBLE_EQUAL(v1.x, v2.x, v2.x * FLT_EPSILON);
    CU_ASSERT_DOUBLE_EQUAL(v1.y, v2.y, v2.y * FLT_EPSILON);
}

void test_sum(void)
{
    struct glug_vec2 v1 = { .x = 1.0f, .y = 8.9f };
    struct glug_vec2 v2 = { .x = -1.01f, .y = -5.5f };
    struct glug_vec2 sum = glug_vec2_sum(&v1, &v2);

    float sumx = v1.x + v2.x;
    float sumy = v1.y + v2.y;

    CU_ASSERT_DOUBLE_EQUAL(sum.x, sumx, sumx * FLT_EPSILON);
    CU_ASSERT_DOUBLE_EQUAL(sum.y, sumy, sumy * FLT_EPSILON);
}

void test_diff(void)
{
    struct glug_vec2 v1 = { .x = 17.17f, .y = 19.8f };
    struct glug_vec2 v2 = { .x = 8.f, .y = 9.f };
    struct glug_vec2 diff = glug_vec2_diff(&v1, &v2);

    float diffx = v1.x - v2.x;
    float diffy = v1.y - v2.y;

    CU_ASSERT_DOUBLE_EQUAL(diff.x, diffx, diffx * FLT_EPSILON);
    CU_ASSERT_DOUBLE_EQUAL(diff.y, diffy, diffy * FLT_EPSILON);
}

void test_prod(void)
{
    struct glug_vec2 v = { .x = 4.f, .y = 5.f };
    float scalar = 4.1f;
    struct glug_vec2 prod = glug_vec2_prod(&v, scalar);

    float prodx = v.x * scalar;
    float prody = v.y * scalar;

    CU_ASSERT_DOUBLE_EQUAL(prod.x, prodx, prodx * FLT_EPSILON);
    CU_ASSERT_DOUBLE_EQUAL(prod.y, prody, prody * FLT_EPSILON);
}

void test_quot(void)
{
    struct glug_vec2 v = { .x = 3.142f, .y = 2.718f };
    float scalar = 1.414f;
    struct glug_vec2 quot = glug_vec2_quot(&v, scalar);

    float quotx = v.x / scalar;
    float quoty = v.y / scalar;

    CU_ASSERT_DOUBLE_EQUAL(quot.x, quotx, quotx * FLT_EPSILON);
    CU_ASSERT_DOUBLE_EQUAL(quot.y, quoty, quoty * FLT_EPSILON);
}
