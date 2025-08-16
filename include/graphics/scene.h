#ifndef SCENE_H
#define SCENE_H

#include <stdlib.h>
#include <stdio.h>

#include "types.h"

#include "math/interval.h"

#include "graphics/shape.h"
#include "graphics/color.h"
#include "graphics/ray.h"
#include "graphics/camera.h"

#include "io/image.h"

typedef struct SCENE
{
    SHAPE_LIST* shape_list;
} SCENE;

SCENE* SCENE_create();
void SCENE_destroy(SCENE* scene);

COLOR SCENE_hit(const SCENE* scene, const RAY* ray);
u32 SCENE_render(const SCENE* scene, const IMAGE* image, const CAMERA* camera);

#endif // SCENE_H