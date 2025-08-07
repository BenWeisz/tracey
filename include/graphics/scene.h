#ifndef SCENE_H
#define SCENE_H

#include <stdlib.h>
#include <stdio.h>

#include "types.h"
#include "graphics/shape.h"
#include "graphics/color.h"
#include "graphics/ray.h"

typedef struct SCENE
{
    SHAPE_LIST* shape_list;
} SCENE;

SCENE* SCENE_create();
void SCENE_destroy(SCENE* scene);

COLOR SCENE_get_color_at(const SCENE* scene, const RAY* ray);

#endif // SCENE_H