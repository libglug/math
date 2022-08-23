#include <glug/math/plane.h>
#include <glug/math/vec3.h>

void glug_plane_from_points(struct glug_plane *dst, const struct glug_vec3 *a, const struct glug_vec3 *b, const struct glug_vec3 *c)
{
    struct glug_vec3 ab;
    glug_vec3_sub(&ab, b, a);
    struct glug_vec3 ac;
    glug_vec3_sub(&ac, c, a);
    struct glug_vec3 norm;
    glug_vec3_cross(&norm, &ab, &ac);
    glug_vec3_normalize(&norm);

    dst->normal = norm;
    dst->offset = glug_vec3_dot(&norm, a);
}

void glug_plane_from_normal(struct glug_plane *dst, const struct glug_vec3 *n, const struct glug_vec3 *p)
{
    struct glug_vec3 norm = *n;
    glug_vec3_normalize(&norm);

    dst->normal = norm;
    dst->offset = glug_vec3_dot(&norm, p);
}

glug_bool_t glug_plane_equal(const struct glug_plane *a, const struct glug_plane *b)
{

}

void glug_plane_normalize(struct glug_plane *dst)
{
    float l = 1.f / glug_vec3_len(&dst->normal);
    glug_vec3_mul(&dst->normal, l);
    dst->offset *= l;
}

glug_bool_t glug_plane_contains_point(const struct glug_plane *p, const struct glug_vec3 *r)
{
//    return p->offset == glug_vec3_dot(&p->normal, r);
}

float glug_plane_distance_to_point(const struct glug_plane *p, const struct glug_vec3 *r)
{
    return glug_vec3_dot(&p->normal, r) - p->offset;
}

void glug_plane_project_point(const struct glug_plane *p, struct glug_vec3 *dst)
{
    struct glug_vec3 cn = p->normal;

    glug_vec3_mul(&cn, -glug_plane_distance_to_point(p, dst));
    glug_vec3_add(dst, &cn);
}
