#ifndef GLUG_MAT2_H
#define GLUG_MAT2_H

#include <glug/import.h>
#include <glug/math/mat2_t.h>
#include <glug/math/vec2_t.h>

#include <stddef.h>

struct glug_mat2 GLUG_LIB_API glug_mat2_identity();
void GLUG_LIB_API glug_mat2_to_identity(struct glug_mat2 *dst);

void GLUG_LIB_API glug_mat2_set(struct glug_mat2 *dst, float e00, float e01, float e10, float e11);
int  GLUG_LIB_API glug_mat2_equal(const struct glug_mat2 *a, const struct glug_mat2 *b);

struct glug_mat2 GLUG_LIB_API glug_mat2_sum(const struct glug_mat2 *a, const struct glug_mat2 *b);
struct glug_mat2 GLUG_LIB_API glug_mat2_diff(const struct glug_mat2 *a, const struct glug_mat2 *b);
struct glug_mat2 GLUG_LIB_API glug_mat2_prod(const struct glug_mat2 *m, float scalar);
struct glug_mat2 GLUG_LIB_API glug_mat2_quot(const struct glug_mat2 *m, float scalar);
struct glug_mat2 GLUG_LIB_API glug_mat2_prodm(const struct glug_mat2 *a, const struct glug_mat2 *b);

void GLUG_LIB_API glug_mat2_add(struct glug_mat2 *dst, const struct glug_mat2 *b);
void GLUG_LIB_API glug_mat2_sub(struct glug_mat2 *dst, const struct glug_mat2 *b);
void GLUG_LIB_API glug_mat2_mul(struct glug_mat2 *dst, float scalar);
void GLUG_LIB_API glug_mat2_div(struct glug_mat2 *dst, float scalar);
void GLUG_LIB_API glug_mat2_premulm(struct glug_mat2 *dst, const struct glug_mat2 *b);
void GLUG_LIB_API glug_mat2_postmulm(struct glug_mat2 *dst, const struct glug_mat2 *b);

float  GLUG_LIB_API *glug_mat2_elements();
size_t GLUG_LIB_API  glug_mat2_nelements();

float GLUG_LIB_API glug_mat2_determinant(const struct glug_mat2 *m);
struct glug_mat2 GLUG_LIB_API glug_mat2_get_transpose(const struct glug_mat2 *m);
void GLUG_LIB_API glug_mat2_transpose(struct glug_mat2 *dst);
struct glug_mat2 GLUG_LIB_API glug_mat2_inverse(const struct glug_mat2 *m);
void GLUG_LIB_API glug_mat2_invert(struct glug_mat2 *dst);

struct glug_vec2 GLUG_LIB_API glug_mat2_prodv(const struct glug_mat2 *m, const struct glug_vec2 *v);
void GLUG_LIB_API glug_mat2_mulv(const struct glug_mat2 *m, struct glug_vec2 *dst);

#endif // GLUG_MAT2_H
