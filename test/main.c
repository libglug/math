#include <CUnit/Basic.h>

extern CU_pSuite (create_vec2_suite)(void);
extern CU_pSuite (create_vec3_suite)(void);

#define CREATE_SUITE(create_suite) if (!create_suite()) return CUEA_FAIL;

static int add_suites(void);

int main()
{
    /* initialize the CUnit test registry */
    if (CU_initialize_registry() != CUE_SUCCESS)
        return CU_get_error();

    /* add suites to the registry */
    if (add_suites() != CUE_SUCCESS)
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

int add_suites()
{
    CREATE_SUITE(create_vec2_suite);
    CREATE_SUITE(create_vec3_suite);

    return CUE_SUCCESS;
}
