#include <glug/math/triangle2.h>
#include <glug/math/vec2.h>
#include <glug/math/vec3.h>

void glug_triangle2_set(struct glug_triangle2 *dst, const struct glug_vec2 *a, const struct glug_vec2 *b, const struct glug_vec2 *c)
{
    dst->a = *a;
    dst->b = *b;
    dst->c = *c;
}

glug_bool_t glug_triangle2_equal(const struct glug_triangle2 *a, const struct glug_triangle2 *b)
{

}

struct glug_vec2 glug_triangle2_barycentric(const struct glug_triangle2 *t, const struct glug_vec3 *bary)
{
    struct glug_vec2 dst;
    dst.x = bary->x * t->a.x + bary->y * t->b.x + bary->z * t->c.x;
    dst.y = bary->x * t->a.y + bary->y * t->b.y + bary->z * t->c.y;

    return dst;
}

struct glug_vec2 glug_triangle2_trilinear(const struct glug_triangle2 *t, const struct glug_vec3 *tril)
{
    float ax = glug_vec2_dist(&t->b, &t->c) * tril->x,
          by = glug_vec2_dist(&t->c, &t->a) * tril->y,
          cz = glug_vec2_dist(&t->a, &t->b) * tril->z,
          s = (ax + by + cz);
    struct glug_vec2 dst = {
        (t->a.x * ax + t->b.x * by + t->c.x * cz),
        (t->a.y * ax + t->b.y * by + t->c.y * cz),
    };
    glug_vec2_div(&dst, s);

    return dst;
}

struct glug_vec3 glug_triangle2_to_barycentric(const struct glug_triangle2 *t, const struct glug_vec2 *p)
{
    struct glug_vec2 p0 = glug_vec2_diff(p, &t->a),
                     p1 = glug_vec2_diff(&t->b, &t->a),
                     p2 = glug_vec2_diff(&t->c, &t->a);
    float p01 = glug_vec2_dot(&p0, &p1),
          p02 = glug_vec2_dot(&p0, &p2),
          p11 = glug_vec2_dot(&p1, &p1),
          p12 = glug_vec2_dot(&p1, &p2),
          p22 = glug_vec2_dot(&p2, &p2);

    float den = 1.f / (p11 * p22 - p12 * p12);

    float w1 = (p01 * p22 - p12 * p02) * den,
          w2 = (p11 * p02 - p01 * p12) * den;

    struct glug_vec3 dst = { 1.f - w1 - w2, w1, w2 };
    return dst;
}

struct glug_vec3 glug_triangle2_to_trilinear(const struct glug_triangle2 *t, const struct glug_vec2 *p)
{
    float a = glug_vec2_dist(&t->b, &t->c),
          b = glug_vec2_dist(&t->c, &t->a),
          c = glug_vec2_dist(&t->a, &t->b);
    struct glug_vec3 bary = glug_triangle2_to_barycentric(t, p);
    struct glug_vec3 dst = {
        bary.x / a,
        bary.y / b,
        bary.z / c,
    };

    return dst;
}

struct glug_vec2 glug_triangle2_centroid(const struct glug_triangle2 *t)
{
    struct glug_vec2 cent = t->a;
    glug_vec2_add(&cent, &t->b);
    glug_vec2_add(&cent, &t->c);
    glug_vec2_div(&cent, 3.f);

    return cent;
}

struct glug_vec2 glug_triangle2_incenter(const struct glug_triangle2 *t)
{
    struct glug_vec3 tril = { 1.f, 1.f, 1.f };
    return glug_triangle2_trilinear(t, &tril);
}

float glug_triangle2_distance_to_point(const struct glug_triangle2 *t, const struct glug_vec2 *p)
{
    struct glug_vec2 close = glug_triangle2_closest_point(t, p);
    return glug_vec2_dist(&close, p);
}

glug_bool_t glug_triangle2_contains_point(const struct glug_triangle2 *t, const struct glug_vec2 *p)
{
    struct glug_vec3 bary = glug_triangle2_to_barycentric(t, p);
    return !(bary.x < 0 || bary.y < 0 || bary.z < 0);
}

struct glug_vec2 glug_triangle2_closest_point(const struct glug_triangle2 *t, const struct glug_vec2 *p)
{
    struct glug_vec2 dst = *p;
    glug_triangle2_project_point(t, &dst);

    return dst;
}

void glug_triangle2_project_point(const struct glug_triangle2 *t, struct glug_vec2 *dst)
{
    struct glug_vec3 tril = glug_triangle2_to_trilinear(t, dst);
    struct glug_vec3 zero = { 0 };

    if (tril.x > 0 && tril.y > 0 && tril.z > 0) return;

    glug_vec3_maximize(&tril, &zero);
    *dst = glug_triangle2_trilinear(t, &tril);
}
