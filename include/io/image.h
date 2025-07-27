#ifndef IMAGE_H
#define IMAGE_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "types.h"
#include "io.h"
#include "graphics/color.h"

typedef struct IMAGE
{
    u32 width;
    u32 height;
    u8 depth;
    f64* buf;
} IMAGE;

IMAGE* IMAGE_create(const u32 width, const u32 height);
void IMAGE_destroy(IMAGE* image);

u32 IMAGE_write(const IMAGE* image, const char* path);

void IMAGE_set_pixel(IMAGE* image, const u32 x, const u32 y, const COLOR c);

#endif // IMAGE_H