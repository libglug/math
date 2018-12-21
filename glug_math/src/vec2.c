#include <glug/math/vec2.h>

#include <math.h>

void GLUG_LIB_API glug_vec2_set(struct glug_vec2 *dst, float x, float y)
{
    dst->x = x;
    dst->y = y;
}

void GLUG_LIB_API glug_vec2_copy(struct glug_vec2 *dst, const struct glug_vec2 *src)
{
    dst->x = src->x;
    dst->y = src->y;
}

int GLUG_LIB_API glug_vec2_equal(const struct glug_vec2 *v, const struct glug_vec2 *b)
{

}

struct glug_vec2 GLUG_LIB_API glug_vec2_sum(const struct glug_vec2 *a, struct glug_vec2 *b)
{
    struct glug_vec2 dst;
    glug_vec2_copy(&dst, a);
    glug_vec2_add(&dst, b);

    return dst;
}

struct glug_vec2 GLUG_LIB_API glug_vec2_diff(const struct glug_vec2 *a, struct glug_vec2 *b)
{
    struct glug_vec2 dst;
    glug_vec2_copy(&dst, a);
    glug_vec2_sub(&dst, b);

    return dst;
}

struct glug_vec2 GLUG_LIB_API glug_vec2_prod(const struct glug_vec2 *v, const float scalar)
{
    struct glug_vec2 dst;
    glug_vec2_copy(&dst, v);
    glug_vec2_mul(&dst, scalar);

    return dst;
}

struct glug_vec2 GLUG_LIB_API glug_vec2_quot(const struct glug_vec2 *v, const float scalar)
{
    struct glug_vec2 dst;
    glug_vec2_copy(&dst, v);
    glug_vec2_div(&dst, scalar);

    return dst;
}

void GLUG_LIB_API glug_vec2_add(struct glug_vec2 *dst, const struct glug_vec2 *b)
{
    dst->x += b->x;
    dst->y += b->y;
}

void GLUG_LIB_API glug_vec2_sub(struct glug_vec2 *dst, const struct glug_vec2 *b)
{
    dst->x -= b->x;
    dst->y -= b->y;
}

void GLUG_LIB_API glug_vec2_mul(struct glug_vec2 *dst, const float scalar)
{
    dst->x *= scalar;
    dst->y *= scalar;
}

void GLUG_LIB_API glug_vec2_div(struct glug_vec2 *dst, const float scalar)
{
    glug_vec2_mul(dst, 1.f / scalar);
}

float GLUG_LIB_API glug_vec2_dot(const struct glug_vec2 *a, const struct glug_vec2 *b)
{
    return a->x * b->x + a->y * b->y;
}

float GLUG_LIB_API glug_vec2_len(const struct glug_vec2 *v)
{
    return sqrtf(glug_vec2_len_squared(v));
}

float GLUG_LIB_API glug_vec2_len_squared(const struct glug_vec2 *v)
{
    return v->x * v->x + v->y * v->y;
}

float GLUG_LIB_API glug_vec2_len_manhattan(const struct glug_vec2 *v)
{
    return fabsf(v->x) + fabsf(v->y);
}

void GLUG_LIB_API glug_vec2_set_len(struct glug_vec2 *v, const float length)
{
    glug_vec2_mul(v, length / glug_vec2_len(v));
}

int GLUG_LIB_API glug_vec2_is_normal(const struct glug_vec2 *v)
{

}

struct glug_vec2 glug_vec2_normal(const struct glug_vec2 *v)
{
    struct glug_vec2 dst;
    glug_vec2_copy(&dst, v);
    glug_vec2_quot(&dst, glug_vec2_len(&dst));

    return dst;
}

void GLUG_LIB_API glug_vec2_normalize(struct glug_vec2 *v)
{
    glug_vec2_div(v, glug_vec2_len(v));
}

float GLUG_LIB_API glug_vec2_dist(const struct glug_vec2 *a, const struct glug_vec2 *b)
{
    return sqrtf(glug_vec2_dist_squared(a, b));
}

float GLUG_LIB_API glug_vec2_dist_squared(const struct glug_vec2 *a, const struct glug_vec2 *b)
{
    float dx = b->x - a->x;
    float dy = b->y - a->y;

    return dx * dx + dy * dy;
}

float GLUG_LIB_API glug_vec2_dist_manhattan(const struct glug_vec2 *a, const struct glug_vec2 *b)
{
    float dx = fabsf(b->x - a->x);
    float dy = fabsf(b->y - a->y);

    return dx + dy;
}

float GLUG_LIB_API glug_vec2_angle_btw(const struct glug_vec2 *a, const struct glug_vec2 *b)
{
    return acosf(glug_vec2_dot(a, b) / glug_vec2_len(a) / glug_vec2_len(b));
}

struct glug_vec2 GLUG_LIB_API glug_vec2_projection(const struct glug_vec2 *a, const struct glug_vec2 *b)
{
    struct glug_vec2 dst;
    glug_vec2_copy(&dst, a);
    glug_vec2_project(&dst, b);

    return dst;
}

struct glug_vec2 GLUG_LIB_API glug_vec2_reflection(const struct glug_vec2 *a, const struct glug_vec2 *b)
{
    struct glug_vec2 dst;
    glug_vec2_copy(&dst, a);
    glug_vec2_reflect(&dst, b);

    return dst;
}

struct glug_vec2 GLUG_LIB_API glug_vec2_rejection(const struct glug_vec2 *a, const struct glug_vec2 *b)
{
    struct glug_vec2 dst;
    glug_vec2_copy(&dst, a);
    glug_vec2_reject(&dst, b);

    return dst;
}

void GLUG_LIB_API glug_vec2_project(struct glug_vec2 *dst, const struct glug_vec2 *b)
{
    struct glug_vec2 bh = glug_vec2_normal(b);
    float proj_len = glug_vec2_dot(dst, &bh);
    glug_vec2_copy(dst, &bh);
    glug_vec2_prod(dst, proj_len);
}

void GLUG_LIB_API glug_vec2_reflect(struct glug_vec2 *dst, const struct glug_vec2 *b)
{
    struct glug_vec2 rej = glug_vec2_rejection(dst, b);
    glug_vec2_sub(dst, &rej);
    glug_vec2_sub(dst, &rej);
}

void GLUG_LIB_API glug_vec2_reject(struct glug_vec2 *dst, const struct glug_vec2 *b)
{
    struct glug_vec2 proj = glug_vec2_projection(dst, b);
    glug_vec2_diff(dst, &proj);
}
