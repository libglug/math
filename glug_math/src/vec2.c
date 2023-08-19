#include <glug/math/vec2_t.h>
#include <glug/math/vec2.h>
#include <glug/math/float.h>

#include <math.h>

float glug_vec2_x(const struct glug_vec2 *v)
{
    return v->x;
}

float glug_vec2_y(const struct glug_vec2 *v)
{
    return v->y;
}

glug_bool_t glug_vec2_equal(const struct glug_vec2 *v1, const struct glug_vec2 *v2)
{

}

struct glug_vec2 *glug_vec2_add(struct glug_vec2 *dst, const struct glug_vec2 *v1, const struct glug_vec2 *v2)
{
    *dst = (struct glug_vec2){
        .x = v1->x + v2->x,
        .y = v1->y + v2->y,
    };

    return dst;
}

struct glug_vec2 *glug_vec2_sub(struct glug_vec2 *dst, const struct glug_vec2 *v1, const struct glug_vec2 *v2)
{
    *dst = (struct glug_vec2){
        .x = v1->x - v2->x,
        .y = v1->y - v2->y,
    };

    return dst;
}

struct glug_vec2 *glug_vec2_mul(struct glug_vec2 *dst, const struct glug_vec2 *v, float scalar)
{
    *dst = (struct glug_vec2){
        .x = v->x * scalar,
        .y = v->y * scalar,
    };

    return dst;
}

struct glug_vec2 *glug_vec2_div(struct glug_vec2 *dst, const struct glug_vec2 *v, float scalar)
{
    return glug_vec2_mul(dst, v, 1.f / scalar);
}

struct glug_vec2 *glug_vec2_mul_cw(struct glug_vec2 *dst, const struct glug_vec2 *v, const struct glug_vec2 *v2)
{
    *dst = (struct glug_vec2){
        .x = v->x * v2->x,
        .y = v->y * v2->y,
    };
    return dst;
}

struct glug_vec2 *glug_vec2_div_cw(struct glug_vec2 *dst, const struct glug_vec2 *v, const struct glug_vec2 *v2)
{
    *dst = (struct glug_vec2){
        .x = v->x / v2->x,
        .y = v->y / v2->y,
    };
    return dst;
}

struct glug_vec2 *glug_vec2_sign(struct glug_vec2 *dst, const struct glug_vec2 *v)
{
    *dst = (struct glug_vec2){
        .x = glug_float_sign(v->x),
        .y = glug_float_sign(v->y),
    };
    return dst;
}

struct glug_vec2 *glug_vec2_integral(struct glug_vec2 *dst, const struct glug_vec2 *v)
{
    *dst = (struct glug_vec2){
        .x = glug_float_integral(v->x),
        .y = glug_float_integral(v->y),
    };
    return dst;
}

struct glug_vec2 *glug_vec2_frac(struct glug_vec2 *dst, const struct glug_vec2 *v)
{
    *dst = (struct glug_vec2){
        .x = glug_float_frac(v->x),
        .y = glug_float_frac(v->y),
    };
    return dst;
}

struct glug_vec2 *glug_vec2_max(struct glug_vec2 *dst, const struct glug_vec2 *v1, const struct glug_vec2 *v2)
{
    *dst = (struct glug_vec2){
        .x = glug_float_max(v1->x, v2->x),
        .y = glug_float_max(v1->y, v2->y),
    };
    return dst;
}

struct glug_vec2 *glug_vec2_min(struct glug_vec2 *dst, const struct glug_vec2 *v1, const struct glug_vec2 *v2)
{
    *dst = (struct glug_vec2){
        .x = glug_float_min(v1->x, v2->x),
        .y = glug_float_min(v1->y, v2->y),
    };
    return dst;
}

struct glug_vec2 *glug_vec2_clamp(struct glug_vec2 *dst, const struct glug_vec2 *v, const struct glug_vec2 *min, const struct glug_vec2 *max)
{
    struct glug_vec2 tmp_max;
    return glug_vec2_min(dst, max, glug_vec2_max(&tmp_max, v, min));
}

struct glug_vec2 *glug_vec2_floor(struct glug_vec2 *dst, const struct glug_vec2 *v)
{
    *dst = (struct glug_vec2){
        .x = glug_float_floor(v->x),
        .y = glug_float_floor(v->y),
    };
    return dst;
}

struct glug_vec2 *glug_vec2_ceil(struct glug_vec2 *dst, const struct glug_vec2 *v)
{
    *dst = (struct glug_vec2){
        .x = glug_float_ceil(v->x),
        .y = glug_float_ceil(v->y),
    };
    return dst;
}

