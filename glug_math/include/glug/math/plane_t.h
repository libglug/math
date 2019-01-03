#ifndef GLUG_PLANE_T_H
#define GLUG_PLANE_T_H

#include <glug/math/vec3_t.h>

struct glug_plane
{
    struct glug_vec3 normal;
    float offset;
};

#ifdef GLUG_USE_TYPEDEFS
    typedef struct glug_plane plane;
#endif

#endif // GLUG_PLANE_T_H
