#include <glug/math/circle.h>
#include <glug/math/vec2.h>

void GLUG_LIB_API glug_circle_set(struct glug_circle *dst, const struct glug_vec2 *c, float r)
{
    dst->center = *c;
    dst->radius = r;
}

int GLUG_LIB_API glug_circle_equal(const struct glug_circle *a, const struct glug_circle *b)
{

}

int GLUG_LIB_API glug_circle_contains_point(const struct glug_circle *cir, const struct glug_vec2 *p)
{
    float rp = glug_vec2_dist_squared(&cir->center, p);
    return rp <= cir->radius * cir->radius;
}

struct glug_circle GLUG_LIB_API glug_circle_expansion(const struct glug_circle *c, const struct glug_vec2 *p)
{
    struct glug_circle dst = *c;
    glug_circle_expand_to(&dst, p);

    return dst;
}

void GLUG_LIB_API glug_circle_expand_to(struct glug_circle *dst, const struct glug_vec2 *p)
{
    // |---r---c---r---|        p
    // |----------------------->p (span)
    // |<------c (far)

    struct glug_vec2 far, span;
    if (glug_circle_contains_point(dst, p)) return;

    span = glug_vec2_diff(p, &dst->center);

    // far = -direction of span w/ length r
    far = span;
    glug_vec2_set_len(&far, -dst->radius);
    glug_vec2_sub(&span, &far);

    // new radius = half spanning vector
    glug_vec2_mul(&span, 0.5f);
    dst->radius = glug_vec2_len(&span);

    // new center = old center + half spanning vec + far
    glug_vec2_add(&dst->center, &span);
    glug_vec2_add(&dst->center, &far);
}

int GLUG_LIB_API glug_circle_intersects_circle(const struct glug_circle *a, const struct glug_circle *b)
{
    struct glug_vec2 dc = glug_vec2_diff(&a->center, &b->center);

    return glug_vec2_len_squared(&dc) <= (a->radius + b->radius) * (a->radius + b->radius);
}

struct glug_circle GLUG_LIB_API glug_circle_union(const struct glug_circle *a, const struct glug_circle *b)
{
    struct glug_circle dst = *a;
    glug_circle_unionize(&dst, b);

    return dst;
}

void GLUG_LIB_API glug_circle_unionize(struct glug_circle *dst, const struct glug_circle *b)
{
    struct glug_vec2 dc = glug_vec2_diff(&b->center, &dst->center);
    struct glug_vec2 r = dc;
    float cdiff = glug_vec2_len(&dc);

    // dst fully encompasses b, "return" dst
    if (cdiff + b->radius <= dst->radius) return;
    // b fully encompsses dst, "return" b
    if (cdiff + dst->radius <= b->radius)
    {
        *dst = *b;
        return;
    }

    glug_vec2_set_len(&r, dst->radius);
    dst->radius = 0.5f * (cdiff + dst->radius + b->radius);
    glug_vec2_add(&dst->center, &dc);
    glug_vec2_add(&dst->center, &r);
}


struct glug_vec2 GLUG_LIB_API glug_circle_clamped_point(const struct glug_circle *c, const struct glug_vec2 *p)
{
    struct glug_vec2 dst = *p;
    glug_circle_clamp_point(c, &dst);

    return dst;
}

void GLUG_LIB_API glug_circle_clamp_point(const struct glug_circle *c, struct glug_vec2 *dst)
{
    if (glug_circle_contains_point(c, dst)) return;

    glug_vec2_sub(dst, &c->center);
    glug_vec2_set_len(dst, c->radius);
    glug_vec2_add(dst, &c->center);
}
