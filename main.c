#include <stdio.h>

#include "io/image.h"
#include "math/vec.h"
#include "math/ray.h"
#include "graphics/color.h"

u32 hit_sphere(const VEC4 center, f64 r, const RAY ray)
{
    VEC4 oc = VEC4_sub(center, ray.origin); // o to c
    f64 a = VEC4_dot3(ray.dir, ray.dir);
    f64 b = -2.0 * VEC4_dot3(ray.dir, oc);
    f64 c = VEC4_dot3(oc, oc) - (r * r);
    f64 discriminant = (b * b) - (4 * a * c);
    
    if (discriminant >= 0) return 1;
    return 0;
}

COLOR ray_color(const RAY r)
{
    // VEC4_print(r.dir);
    if (hit_sphere(VEC4_new(0, 0, -1, 0), 0.5, r))
    {
        return COLOR_BLUE;
    }

    VEC4 u_dir = VEC4_normalize3(r.dir);
    f64 a = 0.5 * (u_dir.y + 1.0);
    COLOR c = VEC4_add(VEC4_mul(COLOR_WHITE, 1.0 - a), VEC4_mul(COLOR_new(0.5, 0.7, 1.0), a));
    return c;
}

int main()
{
    const f32 aspect_ratio = 16.0 / 9.0;
    const u32 image_width = 400;
    const u32 image_height = image_width / aspect_ratio;
    IMAGE* image = IMAGE_create(image_width, image_height);
    
    const f32 viewport_height = 2.0;
    const f32 viewport_width = viewport_height * (image_width + 0.0) / image_height;

    VEC4 camera_origin = VEC4_zero();
    camera_origin.w = 1.0;

    f32 camera_focal_length = 1.0;

    VEC4 viewport_u = { viewport_width, 0.0, 0.0, 0.0 };
    VEC4 viewport_v = { 0.0, -viewport_height, 0.0, 0.0 };

    VEC4 viewport_du = VEC4_div(viewport_u, image_width);
    VEC4 viewport_dv = VEC4_div(viewport_v, image_height);

    VEC4 viewport_top_left = VEC4_sub(
        VEC4_add(
            camera_origin, 
            VEC4_new(0.0, 0.0, -camera_focal_length, 0.0)),
        VEC4_add(VEC4_div(viewport_u, 2.0), VEC4_div(viewport_v, 2.0)));
    VEC4 viewport_p00 = VEC4_add(viewport_top_left, VEC4_div(VEC4_add(viewport_du, viewport_dv), 2.0));
    
    VEC4_print(camera_origin);
    VEC4_print(viewport_top_left);
    VEC4_print(viewport_p00);

    for (u32 j = 0; j < image_height; j++)
    {
        // printf("Scanlines remaining: %u\n", (image_height - j));
        for (u32 i = 0; i < image_width; i++)
        {
            RAY r;
            r.origin = camera_origin;
            
            VEC4 u_offset = VEC4_mul(viewport_du, i);
            VEC4 v_offset = VEC4_mul(viewport_dv, j);
            VEC4 offset = VEC4_add(u_offset, v_offset);
            VEC4 viewport_pij = VEC4_add(viewport_p00, offset);

            r.dir = VEC4_sub(viewport_pij, camera_origin);
            // VEC4_print(r.dir);

            COLOR c = ray_color(r);
            IMAGE_set_pixel(image, i, j, c);
        }
    }

    IMAGE_write(image, "./test.ppm");
    IMAGE_destroy(image);

    return 0;
}