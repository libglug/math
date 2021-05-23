#ifdef __cplusplus

  #ifndef GLUG_NAMESPACE_START
    #define GLUG_NAMESPACE_START(ns) namespace ns {
  #endif

  #ifndef GLUG_NAMESPACE_END
    #define GLUG_NAMESPACE_END }
  #endif

#else // C

  #ifndef GLUG_NAMESPACE_START
    #define GLUG_NAMESPACE_START(ns)
  #endif

  #ifndef GLUG_NAMESPACE_END
    #define GLUG_NAMESPACE_END
  #endif

#endif // __cplusplus
