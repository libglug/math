#ifndef GLUG_RECT_T_H
#define GLUG_RECT_T_H

#include <glug/math/vec2_t.h>

struct glug_rect
{
    struct glug_vec2 min;
    struct glug_vec2 max;
};

#ifdef GLUG_USE_TYPEDEFS
    typedef struct glug_rect rect;
#endif

#endif // GLUG_RECT_T_H
