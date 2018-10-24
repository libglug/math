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

int GLUG_LIB_API glug_vec3_equal(const struct glug_vec3 *v, const struct glug_vec3 *v2)
{

}

void GLUG_LIB_API glug_vec3_add(struct glug_vec3 *dst, const struct glug_vec3 *v2)
{
    dst->x += v2->x;
    dst->y += v2->y;
    dst->z += v2->z;
}

void GLUG_LIB_API glug_vec3_sub(struct glug_vec3 *dst, const struct glug_vec3 *v2)
{
    dst->x -= v2->x;
    dst->y -= v2->y;
    dst->z -= v2->z;
}

void GLUG_LIB_API glug_vec3_mul_scalar(struct glug_vec3 *dst, const float scalar)
{
    dst->x *= scalar;
    dst->y *= scalar;
    dst->z *= scalar;
}

void GLUG_LIB_API glug_vec3_div_scalar(struct glug_vec3 *dst, const float scalar)
{    
    dst->x /= scalar;
    dst->y /= scalar;
    dst->z /= scalar;
}

float GLUG_LIB_API glug_vec3_dot(const struct glug_vec3 *v1, const struct glug_vec3 *v2)
{
    return v1->x * v2->x + v1->y * v2->y + v1->z * v2->z;
}

struct glug_vec3 GLUG_LIB_API glug_vec3_cross(const struct glug_vec3 *v1, const struct glug_vec3 *v2)
{
    struct glug_vec3 dst;
    dst.x = v1->y * v2->z - v1->z * v2->y;
    dst.y = v1->z * v2->x - v1->x * v2->z;
    dst.z = v1->x * v2->y - v1->y * v2->x;

    return dst;
}

float GLUG_LIB_API glug_vec3_len(const struct glug_vec3 *v)
{
    return sqrtf(glug_vec3_len_squared(v));
}

float GLUG_LIB_API glug_vec3_len_squared(const struct glug_vec3 *v)
{
    return v->x * v->x + v->y * v->y + v->z * v->z;
}

float GLUG_LIB_API glug_vec3_len_manhattan(const struct glug_vec3 *v)
{
    return v->x + v->y + v->z;
}

void GLUG_LIB_API glug_vec3_set_len(struct glug_vec3 *v, const float length)
{
    glug_vec3_normalize(v);
    glug_vec3_mul_scalar(v, length);
}

int GLUG_LIB_API glug_vec3_is_normal(const struct glug_vec3 *v)
{

}

void GLUG_LIB_API glug_vec3_normalize(struct glug_vec3 *v)
{
    glug_vec3_div_scalar(v, glug_vec3_len(v));
}

float GLUG_LIB_API glug_vec3_dist(const struct glug_vec3 *v1, const struct glug_vec3 *v2)
{
    return sqrtf(glug_vec3_dist_squared(v1, v2));
}

float GLUG_LIB_API glug_vec3_dist_squared(const struct glug_vec3 *v1, const struct glug_vec3 *v2)
{
    float dx = v2->x - v1->x;
    float dy = v2->y - v1->y;
    float dz = v2->z - v1->z;

    return dx * dx + dy * dy + dz * dz;
}

float GLUG_LIB_API glug_vec3_dist_manhattan(const struct glug_vec3 *v1, const struct glug_vec3 *v2)
{
    float dx = v2->x - v1->x;
    float dy = v2->y - v1->y;
    float dz = v2->z - v1->z;

    return dx + dy + dz;
}

float GLUG_LIB_API glug_vec3_angle_btw(const struct glug_vec3 *v1, const struct glug_vec3 *v2)
{
    return acosf(glug_vec3_dot(v1, v2) / glug_vec3_len(v1) / glug_vec3_len(v2));
}
