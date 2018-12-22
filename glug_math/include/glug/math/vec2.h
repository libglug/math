#ifndef GLUG_VEC2_H
#define GLUG_VEC2_H

#include <glug/import.h>

struct glug_vec2
{
    float x, y;
};

#ifdef GLUG_USE_TYPEDEFS
    typedef struct glug_vec2 vec2;
#endif

void  GLUG_LIB_API glug_vec2_set(struct glug_vec2 *dst, float x, float y);
void  GLUG_LIB_API glug_vec2_copy(struct glug_vec2 *dst, const struct glug_vec2 *src);
int   GLUG_LIB_API glug_vec2_equal(const struct glug_vec2 *a, const struct glug_vec2 *b);

struct glug_vec2 GLUG_LIB_API glug_vec2_sum(const struct glug_vec2 *a, struct glug_vec2 *b);
struct glug_vec2 GLUG_LIB_API glug_vec2_diff(const struct glug_vec2 *a, struct glug_vec2 *b);
struct glug_vec2 GLUG_LIB_API glug_vec2_prod(const struct glug_vec2 *v, const float scalar);
struct glug_vec2 GLUG_LIB_API glug_vec2_quot(const struct glug_vec2 *v, const float scalar);

void  GLUG_LIB_API glug_vec2_add(struct glug_vec2 *dst, const struct glug_vec2 *b);
void  GLUG_LIB_API glug_vec2_sub(struct glug_vec2 *dst, const struct glug_vec2 *b);
void  GLUG_LIB_API glug_vec2_mul(struct glug_vec2 *dst, const float scalar);
void  GLUG_LIB_API glug_vec2_div(struct glug_vec2 *dst, const float scalar);

float GLUG_LIB_API glug_vec2_dot(const struct glug_vec2 *v, const struct glug_vec2 *b);

float GLUG_LIB_API glug_vec2_len(const struct glug_vec2 *v);
float GLUG_LIB_API glug_vec2_len_squared(const struct glug_vec2 *v);
float GLUG_LIB_API glug_vec2_len_manhattan(const struct glug_vec2 *v);
void  GLUG_LIB_API glug_vec2_set_len(struct glug_vec2 *v, const float length);

int   GLUG_LIB_API glug_vec2_is_normal(const struct glug_vec2 *v);
struct glug_vec2 GLUG_LIB_API glug_vec2_normal(const struct glug_vec2 *v);
void  GLUG_LIB_API glug_vec2_normalize(struct glug_vec2 *v);

float GLUG_LIB_API glug_vec2_dist(const struct glug_vec2 *a, const struct glug_vec2 *b);
float GLUG_LIB_API glug_vec2_dist_squared(const struct glug_vec2 *a, const struct glug_vec2 *b);
float GLUG_LIB_API glug_vec2_dist_manhattan(const struct glug_vec2 *a, const struct glug_vec2 *b);

float GLUG_LIB_API glug_vec2_angle_btw(const struct glug_vec2 *a, const struct glug_vec2 *b);

struct glug_vec2 GLUG_LIB_API glug_vec2_projection(const struct glug_vec2 *a, const struct glug_vec2 *b);
struct glug_vec2 GLUG_LIB_API glug_vec2_reflection(const struct glug_vec2 *a, const struct glug_vec2 *b);
struct glug_vec2 GLUG_LIB_API glug_vec2_rejection(const struct glug_vec2 *a, const struct glug_vec2 *b);

void GLUG_LIB_API glug_vec2_project(struct glug_vec2 *a, const struct glug_vec2 *b);
void GLUG_LIB_API glug_vec2_reflect(struct glug_vec2 *a, const struct glug_vec2 *b);
void GLUG_LIB_API glug_vec2_reject(struct glug_vec2 *a, const struct glug_vec2 *b);

#endif // GLUG_VEC2_H
