#ifndef GLUG_LINE_H
#define GLUG_LINE_H

#include <glug/extern.h>
#include <glug/import.h>
#include <glug/bool_t.h>

#include <glug/math/line_t.h>

GLUG_EXTERN_START

GLUG_LIB_API void glug_line_from_points(struct glug_line *dst, const struct glug_vec3 *p1, const struct glug_vec3 *p2);

GLUG_LIB_API glug_bool_t glug_line_equal(const struct glug_line *a, const struct glug_line *b);

GLUG_LIB_API void glug_line_at_t(const struct glug_line *l, float t, struct glug_vec3 *dst);
GLUG_LIB_API float glug_line_distance_to_point(const struct glug_line *l, const struct glug_vec3 *p);
GLUG_LIB_API glug_bool_t glug_line_contains_point(const struct glug_line *l, const struct glug_vec3 *p);
GLUG_LIB_API void glug_line_project_point(const struct glug_line *l, struct glug_vec3 *dst);

GLUG_EXTERN_END

#endif // GLUG_LINE_H
