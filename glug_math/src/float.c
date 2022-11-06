#include <glug/math/float.h>
#include <math.h>

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

float glug_float_next(float f)
{
    return nextafterf(f, INFINITY);
}

float glug_float_prev(float f)
{
    return nextafterf(f, -INFINITY);
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
    float smaller = (f1 < f2) * f1 + (f2 <= f1) * f2;
    float larger  = (f1 > f2) * f1 + (f2 >= f1) * f2;

    for (; ulps-- && smaller <= larger;)
        smaller = nextafterf(smaller, INFINITY);

    return larger <= smaller;
}
