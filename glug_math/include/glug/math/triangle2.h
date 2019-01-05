#ifndef GLUG_TRIANGLE2_H
#define GLUG_TRIANGLE2_H

#include <glug/import.h>
#include <glug/math/triangle2_t.h>
#include <glug/math/vec3_t.h>

void GLUG_LIB_API glug_triangle2_set(struct glug_triangle2 *dst, const struct glug_vec2 *a, const struct glug_vec2 *b, const struct glug_vec2 *c);
int  GLUG_LIB_API glug_triangle2_equal(const struct glug_triangle2 *a, const struct glug_triangle2 *b);

struct glug_vec2 GLUG_LIB_API glug_triangle2_barycentric(const struct glug_triangle2 *t, const struct glug_vec3 *bary);
struct glug_vec2 GLUG_LIB_API glug_triangle2_trilinear(const struct glug_triangle2 *t, const struct glug_vec3 *tril);

struct glug_vec3 GLUG_LIB_API glug_triangle2_to_barycentric(const struct glug_triangle2 *t, const struct glug_vec2 *p);
struct glug_vec3 GLUG_LIB_API glug_triangle2_to_trilinear(const struct glug_triangle2 *t, const struct glug_vec2 *p);

struct glug_vec2 GLUG_LIB_API glug_triangle2_centroid(const struct glug_triangle2 *t);
struct glug_vec2 GLUG_LIB_API glug_triangle2_incenter(const struct glug_triangle2 *t);

float GLUG_LIB_API glug_triangle2_distance_to_point(const struct glug_triangle2 *t, const struct glug_vec2 *p);
int GLUG_LIB_API glug_triangle2_contains_point(const struct glug_triangle2 *t, const struct glug_vec2 *p);
struct glug_vec2 GLUG_LIB_API glug_triangle2_closest_point(const struct glug_triangle2 *t, const struct glug_vec2 *p);
void GLUG_LIB_API glug_triangle2_project_point(const struct glug_triangle2 *t, struct glug_vec2 *dst);

#endif // GLUG_TRIANGLE2_H
