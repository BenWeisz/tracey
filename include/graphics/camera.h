#ifndef CAMERA_H
#define CAMERA_H

#include "types.h"
#include "math/vec.h"

#include "graphics/ray.h"

#include "util/glist.h"

typedef struct CAMERA
{
    VEC4 origin;
    VEC4 lookat;
    f64 focal_length;
} CAMERA;

GLIST_DECLARE(RAY, RAY_LIST)

CAMERA CAMERA_new(const VEC4 origin, const VEC4 lookat, const f64 focal_length);

RAY_LIST* CAMERA_get_rays(const CAMERA* camera);

#endif // CAMERA_H