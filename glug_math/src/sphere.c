#include <glug/math/sphere.h>
#include <glug/math/vec3.h>

glug_bool_t glug_sphere_equal(const struct glug_sphere *a, const struct glug_sphere *b)
{

}

glug_bool_t glug_sphere_contains_point(const struct glug_sphere *s, const struct glug_vec3 *p)
{
    float rp = glug_vec3_dist_squared(&s->center, p);
    return rp <= s->radius * s->radius;
}

void glug_sphere_expand_to(struct glug_sphere *dst, const struct glug_vec3 *p)
{
    // |---r---c---r---|        p
    // |----------------------->p (span)
    // |<------c (far)

    struct glug_vec3 far, span;
    if (glug_sphere_contains_point(dst, p)) return;

    span = *p;
    glug_vec3_sub(&span, &dst->center);

    // far = -direction of span w/ length r
    far = span;
    glug_vec3_set_len(&far, -dst->radius);
    glug_vec3_sub(&span, &far);

    // new radius = half spanning vector
    glug_vec3_mul(&span, 0.5f);
    dst->radius = glug_vec3_len(&span);

    // new center = old center + half spanning vec + far
    glug_vec3_add(&dst->center, &span);
    glug_vec3_add(&dst->center, &far);
}

glug_bool_t glug_sphere_intersects_sphere(const struct glug_sphere *a, const struct glug_sphere *b)
{
    struct glug_vec3 dc = a->center;
    glug_vec3_sub(&dc, &b->center);

    return glug_vec3_len_squared(&dc) <= (a->radius + b->radius) * (a->radius + b->radius);
}

void glug_sphere_union(struct glug_sphere *dst, const struct glug_sphere *b)
{
    struct glug_vec3 dc = b->center;
    glug_vec3_sub(&dc, &dst->center);
    struct glug_vec3 r = dc;
    float cdiff = glug_vec3_len(&dc);

    // dst fully encompasses b, "return" dst
    if (cdiff + b->radius <= dst->radius) return;
    // b fully encompsses dst, "return" b
    if (cdiff + dst->radius <= b->radius)
    {
        *dst = *b;
        return;
    }

    glug_vec3_set_len(&r, dst->radius);
    dst->radius = 0.5f * (cdiff + dst->radius + b->radius);
    glug_vec3_add(&dst->center, &dc);
    glug_vec3_add(&dst->center, &r);
}

void glug_sphere_clamp_point(const struct glug_sphere *c, struct glug_vec3 *dst)
{
    if (glug_sphere_contains_point(c, dst)) return;

    glug_vec3_sub(dst, &c->center);
    glug_vec3_set_len(dst, c->radius);
    glug_vec3_add(dst, &c->center);
}

