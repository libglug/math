#if defined (WIN32) || defined (_WIN32) || defined (WIN64) || defined (_WIN64)

  #define GLUG_OS_WIN

#elif defined (__APPLE__) && defined (__MACH__)
  #include <TargetConditionals.h>

  #if TARGET_OS_MAC == 1

    #define GLUG_OS_MAC

  #endif

#elif defined (__linux__)

  #define GLUG_OS_LIN

#endif
