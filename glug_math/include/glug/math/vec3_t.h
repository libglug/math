#ifndef GLUG_VEC3_T_H
#define GLUG_VEC3_T_H

struct glug_vec3
{
    float x, y, z;
};

#ifdef GLUG_USE_TYPEDEFS
    typedef struct glug_vec3 vec3;
#endif

#endif // GLUG_VEC3_T_H
