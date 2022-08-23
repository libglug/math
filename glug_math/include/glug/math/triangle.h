#ifndef GLUG_TRIANGLE_H
#define GLUG_TRIANGLE_H

#include <glug/extern.h>
#include <glug/import.h>
#include <glug/bool_t.h>

#include <glug/math/triangle_t.h>

GLUG_EXTERN_START

GLUG_LIB_API glug_bool_t glug_triangle_equal(const struct glug_triangle *a, const struct glug_triangle *b);

GLUG_LIB_API struct glug_vec3 glug_triangle_barycentric(const struct glug_triangle *t, const struct glug_vec3 *bary);
GLUG_LIB_API struct glug_vec3 glug_triangle_trilinear(const struct glug_triangle *t, const struct glug_vec3 *tril);

GLUG_LIB_API struct glug_vec3 glug_triangle_to_barycentric(const struct glug_triangle *t, const struct glug_vec3 *p);
GLUG_LIB_API struct glug_vec3 glug_triangle_to_trilinear(const struct glug_triangle *t, const struct glug_vec3 *p);

GLUG_LIB_API float glug_triangle_len_a(const struct glug_triangle *t);
GLUG_LIB_API float glug_triangle_len_sq_a(const struct glug_triangle *t);
GLUG_LIB_API float glug_triangle_len_b(const struct glug_triangle *t);
GLUG_LIB_API float glug_triangle_len_sq_b(const struct glug_triangle *t);
GLUG_LIB_API float glug_triangle_len_c(const struct glug_triangle *t);
GLUG_LIB_API float glug_triangle_len_sq_c(const struct glug_triangle *t);
GLUG_LIB_API float glug_triangle_perimeter(const struct glug_triangle *t);

GLUG_LIB_API float glug_triangle_angle_a(const struct glug_triangle *t);
GLUG_LIB_API float glug_triangle_angle_b(const struct glug_triangle *t);
GLUG_LIB_API float glug_triangle_angle_c(const struct glug_triangle *t);

GLUG_LIB_API struct glug_vec3 glug_triangle_normal(const struct glug_triangle *t);
GLUG_LIB_API struct glug_vec3 glug_triangle_centroid(const struct glug_triangle *t);
GLUG_LIB_API struct glug_vec3 glug_triangle_incenter(const struct glug_triangle *t);
GLUG_LIB_API void glug_triangle_orthocenter(const struct glug_triangle *t, struct glug_vec3 *dst);
GLUG_LIB_API void glug_triangle_circumcenter(const struct glug_triangle *t, struct glug_vec3 *dst);
GLUG_LIB_API void glug_triangle_excenter_a(const struct glug_triangle *t, struct glug_vec3 *dst);
GLUG_LIB_API void glug_triangle_excenter_b(const struct glug_triangle *t, struct glug_vec3 *dst);
GLUG_LIB_API void glug_triangle_excenter_c(const struct glug_triangle *t, struct glug_vec3 *dst);

GLUG_LIB_API float glug_triangle_distance_to_point(const struct glug_triangle *t, const struct glug_vec3 *p);
GLUG_LIB_API glug_bool_t glug_triangle_contains_point(const struct glug_triangle *t, const struct glug_vec3 *p);
GLUG_LIB_API void glug_triangle_project_point(const struct glug_triangle *t, struct glug_vec3 *dst);

GLUG_EXTERN_END

#endif // GLUG_TRIANGLE_H
