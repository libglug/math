#ifndef GLUG_CIRCLE_H
#define GLUG_CIRCLE_H

#include <glug/import.h>

#include <glug/math/vec2.h>

struct glug_circle
{
    struct glug_vec2 c;
    float r;
};

#ifdef GLUG_USE_TYPEDEFS
    typedef struct glug_circle circle;
#endif

void GLUG_LIB_API glug_circle_set(struct glug_circle *dst, const struct glug_vec2 *c, float r);
void GLUG_LIB_API glug_circle_copy(struct glug_circle *dst, const struct glug_circle *src);
int  GLUG_LIB_API glug_circle_equal(const struct glug_circle *a, const struct glug_circle *b);

int  GLUG_LIB_API glug_circle_contains_point(const struct glug_circle *cir, const struct glug_vec2 *p);
struct glug_circle GLUG_LIB_API glug_circle_expansion(const struct glug_circle *c, const struct glug_vec2 *p);
void GLUG_LIB_API glug_circle_expand_to(struct glug_circle *dst, const struct glug_vec2 *p);

// TODO: move out of the circle header
struct glug_vec2 GLUG_LIB_API glug_circle_clamped_point(const struct glug_circle *c, const struct glug_vec2 *p);
void GLUG_LIB_API glug_circle_clamp_point(const struct glug_circle *c, struct glug_vec2 *dst);

#endif // GLUG_CIRCLE_H
