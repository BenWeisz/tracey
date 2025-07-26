#include <stdio.h>

#include "image.h"

int main()
{
    IMAGE* image = IMAGE_create(2, 2);
    IMAGE_set_pixel(image, 0, 0, 1.0, 0.0, 0.0);
    IMAGE_set_pixel(image, 1, 0, 0.0, 1.0, 0.0);
    IMAGE_set_pixel(image, 0, 1, 0.0, 0.0, 1.0);
    IMAGE_set_pixel(image, 1, 1, 1.0, 1.0, 1.0);

    IMAGE_write(image, "./test.ppm");
    IMAGE_destroy(image);

    return 0;
}