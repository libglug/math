#ifndef GLUG_VEC2_H
#define GLUG_VEC2_H

#include <glug/extern.h>
#include <glug/import.h>
#include <glug/bool_t.h>

#include <glug/math/vec2_t.h>

GLUG_EXTERN_START

GLUG_LIB_API glug_bool_t glug_vec2_equal(const struct glug_vec2 *v1, const struct glug_vec2 *v2);

GLUG_LIB_API void glug_vec2_add(struct glug_vec2 *dst, const struct glug_vec2 *v2);
GLUG_LIB_API void glug_vec2_sub(struct glug_vec2 *dst, const struct glug_vec2 *v2);
GLUG_LIB_API void glug_vec2_mul(struct glug_vec2 *dst, float scalar);
GLUG_LIB_API void glug_vec2_div(struct glug_vec2 *dst, float scalar);

GLUG_LIB_API void glug_vec2_sign(struct glug_vec2 *dst, const struct glug_vec2 *v);
GLUG_LIB_API void glug_vec2_integral(struct glug_vec2 *dst, const struct glug_vec2 *v);
GLUG_LIB_API void glug_vec2_frac(struct glug_vec2 *dst, const struct glug_vec2 *v);

GLUG_LIB_API void glug_vec2_max(struct glug_vec2 *dst, const struct glug_vec2 *v2);
GLUG_LIB_API void glug_vec2_min(struct glug_vec2 *dst, const struct glug_vec2 *v2);
GLUG_LIB_API void glug_vec2_clamp(struct glug_vec2 *dst, const struct glug_vec2 *min, const struct glug_vec2 *max);

GLUG_LIB_API void glug_vec2_floor(struct glug_vec2 *dst, const struct glug_vec2 *v);
GLUG_LIB_API void glug_vec2_ceil(struct glug_vec2 *dst, const struct glug_vec2 *v);
GLUG_LIB_API void glug_vec2_round(struct glug_vec2 *dst, const struct glug_vec2 *v);
GLUG_LIB_API void glug_vec2_round_zero(struct glug_vec2 *dst, const struct glug_vec2 *v);

GLUG_LIB_API float glug_vec2_dot(const struct glug_vec2 *v1, const struct glug_vec2 *v2);

GLUG_LIB_API float glug_vec2_len(const struct glug_vec2 *v);
GLUG_LIB_API float glug_vec2_len_squared(const struct glug_vec2 *v);
GLUG_LIB_API float glug_vec2_len_taxi(const struct glug_vec2 *v);
GLUG_LIB_API void  glug_vec2_set_len(struct glug_vec2 *v, float length);
GLUG_LIB_API void  glug_vec2_clamp_len(struct glug_vec2 *v, float min, float max);

GLUG_LIB_API glug_bool_t glug_vec2_is_normal(const struct glug_vec2 *v);
GLUG_LIB_API void  glug_vec2_normalize(struct glug_vec2 *v);

GLUG_LIB_API float glug_vec2_dist(const struct glug_vec2 *v1, const struct glug_vec2 *v2);
GLUG_LIB_API float glug_vec2_dist_squared(const struct glug_vec2 *v1, const struct glug_vec2 *v2);
GLUG_LIB_API float glug_vec2_dist_taxi(const struct glug_vec2 *v1, const struct glug_vec2 *v2);

GLUG_LIB_API float glug_vec2_angle_btw(const struct glug_vec2 *v1, const struct glug_vec2 *v2);

GLUG_LIB_API void glug_vec2_project(struct glug_vec2 *dst, const struct glug_vec2 *v2);
GLUG_LIB_API void glug_vec2_reject(struct glug_vec2 *dst, const struct glug_vec2 *v2);
GLUG_LIB_API void glug_vec2_reflect(struct glug_vec2 *dst, const struct glug_vec2 *v2);
GLUG_LIB_API void glug_vec2_refract(struct glug_vec2 *dst, const struct glug_vec2 *n, float incidx, float tranidx);

GLUG_EXTERN_END

#endif // GLUG_VEC2_H
