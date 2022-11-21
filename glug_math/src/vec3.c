#include <glug/math/vec3.h>
#include <glug/math/float.h>

#include <math.h>

glug_bool_t glug_vec3_equal(const struct glug_vec3 *v1, const struct glug_vec3 *v2)
{

}

void glug_vec3_add(struct glug_vec3 *dst, const struct glug_vec3 *v2)
{
    struct glug_vec3 res = *dst;
    res.x += v2->x;
    res.y += v2->y;
    res.z += v2->z;

    *dst = res;
}

void glug_vec3_sub(struct glug_vec3 *dst, const struct glug_vec3 *v2)
{
    struct glug_vec3 res = *dst;
    res.x -= v2->x;
    res.y -= v2->y;
    res.z -= v2->z;

    *dst = res;
}

void glug_vec3_mul(struct glug_vec3 *dst, float scalar)
{
    struct glug_vec3 res = *dst;
    res.x *= scalar;
    res.y *= scalar;
    res.z *= scalar;

    *dst = res;
}

void glug_vec3_div(struct glug_vec3 *dst, float scalar)
{
    glug_vec3_mul(dst, 1.f / scalar);
}

void glug_vec3_sign(struct glug_vec3 *dst, const struct glug_vec3 *v)
{
    *dst = (struct glug_vec3){
        .x = glug_float_sign(v->x),
        .y = glug_float_sign(v->y),
        .z = glug_float_sign(v->z),
    };
}

void glug_vec3_integral(struct glug_vec3 *dst, const struct glug_vec3 *v)
{
    *dst = (struct glug_vec3){
        .x = glug_float_integral(v->x),
        .y = glug_float_integral(v->y),
        .z = glug_float_integral(v->z),
    };
}

void glug_vec3_frac(struct glug_vec3 *dst, const struct glug_vec3 *v)
{
    *dst = (struct glug_vec3){
        .x = glug_float_frac(v->x),
        .y = glug_float_frac(v->y),
        .z = glug_float_frac(v->z),
    };
}

void glug_vec3_max(struct glug_vec3 *dst, const struct glug_vec3 *v2)
{
    struct glug_vec3 res = *dst;
    res.x = glug_float_max(dst->x, v2->x);
    res.y = glug_float_max(dst->y, v2->y);
    res.z = glug_float_max(dst->z, v2->z);

    *dst = res;
}

void glug_vec3_min(struct glug_vec3 *dst, const struct glug_vec3 *v2)
{
    struct glug_vec3 res = *dst;
    res.x = glug_float_min(dst->x, v2->x);
    res.y = glug_float_min(dst->y, v2->y);
    res.z = glug_float_min(dst->z, v2->z);

    *dst = res;
}

void glug_vec3_clamp(struct glug_vec3 *dst, const struct glug_vec3 *min, const struct glug_vec3 *max)
{
    struct glug_vec3 res = *dst;
    glug_vec3_max(&res, min);
    glug_vec3_min(&res, max);

    *dst = res;
}

void glug_vec3_floor(struct glug_vec3 *dst, const struct glug_vec3 *v)
{
    *dst = (struct glug_vec3){
        .x = glug_float_floor(v->x),
        .y = glug_float_floor(v->y),
        .z = glug_float_floor(v->z),
    };
}

void glug_vec3_ceil(struct glug_vec3 *dst, const struct glug_vec3 *v)
{
    *dst = (struct glug_vec3){
        .x = glug_float_ceil(v->x),
        .y = glug_float_ceil(v->y),
        .z = glug_float_ceil(v->z),
    };
}

void glug_vec3_round(struct glug_vec3 *dst, const struct glug_vec3 *v)
{
    *dst = (struct glug_vec3){
        .x = glug_float_round(v->x),
        .y = glug_float_round(v->y),
        .z = glug_float_round(v->z),
    };
}

void glug_vec3_round_zero(struct glug_vec3 *dst, const struct glug_vec3 *v)
{
    *dst = (struct glug_vec3){
        .x = glug_float_round_zero(v->x),
        .y = glug_float_round_zero(v->y),
        .z = glug_float_round_zero(v->z),
    };
}

float glug_vec3_dot(const struct glug_vec3 *v1, const struct glug_vec3 *v2)
{
    return v1->x * v2->x + v1->y * v2->y + v1->z * v2->z;
}

