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

int GLUG_LIB_API glug_vec2_equal(const struct glug_vec2 *v, const struct glug_vec2 *v2)
{

}

struct glug_vec2 GLUG_LIB_API glug_vec2_add(const struct glug_vec2 *v1, struct glug_vec2 *v2)
{
    struct glug_vec2 dst;
    glug_vec2_copy(&dst, v1);
    glug_vec2_add_set(&dst, v2);

    return dst;
}

struct glug_vec2 GLUG_LIB_API glug_vec2_sub(const struct glug_vec2 *v1, struct glug_vec2 *v2)
{
    struct glug_vec2 dst;
    glug_vec2_copy(&dst, v1);
    glug_vec2_sub_set(&dst, v2);

    return dst;
}

struct glug_vec2 GLUG_LIB_API glug_vec2_mul(const struct glug_vec2 *v, const float scalar)
{
    struct glug_vec2 dst;
    glug_vec2_copy(&dst, v);
    glug_vec2_mul_set(&dst, scalar);

    return dst;
}

struct glug_vec2 GLUG_LIB_API glug_vec2_div(const struct glug_vec2 *v, const float scalar)
{
    struct glug_vec2 dst;
    glug_vec2_copy(&dst, v);
    glug_vec2_div_set(&dst, scalar);

    return dst;
}

void GLUG_LIB_API glug_vec2_add_set(struct glug_vec2 *dst, const struct glug_vec2 *v2)
{
    dst->x += v2->x;
    dst->y += v2->y;
}

void GLUG_LIB_API glug_vec2_sub_set(struct glug_vec2 *dst, const struct glug_vec2 *v2)
{
    dst->x -= v2->x;
    dst->y -= v2->y;
}

void GLUG_LIB_API glug_vec2_mul_set(struct glug_vec2 *dst, const float scalar)
{
    dst->x *= scalar;
    dst->y *= scalar;
}

void GLUG_LIB_API glug_vec2_div_set(struct glug_vec2 *dst, const float scalar)
{    
    dst->x /= scalar;
    dst->y /= scalar;
}

float GLUG_LIB_API glug_vec2_dot(const struct glug_vec2 *v1, const struct glug_vec2 *v2)
{
    return v1->x * v2->x + v1->y * v2->y;
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
    glug_vec2_mul_set(v, length / glug_vec2_len(v));
}

int GLUG_LIB_API glug_vec2_is_normal(const struct glug_vec2 *v)
{
    return glug_vec2_len(v) == 1.f;
}

void GLUG_LIB_API glug_vec2_normalize(struct glug_vec2 *v)
{
    glug_vec2_div_set(v, glug_vec2_len(v));
}

float GLUG_LIB_API glug_vec2_dist(const struct glug_vec2 *v1, const struct glug_vec2 *v2)
{
    return sqrtf(glug_vec2_dist_squared(v1, v2));
}

float GLUG_LIB_API glug_vec2_dist_squared(const struct glug_vec2 *v1, const struct glug_vec2 *v2)
{
    float dx = v2->x - v1->x;
    float dy = v2->y - v1->y;

    return dx * dx + dy * dy;
}

float GLUG_LIB_API glug_vec2_dist_manhattan(const struct glug_vec2 *v1, const struct glug_vec2 *v2)
{
    float dx = fabsf(v2->x - v1->x);
    float dy = fabsf(v2->y - v1->y);

    return dx + dy;
}

float GLUG_LIB_API glug_vec2_angle_btw(const struct glug_vec2 *v1, const struct glug_vec2 *v2)
{
    return acosf(glug_vec2_dot(v1, v2) / glug_vec2_len(v1) / glug_vec2_len(v2));
}
