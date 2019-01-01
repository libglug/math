#ifndef GLUG_BOX_T_H
#define GLUG_BOX_T_H

#include <glug/math/vec3_t.h>

struct glug_box
{
    struct glug_vec3 min;
    struct glug_vec3 max;
};

#ifdef GLUG_USE_TYPEDEFS
    typedef struct glug_box box;
#endif

#endif // GLUG_BOX_T_H
