#include <glug/math/float.h>
#include <math.h>

#include <time.h>
#include <stdlib.h>

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

    for (; ulps-- && min <= max;)
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
    srand(time(NULL));
    int r = rand();

    // normalize r to [0, 1]
    double nrand = (double)r / RAND_MAX;
    // scale to the range of [min, max]
    float range = max - min;
    return (float)(nrand * range + min);
}

void glug_float_swap(float *f1, float *f2)
{
    float tmp = *f1;
    *f1 = *f2;
    *f2 = tmp;
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
