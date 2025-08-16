#include "graphics/scene.h"

SCENE* SCENE_create()
{
    SCENE* scene = (SCENE*)malloc(sizeof(SCENE));
    if (scene == NULL)
    {
        printf("ERROR: Failed to allocate space for scene.\n");
        return NULL;
    }

    scene->shape_list = SHAPE_LIST_create();
    if (scene->shape_list == NULL)
    {
        free(scene);
        return NULL;
    }

    return scene;
}

void SCENE_destroy(SCENE* scene)
{
    if (scene != NULL)
    {
        if (scene->shape_list != NULL) 
            SHAPE_LIST_destroy(scene->shape_list);
        free(scene);
    }
}

COLOR SCENE_hit(const SCENE* scene, const RAY* ray)
{
    SHAPE_LIST_ITERATOR iterator = SHAPE_LIST_iterator(scene->shape_list);
    SHAPE* shape = SHAPE_LIST_next(&iterator);
    
    // TODO: Change this later
    SHAPE_HIT closest_hit;
    closest_hit.t = RAY_MAX_T;
    while (shape != NULL)
    {
        SHAPE_HIT shape_hit;
        INTERVAL t_interval = INTERVAL_new(0, closest_hit.t);
        u32 hit = SHAPE_hit(shape, ray, t_interval, &shape_hit);
        if (hit && shape_hit.t < closest_hit.t)
        {
            closest_hit = shape_hit;
        }

        shape = SHAPE_LIST_next(&iterator);
    }

    if (closest_hit.t != RAY_MAX_T)
    {
        COLOR c = VEC4_div(VEC4_addc(closest_hit.n, 1.0), 2.0);
        return c;
    }

    VEC4 u_dir = VEC4_normalize3(ray->dir);
    f64 a = 0.5 * (u_dir.y + 1.0);
    COLOR c = VEC4_add(VEC4_mul(COLOR_WHITE, 1.0 - a), VEC4_mul(COLOR_new(0.5, 0.7, 1.0), a));
    return c;
}

u32 SCENE_render(const SCENE* scene, const IMAGE* image, const CAMERA* camera)
{
    return 0;
}