#include <glug/math/float.h>

void GLUG_LIB_API glug_float_swap(float *a, float *b)
{
    float tmp = *a;
    *a = *b;
    *b = tmp;
}
