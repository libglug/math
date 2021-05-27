#ifndef GLUG_LINE3_T_H
#define GLUG_LINE3_T_H

#include <glug/math/vec3_t.h>

struct glug_line3
{
    struct glug_vec3 v, r0;
};

#ifdef GLUG_USE_TYPEDEFS
    typedef struct glug_line3 line3_t;
#endif

#endif // GLUG_LINE3_T_H
