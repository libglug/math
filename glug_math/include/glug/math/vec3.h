#ifndef GLUG_VEC3_H
#define GLUG_VEC3_H

struct glug_vec3
{
    float x, y, z;
};

#ifdef GLUG_USE_TYPEDEFS
    typedef struct glug_vec3 vec3;
#endif


void  GLUG_LIB_API glug_vec3_set(struct glug_vec3 *dst, float x, float y, float z);
void  GLUG_LIB_API glug_vec3_copy(struct glug_vec3 *dst, const struct glug_vec3 *src);
int   GLUG_LIB_API glug_vec3_equal(const struct glug_vec3 *v1, const struct glug_vec3 *v2);

struct glug_vec3 GLUG_LIB_API glug_vec3_add(const struct glug_vec3 *v1, struct glug_vec3 *v2);
struct glug_vec3 GLUG_LIB_API glug_vec3_sub(const struct glug_vec3 *v1, struct glug_vec3 *v2);
struct glug_vec3 GLUG_LIB_API glug_vec3_mul(const struct glug_vec3 *v, const float scalar);
struct glug_vec3 GLUG_LIB_API glug_vec3_div(const struct glug_vec3 *v, const float scalar);

void  GLUG_LIB_API glug_vec3_add_set(struct glug_vec3 *dst, const struct glug_vec3 *v2);
void  GLUG_LIB_API glug_vec3_sub_set(struct glug_vec3 *dst, const struct glug_vec3 *v2);
void  GLUG_LIB_API glug_vec3_mul_set(struct glug_vec3 *dst, const float scalar);
void  GLUG_LIB_API glug_vec3_div_set(struct glug_vec3 *dst, const float scalar);

float GLUG_LIB_API glug_vec3_dot(const struct glug_vec3 *v, const struct glug_vec3 *v2);
struct glug_vec3 GLUG_LIB_API glug_vec3_cross(const struct glug_vec3 *v1, const struct glug_vec3 *v2);

float GLUG_LIB_API glug_vec3_len(const struct glug_vec3 *v);
float GLUG_LIB_API glug_vec3_len_squared(const struct glug_vec3 *v);
float GLUG_LIB_API glug_vec3_len_manhattan(const struct glug_vec3 *v);
void  GLUG_LIB_API glug_vec3_set_len(struct glug_vec3 *v, const float length);

int   GLUG_LIB_API glug_vec3_is_normal(const struct glug_vec3 *v);
void  GLUG_LIB_API glug_vec3_normalize(struct glug_vec3 *v);

float GLUG_LIB_API glug_vec3_dist(const struct glug_vec3 *v1, const struct glug_vec3 *v2);
float GLUG_LIB_API glug_vec3_dist_squared(const struct glug_vec3 *v1, const struct glug_vec3 *v2);
float GLUG_LIB_API glug_vec3_dist_manhattan(const struct glug_vec3 *v1, const struct glug_vec3 *v2);

float GLUG_LIB_API glug_vec3_angle_btw(const struct glug_vec3 *v1, const struct glug_vec3 *v2);

#endif // GLUG_VEC3_H
