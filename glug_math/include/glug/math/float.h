#ifndef GLUG_FLOAT_H
#define GLUG_FLOAT_H

#include <stdint.h>

#include <glug/extern.h>
#include <glug/import.h>
#include <glug/bool_t.h>

GLUG_EXTERN_START

GLUG_LIB_API float glug_float_inf(void);
GLUG_LIB_API float glug_float_nan(void);
GLUG_LIB_API float glug_float_π(void);
GLUG_LIB_API float glug_float_pi(void);
GLUG_LIB_API float glug_float_e(void);
GLUG_LIB_API float glug_float_sqrt2(void);
GLUG_LIB_API float glug_float_log2(void);

GLUG_LIB_API glug_bool_t glug_float_equal_strict(float f1, float f2);
GLUG_LIB_API glug_bool_t glug_float_equal_approx(float f1, float f2, float diff);
GLUG_LIB_API glug_bool_t glug_float_equal_ulps  (float f1, float f2, uint32_t ulps);

GLUG_LIB_API float glug_float_next(float f);
GLUG_LIB_API float glug_float_prev(float f);
GLUG_LIB_API float glug_float_rand(float min, float max);
GLUG_LIB_API void glug_float_swap(float *f1, float *f2);

GLUG_LIB_API glug_bool_t glug_float_is_pow2(float f);
GLUG_LIB_API float glug_float_next_pow2(float f);
GLUG_LIB_API float glug_float_prev_pow2(float f);
GLUG_LIB_API float glug_float_lg(float f);

GLUG_LIB_API float glug_float_sign(float f);
GLUG_LIB_API float glug_float_integral(float f);
GLUG_LIB_API float glug_float_frac(float f);
GLUG_LIB_API void glug_float_decomp(float f, float *i, float *frac);
GLUG_LIB_API float glug_float_mod(float num, float div);

GLUG_LIB_API float glug_float_min(float f1, float f2);
GLUG_LIB_API float glug_float_max(float f1, float f2);
GLUG_LIB_API float glug_float_clamp(float f, float min, float max);
GLUG_LIB_API float glug_float_rescale(float f, float old_min, float old_max, float new_min, float new_max);

GLUG_LIB_API float glug_float_floor(float f);
GLUG_LIB_API float glug_float_ceil(float f);
GLUG_LIB_API float glug_float_round(float f);
GLUG_LIB_API float glug_float_round_zero(float f);

GLUG_EXTERN_END

#endif // GLUG_FLOAT_H
