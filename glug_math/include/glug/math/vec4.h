#ifndef GLUG_VEC4_H
#define GLUG_VEC4_H

struct glug_vec4
{
    float x, y, z, w;
};

void GLUG_LIB_API glug_vec4_set(struct glug_vec4 *dst, float x, float y, float z, float w);
void GLUG_LIB_API glug_vec4_copy(struct glug_vec4 *dst, const struct glug_vec4 *src);

int GLUG_LIB_API glug_vec4_equal(const struct glug_vec4 *v1, const struct glug_vec4 *v2);

void GLUG_LIB_API glug_vec4_add(struct glug_vec4 *dst, const struct glug_vec4 *v2);
void GLUG_LIB_API glug_vec4_sub(struct glug_vec4 *dst, const struct glug_vec4 *v2);
void GLUG_LIB_API glug_vec4_mul_scalar(struct glug_vec4 *dst, const float scalar);
void GLUG_LIB_API glug_vec4_div_scalar(struct glug_vec4 *dst, const float scalar);

float GLUG_LIB_API glug_vec4_dot(const struct glug_vec4 *v1, const struct glug_vec4 *v2);

float GLUG_LIB_API glug_vec4_len(const struct glug_vec4 *v);
float GLUG_LIB_API glug_vec4_len_squared(const struct glug_vec4 *v);
float GLUG_LIB_API glug_vec4_len_manhattan(const struct glug_vec4 *v);
void GLUG_LIB_API glug_vec4_set_length(struct glug_vec4 *v, const float length);

int GLUG_LIB_API glug_vec4_is_normal(const struct glug_vec4 *v);
void GLUG_LIB_API glug_vec4_normalize(struct glug_vec4 *v);

float GLUG_LIB_API glug_vec4_dist(const struct glug_vec4 *v1, const struct glug_vec4 *v2);
float GLUG_LIB_API glug_vec4_dist_squared(const struct glug_vec4 *v1, const struct glug_vec4 *v2);
float GLUG_LIB_API glug_vec4_dist_manhattan(const struct glug_vec4 *v1, const struct glug_vec4 *v2);

float GLUG_LIB_API glug_vec4_angle_btw(const struct glug_vec4 *v1, const struct glug_vec4 *v2);

#endif // GLUG_VEC4_H
