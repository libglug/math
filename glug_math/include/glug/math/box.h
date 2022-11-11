#ifndef GLUG_BOX_H
#define GLUG_BOX_H

#include <glug/extern.h>
#include <glug/import.h>
#include <glug/bool_t.h>

#include <glug/math/box_t.h>
#include <glug/math/vec3_t.h>

GLUG_EXTERN_START

GLUG_LIB_API void glug_box_from_size(struct glug_box *dst, const struct glug_vec3 *c, const struct glug_vec3 *s);
GLUG_LIB_API glug_bool_t glug_box_equal(const struct glug_box *b1, const struct glug_box *b2);

GLUG_LIB_API glug_bool_t glug_box_is_empty(const struct glug_box *b);
GLUG_LIB_API glug_bool_t glug_box_contains_point(const struct glug_box *b, const struct glug_vec3 *p);
GLUG_LIB_API void glug_box_clamp_point(const struct glug_box *b, struct glug_vec3 *dst);

GLUG_LIB_API void glug_box_expand_to(struct glug_box *dst, const struct glug_vec3 *p);
GLUG_LIB_API glug_bool_t glug_box_intersects_box(const struct glug_box *b1, const struct glug_box *b2);
GLUG_LIB_API void glug_box_intersect(struct glug_box *dst, const struct glug_box *b2);
GLUG_LIB_API void glug_box_union(struct glug_box *dst, const struct glug_box *b2);


GLUG_EXTERN_END

#endif // GLUG_BOX_H
