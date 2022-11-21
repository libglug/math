#include <glug/math/vec2.h>
#include <glug/math/float.h>

#include <math.h>

glug_bool_t glug_vec2_equal(const struct glug_vec2 *v1, const struct glug_vec2 *v2)
{

}

void glug_vec2_add(struct glug_vec2 *dst, const struct glug_vec2 *v2)
{
    struct glug_vec2 res = *dst;
    res.x += v2->x;
    res.y += v2->y;

    *dst = res;
}

void glug_vec2_sub(struct glug_vec2 *dst, const struct glug_vec2 *v2)
{
    struct glug_vec2 res = *dst;
    res.x -= v2->x;
    res.y -= v2->y;

    *dst = res;
}

void glug_vec2_mul(struct glug_vec2 *dst, float scalar)
{
    struct glug_vec2 res = *dst;
    res.x *= scalar;
    res.y *= scalar;

    *dst = res;
}

void glug_vec2_div(struct glug_vec2 *dst, float scalar)
{
    glug_vec2_mul(dst, 1.f / scalar);
}

void glug_vec2_mul_cw(struct glug_vec2 *dst, const struct glug_vec2 *v, const struct glug_vec2 *v2)
{
    *dst = (struct glug_vec2){
        .x = v->x * v2->x,
        .y = v->y * v2->y,
    };
}

void glug_vec2_div_cw(struct glug_vec2 *dst, const struct glug_vec2 *v, const struct glug_vec2 *v2)
{
    *dst = (struct glug_vec2){
        .x = v->x / v2->x,
        .y = v->y / v2->y,
    };
}

void glug_vec2_sign(struct glug_vec2 *dst, const struct glug_vec2 *v)
{
    *dst = (struct glug_vec2){
        .x = glug_float_sign(v->x),
        .y = glug_float_sign(v->y),
    };
}

void glug_vec2_integral(struct glug_vec2 *dst, const struct glug_vec2 *v)
{
    *dst = (struct glug_vec2){
        .x = glug_float_integral(v->x),
        .y = glug_float_integral(v->y),
    };
}

void glug_vec2_frac(struct glug_vec2 *dst, const struct glug_vec2 *v)
{
    *dst = (struct glug_vec2){
        .x = glug_float_frac(v->x),
        .y = glug_float_frac(v->y),
    };
}

void glug_vec2_max(struct glug_vec2 *dst, const struct glug_vec2 *v2)
{
    struct glug_vec2 res = *dst;
    res.x = glug_float_max(dst->x, v2->x);
    res.y = glug_float_max(dst->y, v2->y);

    *dst = res;
}

void glug_vec2_min(struct glug_vec2 *dst, const struct glug_vec2 *v2)
{
    struct glug_vec2 res = *dst;
    res.x = glug_float_min(dst->x, v2->x);
    res.y = glug_float_min(dst->y, v2->y);

    *dst = res;
}

void glug_vec2_clamp(struct glug_vec2 *dst, const struct glug_vec2 *min, const struct glug_vec2 *max)
{
    struct glug_vec2 res = *dst;
    glug_vec2_max(&res, min);
    glug_vec2_min(&res, max);

    *dst = res;
}

void glug_vec2_floor(struct glug_vec2 *dst, const struct glug_vec2 *v)
{
    *dst = (struct glug_vec2){
        .x = glug_float_floor(v->x),
        .y = glug_float_floor(v->y),
    };
}

void glug_vec2_ceil(struct glug_vec2 *dst, const struct glug_vec2 *v)
{
    *dst = (struct glug_vec2){
        .x = glug_float_ceil(v->x),
        .y = glug_float_ceil(v->y),
    };
}

void glug_vec2_round(struct glug_vec2 *dst, const struct glug_vec2 *v)
{
    *dst = (struct glug_vec2){
        .x = glug_float_round(v->x),
        .y = glug_float_round(v->y),
    };
}

void glug_vec2_round_zero(struct glug_vec2 *dst, const struct glug_vec2 *v)
{
    *dst = (struct glug_vec2){
        .x = glug_float_round_zero(v->x),
        .y = glug_float_round_zero(v->y),
    };
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

void glug_vec2_set_len(struct glug_vec2 *v, float length)
{
    glug_vec2_mul(v, length / glug_vec2_len(v));
}

void glug_vec2_clamp_len(struct glug_vec2 *v, float min, float max)
{
    float l = glug_vec2_len(v);
    float clamped = glug_float_clamp(l, min, max);

    glug_vec2_mul(v, clamped / l);
}

glug_bool_t glug_vec2_is_normal(const struct glug_vec2 *v)
{

}

void glug_vec2_normalize(struct glug_vec2 *v)
{
    glug_vec2_div(v, glug_vec2_len(v));
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
    return acosf(glug_vec2_dot(v1, v2) / glug_vec2_len(v1) / glug_vec2_len(v2));
}

void glug_vec2_project(struct glug_vec2 *dst, const struct glug_vec2 *v2)
{
    struct glug_vec2 res = *v2;
    glug_vec2_normalize(&res);
    float proj_len = glug_vec2_dot(dst, &res);
    glug_vec2_mul(&res, proj_len);

    *dst = res;
}

void glug_vec2_reject(struct glug_vec2 *dst, const struct glug_vec2 *v2)
{
    struct glug_vec2 res = *dst, proj = *dst;
    glug_vec2_project(&proj, v2);
    glug_vec2_sub(&res, &proj);

    *dst = res;
}

void glug_vec2_reflect(struct glug_vec2 *dst, const struct glug_vec2 *v2)
{
    struct glug_vec2 res = *dst, rej = *dst;
    glug_vec2_reject(&rej, v2);
    glug_vec2_sub(&res, &rej);
    glug_vec2_sub(&res, &rej);

    *dst = res;
}

void glug_vec2_refract(struct glug_vec2 *dst, const struct glug_vec2 *n, float incidx, float tranidx)
{
    // (ni/nt * N.I - sqrt(1 - (ni/nt)^2 * (1 - N.I * N.I)) * N - ni/nt * I
    float incproj, idxratio = incidx / tranidx;
    float dstlen = glug_vec2_len(dst);
    struct glug_vec2 norm = *n, inc = *dst;
    glug_vec2_normalize(&norm);
    glug_vec2_normalize(&inc);
    glug_vec2_mul(&inc, -1);

    incproj = glug_vec2_dot(&inc, &norm);
    glug_vec2_mul(&inc, idxratio);

    *dst = norm;
    glug_vec2_mul(dst, -sqrtf(1 - idxratio * idxratio * (1 - incproj * incproj)) + idxratio * incproj);
    glug_vec2_sub(dst, &inc);
    glug_vec2_mul(dst, dstlen);
}
