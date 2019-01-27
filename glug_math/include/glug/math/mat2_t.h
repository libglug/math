#ifndef GLUG_MAT2_T_H
#define GLUG_MAT2_T_H

struct glug_mat2
{
    float els[2][2];
};

#ifdef GLUG_USE_TYPEDEFS
    typedef struct glug_mat2 mat2;
#endif

#endif // GLUG_MAT2_T_H
