#ifndef GLUG_TRIANGLE3_H
#define GLUG_TRIANGLE3_H

#include <glug/import.h>
#include <glug/math/triangle3_t.h>

void GLUG_LIB_API glug_triangle3_set(struct glug_triangle3 *dst, const struct glug_vec3 *a, const struct glug_vec3 *b, const struct glug_vec3 *c);
int  GLUG_LIB_API glug_triangle3_equal(const struct glug_triangle3 *a, const struct glug_triangle3 *b);

struct glug_vec3 GLUG_LIB_API glug_triangle3_barycentric(const struct glug_triangle3 *t, const struct glug_vec3 *bary);
struct glug_vec3 GLUG_LIB_API glug_triangle3_trilinear(const struct glug_triangle3 *t, const struct glug_vec3 *tril);

struct glug_vec3 GLUG_LIB_API glug_triangle3_to_barycentric(const struct glug_triangle3 *t, const struct glug_vec3 *p);
struct glug_vec3 GLUG_LIB_API glug_triangle3_to_trilinear(const struct glug_triangle3 *t, const struct glug_vec3 *p);

struct glug_vec3 GLUG_LIB_API glug_triangle3_normal(const struct glug_triangle3 *t);
struct glug_vec3 GLUG_LIB_API glug_triangle3_centroid(const struct glug_triangle3 *t);
struct glug_vec3 GLUG_LIB_API glug_triangle3_incenter(const struct glug_triangle3 *t);

float GLUG_LIB_API glug_triangle3_distance_to_point(const struct glug_triangle3 *t, const struct glug_vec3 *p);
int GLUG_LIB_API glug_triangle3_contains_point(const struct glug_triangle3 *t, const struct glug_vec3 *p);
struct glug_vec3 GLUG_LIB_API glug_triangle3_closest_point(const struct glug_triangle3 *t, const struct glug_vec3 *p);
void GLUG_LIB_API glug_triangle3_project_point(const struct glug_triangle3 *t, struct glug_vec3 *dst);

#endif // GLUG_TRIANGLE3_H
