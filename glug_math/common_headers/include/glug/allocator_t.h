#ifndef GLUG_ALLOCATOR_H
#define GLUG_ALLOCATOR_H

#include <stddef.h>

typedef void *(*glug_malloc_t) (size_t nbytes, void *context);
typedef void  (*glug_free_t)   (void *block, void *context);
typedef void *(*glug_realloc_t)(void *block, void *context);

struct glug_allocator
{
    glug_malloc_t   malloc;
    glug_free_t     free;
    void           *context;
};

struct glug_reallocator
{
    struct glug_allocator allocator;
    glug_realloc_t        realloc;
};

#ifdef GLUG_USE_TYPEDEFS
    typedef struct glug_allocator   glug_allocator_t;
    typedef struct glug_reallocator glug_reallocator_t;
#endif

#endif // GLUG_ALLOCATOR_H