struct glug_vec2 *glug_vec2_round(struct glug_vec2 *dst, const struct glug_vec2 *v)
{
    *dst = (struct glug_vec2){
        .x = glug_float_round(v->x),
        .y = glug_float_round(v->y),
    };
    return dst;
}

struct glug_vec2 *glug_vec2_round_zero(struct glug_vec2 *dst, const struct glug_vec2 *v)
{
    *dst = (struct glug_vec2){
        .x = glug_float_round_zero(v->x),
        .y = glug_float_round_zero(v->y),
    };
    return dst;
}

float glug_vec2_dot(const struct glug_vec2 *v1, const struct glug_vec2 *v2)
{
    return v1->x * v2->x + v1->y * v2->y;
}

float glug_vec2_len(const struct glug_vec2 *v)
{
    return sqrtf(glug_vec2_len_squared(v));
}

float glug_vec2_len_squared(const struct glug_vec2 *v)
{
    return v->x * v->x + v->y * v->y;
}

float glug_vec2_len_taxi(const struct glug_vec2 *v)
{
    return fabsf(v->x) + fabsf(v->y);
}

struct glug_vec2 *glug_vec2_set_len(struct glug_vec2 *dst, const struct glug_vec2 *v, float length)
{
    return glug_vec2_mul(dst, v, length / glug_vec2_len(v));
}

struct glug_vec2 *glug_vec2_clamp_len(struct glug_vec2 *dst, const struct glug_vec2 *v, float min, float max)
{
    return glug_vec2_set_len(dst, v, glug_float_clamp(glug_vec2_len(v), min, max));
}

glug_bool_t glug_vec2_is_normal(const struct glug_vec2 *v)
{

}

struct glug_vec2 *glug_vec2_normalize(struct glug_vec2 *dst, const struct glug_vec2 *v)
{
    return glug_vec2_div(dst, v, glug_vec2_len(v));
}

float glug_vec2_dist(const struct glug_vec2 *v1, const struct glug_vec2 *v2)
{
    return sqrtf(glug_vec2_dist_squared(v1, v2));
}

float glug_vec2_dist_squared(const struct glug_vec2 *v1, const struct glug_vec2 *v2)
{
    float dx = v2->x - v1->x;
    float dy = v2->y - v1->y;

    return dx * dx + dy * dy;
}

float glug_vec2_dist_taxi(const struct glug_vec2 *v1, const struct glug_vec2 *v2)
{
    float dx = fabsf(v2->x - v1->x);
    float dy = fabsf(v2->y - v1->y);

    return dx + dy;
}

float glug_vec2_angle_btw(const struct glug_vec2 *v1, const struct glug_vec2 *v2)
{
    float dot = glug_vec2_dot(v1, v2);
    float l1 = glug_vec2_len(v1);
    float l2 = glug_vec2_len(v2);
    return acosf(dot / l1 / l2);
}

struct glug_vec2 *glug_vec2_project(struct glug_vec2 *dst, const struct glug_vec2 *v, const struct glug_vec2 *onto)
{
    struct glug_vec2 normal;
    glug_vec2_normalize(&normal, onto);
    float proj_len = glug_vec2_dot(v, &normal);
    return glug_vec2_mul(dst, &normal, proj_len);
}

struct glug_vec2 *glug_vec2_reject(struct glug_vec2 *dst, const struct glug_vec2 *v, const struct glug_vec2 *from)
{
    struct glug_vec2 proj;
    return glug_vec2_sub(dst, v, glug_vec2_project(&proj, v, from));
}

struct glug_vec2 *glug_vec2_reflect(struct glug_vec2 *dst, const struct glug_vec2 *v, const struct glug_vec2 *about)
{
    struct glug_vec2 rej;
    return glug_vec2_sub(dst, v, glug_vec2_mul(&rej, glug_vec2_reject(&rej, v, about), 2.f));
}

struct glug_vec2 *glug_vec2_refract(struct glug_vec2 *dst, const struct glug_vec2 *v, const struct glug_vec2 *n, float idx_ratio)
{
    float v_len = glug_vec2_len(v);
    float n_len = glug_vec2_len(n);
    float dst_len = v_len * idx_ratio;

    struct glug_vec2 dst_proj, dst_rej;
    glug_vec2_sub(&dst_rej, v, glug_vec2_project(&dst_proj, v, n));

    float inc_cosangle = -glug_vec2_dot(v, n) / v_len / n_len;
    float rej_len = sqrtf(1 - inc_cosangle * inc_cosangle) * idx_ratio * dst_len;
    glug_vec2_set_len(&dst_rej, &dst_rej, rej_len);

    float proj_len = sqrtf(dst_len * dst_len - rej_len * rej_len);
    glug_vec2_set_len(&dst_proj, &dst_proj, proj_len);

    return glug_vec2_add(dst, &dst_proj, &dst_rej);
}
