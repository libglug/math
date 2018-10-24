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

int GLUG_LIB_API glug_vec4_equal(const struct glug_vec4 *v, const struct glug_vec4 *v2)
{

}

void GLUG_LIB_API glug_vec4_add(struct glug_vec4 *dst, const struct glug_vec4 *v2)
{
    dst->x += v2->x;
    dst->y += v2->y;
    dst->z += v2->z;
    dst->w += v2->w;
}

void GLUG_LIB_API glug_vec4_sub(struct glug_vec4 *dst, const struct glug_vec4 *v2)
{
    dst->x -= v2->x;
    dst->y -= v2->y;
    dst->z -= v2->z;
    dst->w -= v2->w;
}

void GLUG_LIB_API glug_vec4_mul_scalar(struct glug_vec4 *dst, const float scalar)
{
    dst->x *= scalar;
    dst->y *= scalar;
    dst->z *= scalar;
    dst->w *= scalar;
}

void GLUG_LIB_API glug_vec4_div_scalar(struct glug_vec4 *dst, const float scalar)
{
    dst->x /= scalar;
    dst->y /= scalar;
    dst->z /= scalar;
    dst->w /= scalar;
}

float GLUG_LIB_API glug_vec4_dot(const struct glug_vec4 *v1, const struct glug_vec4 *v2)
{
    return v1->x * v2->x + v1->y * v2->y + v1->z * v2->z + v1->w * v2->w;
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
    return v->x + v->y + v->z + v->w;
}

void GLUG_LIB_API glug_vec4_set_length(struct glug_vec4 *v, const float length)
{
    glug_vec4_normalize(v);
    glug_vec4_mul_scalar(v, length);
}

int GLUG_LIB_API glug_vec4_is_normal(const struct glug_vec4 *v)
{

}

void GLUG_LIB_API glug_vec4_normalize(struct glug_vec4 *v)
{
    glug_vec4_div_scalar(v, glug_vec4_len(v));
}

float GLUG_LIB_API glug_vec4_dist(const struct glug_vec4 *v1, const struct glug_vec4 *v2)
{
    return sqrtf(glug_vec4_dist_squared(v1, v2));
}

float GLUG_LIB_API glug_vec4_dist_squared(const struct glug_vec4 *v1, const struct glug_vec4 *v2)
{
    float dx = v2->x - v1->x;
    float dy = v2->y - v1->y;
    float dz = v2->z - v1->z;
    float dw = v2->w - v1->w;

    return dx * dx + dy * dy + dz * dz + dw * dw;
}

float GLUG_LIB_API glug_vec4_dist_manhattan(const struct glug_vec4 *v1, const struct glug_vec4 *v2)
{
    float dx = v2->x - v1->x;
    float dy = v2->y - v1->y;
    float dz = v2->z - v1->z;
    float dw = v2->w - v1->w;

    return dx + dy + dz + dw;
}

float GLUG_LIB_API glug_vec4_angle_btw(const struct glug_vec4 *v1, const struct glug_vec4 *v2)
{
    return acosf(glug_vec4_dot(v1, v2) / glug_vec4_len(v1) / glug_vec4_len(v2));
}
