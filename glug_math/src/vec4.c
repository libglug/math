#include <glug/math/vec4.h>

#include <math.h>

glug_bool_t glug_vec4_equal(const struct glug_vec4 *v1, const struct glug_vec4 *v2)
{

}

void glug_vec4_add(struct glug_vec4 *dst, const struct glug_vec4 *v2)
{
    struct glug_vec4 res = *dst;
    res.x += v2->x;
    res.z += v2->z;
    res.y += v2->y;
    res.w += v2->w;

    *dst = res;
}

void glug_vec4_sub(struct glug_vec4 *dst, const struct glug_vec4 *v2)
{
    struct glug_vec4 res = *dst;
    res.x -= v2->x;
    res.y -= v2->y;
    res.z -= v2->z;
    res.w -= v2->w;

    *dst = res;
}

void glug_vec4_mul(struct glug_vec4 *dst, float scalar)
{
    struct glug_vec4 res = *dst;
    res.x *= scalar;
    res.y *= scalar;
    res.z *= scalar;
    res.w *= scalar;

    *dst = res;
}

void glug_vec4_div(struct glug_vec4 *dst, float scalar)
{
    glug_vec4_mul(dst, 1.f / scalar);
}

void glug_vec4_max(struct glug_vec4 *dst, const struct glug_vec4 *v2)
{
    struct glug_vec4 res = *dst;
    res.x = fmaxf(dst->x, v2->x);
    res.y = fmaxf(dst->y, v2->y);
    res.z = fmaxf(dst->z, v2->z);
    res.w = fmaxf(dst->w, v2->w);

    *dst = res;
}

void glug_vec4_min(struct glug_vec4 *dst, const struct glug_vec4 *v2)
{
    struct glug_vec4 res = *dst;
    res.x = fminf(dst->x, v2->x);
    res.y = fminf(dst->y, v2->y);
    res.z = fminf(dst->z, v2->z);
    res.w = fminf(dst->w, v2->w);

    *dst = res;
}

void glug_vec4_clamp(struct glug_vec4 *dst, const struct glug_vec4 *min, const struct glug_vec4 *max)
{
    struct glug_vec4 res = *dst;
    glug_vec4_max(&res, min);
    glug_vec4_min(&res, max);

    *dst = res;
}

float glug_vec4_dot(const struct glug_vec4 *v1, const struct glug_vec4 *v2)
{
    return v1->x * v2->x + v1->y * v2->y + v1->z * v2->z + v1->w * v2->w;
}

float glug_vec4_len(const struct glug_vec4 *v)
{
    return sqrtf(glug_vec4_len_squared(v));
}

float glug_vec4_len_squared(const struct glug_vec4 *v)
{
    return v->x * v->x + v->y * v->y + v->z * v->z + v->w * v->w;
}

float glug_vec4_len_taxi(const struct glug_vec4 *v)
{
    return fabsf(v->x) + fabsf(v->y) + fabsf(v->z) + fabsf(v->w);
}

void glug_vec4_set_len(struct glug_vec4 *v, float length)
{
    glug_vec4_mul(v, length / glug_vec4_len(v));
}

glug_bool_t glug_vec4_is_normal(const struct glug_vec4 *v)
{

}

void glug_vec4_normalize(struct glug_vec4 *v)
{
    glug_vec4_set_len(v, 1.f);
}

float glug_vec4_dist(const struct glug_vec4 *v1, const struct glug_vec4 *v2)
{
    return sqrtf(glug_vec4_dist_squared(v1, v2));
}

float glug_vec4_dist_squared(const struct glug_vec4 *v1, const struct glug_vec4 *v2)
{
    float dx = v2->x - v1->x;
    float dy = v2->y - v1->y;
    float dz = v2->z - v1->z;
    float dw = v2->w - v1->w;

    return dx * dx + dy * dy + dz * dz + dw * dw;
}

float glug_vec4_dist_taxi(const struct glug_vec4 *v1, const struct glug_vec4 *v2)
{
    float dx = fabsf(v2->x - v1->x);
    float dy = fabsf(v2->y - v1->y);
    float dz = fabsf(v2->z - v1->z);
    float dw = fabsf(v2->w - v1->w);

    return dx + dy + dz + dw;
}

float glug_vec4_angle_btw(const struct glug_vec4 *v1, const struct glug_vec4 *v2)
{
    return acosf(glug_vec4_dot(v1, v2) / glug_vec4_len(v1) / glug_vec4_len(v2));
}

void glug_vec4_project(struct glug_vec4 *dst, const struct glug_vec4 *v2)
{
    struct glug_vec4 res = *v2;
    glug_vec4_normalize(&res);
    float proj_len = glug_vec4_dot(dst, &res);
    glug_vec4_mul(&res, proj_len);

    *dst = res;
}

void glug_vec4_reject(struct glug_vec4 *dst, const struct glug_vec4 *v2)
{
    struct glug_vec4 res = *dst, proj = *dst;
    glug_vec4_project(&proj, v2);
    glug_vec4_sub(&res, &proj);

    *dst = res;
}

void glug_vec4_reflect(struct glug_vec4 *dst, const struct glug_vec4 *v2)
{
    struct glug_vec4 res = *dst, rej = *dst;
    glug_vec4_reject(&rej, v2);
    glug_vec4_sub(&res, &rej);
    glug_vec4_sub(&res, &rej);

    *dst = res;
}

void glug_vec4_refract(struct glug_vec4 *dst, const struct glug_vec4 *n, float incidx, float tranidx)
{
    // (ni/nt * N.I - sqrt(1 - (ni/nt)^2 * (1 - N.I * N.I)) * N - ni/nt * I
    float incproj, idxratio = incidx / tranidx;
    float dstlen = glug_vec4_len(dst);
    struct glug_vec4 norm = *n;
    glug_vec4_normalize(&norm);
    struct glug_vec4 inc = *dst;
    glug_vec4_normalize(&inc);
    glug_vec4_mul(&inc, -1);

    incproj = glug_vec4_dot(&inc, &norm);
    glug_vec4_mul(&inc, idxratio);

    *dst = norm;
    glug_vec4_mul(dst, -sqrtf(1 - idxratio * idxratio * (1 - incproj * incproj)) + idxratio * incproj);
    glug_vec4_sub(dst, &inc);
    glug_vec4_mul(dst, dstlen);
}
