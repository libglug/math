#ifndef GLUG_VEC4_T_H
#define GLUG_VEC4_T_H

struct glug_vec4
{
    float x, y, z, w;
};

#ifdef GLUG_USE_TYPEDEFS
    typedef struct glug_vec4 vec4;
#endif

#endif // GLUG_VEC4_T_H
