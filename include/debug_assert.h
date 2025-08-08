#ifndef DEBUG_ASSERT_H
#define DEBUG_ASSERT_H

#ifdef __DEBUG__
    #include <stdio.h>
    #define DEBUG_ASSERT(expr) \
        do { \
            if (!(expr)) { \
                printf("ASSERT FAILED: %s\nFile: %s, Line: %d\n", #expr, __FILE__, __LINE__); \
                exit(1); \
            } \
        } while (0)
    
    #include <math.h>
    #define DEBUG_ASSERT_CLOSE(x, y) DEBUG_ASSERT(fabs((x) - (y)) < 0.001)
#else
    #define DEBUG_ASSERT(expr) ((void)0)
    #define DEBUG_ASSERT_CLOSE(x, y) ((void)0)
#endif

#endif // DEBUG_ASSERT_H