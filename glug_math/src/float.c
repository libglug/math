#include <glug/math/float.h>
#include <math.h>

float glug_float_next(float f)
{
    return nextafterf(f, INFINITY);
}

float glug_float_prev(float f)
{
    return nextafterf(f, -INFINITY);
}

void glug_float_swap(float *f1, float *f2)
{
    float tmp = *f1;
    *f1 = *f2;
    *f2 = tmp;
}

float glug_float_sign(float f)
{
    float neg = f < 0.f;
    float pos = f > 0.f;

    return pos - neg;
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
