#ifndef GLUG_LINE2_T_H
#define GLUG_LINE2_T_H

#include <glug/math/vec2_t.h>

struct glug_line2
{
    struct glug_vec2 v, r0;
};

#ifdef GLUG_USE_TYPEDEFS
    typedef struct glug_line2 line2_t;
#endif

#endif // GLUG_LINE2_T_H
