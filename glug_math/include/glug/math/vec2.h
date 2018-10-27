#ifndef GLUG_VEC2_H
#define GLUG_VEC2_H

struct glug_vec2
{
    float x, y;
};

#ifdef GLUG_USE_TYPEDEFS
    typedef struct glug_vec2 vec2;
#endif


void  GLUG_LIB_API glug_vec2_set(struct glug_vec2 *dst, float x, float y);
void  GLUG_LIB_API glug_vec2_copy(struct glug_vec2 *dst, const struct glug_vec2 *src);
int   GLUG_LIB_API glug_vec2_equal(const struct glug_vec2 *v1, const struct glug_vec2 *v2);

struct glug_vec2 GLUG_LIB_API glug_vec2_add(const struct glug_vec2 *v1, struct glug_vec2 *v2);
struct glug_vec2 GLUG_LIB_API glug_vec2_sub(const struct glug_vec2 *v1, struct glug_vec2 *v2);
struct glug_vec2 GLUG_LIB_API glug_vec2_mul(const struct glug_vec2 *v, const float scalar);
struct glug_vec2 GLUG_LIB_API glug_vec2_div(const struct glug_vec2 *v, const float scalar);

void  GLUG_LIB_API glug_vec2_add_set(struct glug_vec2 *dst, const struct glug_vec2 *v2);
void  GLUG_LIB_API glug_vec2_sub_set(struct glug_vec2 *dst, const struct glug_vec2 *v2);
void  GLUG_LIB_API glug_vec2_mul_set(struct glug_vec2 *dst, const float scalar);
void  GLUG_LIB_API glug_vec2_div_set(struct glug_vec2 *dst, const float scalar);

float GLUG_LIB_API glug_vec2_dot(const struct glug_vec2 *v, const struct glug_vec2 *v2);

float GLUG_LIB_API glug_vec2_len(const struct glug_vec2 *v);
float GLUG_LIB_API glug_vec2_len_squared(const struct glug_vec2 *v);
float GLUG_LIB_API glug_vec2_len_manhattan(const struct glug_vec2 *v);
void  GLUG_LIB_API glug_vec2_set_len(struct glug_vec2 *v, const float length);

int   GLUG_LIB_API glug_vec2_is_normal(const struct glug_vec2 *v);
void  GLUG_LIB_API glug_vec2_normalize(struct glug_vec2 *v);

float GLUG_LIB_API glug_vec2_dist(const struct glug_vec2 *v1, const struct glug_vec2 *v2);
float GLUG_LIB_API glug_vec2_dist_squared(const struct glug_vec2 *v1, const struct glug_vec2 *v2);
float GLUG_LIB_API glug_vec2_dist_manhattan(const struct glug_vec2 *v1, const struct glug_vec2 *v2);

float GLUG_LIB_API glug_vec2_angle_btw(const struct glug_vec2 *v1, const struct glug_vec2 *v2);

#endif // GLUG_VEC2_H
