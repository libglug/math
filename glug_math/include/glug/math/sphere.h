#ifndef GLUG_SPHERE_H
#define GLUG_SPHERE_H

#include <glug/import.h>
#include <glug/bool_t.h>
#include <glug/math/sphere_t.h>

GLUG_LIB_API void glug_sphere_set(struct glug_sphere *dst, const struct glug_vec3 *c, float r);
GLUG_LIB_API glug_bool_t glug_sphere_equal(const struct glug_sphere *a, const struct glug_sphere *b);

GLUG_LIB_API glug_bool_t glug_sphere_contains_point(const struct glug_sphere *cir, const struct glug_vec3 *p);
GLUG_LIB_API struct glug_sphere glug_sphere_expansion(const struct glug_sphere *c, const struct glug_vec3 *p);
GLUG_LIB_API void glug_sphere_expand_to(struct glug_sphere *dst, const struct glug_vec3 *p);

GLUG_LIB_API glug_bool_t glug_sphere_intersects_sphere(const struct glug_sphere *a, const struct glug_sphere *b);
GLUG_LIB_API struct glug_sphere glug_sphere_union(const struct glug_sphere *a, const struct glug_sphere *b);
GLUG_LIB_API void glug_sphere_unionize(struct glug_sphere *dst, const struct glug_sphere *b);

// TODO: move out of the sphere header
GLUG_LIB_API struct glug_vec3 glug_sphere_clamped_point(const struct glug_sphere *c, const struct glug_vec3 *p);
GLUG_LIB_API void glug_sphere_clamp_point(const struct glug_sphere *c, struct glug_vec3 *dst);

#endif // GLUG_SPHERE_H
