#include <CUnit/Assert.h>
#include <CUnit/Basic.h>
#include <glug/math/vec3.h>

#include <float.h>

#define ADD_TEST(add_test, suite, name, fcn) if (!add_test((suite), (name), (fcn))) return NULL;

static void test_set(void);
static void test_copy(void);
static void test_sum(void);
static void test_diff(void);
static void test_prod(void);
static void test_quot(void);

CU_pSuite create_vec3_suite()
{
    CU_pSuite vec3_suite = CU_add_suite("vec3f", NULL, NULL);
    if (!vec3_suite) return NULL;

    ADD_TEST(CU_add_test, vec3_suite, "set", test_set);
    ADD_TEST(CU_add_test, vec3_suite, "copy", test_copy);
    ADD_TEST(CU_add_test, vec3_suite, "sum", test_sum);
    ADD_TEST(CU_add_test, vec3_suite, "diff", test_diff);
    ADD_TEST(CU_add_test, vec3_suite, "prod", test_prod);
    ADD_TEST(CU_add_test, vec3_suite, "quot", test_quot);

    return vec3_suite;
}

void test_set(void)
{
    struct glug_vec3 v3 = { .x = 0, .y = 0, .z = 0 };
    float x = 5.f, y = 6.f, z = 7.f;
    glug_vec3_set(&v3, x, y, z);

    CU_ASSERT_DOUBLE_EQUAL(v3.x, x, x * FLT_EPSILON);
    CU_ASSERT_DOUBLE_EQUAL(v3.y, y, y * FLT_EPSILON);
    CU_ASSERT_DOUBLE_EQUAL(v3.z, z, z * FLT_EPSILON);
}

void test_copy(void)
{
    struct glug_vec3 v1 = { .x = 0, .y = 0, .z = 0 };
    struct glug_vec3 v2 = { .x = 4.f, .y = 5.f, .z = 10.f };
    glug_vec3_copy(&v1, &v2);

    CU_ASSERT_DOUBLE_EQUAL(v1.x, v2.x, v2.x * FLT_EPSILON);
    CU_ASSERT_DOUBLE_EQUAL(v1.y, v2.y, v2.y * FLT_EPSILON);
    CU_ASSERT_DOUBLE_EQUAL(v1.z, v2.z, v2.z * FLT_EPSILON);
}

void test_sum(void)
{
    struct glug_vec3 v1 = { .x = 1.0f, .y = 8.9f, .z = 10.f };
    struct glug_vec3 v2 = { .x = -1.01f, .y = -5.5f, .z = 19.1f };
    struct glug_vec3 sum = glug_vec3_sum(&v1, &v2);

    float sumx = v1.x + v2.x;
    float sumy = v1.y + v2.y;
    float sumz = v1.z + v2.z;

    CU_ASSERT_DOUBLE_EQUAL(sum.x, sumx, sumx * FLT_EPSILON);
    CU_ASSERT_DOUBLE_EQUAL(sum.y, sumy, sumy * FLT_EPSILON);
    CU_ASSERT_DOUBLE_EQUAL(sum.z, sumz, sumz * FLT_EPSILON);
}

void test_diff(void)
{
    struct glug_vec3 v1 = { .x = 17.17f, .y = 19.8f, .z = 79.f };
    struct glug_vec3 v2 = { .x = 8.f, .y = 9.f, .z = 18.697f };
    struct glug_vec3 diff = glug_vec3_diff(&v1, &v2);

    float diffx = v1.x - v2.x;
    float diffy = v1.y - v2.y;
    float diffz = v1.z - v2.z;

    CU_ASSERT_DOUBLE_EQUAL(diff.x, diffx, diffx * FLT_EPSILON);
    CU_ASSERT_DOUBLE_EQUAL(diff.y, diffy, diffy * FLT_EPSILON);
    CU_ASSERT_DOUBLE_EQUAL(diff.z, diffz, diffz * FLT_EPSILON);
}

void test_prod(void)
{
    struct glug_vec3 v = { .x = 4.f, .y = 5.f, .z = 10.f };
    float scalar = 4.1f;
    struct glug_vec3 prod = glug_vec3_prod(&v, scalar);

    float prodx = v.x * scalar;
    float prody = v.y * scalar;
    float prodz = v.z * scalar;

    CU_ASSERT_DOUBLE_EQUAL(prod.x, prodx, prodx * FLT_EPSILON);
    CU_ASSERT_DOUBLE_EQUAL(prod.y, prody, prody * FLT_EPSILON);
    CU_ASSERT_DOUBLE_EQUAL(prod.z, prodz, prodz * FLT_EPSILON);
}

void test_quot(void)
{
    struct glug_vec3 v = { .x = 3.142f, .y = 2.718f, .z = 1.618f };
    float scalar = 1.414f;
    struct glug_vec3 quot = glug_vec3_quot(&v, scalar);

    float quotx = v.x / scalar;
    float quoty = v.y / scalar;
    float quotz = v.z / scalar;

    CU_ASSERT_DOUBLE_EQUAL(quot.x, quotx, quotx * FLT_EPSILON);
    CU_ASSERT_DOUBLE_EQUAL(quot.y, quoty, quoty * FLT_EPSILON);
    CU_ASSERT_DOUBLE_EQUAL(quot.z, quotz, quotz * FLT_EPSILON);
}
