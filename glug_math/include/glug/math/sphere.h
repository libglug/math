#ifndef GLUG_SPHERE_H
#define GLUG_SPHERE_H

#include <glug/import.h>
#include <glug/math/sphere_t.h>

void GLUG_LIB_API glug_sphere_set(struct glug_sphere *dst, const struct glug_vec3 *c, float r);
void GLUG_LIB_API glug_sphere_copy(struct glug_sphere *dst, const struct glug_sphere *src);
int  GLUG_LIB_API glug_sphere_equal(const struct glug_sphere *a, const struct glug_sphere *b);

int  GLUG_LIB_API glug_sphere_contains_point(const struct glug_sphere *cir, const struct glug_vec3 *p);
struct glug_sphere GLUG_LIB_API glug_sphere_expansion(const struct glug_sphere *c, const struct glug_vec3 *p);
void GLUG_LIB_API glug_sphere_expand_to(struct glug_sphere *dst, const struct glug_vec3 *p);

int GLUG_LIB_API glug_sphere_intersects_sphere(const struct glug_sphere *a, const struct glug_sphere *b);
struct glug_sphere GLUG_LIB_API glug_sphere_union(const struct glug_sphere *a, const struct glug_sphere *b);
void GLUG_LIB_API glug_sphere_unionize(struct glug_sphere *dst, const struct glug_sphere *b);

// TODO: move out of the sphere header
struct glug_vec3 GLUG_LIB_API glug_sphere_clamped_point(const struct glug_sphere *c, const struct glug_vec3 *p);
void GLUG_LIB_API glug_sphere_clamp_point(const struct glug_sphere *c, struct glug_vec3 *dst);

#endif // GLUG_SPHERE_H
