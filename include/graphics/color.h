#ifndef COLOR_H
#define COLOR_H

#include "math/vec.h"
#include "types.h"

typedef VEC4 COLOR;

extern COLOR COLOR_BLACK;
extern COLOR COLOR_RED;
extern COLOR COLOR_GREEN;
extern COLOR COLOR_BLUE;
extern COLOR COLOR_WHITE;

COLOR COLOR_new(const f64 r, const f64 g, const f64 b);

#endif // COLOR_H