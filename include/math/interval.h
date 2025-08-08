#ifndef INTERVAL_H
#define INTERVAL_H

#include <math.h>

#include "types.h"

typedef struct INTERVAL
{
    f64 low;
    f64 high;
} INTERVAL;

INTERVAL INTERVAL_new(f64 low, f64 high);
INTERVAL INTERVAL_universe();
INTERVAL INTERVAL_empty();
f64 INTERVAL_size(INTERVAL interval);
u32 INTERVAL_contains(INTERVAL interval, f64 x);
u32 INTERVAL_surrounds(INTERVAL interval, f64 x);

#endif // INTERVAL_H