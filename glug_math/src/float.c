#include <glug/math/float.h>

void glug_float_swap(float *a, float *b)
{
    float tmp = *a;
    *a = *b;
    *b = tmp;
}
