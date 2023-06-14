#include <glug/math/float.h>
#include <math.h>

#include <time.h>
#include <glug/os.h>
#define _CRT_RAND_S
#include <stdlib.h>

#define LOG2 0.3010299956639812

float glug_float_inf(void)
{
    return INFINITY;
}

float glug_float_nan(void)
{
    return (float)NAN;
}

float glug_float_π(void)
{
    return (float)glug_float_pi();
}

float glug_float_pi(void)
{
    return (float)M_PI;
}

float glug_float_e(void)
{
    return (float)M_E;
}

float glug_float_sqrt2(void)
{
    return (float)M_SQRT2;
}

float glug_float_log2(void)
{
    return (float)LOG2;
}

glug_bool_t glug_float_equal_strict(float f1, float f2)
{
    return f1 == f2;
}

glug_bool_t glug_float_equal_approx(float f1, float f2, float diff)
{
    return fabsf(f1 - f2) <= diff;
}

glug_bool_t glug_float_equal_ulps(float f1, float f2, uint32_t ulps)
{
    float min = glug_float_min(f1, f2);
    float max = glug_float_max(f1, f2);

    while (ulps-- && min <= max)
        min = glug_float_next(min);

    return max <= min;
}

float glug_float_next(float f)
{
    return nextafterf(f, INFINITY);
}

float glug_float_prev(float f)
{
    return nextafterf(f, -INFINITY);
}

float glug_float_rand(float min, float max)
{
    uint32_t r;
#if GLUG_OS == GLUG_OS_WIN
    rand_s(&r);
#else
    r = arc4random();
#endif

    // normalize r to [0, 1]
    float nrand = r / (float)UINT32_MAX;
    // scale to the range of [min, max]
    return glug_float_rescale(nrand, 0.f, 1.f, min, max);
}

void glug_float_swap(float *f1, float *f2)
{
    float tmp = *f1;
    *f1 = *f2;
    *f2 = tmp;
}

glug_bool_t glug_float_is_pow2(float f)
{
    int exp;
    float coeff = frexp(f, &exp);

    // if `coeff` is 0.5f, then f was a power of 2 resulting from `1/2 * 2^exp`
    return coeff == glug_float_sign(f) * 0.5f;
}

float glug_float_next_pow2(float f)
{
    if (f < 0.f) return -glug_float_prev_pow2(-f);

    int exp;
    float coeff = frexp(f, &exp);

    if (isinf(coeff) || isnan(coeff) || coeff == 0.f) return coeff;

    return glug_float_sign(f) * exp2(exp);
}

float glug_float_prev_pow2(float f)
{
    if (f < 0.f) return -glug_float_next_pow2(-f);

    int exp;
    float coeff = frexp(f, &exp);

    if (isinf(coeff) || isnan(coeff) || coeff == 0.f) return coeff;

    // shift the exponent by -1 so that we get the previous power of 2 but...
    // if `coeff` (returned by frexp) is 0.5f, it's "added an extra power of 2" to `exp` already so we have to take it back out
    int expshift = -1 + (coeff == 0.5f) * -1;
    return glug_float_sign(f) * exp2(exp + expshift);
}
float glug_float_lg(float f)
{
    return log2f(f);
}

float glug_float_integral(float f)
{
    float i, frac;
    glug_float_decomp(f, &i, &frac);

    return i;
}

float glug_float_frac(float f)
{
    float i, frac;
    glug_float_decomp(f, &i, &frac);

    return frac;
}

void glug_float_decomp(float f, float *i, float *frac)
{
    *frac = modff(f, i);
}

float glug_float_mod(float num, float div)
{
    return fmodf(num, div);
}

float glug_float_sign(float f)
{
    int neg = f < 0.f;
    int pos = f > 0.f;

    return 1.f * (pos - neg);
}

float glug_float_min(float f1, float f2)
{
    return fminf(f1, f2);
}

float glug_float_max(float f1, float f2)
{
    return fmaxf(f1, f2);
}

float glug_float_clamp(float f, float min, float max)
{
    return glug_float_max(min, glug_float_min(f, max));
}

float glug_float_rescale(float f, float old_min, float old_max, float new_min, float new_max)
{
    return (f - old_min) / (old_max - old_min) * (new_max - new_min) + new_min;
}

float glug_float_floor(float f)
{
    return floorf(f);
}

float glug_float_ceil(float f)
{
    return ceilf(f);
}

float glug_float_round(float f)
{
    return roundf(f);
}

float glug_float_round_zero(float f)
{
    return f - glug_float_frac(f);
}
