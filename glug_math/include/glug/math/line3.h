#ifndef GLUG_LINE3_H
#define GLUG_LINE3_H

#include <glug/import.h>
#include <glug/math/line3_t.h>

struct glug_line3 GLUG_LIB_API glug_line3_from_points(const struct glug_vec3 *a, const struct glug_vec3 *b);
void GLUG_LIB_API glug_line3_set_by_points(struct glug_line3 *l, const struct glug_vec3 *a, const struct glug_vec3 *b);

void GLUG_LIB_API glug_line3_set(struct glug_line3 *dst, const struct glug_vec3 *v, const struct glug_vec3 *r0);
void GLUG_LIB_API glug_line3_copy(struct glug_line3 *dst, const struct glug_line3 *src);
int  GLUG_LIB_API glug_line3_equal(const struct glug_line3 *a, const struct glug_line3 *b);

struct glug_vec3 GLUG_LIB_API glug_line3_at_t(const struct glug_line3 *l, float t);

float GLUG_LIB_API glug_line3_distance_to_point(const struct glug_line3 *l, const struct glug_vec3 *p);
int GLUG_LIB_API glug_line3_contains_point(const struct glug_line3 *l, const struct glug_vec3 *p);
struct glug_vec3 GLUG_LIB_API glug_line3_closest_point(const struct glug_line3 *l, const struct glug_vec3 *p);
void GLUG_LIB_API glug_line3_project_point(const struct glug_line3 *l, struct glug_vec3 *dst);

#endif // GLUG_LINE3_H
