#include <glug/math/vec4.h>

#include <math.h>

void GLUG_LIB_API glug_vec4_set(struct glug_vec4 *dst, float x, float y, float z, float w)
{
    dst->x = x;
    dst->y = y;
    dst->z = z;
    dst->w = w;
}
void GLUG_LIB_API glug_vec4_copy(struct glug_vec4 *dst, const struct glug_vec4 *src)
{
    dst->x = src->x;
    dst->y = src->y;
    dst->z = src->z;
    dst->w = src->w;
}

int GLUG_LIB_API glug_vec4_equal(const struct glug_vec4 *a, const struct glug_vec4 *b)
{

}

struct glug_vec4 GLUG_LIB_API glug_vec4_sum(const struct glug_vec4 *a, struct glug_vec4 *b)
{
    struct glug_vec4 dst;
    glug_vec4_copy(&dst, a);
    glug_vec4_add(&dst, b);

    return dst;
}

struct glug_vec4 GLUG_LIB_API glug_vec4_diff(const struct glug_vec4 *a, struct glug_vec4 *b)
{
    struct glug_vec4 dst;
    glug_vec4_copy(&dst, a);
    glug_vec4_sub(&dst, b);

    return dst;
}

struct glug_vec4 GLUG_LIB_API glug_vec4_prod(const struct glug_vec4 *v, const float scalar)
{
    struct glug_vec4 dst;
    glug_vec4_copy(&dst, v);
    glug_vec4_mul(&dst, scalar);

    return dst;
}

struct glug_vec4 GLUG_LIB_API glug_vec4_quot(const struct glug_vec4 *v, const float scalar)
{
    struct glug_vec4 dst;
    glug_vec4_copy(&dst, v);
    glug_vec4_div(&dst, scalar);

    return dst;
}

void GLUG_LIB_API glug_vec4_add(struct glug_vec4 *dst, const struct glug_vec4 *b)
{
    dst->x += b->x;
    dst->y += b->y;
    dst->z += b->z;
    dst->w += b->w;
}

void GLUG_LIB_API glug_vec4_sub(struct glug_vec4 *dst, const struct glug_vec4 *b)
{
    dst->x -= b->x;
    dst->y -= b->y;
    dst->z -= b->z;
    dst->w -= b->w;
}

void GLUG_LIB_API glug_vec4_mul(struct glug_vec4 *dst, const float scalar)
{
    dst->x *= scalar;
    dst->y *= scalar;
    dst->z *= scalar;
    dst->w *= scalar;
}

void GLUG_LIB_API glug_vec4_div(struct glug_vec4 *dst, const float scalar)
{
    glug_vec4_mul(dst, 1.f / scalar);
}

float GLUG_LIB_API glug_vec4_dot(const struct glug_vec4 *a, const struct glug_vec4 *b)
{
    return a->x * b->x + a->y * b->y + a->z * b->z + a->w * b->w;
}

float GLUG_LIB_API glug_vec4_len(const struct glug_vec4 *v)
{
    return sqrtf(glug_vec4_len_squared(v));
}

float GLUG_LIB_API glug_vec4_len_squared(const struct glug_vec4 *v)
{
    return v->x * v->x + v->y * v->y + v->z * v->z + v->w * v->w;
}

float GLUG_LIB_API glug_vec4_len_manhattan(const struct glug_vec4 *v)
{
    return fabsf(v->x) + fabsf(v->y) + fabsf(v->z) + fabsf(v->w);
}

void GLUG_LIB_API glug_vec4_set_len(struct glug_vec4 *v, const float length)
{
    glug_vec4_mul(v, length / glug_vec4_len(v));
}

int GLUG_LIB_API glug_vec4_is_normal(const struct glug_vec4 *v)
{

}

struct glug_vec4 glug_vec4_normal(const struct glug_vec4 *v)
{
    struct glug_vec4 dst;
    glug_vec4_copy(&dst, v);
    glug_vec4_quot(&dst, glug_vec4_len(&dst));

    return dst;
}

void GLUG_LIB_API glug_vec4_normalize(struct glug_vec4 *v)
{
    glug_vec4_div(v, glug_vec4_len(v));
}

float GLUG_LIB_API glug_vec4_dist(const struct glug_vec4 *a, const struct glug_vec4 *b)
{
    return sqrtf(glug_vec4_dist_squared(a, b));
}

float GLUG_LIB_API glug_vec4_dist_squared(const struct glug_vec4 *a, const struct glug_vec4 *b)
{
    float dx = b->x - a->x;
    float dy = b->y - a->y;
    float dz = b->z - a->z;
    float dw = b->w - a->w;

    return dx * dx + dy * dy + dz * dz + dw * dw;
}

float GLUG_LIB_API glug_vec4_dist_manhattan(const struct glug_vec4 *a, const struct glug_vec4 *b)
{
    float dx = fabsf(b->x - a->x);
    float dy = fabsf(b->y - a->y);
    float dz = fabsf(b->z - a->z);
    float dw = fabsf(b->w - a->w);

    return dx + dy + dz + dw;
}

float GLUG_LIB_API glug_vec4_angle_btw(const struct glug_vec4 *a, const struct glug_vec4 *b)
{
    return acosf(glug_vec4_dot(a, b) / glug_vec4_len(a) / glug_vec4_len(b));
}

struct glug_vec4 GLUG_LIB_API glug_vec4_projection(const struct glug_vec4 *a, const struct glug_vec4 *b)
{
    struct glug_vec4 dst;
    glug_vec4_copy(&dst, a);
    glug_vec4_project(&dst, b);

    return dst;
}

struct glug_vec4 GLUG_LIB_API glug_vec4_reflection(const struct glug_vec4 *a, const struct glug_vec4 *b)
{
    struct glug_vec4 dst;
    glug_vec4_copy(&dst, a);
    glug_vec4_reflect(&dst, b);

    return dst;
}

struct glug_vec4 GLUG_LIB_API glug_vec4_rejection(const struct glug_vec4 *a, const struct glug_vec4 *b)
{
    struct glug_vec4 dst;
    glug_vec4_copy(&dst, a);
    glug_vec4_reject(&dst, b);

    return dst;
}

void GLUG_LIB_API glug_vec4_project(struct glug_vec4 *dst, const struct glug_vec4 *b)
{
    struct glug_vec4 bh = glug_vec4_normal(b);
    float proj_len = glug_vec4_dot(dst, &bh);
    glug_vec4_copy(dst, &bh);
    glug_vec4_prod(dst, proj_len);
}

void GLUG_LIB_API glug_vec4_reflect(struct glug_vec4 *dst, const struct glug_vec4 *b)
{
    struct glug_vec4 rej = glug_vec4_rejection(dst, b);
    glug_vec4_sub(dst, &rej);
    glug_vec4_sub(dst, &rej);
}

void GLUG_LIB_API glug_vec4_reject(struct glug_vec4 *dst, const struct glug_vec4 *b)
{
    struct glug_vec4 proj = glug_vec4_projection(dst, b);
    glug_vec4_diff(dst, &proj);
}
