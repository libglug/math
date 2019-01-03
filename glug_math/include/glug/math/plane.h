#ifndef GLUG_PLANE_H
#define GLUG_PLANE_H

#include <glug/import.h>
#include <glug/math/plane_t.h>

struct glug_plane GLUG_LIB_API glug_plane_from_points(const struct glug_vec3 *a, const struct glug_vec3 *b, const struct glug_vec3 *c);
struct glug_plane GLUG_LIB_API glug_plane_from_normal(const struct glug_vec3 *n, const struct glug_vec3 *r);

void GLUG_LIB_API glug_plane_set_by_points(struct glug_plane *dst, const struct glug_vec3 *a, const struct glug_vec3 *b, const struct glug_vec3 *c);
void GLUG_LIB_API glug_plane_set_by_normal(struct glug_plane *dst, const struct glug_vec3 *n, const struct glug_vec3 *r);

void GLUG_LIB_API glug_plane_set(struct glug_plane *dst, const struct glug_vec3 *n, float d);
void GLUG_LIB_API glug_plane_copy(struct glug_plane *dst, const struct glug_plane *src);
int  GLUG_LIB_API glug_plane_equal(const struct glug_plane *a, const struct glug_plane *b);

int GLUG_LIB_API glug_plane_contains_point(const struct glug_plane *p, const struct glug_vec3 *r);
struct glug_vec3 GLUG_LIB_API glug_plane_closest_point(const struct glug_plane *p, const struct glug_vec3 *r);
void GLUG_LIB_API glug_plane_project_point(const struct glug_plane *p, struct glug_vec3 *dst);

#endif // GLUG_PLANE_H
