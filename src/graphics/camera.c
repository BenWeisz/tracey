#include "graphics/camera.h"

GLIST_DEFINE(RAY, RAY_LIST)

CAMERA CAMERA_new(const VEC4 origin, const VEC4 lookat, const f64 focal_length)
{
    CAMERA camera;
    camera.origin = origin;
    camera.lookat = lookat;
    camera.focal_length = focal_length;
    return camera;
}

RAY_LIST* CAMERA_get_rays(const CAMERA* camera)
{
    RAY_LIST* ray_list = RAY_LIST_create();
    return ray_list;
}

