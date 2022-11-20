#ifndef GLUG_TRIANGLE_T_H
#define GLUG_TRIANGLE_T_H

#include <glug/math/vec3_t.h>

struct glug_triangle
{
    struct glug_vec3 a, b, c;
};

#ifdef GLUG_USE_TYPEDEFS
    typedef struct glug_triangle triangle_t;
#endif

#endif // GLUG_TRIANGLE_T_H
