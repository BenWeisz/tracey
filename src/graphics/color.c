#include "graphics/color.h"

COLOR COLOR_BLACK = { 0.0, 0.0, 0.0, 0.0 };
COLOR COLOR_RED =   { 1.0, 0.0, 0.0, 0.0 };
COLOR COLOR_GREEN = { 0.0, 1.0, 0.0, 0.0 };
COLOR COLOR_BLUE =  { 0.0, 0.0, 1.0, 0.0 };
COLOR COLOR_WHITE = { 1.0, 1.0, 1.0, 0.0 };

COLOR COLOR_new(const f64 r, const f64 g, const f64 b)
{
    COLOR c = { r, g, b, 0.0 };
    return c;
}