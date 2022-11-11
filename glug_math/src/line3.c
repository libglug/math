#include <glug/math/line3.h>
#include <glug/math/vec3.h>

#include <math.h>

void glug_line3_from_points(struct glug_line3 *dst, const struct glug_vec3 *p1, const struct glug_vec3 *p2)
{    
    struct glug_vec3 v = *p2;
    glug_vec3_sub(&v, p1);
    *dst = (struct glug_line3){
        .r0 = *p1,
        .v  = v,
    };
}

glug_bool_t glug_line3_equal(const struct glug_line3 *a, const struct glug_line3 *b)
{

}

void glug_line3_at_t(const struct glug_line3 *l, float t, struct glug_vec3 *dst)
{
    struct glug_vec3 p = l->v;
    glug_vec3_mul(&p, t);
    glug_vec3_add(&p, &l->r0);

    *dst = p;
}

static void distance_and_proj(const struct glug_line3 *l, const struct glug_vec3 *p, struct glug_vec3 *proj, float *d)
{
    struct glug_vec3 pr0 = *p;
    glug_vec3_sub(&pr0, &l->r0);
    *proj = pr0;
    glug_vec3_project(proj, &l->v);
    *d = sqrtf(glug_vec3_len_squared(&pr0) - glug_vec3_len_squared(proj));
}

float glug_line3_distance_to_point(const struct glug_line3 *l, const struct glug_vec3 *p)
{
    struct glug_vec3 proj;
    float d;
    distance_and_proj(l, p, &proj, &d);

    return d;
}

glug_bool_t glug_line3_contains_point(const struct glug_line3 *l, const struct glug_vec3 *p)
{

}

void glug_line3_project_point(const struct glug_line3 *l, struct glug_vec3 *dst)
{
    struct glug_vec3 proj;
    float d;
    distance_and_proj(l, dst, &proj, &d);

    *dst = proj;
    glug_vec3_mul(dst, d);
    glug_vec3_add(dst, &l->r0);
}
