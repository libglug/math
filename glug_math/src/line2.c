#include <glug/math/line2.h>
#include <glug/math/vec2.h>

#include <math.h>

struct glug_line2 glug_line2_from_points(const struct glug_vec2 *a, const struct glug_vec2 *b)
{
    struct glug_line2 dst;
    glug_line2_set_by_points(&dst, a, b);

    return dst;
}

struct glug_line2 glug_line2_from_slope(float m, float b)
{
    struct glug_line2 dst;
    glug_line2_set_by_slope(&dst, m, b);

    return dst;
}

void glug_line2_set_by_points(struct glug_line2 *l, const struct glug_vec2 *a, const struct glug_vec2 *b)
{
    l->r0 = *a;
    l->v = *b;
    glug_vec2_sub(&l->v, a);
}

void glug_line2_set_by_slope(struct glug_line2 *l, float m, float b)
{
    if (isinf(m))
    {
        glug_vec2_set(&l->v, 0, 1.f);
        glug_vec2_set(&l->r0, b, 0.f);
    }
    else
    {
        glug_vec2_set(&l->v, 1.f, m);
        glug_vec2_set(&l->r0, 0.f, b);
    }
}

void glug_line2_set(struct glug_line2 *dst, const struct glug_vec2 *v, const struct glug_vec2 *r0)
{
    dst->v = *v;
    dst->r0 = *r0;
}

glug_bool_t glug_line2_equal(const struct glug_line2 *a, const struct glug_line2 *b)
{

}

struct glug_vec2 glug_line2_at_t(const struct glug_line2 *l, float t)
{
    struct glug_vec2 dst = l->v;
    glug_vec2_mul(&dst, t);
    glug_vec2_add(&dst, &l->r0);

    return dst;
}

static void distance_and_proj(const struct glug_line2 *l, const struct glug_vec2 *p, struct glug_vec2 *proj, float *d)
{
    struct glug_vec2 pr0 = glug_vec2_diff(p, &l->r0);
    *proj = glug_vec2_projection(&pr0, &l->v);
    *d = sqrtf(glug_vec2_len_squared(&pr0) - glug_vec2_len_squared(proj));
}

float glug_line2_distance_to_point(const struct glug_line2 *l, const struct glug_vec2 *p)
{
    struct glug_vec2 proj;
    float d;
    distance_and_proj(l, p, &proj, &d);

    return d;
}

glug_bool_t glug_line2_contains_point(const struct glug_line2 *l, const struct glug_vec2 *p)
{

}

struct glug_vec2 glug_line2_closest_point(const struct glug_line2 *l, const struct glug_vec2 *p)
{
    struct glug_vec2 proj;
    float d;
    distance_and_proj(l, p, &proj, &d);

    struct glug_vec2 dst = proj;
    glug_vec2_mul(&dst, d);
    glug_vec2_add(&dst, &l->r0);

    return dst;
}

void glug_line2_project_point(const struct glug_line2 *l, struct glug_vec2 *dst)
{
    struct glug_vec2 proj;
    float d;
    distance_and_proj(l, dst, &proj, &d);

    *dst = proj;
    glug_vec2_mul(dst, d);
    glug_vec2_add(dst, &l->r0);
}
