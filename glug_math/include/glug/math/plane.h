#ifndef GLUG_PLANE_H
#define GLUG_PLANE_H

#include <glug/extern.h>
#include <glug/import.h>
#include <glug/bool_t.h>

#include <glug/math/plane_t.h>

GLUG_EXTERN_START

GLUG_LIB_API void glug_plane_from_points(struct glug_plane *dst, const struct glug_vec3 *a, const struct glug_vec3 *b, const struct glug_vec3 *c);
GLUG_LIB_API void glug_plane_from_normal(struct glug_plane *dst, const struct glug_vec3 *n, const struct glug_vec3 *p);

GLUG_LIB_API glug_bool_t glug_plane_equal(const struct glug_plane *a, const struct glug_plane *b);

GLUG_LIB_API void glug_plane_normalize(struct glug_plane *dst);

GLUG_LIB_API float glug_plane_distance_to_point(const struct glug_plane *p, const struct glug_vec3 *r);
GLUG_LIB_API glug_bool_t glug_plane_contains_point(const struct glug_plane *p, const struct glug_vec3 *r);
GLUG_LIB_API void glug_plane_project_point(const struct glug_plane *p, struct glug_vec3 *dst);

GLUG_EXTERN_END

#endif // GLUG_PLANE_H
