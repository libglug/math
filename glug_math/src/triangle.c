#include <glug/math/triangle.h>
#include <glug/math/vec3.h>

glug_bool_t glug_triangle_equal(const struct glug_triangle *a, const struct glug_triangle *b)
{

}

struct glug_vec3 glug_triangle_barycentric(const struct glug_triangle *t, const struct glug_vec3 *bary)
{
    struct glug_vec3 dst;
    dst.x = bary->x * t->a.x + bary->y * t->b.x + bary->z * t->c.x;
    dst.y = bary->x * t->a.y + bary->y * t->b.y + bary->z * t->c.y;
    dst.z = bary->x * t->a.z + bary->y * t->b.z + bary->z * t->c.z;

    return dst;
}

struct glug_vec3 glug_triangle_trilinear(const struct glug_triangle *t, const struct glug_vec3 *tril)
{
    float ax = glug_vec3_dist(&t->b, &t->c) * tril->x,
          by = glug_vec3_dist(&t->c, &t->a) * tril->y,
          cz = glug_vec3_dist(&t->a, &t->b) * tril->z,
          s = (ax + by + cz);
    struct glug_vec3 dst = {
        (t->a.x * ax + t->b.x * by + t->c.x * cz),
        (t->a.y * ax + t->b.y * by + t->c.y * cz),
        (t->a.z * ax + t->b.z * by + t->c.z * cz)
    };
    glug_vec3_div(&dst, s);

    return dst;
}

struct glug_vec3 glug_triangle_to_barycentric(const struct glug_triangle *t, const struct glug_vec3 *p)
{
    struct glug_vec3 p0 = *p,
                     p1 = t->b,
                     p2 = t->c;
    glug_vec3_sub(&p0, &t->a);
    glug_vec3_sub(&p1, &t->a);
    glug_vec3_sub(&p2, &t->a);

    float p01 = glug_vec3_dot(&p0, &p1),
          p02 = glug_vec3_dot(&p0, &p2),
          p11 = glug_vec3_dot(&p1, &p1),
          p12 = glug_vec3_dot(&p1, &p2),
          p22 = glug_vec3_dot(&p2, &p2);

    float den = 1.f / (p11 * p22 - p12 * p12);

    float w1 = (p01 * p22 - p12 * p02) * den,
          w2 = (p11 * p02 - p01 * p12) * den;

    struct glug_vec3 dst = { 1.f - w1 - w2, w1, w2 };
    return dst;
}

struct glug_vec3 glug_triangle_to_trilinear(const struct glug_triangle *t, const struct glug_vec3 *p)
{
    float a = glug_vec3_dist(&t->b, &t->c),
          b = glug_vec3_dist(&t->c, &t->a),
          c = glug_vec3_dist(&t->a, &t->b);
    struct glug_vec3 bary = glug_triangle_to_barycentric(t, p);
    struct glug_vec3 dst = {
        bary.x / a,
        bary.y / b,
        bary.z / c,
    };

    return dst;
}

struct glug_vec3 glug_triangle_normal(const struct glug_triangle *t)
{
    struct glug_vec3 ab = t->b, ac = t->c;
    glug_vec3_sub(&ab, &t->a),
    glug_vec3_sub(&ac, &t->a);
    struct glug_vec3 n;
    glug_vec3_cross(&n, &ab, &ac);

    glug_vec3_normalize(&n);
    return n;
}

struct glug_vec3 glug_triangle_centroid(const struct glug_triangle *t)
{
    struct glug_vec3 cent = t->a;
    glug_vec3_add(&cent, &t->b);
    glug_vec3_add(&cent, &t->c);
    glug_vec3_div(&cent, 3.f);

    return cent;
}

struct glug_vec3 glug_triangle_incenter(const struct glug_triangle *t)
{
    struct glug_vec3 tril = { 1.f, 1.f, 1.f };
    return glug_triangle_trilinear(t, &tril);
}

float glug_triangle_distance_to_point(const struct glug_triangle *t, const struct glug_vec3 *p)
{
    struct glug_vec3 close = *p;
    glug_triangle_project_point(t, &close);
    return glug_vec3_dist(&close, p);
}

glug_bool_t glug_triangle_contains_point(const struct glug_triangle *t, const struct glug_vec3 *p)
{
    struct glug_vec3 bary = glug_triangle_to_barycentric(t, p);
    return !(bary.x < 0 || bary.y < 0 || bary.z < 0);
}

void glug_triangle_project_point(const struct glug_triangle *t, struct glug_vec3 *dst)
{
    struct glug_vec3 tril = glug_triangle_to_trilinear(t, dst);
    struct glug_vec3 zero = { 0 };

    if (tril.x > 0 && tril.y > 0 && tril.z > 0) return;

    glug_vec3_max(&tril, &zero);
    *dst = glug_triangle_trilinear(t, &tril);
}
