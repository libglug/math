#include <CUnit/Basic.h>

#define ADD_TEST(suite, name) CU_add_test((suite), (#name), (test_##name));
