#ifndef GLUG_RECT_H
#define GLUG_RECT_H

#include <glug/import.h>
#include <glug/math/rect_t.h>

void GLUG_LIB_API glug_rect_set(struct glug_rect *dst, const struct glug_vec2 *min, const struct glug_vec2 *max);
void GLUG_LIB_API glug_rect_copy(struct glug_rect *dst, const struct glug_rect *src);
int  GLUG_LIB_API glug_rect_equal(const struct glug_rect *a, const struct glug_rect *b);

int GLUG_LIB_API glug_rect_is_empty(const struct glug_rect *r);

int GLUG_LIB_API glug_rect_contains_point(const struct glug_rect *r, const struct glug_vec2 *p);
struct glug_rect GLUG_LIB_API glug_rect_expansion(const struct glug_rect *r, const struct glug_vec2 *p);
void GLUG_LIB_API glug_rect_expand_to(struct glug_rect *dst, const struct glug_vec2 *p);

int GLUG_LIB_API glug_rect_intersects_rect(const struct glug_rect *a, const struct glug_rect *b);
struct glug_rect GLUG_LIB_API glug_rect_intersection(const struct glug_rect *a, const struct glug_rect *b);
void GLUG_LIB_API glug_rect_intersect(struct glug_rect *dst, const struct glug_rect *b);

struct glug_rect GLUG_LIB_API glug_rect_union(const struct glug_rect *a, const struct glug_rect *b);
void GLUG_LIB_API glug_rect_unionize(struct glug_rect *dst, const struct glug_rect *b);

// TODO: move out of the rect header
struct glug_vec2 GLUG_LIB_API glug_rect_clamped_point(const struct glug_rect *r, const struct glug_vec2 *p);
void GLUG_LIB_API glug_rect_clamp_point(const struct glug_rect *r, struct glug_vec2 *dst);

#endif // GLUG_RECT_H
