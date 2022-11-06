#ifndef GLUG_VEC4_H
#define GLUG_VEC4_H

#include <glug/extern.h>
#include <glug/import.h>
#include <glug/bool_t.h>

#include <glug/math/vec4_t.h>

GLUG_EXTERN_START

GLUG_LIB_API void  glug_vec4_set(struct glug_vec4 *dst, float x, float y, float z, float w);
GLUG_LIB_API glug_bool_t glug_vec4_equal(const struct glug_vec4 *a, const struct glug_vec4 *b);

GLUG_LIB_API struct glug_vec4 glug_vec4_sum(const struct glug_vec4 *a, const struct glug_vec4 *b);
GLUG_LIB_API struct glug_vec4 glug_vec4_diff(const struct glug_vec4 *a, const struct glug_vec4 *b);
GLUG_LIB_API struct glug_vec4 glug_vec4_prod(const struct glug_vec4 *v, float scalar);
GLUG_LIB_API struct glug_vec4 glug_vec4_quot(const struct glug_vec4 *v, float scalar);

GLUG_LIB_API void  glug_vec4_add(struct glug_vec4 *dst, const struct glug_vec4 *b);
GLUG_LIB_API void  glug_vec4_sub(struct glug_vec4 *dst, const struct glug_vec4 *b);
GLUG_LIB_API void  glug_vec4_mul(struct glug_vec4 *dst, float scalar);
GLUG_LIB_API void  glug_vec4_div(struct glug_vec4 *dst, float scalar);

GLUG_LIB_API struct glug_vec4 glug_vec4_max(const struct glug_vec4 *a, const struct glug_vec4 *b);
GLUG_LIB_API struct glug_vec4 glug_vec4_min(const struct glug_vec4 *a, const struct glug_vec4 *b);
GLUG_LIB_API struct glug_vec4 glug_vec4_clamped(const struct glug_vec4 *a, const struct glug_vec4 *min, const struct glug_vec4 *max);

GLUG_LIB_API void glug_vec4_maximize(struct glug_vec4 *dst, const struct glug_vec4 *b);
GLUG_LIB_API void glug_vec4_minimize(struct glug_vec4 *dst, const struct glug_vec4 *b);
GLUG_LIB_API void glug_vec4_clamp(struct glug_vec4 *dst, const struct glug_vec4 *min, const struct glug_vec4 *max);

GLUG_LIB_API float glug_vec4_dot(const struct glug_vec4 *a, const struct glug_vec4 *b);

GLUG_LIB_API float glug_vec4_len(const struct glug_vec4 *v);
GLUG_LIB_API float glug_vec4_len_squared(const struct glug_vec4 *v);
GLUG_LIB_API float glug_vec4_len_taxi(const struct glug_vec4 *v);
GLUG_LIB_API void  glug_vec4_set_len(struct glug_vec4 *v, float length);

GLUG_LIB_API glug_bool_t glug_vec4_is_normal(const struct glug_vec4 *v);
GLUG_LIB_API struct glug_vec4 glug_vec4_normal(const struct glug_vec4 *v);
GLUG_LIB_API void  glug_vec4_normalize(struct glug_vec4 *v);

GLUG_LIB_API float glug_vec4_dist(const struct glug_vec4 *a, const struct glug_vec4 *b);
GLUG_LIB_API float glug_vec4_dist_squared(const struct glug_vec4 *a, const struct glug_vec4 *b);
GLUG_LIB_API float glug_vec4_dist_taxi(const struct glug_vec4 *a, const struct glug_vec4 *b);

GLUG_LIB_API float glug_vec4_angle_btw(const struct glug_vec4 *a, const struct glug_vec4 *b);

GLUG_LIB_API struct glug_vec4 glug_vec4_projection(const struct glug_vec4 *a, const struct glug_vec4 *b);
GLUG_LIB_API struct glug_vec4 glug_vec4_rejection(const struct glug_vec4 *a, const struct glug_vec4 *b);
GLUG_LIB_API struct glug_vec4 glug_vec4_reflection(const struct glug_vec4 *a, const struct glug_vec4 *b);
GLUG_LIB_API struct glug_vec4 glug_vec4_refraction(const struct glug_vec4 *inc, const struct glug_vec4 *n, float incidx, float tranidx);

GLUG_LIB_API void glug_vec4_project(struct glug_vec4 *dst, const struct glug_vec4 *b);
GLUG_LIB_API void glug_vec4_reject(struct glug_vec4 *dst, const struct glug_vec4 *b);
GLUG_LIB_API void glug_vec4_reflect(struct glug_vec4 *dst, const struct glug_vec4 *b);
GLUG_LIB_API void glug_vec4_refract(struct glug_vec4 *dst, const struct glug_vec4 *n, float incidx, float tranidx);

GLUG_EXTERN_END

#endif // GLUG_VEC4_H
