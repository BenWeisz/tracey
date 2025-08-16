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
    return INTERVAL_new(-INFINITY, INFINITY);
}

INTERVAL INTERVAL_empty()
{
    return INTERVAL_new(INFINITY, -INFINITY);
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