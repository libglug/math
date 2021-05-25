#include "os.h"

#ifndef GLUG_LIB_API
    #ifndef GLUG_STATIC
        #if GLUG_OS == GLUG_OS_WIN

            #define GLUG_LIB_API __declspec (dllimport)

        #elif GLUG_OS == GLUG_OS_OSX || GLUG_OS == GLUG_OS_LIN || GLUG_OS == GLUG_OS_BSD

            #define GLUG_LIB_API __attribute__ ((visibility ("default")))

        #else

            #define GLUG_LIB_API

        #endif
    #else

        #define GLUG_LIB_API

    #endif // GLUG_STATIC

#endif // GLUG_LIB_API
