#ifndef GLUG_ASSERTS_H
#define GLUG_ASSERTS_H

void ASSERT_MAT2_EQUAL(struct glug_mat2 *m1, struct glug_mat2 *m2, float delta);
void ASSERT_VEC2_EQUAL(struct glug_vec2 *v1, struct glug_vec2 *v2, float delta);

#endif // GLUG_ASSERTS_H
