#ifndef GLUG_VEC3_H
#define GLUG_VEC3_H

#include <glug/import.h>
#include <glug/math/vec3_t.h>

GLUG_LIB_API void  glug_vec3_set(struct glug_vec3 *dst, float x, float y, float z);
GLUG_LIB_API int   glug_vec3_equal(const struct glug_vec3 *a, const struct glug_vec3 *b);

GLUG_LIB_API struct glug_vec3 glug_vec3_sum (const struct glug_vec3 *a, const struct glug_vec3 *b);
GLUG_LIB_API struct glug_vec3 glug_vec3_diff(const struct glug_vec3 *a, const struct glug_vec3 *b);
GLUG_LIB_API struct glug_vec3 glug_vec3_prod(const struct glug_vec3 *v, float scalar);
GLUG_LIB_API struct glug_vec3 glug_vec3_quot(const struct glug_vec3 *v, float scalar);

GLUG_LIB_API void  glug_vec3_add(struct glug_vec3 *dst, const struct glug_vec3 *b);
GLUG_LIB_API void  glug_vec3_sub(struct glug_vec3 *dst, const struct glug_vec3 *b);
GLUG_LIB_API void  glug_vec3_mul(struct glug_vec3 *dst, float scalar);
GLUG_LIB_API void  glug_vec3_div(struct glug_vec3 *dst, float scalar);

GLUG_LIB_API struct glug_vec3 glug_vec3_max(const struct glug_vec3 *a, const struct glug_vec3 *b);
GLUG_LIB_API struct glug_vec3 glug_vec3_min(const struct glug_vec3 *a, const struct glug_vec3 *b);
GLUG_LIB_API struct glug_vec3 glug_vec3_clamped(const struct glug_vec3 *a, const struct glug_vec3 *min, const struct glug_vec3 *max);

GLUG_LIB_API void glug_vec3_maximize(struct glug_vec3 *dst, const struct glug_vec3 *b);
GLUG_LIB_API void glug_vec3_minimize(struct glug_vec3 *dst, const struct glug_vec3 *b);
GLUG_LIB_API void glug_vec3_clamp(struct glug_vec3 *dst, const struct glug_vec3 *min, const struct glug_vec3 *max);

GLUG_LIB_API float glug_vec3_dot(const struct glug_vec3 *v, const struct glug_vec3 *b);
GLUG_LIB_API struct glug_vec3 glug_vec3_cross(const struct glug_vec3 *a, const struct glug_vec3 *b);

GLUG_LIB_API float glug_vec3_len(const struct glug_vec3 *v);
GLUG_LIB_API float glug_vec3_len_squared(const struct glug_vec3 *v);
GLUG_LIB_API float glug_vec3_len_manhattan(const struct glug_vec3 *v);
GLUG_LIB_API void  glug_vec3_set_len(struct glug_vec3 *dst, float length);

GLUG_LIB_API int   glug_vec3_is_normal(const struct glug_vec3 *v);
GLUG_LIB_API struct glug_vec3 glug_vec3_normal(const struct glug_vec3 *v);
GLUG_LIB_API void  glug_vec3_normalize(struct glug_vec3 *v);

GLUG_LIB_API float glug_vec3_dist(const struct glug_vec3 *a, const struct glug_vec3 *b);
GLUG_LIB_API float glug_vec3_dist_squared(const struct glug_vec3 *a, const struct glug_vec3 *b);
GLUG_LIB_API float glug_vec3_dist_manhattan(const struct glug_vec3 *a, const struct glug_vec3 *b);

GLUG_LIB_API float glug_vec3_angle_btw(const struct glug_vec3 *a, const struct glug_vec3 *b);

GLUG_LIB_API struct glug_vec3 glug_vec3_projection(const struct glug_vec3 *a, const struct glug_vec3 *b);
GLUG_LIB_API struct glug_vec3 glug_vec3_rejection(const struct glug_vec3 *a, const struct glug_vec3 *b);
GLUG_LIB_API struct glug_vec3 glug_vec3_reflection(const struct glug_vec3 *a, const struct glug_vec3 *b);
GLUG_LIB_API struct glug_vec3 glug_vec3_refraction(const struct glug_vec3 *inc, const struct glug_vec3 *n, float incidx, float tranidx);

GLUG_LIB_API void glug_vec3_project(struct glug_vec3 *dst, const struct glug_vec3 *b);
GLUG_LIB_API void glug_vec3_reject(struct glug_vec3 *dst, const struct glug_vec3 *b);
GLUG_LIB_API void glug_vec3_reflect(struct glug_vec3 *dst, const struct glug_vec3 *b);
GLUG_LIB_API void glug_vec3_refract(struct glug_vec3 *dst, const struct glug_vec3 *n, float incidx, float tranidx);

#endif // GLUG_VEC3_H
