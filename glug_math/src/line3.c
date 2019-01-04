#include <glug/math/line3.h>
#include <glug/math/vec3.h>

#include <math.h>

struct glug_line3 GLUG_LIB_API glug_line3_from_points(const struct glug_vec3 *a, const struct glug_vec3 *b)
{
    struct glug_line3 dst;
    glug_line3_set_by_points(&dst, a, b);

    return dst;
}

void GLUG_LIB_API glug_line3_set_by_points(struct glug_line3 *l, const struct glug_vec3 *a, const struct glug_vec3 *b)
{
    l->r0 = *a;
    l->v = *b;
    glug_vec3_sub(&l->v, a);
}

void GLUG_LIB_API glug_line3_set(struct glug_line3 *dst, const struct glug_vec3 *v, const struct glug_vec3 *r0)
{
    glug_vec3_copy(&dst->v, v);
    glug_vec3_copy(&dst->r0, r0);
}

void GLUG_LIB_API glug_line3_copy(struct glug_line3 *dst, const struct glug_line3 *src)
{
    glug_line3_set(dst, &src->v, &src->r0);
}

int GLUG_LIB_API glug_line3_equal(const struct glug_line3 *a, const struct glug_line3 *b)
{

}

struct glug_vec3 GLUG_LIB_API glug_line3_at_t(const struct glug_line3 *l, float t)
{
    struct glug_vec3 dst = l->v;
    glug_vec3_mul(&dst, t);
    glug_vec3_add(&dst, &l->r0);

    return dst;
}

static void distance_and_proj(const struct glug_line3 *l, const struct glug_vec3 *p, struct glug_vec3 *proj, float *d)
{
    struct glug_vec3 pr0 = glug_vec3_diff(p, &l->r0);
    *proj = glug_vec3_projection(&pr0, &l->v);
    *d = sqrtf(glug_vec3_len_squared(&pr0) - glug_vec3_len_squared(proj));
}

float GLUG_LIB_API glug_line3_distance_to_point(const struct glug_line3 *l, const struct glug_vec3 *p)
{
    struct glug_vec3 proj;
    float d;
    distance_and_proj(l, p, &proj, &d);

    return d;
}

int GLUG_LIB_API glug_line3_contains_point(const struct glug_line3 *l, const struct glug_vec3 *p)
{

}

struct glug_vec3 GLUG_LIB_API glug_line3_closest_point(const struct glug_line3 *l, const struct glug_vec3 *p)
{
    struct glug_vec3 proj;
    float d;
    distance_and_proj(l, p, &proj, &d);

    struct glug_vec3 dst = proj;
    glug_vec3_mul(&dst, d);
    glug_vec3_add(&dst, &l->r0);

    return dst;
}

void GLUG_LIB_API glug_line3_project_point(const struct glug_line3 *l, struct glug_vec3 *dst)
{
    struct glug_vec3 proj;
    float d;
    distance_and_proj(l, dst, &proj, &d);

    *dst = proj;
    glug_vec3_mul(dst, d);
    glug_vec3_add(dst, &l->r0);
}
