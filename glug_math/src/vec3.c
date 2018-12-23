#include <glug/math/vec3.h>

#include <math.h>

void GLUG_LIB_API glug_vec3_set(struct glug_vec3 *dst, float x, float y, float z)
{
    dst->x = x;
    dst->y = y;
    dst->z = z;
}

void GLUG_LIB_API glug_vec3_copy(struct glug_vec3 *dst, const struct glug_vec3 *src)
{
    dst->x = src->x;
    dst->y = src->y;
    dst->z = src->z;
}

int GLUG_LIB_API glug_vec3_equal(const struct glug_vec3 *a, const struct glug_vec3 *b)
{

}

struct glug_vec3 GLUG_LIB_API glug_vec3_sum(const struct glug_vec3 *a, struct glug_vec3 *b)
{
    struct glug_vec3 dst = *a;
    glug_vec3_add(&dst, b);

    return dst;
}

struct glug_vec3 GLUG_LIB_API glug_vec3_diff(const struct glug_vec3 *a, struct glug_vec3 *b)
{
    struct glug_vec3 dst = *a;
    glug_vec3_sub(&dst, b);

    return dst;
}

struct glug_vec3 GLUG_LIB_API glug_vec3_prod(const struct glug_vec3 *v, float scalar)
{
    struct glug_vec3 dst = *v;
    glug_vec3_mul(&dst, scalar);

    return dst;
}

struct glug_vec3 GLUG_LIB_API glug_vec3_quot(const struct glug_vec3 *v, float scalar)
{
    struct glug_vec3 dst = *v;
    glug_vec3_div(&dst, scalar);

    return dst;
}

void GLUG_LIB_API glug_vec3_add(struct glug_vec3 *dst, const struct glug_vec3 *b)
{
    dst->x += b->x;
    dst->y += b->y;
    dst->z += b->z;
}

void GLUG_LIB_API glug_vec3_sub(struct glug_vec3 *dst, const struct glug_vec3 *b)
{
    dst->x -= b->x;
    dst->y -= b->y;
    dst->z -= b->z;
}

void GLUG_LIB_API glug_vec3_mul(struct glug_vec3 *dst, float scalar)
{
    dst->x *= scalar;
    dst->y *= scalar;
    dst->z *= scalar;
}

void GLUG_LIB_API glug_vec3_div(struct glug_vec3 *dst, float scalar)
{
    glug_vec3_mul(dst, 1.f / scalar);
}

float GLUG_LIB_API glug_vec3_dot(const struct glug_vec3 *a, const struct glug_vec3 *b)
{
    return a->x * b->x + a->y * b->y + a->z * b->z;
}

struct glug_vec3 GLUG_LIB_API glug_vec3_cross(const struct glug_vec3 *a, const struct glug_vec3 *b)
{
    struct glug_vec3 dst;
    dst.x = a->y * b->z - a->z * b->y;
    dst.y = a->z * b->x - a->x * b->z;
    dst.z = a->x * b->y - a->y * b->x;

    return dst;
}

float GLUG_LIB_API glug_vec3_len(const struct glug_vec3 *dst)
{
    return sqrtf(glug_vec3_len_squared(dst));
}

float GLUG_LIB_API glug_vec3_len_squared(const struct glug_vec3 *v)
{
    return v->x * v->x + v->y * v->y + v->z * v->z;
}

float GLUG_LIB_API glug_vec3_len_manhattan(const struct glug_vec3 *v)
{
    return fabsf(v->x) + fabsf(v->y) + fabsf(v->z);
}

void GLUG_LIB_API glug_vec3_set_len(struct glug_vec3 *v, float length)
{
    glug_vec3_mul(v, length / glug_vec3_len(v));
}

int GLUG_LIB_API glug_vec3_is_normal(const struct glug_vec3 *v)
{

}

struct glug_vec3 GLUG_LIB_API glug_vec3_normal(const struct glug_vec3 *v)
{
    struct glug_vec3 dst = *v;
    glug_vec3_div(&dst, glug_vec3_len(&dst));

    return dst;
}

