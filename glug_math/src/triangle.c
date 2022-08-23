#include <glug/math/triangle.h>
#include <glug/math/line.h>
#include <glug/math/vec3.h>
#include <math.h>

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
    float ax = glug_triangle_len_a(t) * tril->x,
          by = glug_triangle_len_b(t) * tril->y,
          cz = glug_triangle_len_c(t) * tril->z,
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
    struct glug_vec3 p0, p1, p2;
    glug_vec3_sub(&p0, p, &t->a);
    glug_vec3_sub(&p1, &t->b, &t->a);
    glug_vec3_sub(&p2, &t->c, &t->a);

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

float glug_triangle_len_a(const struct glug_triangle *t)
{
    return sqrtf(glug_triangle_len_sq_a(t));
}

float glug_triangle_len_sq_a(const struct glug_triangle *t)
{
    struct glug_vec3 a;
    glug_vec3_sub(&a, &t->b, &t->c);

    return glug_vec3_len_sq(&a);
}

float glug_triangle_len_b(const struct glug_triangle *t)
{
    return sqrtf(glug_triangle_len_sq_b(t));
}

float glug_triangle_len_sq_b(const struct glug_triangle *t)
{
    struct glug_vec3 b;
    glug_vec3_sub(&b, &t->a, &t->c);

    return glug_vec3_len_sq(&b);
}

float glug_triangle_len_c(const struct glug_triangle *t)
{
    return sqrtf(glug_triangle_len_sq_c(t));
}

float glug_triangle_len_sq_c(const struct glug_triangle *t)
{
    struct glug_vec3 c;
    glug_vec3_sub(&c, &t->a, &t->b);

    return glug_vec3_len_sq(&c);
}

float glug_triangle_perimeter(const struct glug_triangle *t)
{
    return (
        glug_triangle_len_a(t) +
        glug_triangle_len_b(t) +
        glug_triangle_len_c(t)
    );

}

float glug_triangle_angle_a(const struct glug_triangle *t)
{
    struct glug_vec3 ab, ac;
    glug_vec3_sub(&ab, &t->b, &t->a);
    glug_vec3_sub(&ac, &t->c, &t->a);

    return glug_vec3_angle_btw(&ab, &ac);
}

float glug_triangle_angle_b(const struct glug_triangle *t)
{
    struct glug_vec3 ba, bc;
    glug_vec3_sub(&ba, &t->a, &t->b);
    glug_vec3_sub(&bc, &t->c, &t->b);

    return glug_vec3_angle_btw(&ba, &bc);
}

float glug_triangle_angle_c(const struct glug_triangle *t)
{
    struct glug_vec3 ca, cb;
    glug_vec3_sub(&ca, &t->a, &t->c);
    glug_vec3_sub(&cb, &t->b, &t->c);

    return glug_vec3_angle_btw(&ca, &cb);
}

struct glug_vec3 glug_triangle_normal(const struct glug_triangle *t)
{
    struct glug_vec3 ab, ac;
    glug_vec3_sub(&ab, &t->b, &t->a),
    glug_vec3_sub(&ac, &t->c, &t->a);

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

void glug_triangle_orthocenter(const struct glug_triangle *t, struct glug_vec3 *dst)
{
    struct glug_line ab, bc;
    glug_line_from_points(&ab, &t->a, &t->b);
    glug_line_from_points(&bc, &t->b, &t->c);

    struct glug_vec3 ab_int, bc_int;
    glug_line_project_point(&ab, &ab_int, &t->c);
    glug_line_project_point(&bc, &bc_int, &t->a);

    struct glug_line ab_alt, bc_alt;
    glug_line_from_points(&ab_alt, &ab_int, &t->c);
    glug_line_from_points(&bc_alt, &bc_int, &t->a);

    struct glug_vec3 center;
    glug_line_closest_points(&ab_alt, &bc_alt, &center, &center);

    *dst = center;
}

void glug_triangle_circumcenter(const struct glug_triangle *t, struct glug_vec3 *dst)
{
    const struct glug_vec3 n = glug_triangle_normal(t);

    struct glug_vec3 m_ab = t->b;
    glug_vec3_add(&m_ab, &t->a);
    glug_vec3_mul(&m_ab, 0.5f);
    struct glug_vec3 m_bc = t->c;
    glug_vec3_add(&m_bc, &t->b);
    glug_vec3_mul(&m_bc, 0.5f);

    struct glug_vec3 ab_bisectv, bc_bisectv;
    glug_vec3_cross(&ab_bisectv, &m_ab, &n);
    glug_vec3_cross(&bc_bisectv, &m_bc, &n);
    struct glug_line ab_bisector = {
        .v = ab_bisectv,
        .r0 = m_ab,
    };
    struct glug_line bc_bisector = {
        .v = bc_bisectv,
        .r0 = m_bc,
    };

    struct glug_vec3 center;
    glug_line_closest_points(&ab_bisector, &bc_bisector, &center, &center);

    *dst = center;
}

void glug_triangle_excenter_a(const struct glug_triangle *t, struct glug_vec3 *dst)
{
    struct glug_vec3 ex_tril = { -1.f, 1.f, 1.f };
    *dst = glug_triangle_trilinear(t, &ex_tril);
}

void glug_triangle_excenter_b(const struct glug_triangle *t, struct glug_vec3 *dst)
{
    struct glug_vec3 ex_tril = { 1.f, -1.f, 1.f };
    *dst = glug_triangle_trilinear(t, &ex_tril);
}

void glug_triangle_excenter_c(const struct glug_triangle *t, struct glug_vec3 *dst)
{
    struct glug_vec3 ex_tril = { 1.f, 1.f, -1.f };
    *dst = glug_triangle_trilinear(t, &ex_tril);
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
