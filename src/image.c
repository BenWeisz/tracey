#include "image.h"

IMAGE* IMAGE_create(const u32 width, const u32 height)
{
    IMAGE* image = (IMAGE*)malloc(sizeof(IMAGE));
    if (image == NULL)
    {
        printf("ERROR: Failed to create image\n");
        return NULL;
    }

    image->width = width;
    image->height = height;
    
    image->buf = (f32*)malloc(sizeof(f32) * width * height * 3);
    if (image->buf == NULL)
    {
        printf("ERROR: Failed to create buffer for image\n");
        free(image);
        return NULL;
    }

    return image;
}

void IMAGE_destroy(IMAGE* image)
{
    free(image->buf);
    image->buf = NULL;
    free(image);
}

u32 IMAGE_write(const IMAGE* image, const char* path)
{
    IO_FILE file = IO_open(path, WRITE);
    
    // Write header
    u32 r = IO_write(file, (u8*)"P6\n", 3);
    if (r == 0)
    {
        IO_close(file);
        printf("ERROR: Failed to save magic header\n");
        return 0;
    }

    // Write the dimension str
    char dimension_str[256];
    snprintf(dimension_str, 256, "%u %u\n", image->width, image->height);
    size_t dimension_str_len = strnlen(dimension_str, 256);
    r = IO_write(file, (u8*)dimension_str, dimension_str_len);
    if (r == 0)
    {
        IO_close(file);
        printf("ERROR: Failed to save dimension string\n");
        return 0;
    }

    // Write the quantization
    r = IO_write(file, (u8*)"255\n", 4);
    if (r == 0)
    {
        IO_close(file);
        printf("ERROR: Failed to save quantization string\n");
        return 0;
    }

    u8* byte_buf = (u8*)malloc(sizeof(u8) * image->width * image->height * 3);
    if (byte_buf == NULL)
    {
        IO_close(file);
        return 0;
    }
    
    // Quantize the data
    for (u32 y = 0; y < image->height; y++)
    {
        for (u32 x = 0; x < image->width; x++)
        {
            for (u32 c = 0; c < 3; c++)
            {
                byte_buf[(((image->width * y) + x) * 3) + c] = (u8)(255.99 * image->buf[(((image->width * y) + x) * 3) + c]);
            }
        }
    }

    
    r = IO_write(file, byte_buf, image->width * image->height * 3);

    free(byte_buf);

    if (r == 0)
    {
        printf("ERROR: Failed to save the image data\n");
        IO_close(file);
        return 0;
    }
    
    IO_close(file);

    return 1;
}

void IMAGE_set_pixel(IMAGE* image, const u32 x, const u32 y, const float r, const float g, const float b)
{
    image->buf[(((image->width * y) + x) * 3)]      = r;
    image->buf[(((image->width * y) + x) * 3) + 1]  = g;
    image->buf[(((image->width * y) + x) * 3) + 2]  = b;
}