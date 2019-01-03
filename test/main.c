#include <CUnit/Basic.h>

extern CU_pSuite (create_box_suite)(void);
extern CU_pSuite (create_circ_suite)(void);
extern CU_pSuite (create_plane_suite)(void);
extern CU_pSuite (create_rect_suite)(void);
extern CU_pSuite (create_sphr_suite)(void);
extern CU_pSuite (create_vec2_suite)(void);
extern CU_pSuite (create_vec3_suite)(void);
extern CU_pSuite (create_vec4_suite)(void);

#define CREATE_SUITE(create_suite) if (!create_suite()) return CU_get_error();

static int add_suites(void);

int main()
{
    unsigned int failures;
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
    if (CU_basic_run_tests() != CUE_SUCCESS)
    {
        CU_cleanup_registry();
        return CU_get_error();
    }

    failures = CU_get_number_of_tests_failed();
    CU_cleanup_registry();
    return (int)failures;
}

int add_suites()
{
    CREATE_SUITE(create_box_suite);
    CREATE_SUITE(create_circ_suite);
    CREATE_SUITE(create_plane_suite);
    CREATE_SUITE(create_rect_suite);
    CREATE_SUITE(create_sphr_suite);
    CREATE_SUITE(create_vec2_suite);
    CREATE_SUITE(create_vec3_suite);
    CREATE_SUITE(create_vec4_suite);

    return CUE_SUCCESS;
}
