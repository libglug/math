#ifndef GLUG_LINE3_H
#define GLUG_LINE3_H

#include <glug/extern.h>
#include <glug/import.h>
#include <glug/bool_t.h>

#include <glug/math/line3_t.h>

GLUG_EXTERN_START

GLUG_LIB_API struct glug_line3 glug_line3_from_points(const struct glug_vec3 *a, const struct glug_vec3 *b);
GLUG_LIB_API void glug_line3_set_by_points(struct glug_line3 *l, const struct glug_vec3 *a, const struct glug_vec3 *b);

GLUG_LIB_API void glug_line3_set(struct glug_line3 *dst, const struct glug_vec3 *v, const struct glug_vec3 *r0);
GLUG_LIB_API glug_bool_t glug_line3_equal(const struct glug_line3 *a, const struct glug_line3 *b);

GLUG_LIB_API struct glug_vec3 glug_line3_at_t(const struct glug_line3 *l, float t);

GLUG_LIB_API float glug_line3_distance_to_point(const struct glug_line3 *l, const struct glug_vec3 *p);
GLUG_LIB_API glug_bool_t glug_line3_contains_point(const struct glug_line3 *l, const struct glug_vec3 *p);
GLUG_LIB_API struct glug_vec3 glug_line3_closest_point(const struct glug_line3 *l, const struct glug_vec3 *p);
GLUG_LIB_API void glug_line3_project_point(const struct glug_line3 *l, struct glug_vec3 *dst);

GLUG_EXTERN_END

#endif // GLUG_LINE3_H
