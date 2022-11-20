#ifndef GLUG_VEC3_H
#define GLUG_VEC3_H

#include <glug/extern.h>
#include <glug/import.h>
#include <glug/bool_t.h>

#include <glug/math/vec3_t.h>

GLUG_EXTERN_START

GLUG_LIB_API glug_bool_t glug_vec3_equal(const struct glug_vec3 *v1, const struct glug_vec3 *v2);

GLUG_LIB_API void glug_vec3_add(struct glug_vec3 *dst, const struct glug_vec3 *v2);
GLUG_LIB_API void glug_vec3_sub(struct glug_vec3 *dst, const struct glug_vec3 *v2);
GLUG_LIB_API void glug_vec3_mul(struct glug_vec3 *dst, float scalar);
GLUG_LIB_API void glug_vec3_div(struct glug_vec3 *dst, float scalar);

GLUG_LIB_API void glug_vec3_max(struct glug_vec3 *dst, const struct glug_vec3 *v2);
GLUG_LIB_API void glug_vec3_min(struct glug_vec3 *dst, const struct glug_vec3 *v2);
GLUG_LIB_API void glug_vec3_clamp(struct glug_vec3 *dst, const struct glug_vec3 *min, const struct glug_vec3 *max);

GLUG_LIB_API float glug_vec3_dot(const struct glug_vec3 *v1, const struct glug_vec3 *v2);
GLUG_LIB_API void glug_vec3_cross(struct glug_vec3 *dst, const struct glug_vec3 *v1, const struct glug_vec3 *v2);

GLUG_LIB_API float glug_vec3_len(const struct glug_vec3 *v);
GLUG_LIB_API float glug_vec3_len_squared(const struct glug_vec3 *v);
GLUG_LIB_API float glug_vec3_len_taxi(const struct glug_vec3 *v);
GLUG_LIB_API void  glug_vec3_set_len(struct glug_vec3 *dst, float length);

GLUG_LIB_API glug_bool_t glug_vec3_is_normal(const struct glug_vec3 *v);
GLUG_LIB_API void  glug_vec3_normalize(struct glug_vec3 *v);

GLUG_LIB_API float glug_vec3_dist(const struct glug_vec3 *v1, const struct glug_vec3 *v2);
GLUG_LIB_API float glug_vec3_dist_squared(const struct glug_vec3 *v1, const struct glug_vec3 *v2);
GLUG_LIB_API float glug_vec3_dist_taxi(const struct glug_vec3 *v1, const struct glug_vec3 *v2);

GLUG_LIB_API float glug_vec3_angle_btw(const struct glug_vec3 *v1, const struct glug_vec3 *v2);

GLUG_LIB_API void glug_vec3_project(struct glug_vec3 *dst, const struct glug_vec3 *v2);
GLUG_LIB_API void glug_vec3_reject(struct glug_vec3 *dst, const struct glug_vec3 *v2);
GLUG_LIB_API void glug_vec3_reflect(struct glug_vec3 *dst, const struct glug_vec3 *v2);
GLUG_LIB_API void glug_vec3_refract(struct glug_vec3 *dst, const struct glug_vec3 *n, float incidx, float tranidx);

GLUG_EXTERN_END

#endif // GLUG_VEC3_H
