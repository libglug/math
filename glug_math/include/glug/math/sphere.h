#ifndef GLUG_SPHERE_H
#define GLUG_SPHERE_H

#include <glug/extern.h>
#include <glug/import.h>
#include <glug/bool_t.h>

#include <glug/math/sphere_t.h>

GLUG_EXTERN_START

GLUG_LIB_API glug_bool_t glug_sphere_equal(const struct glug_sphere *a, const struct glug_sphere *b);

GLUG_LIB_API glug_bool_t glug_sphere_contains_point(const struct glug_sphere *s, const struct glug_vec3 *p);
GLUG_LIB_API void glug_sphere_expand_to(struct glug_sphere *dst, const struct glug_vec3 *p);
GLUG_LIB_API glug_bool_t glug_sphere_intersects_sphere(const struct glug_sphere *a, const struct glug_sphere *b);
GLUG_LIB_API void glug_sphere_union(struct glug_sphere *dst, const struct glug_sphere *b);

GLUG_LIB_API void glug_sphere_clamp_point(const struct glug_sphere *c, struct glug_vec3 *dst);

GLUG_EXTERN_END

#endif // GLUG_SPHERE_H
