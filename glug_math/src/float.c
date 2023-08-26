#include <glug/math/float.h>
#define _USE_MATH_DEFINES
#include <math.h>
#include <time.h>
#include <stdlib.h>

#include <fenv.h>
#include <stdio.h>

#define LOG2 0.3010299956639812

float glug_float_inf(void)
{
    return INFINITY;
}

float glug_float_nan(void)
{
    return (float)NAN;
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

bool glug_float_is_inf(float f)
{
    return isinf(f);
}

bool glug_float_is_nan(float f)
{
    return isnan(f);
}

bool glug_float_equal_strict(float f1, float f2)
{
    return (
        (!glug_float_is_nan(f1) && !glug_float_is_nan(f2)) && (
            (glug_float_is_inf(f1) && glug_float_is_inf(f2) && glug_float_sign(f1) == glug_float_sign(f2)) ||
            (f1 == f2)
        )
    );
}

bool glug_float_equal_approx(float f1, float f2, float diff)
{
    return fabsf(f1 - f2) <= diff;
}

bool glug_float_equal_ulps(float f1, float f2, uint32_t ulps)
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

enum float_error glug_float_load(float *res, float scalar, int exp)
{
    feclearexcept(FE_ALL_EXCEPT);

    *res = ldexpf(scalar, exp);

    enum float_error err = fe_none;
    if (fetestexcept(FE_OVERFLOW))
    {
        printf("overflow");
        err = fe_overflow;
    }

    if (fetestexcept(FE_UNDERFLOW))
    {
        printf("underflow");
        err = fe_underflow;
    }

    return err;
}

void glug_float_unload(float f, float *scalar, int *exp)
{
    *scalar = frexpf(f, exp);
}

float glug_float_rand()
{
    srand(time(NULL));
    int r = rand();

    // normalize r to [0, 1]
    double nrand = (double)r / RAND_MAX;
    return (float)nrand;
}

void glug_float_swap(float *f1, float *f2)
{
    float tmp = *f1;
    *f1 = *f2;
    *f2 = tmp;
}

bool glug_float_is_pow2(float f)
{
    int exp;
    float coeff = frexpf(f, &exp);

    // if `coeff` is 0.5f, then f was a power of 2 resulting from `1/2 * 2^exp`
    return coeff == glug_float_sign(f) * 0.5f;
}

float glug_float_next_pow2(float f)
{
    if (f < 0.f) return -glug_float_prev_pow2(-f);

    int exp;
    float coeff = frexpf(f, &exp);

    if (isinf(coeff) || isnan(coeff) || coeff == 0.f) return coeff;

    return glug_float_sign(f) * exp2f((float)exp);
}

float glug_float_prev_pow2(float f)
{
    if (f < 0.f) return -glug_float_next_pow2(-f);

    int exp;
    float coeff = frexpf(f, &exp);

    if (isinf(coeff) || isnan(coeff) || coeff == 0.f) return coeff;

    // shift the exponent by -1 so that we get the previous power of 2 but...
    // if `coeff` (returned by frexp) is 0.5f, it's "added an extra power of 2" to `exp` already so we have to take it back out
    int expshift = -1 + (coeff == 0.5f) * -1;
    return glug_float_sign(f) * exp2f(exp + expshift);
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

float glug_float_abs(float f) {
    return fabsf(f);
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

float glug_float_round_inf(float f)
{
    float sign = glug_float_sign(f);
    float rounded = glug_float_ceil(glug_float_abs(f));

    return sign * rounded;
}
