#ifndef GLUG_VEC4_H
#define GLUG_VEC4_H

#include <glug/import.h>

struct glug_vec4
{
    float x, y, z, w;
};

#ifdef GLUG_USE_TYPEDEFS
    typedef struct glug_vec4 vec4;
#endif

void  GLUG_LIB_API glug_vec4_set(struct glug_vec4 *dst, float x, float y, float z, float w);
void  GLUG_LIB_API glug_vec4_copy(struct glug_vec4 *dst, const struct glug_vec4 *src);
int   GLUG_LIB_API glug_vec4_equal(const struct glug_vec4 *a, const struct glug_vec4 *b);

struct glug_vec4 GLUG_LIB_API glug_vec4_sum(const struct glug_vec4 *a, struct glug_vec4 *b);
struct glug_vec4 GLUG_LIB_API glug_vec4_diff(const struct glug_vec4 *a, struct glug_vec4 *b);
struct glug_vec4 GLUG_LIB_API glug_vec4_prod(const struct glug_vec4 *v, const float scalar);
struct glug_vec4 GLUG_LIB_API glug_vec4_quot(const struct glug_vec4 *v, const float scalar);

void  GLUG_LIB_API glug_vec4_add(struct glug_vec4 *dst, const struct glug_vec4 *b);
void  GLUG_LIB_API glug_vec4_sub(struct glug_vec4 *dst, const struct glug_vec4 *b);
void  GLUG_LIB_API glug_vec4_mul(struct glug_vec4 *dst, const float scalar);
void  GLUG_LIB_API glug_vec4_div(struct glug_vec4 *dst, const float scalar);

float GLUG_LIB_API glug_vec4_dot(const struct glug_vec4 *a, const struct glug_vec4 *b);

float GLUG_LIB_API glug_vec4_len(const struct glug_vec4 *v);
float GLUG_LIB_API glug_vec4_len_squared(const struct glug_vec4 *v);
float GLUG_LIB_API glug_vec4_len_manhattan(const struct glug_vec4 *v);
void  GLUG_LIB_API glug_vec4_set_len(struct glug_vec4 *v, const float length);

int   GLUG_LIB_API glug_vec4_is_normal(const struct glug_vec4 *v);
struct glug_vec4 GLUG_LIB_API glug_vec4_normal(const struct glug_vec4 *v);
void  GLUG_LIB_API glug_vec4_normalize(struct glug_vec4 *v);

float GLUG_LIB_API glug_vec4_dist(const struct glug_vec4 *a, const struct glug_vec4 *b);
float GLUG_LIB_API glug_vec4_dist_squared(const struct glug_vec4 *a, const struct glug_vec4 *b);
float GLUG_LIB_API glug_vec4_dist_manhattan(const struct glug_vec4 *a, const struct glug_vec4 *b);

float GLUG_LIB_API glug_vec4_angle_btw(const struct glug_vec4 *a, const struct glug_vec4 *b);

struct glug_vec4 GLUG_LIB_API glug_vec4_projection(const struct glug_vec4 *a, const struct glug_vec4 *b);
struct glug_vec4 GLUG_LIB_API glug_vec4_reflection(const struct glug_vec4 *a, const struct glug_vec4 *b);
struct glug_vec4 GLUG_LIB_API glug_vec4_rejection(const struct glug_vec4 *a, const struct glug_vec4 *b);

void GLUG_LIB_API glug_vec4_project(struct glug_vec4 *dst, const struct glug_vec4 *b);
void GLUG_LIB_API glug_vec4_reflect(struct glug_vec4 *dst, const struct glug_vec4 *b);
void GLUG_LIB_API glug_vec4_reject(struct glug_vec4 *dst, const struct glug_vec4 *b);


#endif // GLUG_VEC4_H
