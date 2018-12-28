#ifndef GLUG_VEC2_H
#define GLUG_VEC2_H

#include <glug/import.h>
#include <glug/math/vec2_t.h>

void  GLUG_LIB_API glug_vec2_set(struct glug_vec2 *dst, float x, float y);
void  GLUG_LIB_API glug_vec2_copy(struct glug_vec2 *dst, const struct glug_vec2 *src);
int   GLUG_LIB_API glug_vec2_equal(const struct glug_vec2 *a, const struct glug_vec2 *b);

struct glug_vec2 GLUG_LIB_API glug_vec2_sum(const struct glug_vec2 *a, const struct glug_vec2 *b);
struct glug_vec2 GLUG_LIB_API glug_vec2_diff(const struct glug_vec2 *a, const struct glug_vec2 *b);
struct glug_vec2 GLUG_LIB_API glug_vec2_prod(const struct glug_vec2 *v, float scalar);
struct glug_vec2 GLUG_LIB_API glug_vec2_quot(const struct glug_vec2 *v, float scalar);

void GLUG_LIB_API glug_vec2_add(struct glug_vec2 *dst, const struct glug_vec2 *b);
void GLUG_LIB_API glug_vec2_sub(struct glug_vec2 *dst, const struct glug_vec2 *b);
void GLUG_LIB_API glug_vec2_mul(struct glug_vec2 *dst, float scalar);
void GLUG_LIB_API glug_vec2_div(struct glug_vec2 *dst, float scalar);

struct glug_vec2 GLUG_LIB_API glug_vec2_max(const struct glug_vec2 *a, const struct glug_vec2 *b);
struct glug_vec2 GLUG_LIB_API glug_vec2_min(const struct glug_vec2 *a, const struct glug_vec2 *b);
struct glug_vec2 GLUG_LIB_API glug_vec2_clamped(const struct glug_vec2 *a, const struct glug_vec2 *min, const struct glug_vec2 *max);

void GLUG_LIB_API glug_vec2_maximize(struct glug_vec2 *dst, const struct glug_vec2 *b);
void GLUG_LIB_API glug_vec2_minimize(struct glug_vec2 *dst, const struct glug_vec2 *b);
void GLUG_LIB_API glug_vec2_clamp(struct glug_vec2 *dst, const struct glug_vec2 *min, const struct glug_vec2 *max);

float GLUG_LIB_API glug_vec2_dot(const struct glug_vec2 *v, const struct glug_vec2 *b);

float GLUG_LIB_API glug_vec2_len(const struct glug_vec2 *v);
float GLUG_LIB_API glug_vec2_len_squared(const struct glug_vec2 *v);
float GLUG_LIB_API glug_vec2_len_manhattan(const struct glug_vec2 *v);
void  GLUG_LIB_API glug_vec2_set_len(struct glug_vec2 *v, float length);

int   GLUG_LIB_API glug_vec2_is_normal(const struct glug_vec2 *v);
struct glug_vec2 GLUG_LIB_API glug_vec2_normal(const struct glug_vec2 *v);
void  GLUG_LIB_API glug_vec2_normalize(struct glug_vec2 *v);

float GLUG_LIB_API glug_vec2_dist(const struct glug_vec2 *a, const struct glug_vec2 *b);
float GLUG_LIB_API glug_vec2_dist_squared(const struct glug_vec2 *a, const struct glug_vec2 *b);
float GLUG_LIB_API glug_vec2_dist_manhattan(const struct glug_vec2 *a, const struct glug_vec2 *b);

float GLUG_LIB_API glug_vec2_angle_btw(const struct glug_vec2 *a, const struct glug_vec2 *b);

struct glug_vec2 GLUG_LIB_API glug_vec2_projection(const struct glug_vec2 *a, const struct glug_vec2 *b);
struct glug_vec2 GLUG_LIB_API glug_vec2_rejection(const struct glug_vec2 *a, const struct glug_vec2 *b);
struct glug_vec2 GLUG_LIB_API glug_vec2_reflection(const struct glug_vec2 *a, const struct glug_vec2 *b);
struct glug_vec2 GLUG_LIB_API glug_vec2_refraction(const struct glug_vec2 *inc, const struct glug_vec2 *n, float incidx, float tranidx);

void GLUG_LIB_API glug_vec2_project(struct glug_vec2 *a, const struct glug_vec2 *b);
void GLUG_LIB_API glug_vec2_reject(struct glug_vec2 *a, const struct glug_vec2 *b);
void GLUG_LIB_API glug_vec2_reflect(struct glug_vec2 *a, const struct glug_vec2 *b);
void GLUG_LIB_API glug_vec2_refract(struct glug_vec2 *dst, const struct glug_vec2 *n, float incidx, float tranidx);

#endif // GLUG_VEC2_H
