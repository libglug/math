#ifndef GLUG_TRIANGLE2_T_H
#define GLUG_TRIANGLE2_T_H

#include <glug/math/vec2_t.h>

struct glug_triangle2
{
    struct glug_vec2 a, b, c;
};

#ifdef GLUG_USE_TYPEDEFS
    typedef struct glug_triangle2 triangle2;
#endif

#endif // GLUG_TRIANGLE2_T_H
