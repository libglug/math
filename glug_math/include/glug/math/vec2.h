#ifndef GLUG_VEC2_H
#define GLUG_VEC2_H

#include <glug/import.h>
#include <glug/bool_t.h>
#include <glug/math/vec2_t.h>

GLUG_LIB_API void  glug_vec2_set(struct glug_vec2 *dst, float x, float y);
GLUG_LIB_API glug_bool_t glug_vec2_equal(const struct glug_vec2 *a, const struct glug_vec2 *b);

GLUG_LIB_API struct glug_vec2 glug_vec2_sum(const struct glug_vec2 *a, const struct glug_vec2 *b);
GLUG_LIB_API struct glug_vec2 glug_vec2_diff(const struct glug_vec2 *a, const struct glug_vec2 *b);
GLUG_LIB_API struct glug_vec2 glug_vec2_prod(const struct glug_vec2 *v, float scalar);
GLUG_LIB_API struct glug_vec2 glug_vec2_quot(const struct glug_vec2 *v, float scalar);

GLUG_LIB_API void glug_vec2_add(struct glug_vec2 *dst, const struct glug_vec2 *b);
GLUG_LIB_API void glug_vec2_sub(struct glug_vec2 *dst, const struct glug_vec2 *b);
GLUG_LIB_API void glug_vec2_mul(struct glug_vec2 *dst, float scalar);
GLUG_LIB_API void glug_vec2_div(struct glug_vec2 *dst, float scalar);

GLUG_LIB_API struct glug_vec2 glug_vec2_max(const struct glug_vec2 *a, const struct glug_vec2 *b);
GLUG_LIB_API struct glug_vec2 glug_vec2_min(const struct glug_vec2 *a, const struct glug_vec2 *b);
GLUG_LIB_API struct glug_vec2 glug_vec2_clamped(const struct glug_vec2 *a, const struct glug_vec2 *min, const struct glug_vec2 *max);

GLUG_LIB_API void glug_vec2_maximize(struct glug_vec2 *dst, const struct glug_vec2 *b);
GLUG_LIB_API void glug_vec2_minimize(struct glug_vec2 *dst, const struct glug_vec2 *b);
GLUG_LIB_API void glug_vec2_clamp(struct glug_vec2 *dst, const struct glug_vec2 *min, const struct glug_vec2 *max);

GLUG_LIB_API float glug_vec2_dot(const struct glug_vec2 *v, const struct glug_vec2 *b);

GLUG_LIB_API float glug_vec2_len(const struct glug_vec2 *v);
GLUG_LIB_API float glug_vec2_len_squared(const struct glug_vec2 *v);
GLUG_LIB_API float glug_vec2_len_manhattan(const struct glug_vec2 *v);
GLUG_LIB_API void  glug_vec2_set_len(struct glug_vec2 *v, float length);

GLUG_LIB_API glug_bool_t glug_vec2_is_normal(const struct glug_vec2 *v);
GLUG_LIB_API struct glug_vec2 glug_vec2_normal(const struct glug_vec2 *v);
GLUG_LIB_API void  glug_vec2_normalize(struct glug_vec2 *v);

GLUG_LIB_API float glug_vec2_dist(const struct glug_vec2 *a, const struct glug_vec2 *b);
GLUG_LIB_API float glug_vec2_dist_squared(const struct glug_vec2 *a, const struct glug_vec2 *b);
GLUG_LIB_API float glug_vec2_dist_manhattan(const struct glug_vec2 *a, const struct glug_vec2 *b);

GLUG_LIB_API float glug_vec2_angle_btw(const struct glug_vec2 *a, const struct glug_vec2 *b);

GLUG_LIB_API struct glug_vec2 glug_vec2_projection(const struct glug_vec2 *a, const struct glug_vec2 *b);
GLUG_LIB_API struct glug_vec2 glug_vec2_rejection(const struct glug_vec2 *a, const struct glug_vec2 *b);
GLUG_LIB_API struct glug_vec2 glug_vec2_reflection(const struct glug_vec2 *a, const struct glug_vec2 *b);
GLUG_LIB_API struct glug_vec2 glug_vec2_refraction(const struct glug_vec2 *inc, const struct glug_vec2 *n, float incidx, float tranidx);

GLUG_LIB_API void glug_vec2_project(struct glug_vec2 *a, const struct glug_vec2 *b);
GLUG_LIB_API void glug_vec2_reject(struct glug_vec2 *a, const struct glug_vec2 *b);
GLUG_LIB_API void glug_vec2_reflect(struct glug_vec2 *a, const struct glug_vec2 *b);
GLUG_LIB_API void glug_vec2_refract(struct glug_vec2 *dst, const struct glug_vec2 *n, float incidx, float tranidx);

#endif // GLUG_VEC2_H
