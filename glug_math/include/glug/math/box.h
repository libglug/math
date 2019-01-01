#ifndef GLUG_BOX_H
#define GLUG_BOX_H

#include <glug/import.h>
#include <glug/math/box_t.h>

void GLUG_LIB_API glug_box_set(struct glug_box *dst, const struct glug_vec3 *min, const struct glug_vec3 *max);
void GLUG_LIB_API glug_box_copy(struct glug_box *dst, const struct glug_box *src);
int  GLUG_LIB_API glug_box_equal(const struct glug_box *a, const struct glug_box *b);

int GLUG_LIB_API glug_box_is_empty(const struct glug_box *b);

int  GLUG_LIB_API glug_box_contains_point(const struct glug_box *r, const struct glug_vec3 *p);
struct glug_box GLUG_LIB_API glug_box_expansion(const struct glug_box *r, const struct glug_vec3 *p);
void GLUG_LIB_API glug_box_expand_to(struct glug_box *dst, const struct glug_vec3 *p);

int GLUG_LIB_API glug_box_intersects_box(const struct glug_box *a, const struct glug_box *b);
struct glug_box GLUG_LIB_API glug_box_intersection(const struct glug_box *a, const struct glug_box *b);
void GLUG_LIB_API glug_box_intersect(struct glug_box *dst, const struct glug_box *b);

struct glug_box GLUG_LIB_API glug_box_union(const struct glug_box *a, const struct glug_box *b);
void GLUG_LIB_API glug_box_unionize(struct glug_box *dst, const struct glug_box *b);

// TODO: move out of the box header
struct glug_vec3 GLUG_LIB_API glug_box_clamped_point(const struct glug_box *r, const struct glug_vec3 *p);
void GLUG_LIB_API glug_box_clamp_point(const struct glug_box *r, struct glug_vec3 *dst);

#endif // GLUG_BOX_H
