#include <stdio.h>
#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>
#include <glug/math/vec3.h>

#include <float.h>

static struct glug_vec3 v3 = { .x = 0, .y = 0, .z = 0};

void test_set(void)
{
    float x, y, z;
    x = 5.f;
    y = 6.f;
    z = 7.f;
    glug_vec3_set(&v3, x, y, z);

    CU_ASSERT_DOUBLE_EQUAL(v3.x, x, x * FLT_EPSILON);
    CU_ASSERT_DOUBLE_EQUAL(v3.y, y, y * FLT_EPSILON);
    CU_ASSERT_DOUBLE_EQUAL(v3.z, z, z * FLT_EPSILON);
}

void test_copy(void)
{
    struct glug_vec3 v1 = { .x = 0, .y = 0, .z = 0};
    struct glug_vec3 v2 = { .x = 4, .y = 5, .z = 10};

    glug_vec3_copy(&v1, &v2);

    CU_ASSERT_DOUBLE_EQUAL(v1.x, v2.x, v2.x * FLT_EPSILON);
    CU_ASSERT_DOUBLE_EQUAL(v1.y, v2.y, v2.y * FLT_EPSILON);
    CU_ASSERT_DOUBLE_EQUAL(v1.z, v2.z, v2.z * FLT_EPSILON);
}

int main()
{
   CU_pSuite pSuite = NULL;

   /* initialize the CUnit test registry */
   if (CUE_SUCCESS != CU_initialize_registry())
      return CU_get_error();

   /* add a suite to the registry */
   pSuite = CU_add_suite("Suite_1", NULL, NULL);
   if (NULL == pSuite) {
      CU_cleanup_registry();
      return CU_get_error();
   }

   /* add the tests to the suite */
   if ((NULL == CU_add_test(pSuite, "test vec3 set", test_set)) ||
        NULL == CU_add_test(pSuite, "test vec3 copy", test_copy))
   {
      CU_cleanup_registry();
      return CU_get_error();
   }

   /* Run all tests using the console interface */
   CU_basic_set_mode(CU_BRM_VERBOSE);
   CU_basic_run_tests();
   CU_cleanup_registry();
   return CU_get_error();
}
