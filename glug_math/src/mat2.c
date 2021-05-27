#include <glug/math/mat2.h>
#include <glug/math/float.h>

static const size_t nels = sizeof(struct glug_mat2) / sizeof(float);

struct glug_mat2 glug_mat2_identity()
{
    struct glug_mat2 i = { { { 1.f, 0.f }, { 0.f, 1.f } } };

    return i;
}

void glug_mat2_to_identity(struct glug_mat2 *dst)
{
    glug_mat2_set(dst, 1.f, 0.f, 0.f, 1.f);
}

void glug_mat2_set(struct glug_mat2 *dst, float e00, float e01, float e10, float e11)
{
    dst->els[0][0] = e00;
    dst->els[0][1] = e10;
    dst->els[1][0] = e01;
    dst->els[1][1] = e11;
}

int glug_mat2_equal(const struct glug_mat2 *a, const struct glug_mat2 *b)
{

}

struct glug_mat2 glug_mat2_sum(const struct glug_mat2 *a, const struct glug_mat2 *b)
{
    struct glug_mat2 dst = *a;
    glug_mat2_add(&dst, b);

    return dst;
}

struct glug_mat2 glug_mat2_diff(const struct glug_mat2 *a, const struct glug_mat2 *b)
{
    struct glug_mat2 dst = *a;
    glug_mat2_sub(&dst, b);

    return dst;
}

struct glug_mat2 glug_mat2_prod(const struct glug_mat2 *m, float scalar)
{
    struct glug_mat2 dst = *m;
    glug_mat2_mul(&dst, scalar);

    return dst;
}

struct glug_mat2 glug_mat2_quot(const struct glug_mat2 *m, float scalar)
{
    struct glug_mat2 dst = *m;
    glug_mat2_div(&dst, scalar);

    return dst;
}

struct glug_mat2 glug_mat2_prodm(const struct glug_mat2 *a, const struct glug_mat2 *b)
{
    struct glug_mat2 dst = *a;
    glug_mat2_postmulm(&dst, b);

    return dst;
}

void glug_mat2_add(struct glug_mat2 *dst, const struct glug_mat2 *b)
{
    size_t i = nels;
    float *els = glug_mat2_elements(dst);
    float *bels = glug_mat2_elements(b);
    while (i--)
        els[i] += bels[i];
}

void glug_mat2_sub(struct glug_mat2 *dst, const struct glug_mat2 *b)
{
    size_t i = nels;
    float *els = glug_mat2_elements(dst);
    float *bels = glug_mat2_elements(b);
    while (i--)
        els[i] -= bels[i];
}

void glug_mat2_mul(struct glug_mat2 *dst, float scalar)
{
    size_t i = nels;
    float *els = glug_mat2_elements(dst);
    while (i--)
        els[i] *= scalar;
}

void glug_mat2_div(struct glug_mat2 *dst, float scalar)
{
    glug_mat2_mul(dst, 1.f / scalar);
}

void glug_mat2_premulm(struct glug_mat2 *dst, const struct glug_mat2 *b)
{
    float e00 = b->els[0][0] * dst->els[0][0] + b->els[1][0] * dst->els[0][1];
    float e01 = b->els[0][0] * dst->els[1][0] + b->els[1][0] * dst->els[1][1];
    float e10 = b->els[0][1] * dst->els[0][0] + b->els[1][1] * dst->els[0][1];
    float e11 = b->els[0][1] * dst->els[1][0] + b->els[1][1] * dst->els[1][1];

    glug_mat2_set(dst, e00, e01, e10, e11);
}

void glug_mat2_postmulm(struct glug_mat2 *dst, const struct glug_mat2 *b)
{
    float e00 = dst->els[0][0] * b->els[0][0] + dst->els[1][0] * b->els[0][1];
    float e01 = dst->els[0][0] * b->els[1][0] + dst->els[1][0] * b->els[1][1];
    float e10 = dst->els[0][1] * b->els[0][0] + dst->els[1][1] * b->els[0][1];
    float e11 = dst->els[0][1] * b->els[1][0] + dst->els[1][1] * b->els[1][1];

    glug_mat2_set(dst, e00, e01, e10, e11);
}

float *glug_mat2_elements(struct glug_mat2 *m)
{
    return (float *)m;
}

size_t glug_mat2_nelements()
{
    return nels;
}

float glug_mat2_determinant(const struct glug_mat2 *m)
{
    return m->els[0][0] * m->els[1][1] - m->els[0][1] * m->els[1][0];
}

struct glug_mat2 glug_mat2_get_transpose(const struct glug_mat2 *m)
{
    struct glug_mat2 dst = *m;
    glug_mat2_transpose(&dst);

    return dst;
}

void glug_mat2_transpose(struct glug_mat2 *dst)
{
    glug_float_swap(&dst->els[0][1], &dst->els[1][0]);
}

struct glug_mat2 glug_mat2_inverse(const struct glug_mat2 *m)
{
    struct glug_mat2 dst = *m;
    glug_mat2_invert(&dst);

    return dst;
}

void glug_mat2_invert(struct glug_mat2 *dst)
{
    glug_mat2_div(dst, glug_mat2_determinant(dst));
    glug_float_swap(&dst->els[0][0], &dst->els[1][1]);
    dst->els[0][1] *= -1.f;
    dst->els[1][0] *= -1.f;
}

struct glug_vec2 glug_mat2_prodv(const struct glug_mat2 *m, const struct glug_vec2 *v)
{
    struct glug_vec2 dst = *v;
    glug_mat2_mulv(m, &dst);

    return dst;
}

void glug_mat2_mulv(const struct glug_mat2 *m, struct glug_vec2 *dst)
{
    float x = m->els[0][0] * dst->x + m->els[1][0] * dst->y;
    float y = m->els[0][1] * dst->x + m->els[1][1] * dst->y;

    dst->x = x;
    dst->y = y;
}
