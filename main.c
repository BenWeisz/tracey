#include <stdio.h>
#include <math.h>

#include "io/image.h"
#include "math/vec.h"
#include "graphics/ray.h"
#include "graphics/color.h"
#include "graphics/scene.h"

int main()
{
    const f32 aspect_ratio = 16.0 / 9.0;
    const u32 image_width = 1000;
    const u32 image_height = image_width / aspect_ratio;
    IMAGE* image = IMAGE_create(image_width, image_height);
    
    const f32 viewport_height = 2.0;
    const f32 viewport_width = viewport_height * (image_width + 0.0) / image_height;

    VEC4 camera_eye = VEC4_zero();
    camera_eye.w = 1.0;

    VEC4 camera_lookat = VEC4_zero();
    camera_lookat.z = -1.0;
    camera_lookat.w = 1.0;
    const f32 camera_f = 1.0;
    CAMERA camera = CAMERA_new(camera_eye, camera_lookat, camera_f, viewport_width, viewport_height, image_width, image_height);

    SCENE* scene = SCENE_create();
    SHAPE shape;
    shape.type = SHAPE_TYPE_SPHERE;
    shape.sphere.c = VEC4_new(0, 0, -2, 0);
    shape.sphere.r = 0.5;
    SHAPE_LIST_add(scene->shape_list, shape);
    shape.sphere.c = VEC4_new(0, -100.5, -1, 0);
    shape.sphere.r = 100;
    SHAPE_LIST_add(scene->shape_list, shape);

    RAY_LIST* ray_list = CAMERA_get_rays(&camera);
    RAY_LIST_ITERATOR ray_list_iterator = RAY_LIST_iterator(ray_list);
    for (u32 r_i = 0; r_i < ray_list->size; r_i++)
    {
        RAY* r = RAY_LIST_next(&ray_list_iterator);
        COLOR c = SCENE_hit(scene, r);

        const u32 j = r_i / image_width;
        const u32 i = r_i % image_width;
        IMAGE_set_pixel(image, i, j, c);
    }
    RAY_LIST_destroy(ray_list);
    
    SCENE_destroy(scene);

    IMAGE_write(image, "./test.ppm");
    IMAGE_destroy(image);

    return 0;
}