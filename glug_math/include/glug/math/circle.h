#ifndef GLUG_CIRCLE_H
#define GLUG_CIRCLE_H

#include <glug/extern.h>
#include <glug/import.h>
#include <glug/bool_t.h>

#include <glug/math/circle_t.h>
#include <glug/math/vec2_t.h>

GLUG_EXTERN_START

GLUG_LIB_API glug_bool_t glug_circle_equal(const struct glug_circle *c1, const struct glug_circle *c2);

GLUG_LIB_API glug_bool_t glug_circle_contains_point(const struct glug_circle *c, const struct glug_vec2 *p);
GLUG_LIB_API void glug_circle_clamp_point(const struct glug_circle *c, struct glug_vec2 *dst);

GLUG_LIB_API void glug_circle_expand_to(struct glug_circle *dst, const struct glug_vec2 *p);
GLUG_LIB_API glug_bool_t glug_circle_intersects_circle(const struct glug_circle *c1, const struct glug_circle *c2);
GLUG_LIB_API void glug_circle_union(struct glug_circle *dst, const struct glug_circle *c2);

GLUG_EXTERN_END

#endif // GLUG_CIRCLE_H
