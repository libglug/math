#ifndef GLUG_TRIANGLE2_H
#define GLUG_TRIANGLE2_H

#include <glug/import.h>
#include <glug/math/triangle2_t.h>
#include <glug/math/vec3_t.h>

GLUG_LIB_API void glug_triangle2_set(struct glug_triangle2 *dst, const struct glug_vec2 *a, const struct glug_vec2 *b, const struct glug_vec2 *c);
GLUG_LIB_API int  glug_triangle2_equal(const struct glug_triangle2 *a, const struct glug_triangle2 *b);

GLUG_LIB_API struct glug_vec2 glug_triangle2_barycentric(const struct glug_triangle2 *t, const struct glug_vec3 *bary);
GLUG_LIB_API struct glug_vec2 glug_triangle2_trilinear(const struct glug_triangle2 *t, const struct glug_vec3 *tril);

GLUG_LIB_API struct glug_vec3 glug_triangle2_to_barycentric(const struct glug_triangle2 *t, const struct glug_vec2 *p);
GLUG_LIB_API struct glug_vec3 glug_triangle2_to_trilinear(const struct glug_triangle2 *t, const struct glug_vec2 *p);

GLUG_LIB_API struct glug_vec2 glug_triangle2_centroid(const struct glug_triangle2 *t);
GLUG_LIB_API struct glug_vec2 glug_triangle2_incenter(const struct glug_triangle2 *t);

GLUG_LIB_API float glug_triangle2_distance_to_point(const struct glug_triangle2 *t, const struct glug_vec2 *p);
GLUG_LIB_API int glug_triangle2_contains_point(const struct glug_triangle2 *t, const struct glug_vec2 *p);
GLUG_LIB_API struct glug_vec2 glug_triangle2_closest_point(const struct glug_triangle2 *t, const struct glug_vec2 *p);
GLUG_LIB_API void glug_triangle2_project_point(const struct glug_triangle2 *t, struct glug_vec2 *dst);

#endif // GLUG_TRIANGLE2_H
