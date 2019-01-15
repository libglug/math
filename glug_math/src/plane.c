#include <glug/math/plane.h>
#include <glug/math/vec3.h>

struct glug_plane glug_plane_from_points(const struct glug_vec3 *a, const struct glug_vec3 *b, const struct glug_vec3 *c)
{
    struct glug_plane dst;
    glug_plane_set_by_points(&dst, a, b, c);

    return dst;
}

struct glug_plane glug_plane_from_normal(const struct glug_vec3 *n, const struct glug_vec3 *r)
{
    struct glug_plane dst;
    glug_plane_set_by_normal(&dst, n, r);

    return dst;
}

void glug_plane_set_by_points(struct glug_plane *dst, const struct glug_vec3 *a, const struct glug_vec3 *b, const struct glug_vec3 *c)
{
    struct glug_vec3 ab = glug_vec3_diff(b, a);
    struct glug_vec3 ac = glug_vec3_diff(c, a);
    struct glug_vec3 norm = glug_vec3_cross(&ab, &ac);
    glug_vec3_normalize(&norm);

    glug_plane_set(dst, &norm, glug_vec3_dot(&norm, a));

}

void glug_plane_set_by_normal(struct glug_plane *dst, const struct glug_vec3 *n, const struct glug_vec3 *r)
{
    struct glug_vec3 norm = glug_vec3_normal(n);
    glug_plane_set(dst, &norm, glug_vec3_dot(&norm, r));
}

void glug_plane_set(struct glug_plane *dst, const struct glug_vec3 *n, float d)
{
    dst->normal = *n;
    dst->offset = d;
}

int glug_plane_equal(const struct glug_plane *a, const struct glug_plane *b)
{

}

void GLUG_LIB_API glug_plane_normalize(struct glug_plane *dst)
{
    float l = 1.f / glug_vec3_len(&dst->normal);
    glug_vec3_mul(&dst->normal, l);
    dst->offset *= l;
}

int glug_plane_contains_point(const struct glug_plane *p, const struct glug_vec3 *r)
{
//    return p->offset == glug_vec3_dot(&p->normal, r);
}

float glug_plane_distance_to_point(const struct glug_plane *p, const struct glug_vec3 *r)
{
    return glug_vec3_dot(&p->normal, r) - p->offset;
}

struct glug_vec3 glug_plane_closest_point(const struct glug_plane *p, const struct glug_vec3 *r)
{
    struct glug_vec3 dst = *r;
    glug_plane_project_point(p, &dst);

    return dst;
}

void GLUG_LIB_API glug_plane_project_point(const struct glug_plane *p, struct glug_vec3 *dst)
{
    struct glug_vec3 cn = p->normal;

    glug_vec3_mul(&cn, -glug_plane_distance_to_point(p, dst));
    glug_vec3_add(dst, &cn);
}
