#ifndef GLUG_TRIANGLE3_H
#define GLUG_TRIANGLE3_H

#include <glug/extern.h>
#include <glug/import.h>
#include <glug/bool_t.h>

#include <glug/math/triangle3_t.h>

GLUG_EXTERN_START

GLUG_LIB_API glug_bool_t glug_triangle3_equal(const struct glug_triangle3 *a, const struct glug_triangle3 *b);

GLUG_LIB_API struct glug_vec3 glug_triangle3_barycentric(const struct glug_triangle3 *t, const struct glug_vec3 *bary);
GLUG_LIB_API struct glug_vec3 glug_triangle3_trilinear(const struct glug_triangle3 *t, const struct glug_vec3 *tril);

GLUG_LIB_API struct glug_vec3 glug_triangle3_to_barycentric(const struct glug_triangle3 *t, const struct glug_vec3 *p);
GLUG_LIB_API struct glug_vec3 glug_triangle3_to_trilinear(const struct glug_triangle3 *t, const struct glug_vec3 *p);

GLUG_LIB_API struct glug_vec3 glug_triangle3_normal(const struct glug_triangle3 *t);
GLUG_LIB_API struct glug_vec3 glug_triangle3_centroid(const struct glug_triangle3 *t);
GLUG_LIB_API struct glug_vec3 glug_triangle3_incenter(const struct glug_triangle3 *t);

GLUG_LIB_API float glug_triangle3_distance_to_point(const struct glug_triangle3 *t, const struct glug_vec3 *p);
GLUG_LIB_API glug_bool_t glug_triangle3_contains_point(const struct glug_triangle3 *t, const struct glug_vec3 *p);
GLUG_LIB_API void glug_triangle3_project_point(const struct glug_triangle3 *t, struct glug_vec3 *dst);

GLUG_EXTERN_END

#endif // GLUG_TRIANGLE3_H
