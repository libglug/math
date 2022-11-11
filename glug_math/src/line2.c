#include <glug/math/line2.h>
#include <glug/math/vec2.h>

#include <math.h>

void glug_line2_from_points(struct glug_line2 *dst, const struct glug_vec2 *a, const struct glug_vec2 *b)
{
    struct glug_vec2 v = *b;
    glug_vec2_sub(&v, a);

    *dst = (struct glug_line2){
        .r0 = *a,
        .v  = v,
    };
}

void glug_line2_from_slope(struct glug_line2 *dst, float m, float b)
{
    struct glug_vec2 r0, v;
    if (isinf(m))
    {
        r0 = (struct glug_vec2){ b, 0.f };
        v  = (struct glug_vec2){ 0, 1.f };
    }
    else
    {
        r0 = (struct glug_vec2){ 0.f, b };
        v  = (struct glug_vec2){ 1.f, m };
    }

    *dst = (struct glug_line2){
        .r0 = r0,
        .v  = v,
    };
}

glug_bool_t glug_line2_equal(const struct glug_line2 *a, const struct glug_line2 *b)
{

}

void glug_line2_at_t(const struct glug_line2 *l, float t, struct glug_vec2 *dst)
{
    struct glug_vec2 p = l->v;
    glug_vec2_mul(&p, t);
    glug_vec2_add(&p, &l->r0);

    *dst = p;
}

static void distance_and_proj(const struct glug_line2 *l, const struct glug_vec2 *p, struct glug_vec2 *proj, float *d)
{
    struct glug_vec2 pr0 = *p;
    glug_vec2_sub(&pr0, &l->r0);
    *proj = pr0;
    glug_vec2_project(proj, &l->v);
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

void glug_line2_project_point(const struct glug_line2 *l, struct glug_vec2 *dst)
{
    struct glug_vec2 proj;
    float d;
    distance_and_proj(l, dst, &proj, &d);

    *dst = proj;
    glug_vec2_mul(dst, d);
    glug_vec2_add(dst, &l->r0);
}