void glug_vec3_cross(struct glug_vec3 *dst, const struct glug_vec3 *v1, const struct glug_vec3 *v2)
{
    struct glug_vec3 res = *dst;
    res.x = v1->y * v2->z - v1->z * v2->y;
    res.y = v1->z * v2->x - v1->x * v2->z;
    res.z = v1->x * v2->y - v1->y * v2->x;

    *dst = res;
}

float glug_vec3_len(const struct glug_vec3 *dst)
{
    return sqrtf(glug_vec3_len_squared(dst));
}

float glug_vec3_len_squared(const struct glug_vec3 *v)
{
    return v->x * v->x + v->y * v->y + v->z * v->z;
}

float glug_vec3_len_taxi(const struct glug_vec3 *v)
{
    return fabsf(v->x) + fabsf(v->y) + fabsf(v->z);
}

void glug_vec3_set_len(struct glug_vec3 *v, float length)
{
    glug_vec3_mul(v, length / glug_vec3_len(v));
}

void glug_vec3_clamp_len(struct glug_vec3 *v, float min, float max)
{
    float l = glug_vec3_len(v);
    float clamped = glug_float_clamp(l, min, max);

    glug_vec3_mul(v, clamped / l);
}

glug_bool_t glug_vec3_is_normal(const struct glug_vec3 *v)
{

}

void glug_vec3_normalize(struct glug_vec3 *v)
{
    glug_vec3_set_len(v, 1.f);
}

float glug_vec3_dist(const struct glug_vec3 *v1, const struct glug_vec3 *v2)
{
    return sqrtf(glug_vec3_dist_squared(v1, v2));
}

float glug_vec3_dist_squared(const struct glug_vec3 *v1, const struct glug_vec3 *v2)
{
    float dx = v2->x - v1->x;
    float dy = v2->y - v1->y;
    float dz = v2->z - v1->z;

    return dx * dx + dy * dy + dz * dz;
}

float glug_vec3_dist_taxi(const struct glug_vec3 *v1, const struct glug_vec3 *v2)
{
    float dx = fabsf(v2->x - v1->x);
    float dy = fabsf(v2->y - v1->y);
    float dz = fabsf(v2->z - v1->z);

    return dx + dy + dz;
}

float glug_vec3_angle_btw(const struct glug_vec3 *v1, const struct glug_vec3 *v2)
{
    return acosf(glug_vec3_dot(v1, v2) / glug_vec3_len(v1) / glug_vec3_len(v2));
}

void glug_vec3_project(struct glug_vec3 *dst, const struct glug_vec3 *v2)
{
    struct glug_vec3 res = *v2;
    glug_vec3_normalize(&res);
    float proj_len = glug_vec3_dot(dst, &res);
    glug_vec3_mul(&res, proj_len);

    *dst = res;
}

void glug_vec3_reject(struct glug_vec3 *dst, const struct glug_vec3 *v2)
{
    struct glug_vec3 res = *dst, proj = *dst;
    glug_vec3_project(&proj, v2);
    glug_vec3_sub(&res, &proj);

    *dst = res;
}

void glug_vec3_reflect(struct glug_vec3 *dst, const struct glug_vec3 *v2)
{
    struct glug_vec3 res = *dst, rej = *dst;
    glug_vec3_reject(&rej, v2);
    glug_vec3_sub(&res, &rej);
    glug_vec3_sub(&res, &rej);

    *dst = res;
}

void glug_vec3_refract(struct glug_vec3 *dst, const struct glug_vec3 *n, float incidx, float tranidx)
{
    // (ni/nt * N.I - sqrt(1 - (ni/nt)^2 * (1 - N.I * N.I)) * N - ni/nt * I
    float incproj, idxratio = incidx / tranidx;
    float dstlen = glug_vec3_len(dst);

    struct glug_vec3 norm = *n;
    glug_vec3_normalize(&norm);

    struct glug_vec3 inc = *dst;
    glug_vec3_normalize(&inc);
    glug_vec3_mul(&inc, -1.f);

    incproj = glug_vec3_dot(&inc, &norm);
    glug_vec3_mul(&inc, idxratio);

    *dst = norm;
    glug_vec3_mul(dst, -sqrtf(1 - idxratio * idxratio * (1 - incproj * incproj)) + idxratio * incproj);
    glug_vec3_sub(dst, &inc);
    glug_vec3_mul(dst, dstlen);
}
