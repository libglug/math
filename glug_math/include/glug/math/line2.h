#ifndef GLUG_LINE2_H
#define GLUG_LINE2_H

#include <glug/extern.h>
#include <glug/import.h>
#include <glug/bool_t.h>

#include <glug/math/line2_t.h>

GLUG_EXTERN_START

GLUG_LIB_API void glug_line2_from_points(struct glug_line2 *dst, const struct glug_vec2 *a, const struct glug_vec2 *b);
GLUG_LIB_API void glug_line2_from_slope(struct glug_line2 *dst, float m, float b);

GLUG_LIB_API glug_bool_t glug_line2_equal(const struct glug_line2 *a, const struct glug_line2 *b);

GLUG_LIB_API void glug_line2_at_t(const struct glug_line2 *l, float t, struct glug_vec2 *dst);
GLUG_LIB_API float glug_line2_distance_to_point(const struct glug_line2 *l, const struct glug_vec2 *p);
GLUG_LIB_API glug_bool_t glug_line2_contains_point(const struct glug_line2 *l, const struct glug_vec2 *p);
GLUG_LIB_API void glug_line2_project_point(const struct glug_line2 *l, struct glug_vec2 *dst);

GLUG_EXTERN_END

#endif // GLUG_LINE2_H
