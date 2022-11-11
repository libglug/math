#ifndef GLUG_MAT2_H
#define GLUG_MAT2_H

#include <stddef.h>

#include <glug/extern.h>
#include <glug/import.h>
#include <glug/bool_t.h>

#include <glug/math/mat2_t.h>
#include <glug/math/vec2_t.h>

GLUG_EXTERN_START

GLUG_LIB_API void glug_mat2_identity(struct glug_mat2 *dst);

GLUG_LIB_API glug_bool_t glug_mat2_equal(const struct glug_mat2 *m1, const struct glug_mat2 *m2);

GLUG_LIB_API void glug_mat2_add(struct glug_mat2 *dst, const struct glug_mat2 *m2);
GLUG_LIB_API void glug_mat2_sub(struct glug_mat2 *dst, const struct glug_mat2 *m2);
GLUG_LIB_API void glug_mat2_mul(struct glug_mat2 *dst, float scalar);
GLUG_LIB_API void glug_mat2_div(struct glug_mat2 *dst, float scalar);
GLUG_LIB_API void glug_mat2_premulm(struct glug_mat2 *dst, const struct glug_mat2 *m2);
GLUG_LIB_API void glug_mat2_postmulm(struct glug_mat2 *dst, const struct glug_mat2 *m2);

float  GLUG_LIB_API *glug_mat2_elements();
size_t GLUG_LIB_API  glug_mat2_nelements();

GLUG_LIB_API float glug_mat2_determinant(const struct glug_mat2 *m);
GLUG_LIB_API void glug_mat2_transpose(struct glug_mat2 *dst);
GLUG_LIB_API void glug_mat2_invert(struct glug_mat2 *dst);

GLUG_LIB_API void glug_mat2_mulv(const struct glug_mat2 *m, struct glug_vec2 *dst);

GLUG_EXTERN_END

#endif // GLUG_MAT2_H
