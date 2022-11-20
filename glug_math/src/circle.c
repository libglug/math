#include <glug/math/circle.h>
#include <glug/math/vec2.h>

glug_bool_t glug_circle_equal(const struct glug_circle *c1, const struct glug_circle *c2)
{

}

glug_bool_t glug_circle_contains_point(const struct glug_circle *c, const struct glug_vec2 *p)
{
    float rp = glug_vec2_dist_squared(&c->center, p);
    return rp <= c->radius * c->radius;
}

void glug_circle_clamp_point(const struct glug_circle *c, struct glug_vec2 *dst)
{
    if (glug_circle_contains_point(c, dst)) return;

    glug_vec2_sub(dst, &c->center);
    glug_vec2_set_len(dst, c->radius);
    glug_vec2_add(dst, &c->center);
}

void glug_circle_expand_to(struct glug_circle *dst, const struct glug_vec2 *p)
{
    // |---r---c---r---|        p
    // |----------------------->p (span)
    // |<------c (far)

    struct glug_vec2 far, span;
    if (glug_circle_contains_point(dst, p)) return;

    span = *p;
    glug_vec2_sub(&span, &dst->center);

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

glug_bool_t glug_circle_intersects_circle(const struct glug_circle *c1, const struct glug_circle *c2)
{
    struct glug_vec2 dc = c1->center;
    glug_vec2_sub(&dc, &c2->center);

    return glug_vec2_len_squared(&dc) <= (c1->radius + c2->radius) * (c1->radius + c2->radius);
}

void glug_circle_union(struct glug_circle *dst, const struct glug_circle *c2)
{
    struct glug_vec2 dc = c2->center;
    glug_vec2_sub(&dc, &dst->center);
    float cdiff = glug_vec2_len(&dc);

    // dst fully encompasses b, "return" dst
    if (cdiff + c2->radius <= dst->radius) return;
    // b fully encompsses dst, "return" b
    if (cdiff + dst->radius <= c2->radius)
    {
        *dst = *c2;
        return;
    }

    struct glug_vec2 r = dc;
    glug_vec2_set_len(&r, dst->radius);
    dst->radius = 0.5f * (cdiff + dst->radius + c2->radius);
    glug_vec2_add(&dst->center, &dc);
    glug_vec2_add(&dst->center, &r);
}
