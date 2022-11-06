#ifndef GLUG_RECT_H
#define GLUG_RECT_H

#include <glug/extern.h>
#include <glug/import.h>
#include <glug/bool_t.h>

#include <glug/math/rect_t.h>

GLUG_EXTERN_START

GLUG_LIB_API void glug_rect_set(struct glug_rect *dst, const struct glug_vec2 *min, const struct glug_vec2 *max);
GLUG_LIB_API glug_bool_t glug_rect_equal(const struct glug_rect *a, const struct glug_rect *b);

GLUG_LIB_API glug_bool_t glug_rect_is_empty(const struct glug_rect *r);

GLUG_LIB_API glug_bool_t glug_rect_contains_point(const struct glug_rect *r, const struct glug_vec2 *p);
GLUG_LIB_API struct glug_rect glug_rect_expansion(const struct glug_rect *r, const struct glug_vec2 *p);
GLUG_LIB_API void glug_rect_expand_to(struct glug_rect *dst, const struct glug_vec2 *p);

GLUG_LIB_API glug_bool_t glug_rect_intersects_rect(const struct glug_rect *a, const struct glug_rect *b);
GLUG_LIB_API struct glug_rect glug_rect_intersection(const struct glug_rect *a, const struct glug_rect *b);
GLUG_LIB_API void glug_rect_intersect(struct glug_rect *dst, const struct glug_rect *b);

GLUG_LIB_API struct glug_rect glug_rect_union(const struct glug_rect *a, const struct glug_rect *b);
GLUG_LIB_API void glug_rect_unionize(struct glug_rect *dst, const struct glug_rect *b);

// TODO: move out of the rect header
GLUG_LIB_API struct glug_vec2 glug_rect_clamped_point(const struct glug_rect *r, const struct glug_vec2 *p);
GLUG_LIB_API void glug_rect_clamp_point(const struct glug_rect *r, struct glug_vec2 *dst);

GLUG_EXTERN_END

#endif // GLUG_RECT_H
