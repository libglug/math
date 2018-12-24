#ifndef GLUG_SPHERE_T_H
#define GLUG_SPHERE_T_H

#include <glug/math/vec3_t.h>

struct glug_sphere
{
    struct glug_vec3 c;
    float r;
};

#ifdef GLUG_USE_TYPEDEFS
    typedef struct glug_sphere sphere;
#endif

#endif // GLUG_SPHERE_T_H
