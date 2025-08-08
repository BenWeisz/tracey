#include "math/interval.h"


INTERVAL INTERVAL_new(f64 low, f64 high)
{
    INTERVAL interval;
    interval.low = low;
    interval.high = high;
    return interval;
}

INTERVAL INTERVAL_universe()
{
    INTERVAL interval;
    interval.low = -INFINITY;
    interval.high = INFINITY;
    return interval;
}

INTERVAL INTERVAL_empty()
{
    INTERVAL interval;
    interval.low = INFINITY;
    interval.high = -INFINITY;
    return interval;
}

f64 INTERVAL_size(INTERVAL interval)
{
    return interval.high - interval.low;
}

u32 INTERVAL_contains(INTERVAL interval, f64 x)
{
    return interval.low <= x && x <= interval.high;
}

u32 INTERVAL_surrounds(INTERVAL interval, f64 x)
{
    return interval.low < x && x < interval.high;
}