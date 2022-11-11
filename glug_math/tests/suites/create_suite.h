#ifndef CREATE_SUITE_H
#define CREATE_SUITE_H

#include <CUnit/Basic.h>

#define ADD_TEST(suite, name) CU_add_test((suite), (#name), (test_##name));

CU_pSuite create_suite(char *suite_name, CU_SetUpFunc before_each, CU_TearDownFunc after_each);
int run_tests(CU_BasicRunMode run_mode);

#endif // CREATE_SUITE_H
