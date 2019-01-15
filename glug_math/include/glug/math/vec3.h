#ifndef GLUG_VEC3_H
#define GLUG_VEC3_H

#include <glug/import.h>
#include <glug/math/vec3_t.h>

void  GLUG_LIB_API glug_vec3_set(struct glug_vec3 *dst, float x, float y, float z);
int   GLUG_LIB_API glug_vec3_equal(const struct glug_vec3 *a, const struct glug_vec3 *b);

struct glug_vec3 GLUG_LIB_API glug_vec3_sum (const struct glug_vec3 *a, const struct glug_vec3 *b);
struct glug_vec3 GLUG_LIB_API glug_vec3_diff(const struct glug_vec3 *a, const struct glug_vec3 *b);
struct glug_vec3 GLUG_LIB_API glug_vec3_prod(const struct glug_vec3 *v, float scalar);
struct glug_vec3 GLUG_LIB_API glug_vec3_quot(const struct glug_vec3 *v, float scalar);

void  GLUG_LIB_API glug_vec3_add(struct glug_vec3 *dst, const struct glug_vec3 *b);
void  GLUG_LIB_API glug_vec3_sub(struct glug_vec3 *dst, const struct glug_vec3 *b);
void  GLUG_LIB_API glug_vec3_mul(struct glug_vec3 *dst, float scalar);
void  GLUG_LIB_API glug_vec3_div(struct glug_vec3 *dst, float scalar);

struct glug_vec3 GLUG_LIB_API glug_vec3_max(const struct glug_vec3 *a, const struct glug_vec3 *b);
struct glug_vec3 GLUG_LIB_API glug_vec3_min(const struct glug_vec3 *a, const struct glug_vec3 *b);
struct glug_vec3 GLUG_LIB_API glug_vec3_clamped(const struct glug_vec3 *a, const struct glug_vec3 *min, const struct glug_vec3 *max);

void GLUG_LIB_API glug_vec3_maximize(struct glug_vec3 *dst, const struct glug_vec3 *b);
void GLUG_LIB_API glug_vec3_minimize(struct glug_vec3 *dst, const struct glug_vec3 *b);
void GLUG_LIB_API glug_vec3_clamp(struct glug_vec3 *dst, const struct glug_vec3 *min, const struct glug_vec3 *max);

float GLUG_LIB_API glug_vec3_dot(const struct glug_vec3 *v, const struct glug_vec3 *b);
struct glug_vec3 GLUG_LIB_API glug_vec3_cross(const struct glug_vec3 *a, const struct glug_vec3 *b);

float GLUG_LIB_API glug_vec3_len(const struct glug_vec3 *v);
float GLUG_LIB_API glug_vec3_len_squared(const struct glug_vec3 *v);
float GLUG_LIB_API glug_vec3_len_manhattan(const struct glug_vec3 *v);
void  GLUG_LIB_API glug_vec3_set_len(struct glug_vec3 *dst, float length);

int   GLUG_LIB_API glug_vec3_is_normal(const struct glug_vec3 *v);
struct glug_vec3 GLUG_LIB_API glug_vec3_normal(const struct glug_vec3 *v);
void  GLUG_LIB_API glug_vec3_normalize(struct glug_vec3 *v);

float GLUG_LIB_API glug_vec3_dist(const struct glug_vec3 *a, const struct glug_vec3 *b);
float GLUG_LIB_API glug_vec3_dist_squared(const struct glug_vec3 *a, const struct glug_vec3 *b);
float GLUG_LIB_API glug_vec3_dist_manhattan(const struct glug_vec3 *a, const struct glug_vec3 *b);

float GLUG_LIB_API glug_vec3_angle_btw(const struct glug_vec3 *a, const struct glug_vec3 *b);

struct glug_vec3 GLUG_LIB_API glug_vec3_projection(const struct glug_vec3 *a, const struct glug_vec3 *b);
struct glug_vec3 GLUG_LIB_API glug_vec3_rejection(const struct glug_vec3 *a, const struct glug_vec3 *b);
struct glug_vec3 GLUG_LIB_API glug_vec3_reflection(const struct glug_vec3 *a, const struct glug_vec3 *b);
struct glug_vec3 GLUG_LIB_API glug_vec3_refraction(const struct glug_vec3 *inc, const struct glug_vec3 *n, float incidx, float tranidx);

void GLUG_LIB_API glug_vec3_project(struct glug_vec3 *dst, const struct glug_vec3 *b);
void GLUG_LIB_API glug_vec3_reject(struct glug_vec3 *dst, const struct glug_vec3 *b);
void GLUG_LIB_API glug_vec3_reflect(struct glug_vec3 *dst, const struct glug_vec3 *b);
void GLUG_LIB_API glug_vec3_refract(struct glug_vec3 *dst, const struct glug_vec3 *n, float incidx, float tranidx);

#endif // GLUG_VEC3_H