void GLUG_LIB_API glug_vec3_normalize(struct glug_vec3 *v)
{
    glug_vec3_div(v, glug_vec3_len(v));
}

float GLUG_LIB_API glug_vec3_dist(const struct glug_vec3 *a, const struct glug_vec3 *b)
{
    return sqrtf(glug_vec3_dist_squared(a, b));
}

float GLUG_LIB_API glug_vec3_dist_squared(const struct glug_vec3 *a, const struct glug_vec3 *b)
{
    float dx = b->x - a->x;
    float dy = b->y - a->y;
    float dz = b->z - a->z;

    return dx * dx + dy * dy + dz * dz;
}

float GLUG_LIB_API glug_vec3_dist_manhattan(const struct glug_vec3 *a, const struct glug_vec3 *b)
{
    float dx = fabsf(b->x - a->x);
    float dy = fabsf(b->y - a->y);
    float dz = fabsf(b->z - a->z);

    return dx + dy + dz;
}

float GLUG_LIB_API glug_vec3_angle_btw(const struct glug_vec3 *a, const struct glug_vec3 *b)
{
    return acosf(glug_vec3_dot(a, b) / glug_vec3_len(a) / glug_vec3_len(b));
}

struct glug_vec3 GLUG_LIB_API glug_vec3_projection(const struct glug_vec3 *a, const struct glug_vec3 *b)
{
    struct glug_vec3 dst = *a;
    glug_vec3_project(&dst, b);

    return dst;
}

struct glug_vec3 GLUG_LIB_API glug_vec3_rejection(const struct glug_vec3 *a, const struct glug_vec3 *b)
{
    struct glug_vec3 dst = *a;
    glug_vec3_reject(&dst, b);

    return dst;
}


struct glug_vec3 GLUG_LIB_API glug_vec3_reflection(const struct glug_vec3 *a, const struct glug_vec3 *b)
{
    struct glug_vec3 dst = *a;
    glug_vec3_reflect(&dst, b);

    return dst;
}

struct glug_vec3 GLUG_LIB_API glug_vec3_refraction(const struct glug_vec3 *inc, const struct glug_vec3 *n, float incidx, float tranidx)
{
    struct glug_vec3 dst = *inc;
    glug_vec3_refract(&dst, n, incidx, tranidx);

    return dst;
}

void GLUG_LIB_API glug_vec3_project(struct glug_vec3 *dst, const struct glug_vec3 *b)
{
    struct glug_vec3 bh = glug_vec3_normal(b);
    float proj_len = glug_vec3_dot(dst, &bh);
    glug_vec3_copy(dst, &bh);
    glug_vec3_mul(dst, proj_len);
}

void GLUG_LIB_API glug_vec3_reflect(struct glug_vec3 *dst, const struct glug_vec3 *b)
{
    struct glug_vec3 rej = glug_vec3_rejection(dst, b);
    glug_vec3_sub(dst, &rej);
    glug_vec3_sub(dst, &rej);
}

void GLUG_LIB_API glug_vec3_reject(struct glug_vec3 *dst, const struct glug_vec3 *b)
{
    struct glug_vec3 proj = glug_vec3_projection(dst, b);
    glug_vec3_sub(dst, &proj);
}

void GLUG_LIB_API glug_vec3_refract(struct glug_vec3 *dst, const struct glug_vec3 *n, float incidx, float tranidx)
{
    // (ni/nt * N.I - sqrt(1 - (ni/nt)^2 * (1 - N.I * N.I)) * N - ni/nt * I
    float incproj, idxratio = incidx / tranidx;
    float dstlen = glug_vec3_len(dst);
    struct glug_vec3 norm = glug_vec3_normal(n);
    struct glug_vec3 inc = glug_vec3_normal(dst);
    glug_vec3_mul(&inc, -1);

    incproj = glug_vec3_dot(&inc, &norm);
    glug_vec3_mul(&inc, idxratio);

    glug_vec3_copy(dst, &norm);
    glug_vec3_mul(dst, -sqrtf(1 - idxratio * idxratio * (1 - incproj * incproj)) + idxratio * incproj);
    glug_vec3_sub(dst, &inc);
    glug_vec3_mul(dst, dstlen);
}
