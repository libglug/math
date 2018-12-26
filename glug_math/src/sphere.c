#include <glug/math/sphere.h>
#include <glug/math/vec3.h>

void GLUG_LIB_API glug_sphere_set(struct glug_sphere *dst, const struct glug_vec3 *c, float r)
{
    glug_vec3_copy(&dst->c, c);
    dst->r = r;
}

void GLUG_LIB_API glug_sphere_copy(struct glug_sphere *dst, const struct glug_sphere *src)
{
    glug_sphere_set(dst, &src->c, src->r);
}

int GLUG_LIB_API glug_sphere_equal(const struct glug_sphere *a, const struct glug_sphere *b)
{

}

int GLUG_LIB_API glug_sphere_contains_point(const struct glug_sphere *cir, const struct glug_vec3 *p)
{
    float rp = glug_vec3_dist_squared(&cir->c, p);
    return rp <= cir->r * cir->r;
}

struct glug_sphere GLUG_LIB_API glug_sphere_expansion(const struct glug_sphere *c, const struct glug_vec3 *p)
{
    struct glug_sphere dst = *c;
    glug_sphere_expand_to(&dst, p);

    return dst;
}

void GLUG_LIB_API glug_sphere_expand_to(struct glug_sphere *dst, const struct glug_vec3 *p)
{
    // |---r---c---r---|        p
    // |----------------------->p (span)
    // |<------c (far)

    struct glug_vec3 far, span;
    if (glug_sphere_contains_point(dst, p)) return;

    span = glug_vec3_diff(p, &dst->c);

    // far = -direction of span w/ length r
    glug_vec3_copy(&far, &span);
    glug_vec3_set_len(&far, -dst->r);
    glug_vec3_sub(&span, &far);

    // new radius = half spanning vector
    glug_vec3_mul(&span, 0.5f);
    dst->r = glug_vec3_len(&span);

    // new center = old center + half spanning vec + far
    glug_vec3_add(&dst->c, &span);
    glug_vec3_add(&dst->c, &far);
}

struct glug_sphere GLUG_LIB_API glug_sphere_union(struct glug_sphere *a, struct glug_sphere *b)
{
    struct glug_sphere dst = *a;
    glug_sphere_unionize(&dst, b);

    return dst;
}

void GLUG_LIB_API glug_sphere_unionize(struct glug_sphere *dst, struct glug_sphere *b)
{
    struct glug_vec3 dc = glug_vec3_diff(&b->c, &dst->c);
    struct glug_vec3 r = dc;
    float cdiff = glug_vec3_len(&dc);

    // dst fully encompasses b, "return" dst
    if (cdiff + b->r <= dst->r) return;
    // b fully encompsses dst, "return" b
    if (cdiff + dst->r <= b->r)
    {
        glug_sphere_copy(dst, b);
        return;
    }

    glug_vec3_set_len(&r, dst->r);
    dst->r = 0.5f * (cdiff + dst->r + b->r);
    glug_vec3_add(&dst->c, &dc);
    glug_vec3_add(&dst->c, &r);
}

struct glug_vec3 GLUG_LIB_API glug_sphere_clamped_point(const struct glug_sphere *c, const struct glug_vec3 *p)
{
    struct glug_vec3 dst = *p;
    glug_sphere_clamp_point(c, &dst);

    return dst;
}

void GLUG_LIB_API glug_sphere_clamp_point(const struct glug_sphere *c, struct glug_vec3 *dst)
{
    if (glug_sphere_contains_point(c, dst)) return;

    glug_vec3_sub(dst, &c->c);
    glug_vec3_set_len(dst, c->r);
    glug_vec3_add(dst, &c->c);
}

