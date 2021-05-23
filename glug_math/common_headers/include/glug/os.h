#define GLUG_OS_UNK 0
#define GLUG_OS_WIN 1
#define GLUG_OS_OSX 2
#define GLUG_OS_LIN 3
#define GLUG_OS_BSD 4

#if defined(WIN32) || defined(_WIN32) || defined(WIN64) || defined(_WIN64)

    #define GLUG_OS GLUG_OS_WIN

#elif defined(__APPLE__) && defined(__MACH__)

    #include <TargetConditionals.h>
    #if TARGET_OS_OSX == 1

        #define GLUG_OS GLUG_OS_OSX

    #endif

#elif defined(__linux__)

    #define GLUG_OS GLUG_OS_LIN

#elif defined(__unix__)

    #include <sys/param.h>
    #if defined(BSD)

        #define GLUG_OS GLUG_OS_BSD

    #endif // BSD

#else

    #define GLUG_OS GLUG_OS_UNK

#endif
