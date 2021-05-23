#ifdef __cplusplus

  #ifndef GLUG_EXTERN_START
    #define GLUG_EXTERN_START extern "C" {
  #endif

  #ifndef GLUG_EXTERN_END
    #define GLUG_EXTERN_END }
  #endif

#else // C

  #ifndef GLUG_EXTERN_START
    #define GLUG_EXTERN_START
  #endif

  #ifndef GLUG_EXTERN_END
    #define GLUG_EXTERN_END
  #endif

#endif // __cplusplus
