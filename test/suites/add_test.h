#define ADD_TEST(suite, name) if(!CU_add_test((suite), (#name), (test_##name))) return NULL;
