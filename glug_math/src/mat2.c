#include <glug/math/mat2.h>
#include <glug/math/float.h>

static const size_t nels = sizeof(struct glug_mat2) / sizeof(float);

void glug_mat2_identity(struct glug_mat2 *dst)
{
    dst->els[0][0] = 1.f;
    dst->els[0][1] = 0.f;
    dst->els[1][0] = 0.f;
    dst->els[1][1] = 1.f;

}

glug_bool_t glug_mat2_equal(const struct glug_mat2 *m1, const struct glug_mat2 *m2)
{

}

void glug_mat2_add(struct glug_mat2 *dst, const struct glug_mat2 *m2)
{
    size_t i = nels;
    float *els = glug_mat2_elements(dst);
    float *bels = glug_mat2_elements(m2);
    while (i--)
        els[i] += bels[i];
}

void glug_mat2_sub(struct glug_mat2 *dst, const struct glug_mat2 *m2)
{
    size_t i = nels;
    float *els = glug_mat2_elements(dst);
    float *bels = glug_mat2_elements(m2);
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

void glug_mat2_premulm(struct glug_mat2 *dst, const struct glug_mat2 *m2)
{
    float e00 = m2->els[0][0] * dst->els[0][0] + m2->els[1][0] * dst->els[0][1];
    float e01 = m2->els[0][1] * dst->els[0][0] + m2->els[1][1] * dst->els[0][1];
    float e10 = m2->els[0][0] * dst->els[1][0] + m2->els[1][0] * dst->els[1][1];
    float e11 = m2->els[0][1] * dst->els[1][0] + m2->els[1][1] * dst->els[1][1];

    dst->els[0][0] = e00;
    dst->els[0][1] = e01;
    dst->els[1][0] = e10;
    dst->els[1][1] = e11;

}

void glug_mat2_postmulm(struct glug_mat2 *dst, const struct glug_mat2 *m2)
{
    float e00 = dst->els[0][0] * m2->els[0][0] + dst->els[1][0] * m2->els[0][1];
    float e01 = dst->els[0][1] * m2->els[0][0] + dst->els[1][1] * m2->els[0][1];
    float e10 = dst->els[0][0] * m2->els[1][0] + dst->els[1][0] * m2->els[1][1];
    float e11 = dst->els[0][1] * m2->els[1][0] + dst->els[1][1] * m2->els[1][1];

    dst->els[0][0] = e00;
    dst->els[0][1] = e01;
    dst->els[1][0] = e10;
    dst->els[1][1] = e11;
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
    float x = m->els[0][0] * dst->x + m->els[0][1] * dst->y;
    float y = m->els[1][0] * dst->x + m->els[1][1] * dst->y;

    dst->x = x;
    dst->y = y;
}
