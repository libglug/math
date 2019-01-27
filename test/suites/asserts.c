#include <CUnit/Assert.h>
#include <glug/math/mat2_t.h>
#include <glug/math/vec2_t.h>

void ASSERT_MAT2_EQUAL(struct glug_mat2 *m1, struct glug_mat2 *m2, float delta)
{
    CU_ASSERT_DOUBLE_EQUAL(m1->els[0][0], m2->els[0][0], delta);
    CU_ASSERT_DOUBLE_EQUAL(m1->els[0][1], m2->els[0][1], delta);
    CU_ASSERT_DOUBLE_EQUAL(m1->els[1][0], m2->els[1][0], delta);
    CU_ASSERT_DOUBLE_EQUAL(m1->els[1][1], m2->els[1][1], delta);
}

void ASSERT_VEC2_EQUAL(struct glug_vec2 *v1, struct glug_vec2 *v2, float delta)

{
    CU_ASSERT_DOUBLE_EQUAL(v1->x, v2->x, delta);
    CU_ASSERT_DOUBLE_EQUAL(v1->y, v2->y, delta);
}
