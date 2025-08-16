#ifndef CAMERA_H
#define CAMERA_H

#include "types.h"
#include "debug_assert.h"

#include "math/vec.h"

#include "graphics/ray.h"

#include "util/glist.h"

typedef struct CAMERA
{
    VEC4 eye;
    VEC4 lookat;
    f64 f;
    f64 vw;
    f64 vh;
    f64 iw;
    f64 ih;
} CAMERA;

GLIST_DECLARE(RAY, RAY_LIST)

CAMERA CAMERA_new(const VEC4 eye, const VEC4 lookat, const f64 f, const f64 vw, const f64 vh, const u32 iw, const u32 ih);

RAY_LIST* CAMERA_get_rays(const CAMERA* camera);

#endif // CAMERA_H