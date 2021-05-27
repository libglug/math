#ifndef GLUG_BOX_H
#define GLUG_BOX_H

#include <glug/import.h>
#include <glug/bool_t.h>
#include <glug/math/box_t.h>

GLUG_LIB_API void glug_box_set(struct glug_box *dst, const struct glug_vec3 *min, const struct glug_vec3 *max);
GLUG_LIB_API glug_bool_t glug_box_equal(const struct glug_box *a, const struct glug_box *b);

GLUG_LIB_API glug_bool_t glug_box_is_empty(const struct glug_box *b);

GLUG_LIB_API glug_bool_t  glug_box_contains_point(const struct glug_box *r, const struct glug_vec3 *p);
GLUG_LIB_API struct glug_box glug_box_expansion(const struct glug_box *r, const struct glug_vec3 *p);
GLUG_LIB_API void glug_box_expand_to(struct glug_box *dst, const struct glug_vec3 *p);

GLUG_LIB_API glug_bool_t glug_box_intersects_box(const struct glug_box *a, const struct glug_box *b);
GLUG_LIB_API struct glug_box glug_box_intersection(const struct glug_box *a, const struct glug_box *b);
GLUG_LIB_API void glug_box_intersect(struct glug_box *dst, const struct glug_box *b);

GLUG_LIB_API struct glug_box glug_box_union(const struct glug_box *a, const struct glug_box *b);
GLUG_LIB_API void glug_box_unionize(struct glug_box *dst, const struct glug_box *b);

// TODO: move out of the box header
GLUG_LIB_API struct glug_vec3 glug_box_clamped_point(const struct glug_box *r, const struct glug_vec3 *p);
GLUG_LIB_API void glug_box_clamp_point(const struct glug_box *r, struct glug_vec3 *dst);

#endif // GLUG_BOX_H
