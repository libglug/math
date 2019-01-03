#ifndef GLUG_CIRCLE_T_H
#define GLUG_CIRCLE_T_H

#include <glug/math/vec2_t.h>

struct glug_circle
{
    struct glug_vec2 center;
    float radius;
};

#ifdef GLUG_USE_TYPEDEFS
    typedef struct glug_circle circle;
#endif

#endif // GLUG_CIRCLE_T_H
