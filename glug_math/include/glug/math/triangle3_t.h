#ifndef GLUG_TRIANGLE3_T_H
#define GLUG_TRIANGLE3_T_H

#include <glug/math/vec3_t.h>

struct glug_triangle3
{
    struct glug_vec3 a, b, c;
};

#ifdef GLUG_USE_TYPEDEFS
    typedef struct glug_triangle3 triangle3_t;
#endif

#endif // GLUG_TRIANGLE3_T_H
