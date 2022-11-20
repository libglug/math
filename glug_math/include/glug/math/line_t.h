#ifndef GLUG_LINE_T_H
#define GLUG_LINE_T_H

#include <glug/math/vec3_t.h>

struct glug_line
{
    struct glug_vec3 v, r0;
};

#ifdef GLUG_USE_TYPEDEFS
    typedef struct glug_line line_t;
#endif

#endif // GLUG_LINE_T_H
