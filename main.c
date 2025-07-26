#include <stdio.h>

#include "image.h"

int main()
{
    IMAGE* image = IMAGE_create(100, 100);
    IMAGE_write(image, "./test.ppm");
    IMAGE_destroy(image);

    return 0;
}