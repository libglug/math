#ifndef GLUG_CIRCLE_H
#define GLUG_CIRCLE_H

#include <glug/import.h>
#include <glug/math/circle_t.h>

void GLUG_LIB_API glug_circle_set(struct glug_circle *dst, const struct glug_vec2 *c, float r);
int  GLUG_LIB_API glug_circle_equal(const struct glug_circle *a, const struct glug_circle *b);

int  GLUG_LIB_API glug_circle_contains_point(const struct glug_circle *cir, const struct glug_vec2 *p);
struct glug_circle GLUG_LIB_API glug_circle_expansion(const struct glug_circle *c, const struct glug_vec2 *p);
void GLUG_LIB_API glug_circle_expand_to(struct glug_circle *dst, const struct glug_vec2 *p);

int GLUG_LIB_API glug_circle_intersects_circle(const struct glug_circle *a, const struct glug_circle *b);
struct glug_circle GLUG_LIB_API glug_circle_union(const struct glug_circle *a, const struct glug_circle *b);
void GLUG_LIB_API glug_circle_unionize(struct glug_circle *dst, const struct glug_circle *b);

// TODO: move out of the circle header
struct glug_vec2 GLUG_LIB_API glug_circle_clamped_point(const struct glug_circle *c, const struct glug_vec2 *p);
void GLUG_LIB_API glug_circle_clamp_point(const struct glug_circle *c, struct glug_vec2 *dst);

#endif // GLUG_CIRCLE_H
