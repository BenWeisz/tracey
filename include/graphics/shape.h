#ifndef SHAPE_H
#define SHAPE_H

#include <stdlib.h>
#include <stdio.h>

#include "types.h"
#include "math/vec.h"
#include "graphics/ray.h"
#include "util/glist.h"

#define SHAPE_TYPE_SPHERE 0x00

typedef struct SHAPE
{
    u32 type;
    void* form;
} SHAPE;


typedef struct SHAPE_HIT
{
    VEC4 p;
    VEC4 n;
    f64 t;
} SHAPE_HIT;

SHAPE* SHAPE_create(const u32 type);
void SHAPE_destroy(SHAPE* shape);
u32 SHAPE_hit(const SHAPE* shape, const RAY* ray, const f64 t_min, const f64 t_max, SHAPE_HIT* shape_hit);

typedef struct SPHERE
{
    VEC4 c;
    f64 r;
} SPHERE;

u32 SPHERE_hit(const SPHERE* sphere, const RAY* ray, const f64 t_min, const f64 t_max, SHAPE_HIT* shape_hit);

GLIST_DECLARE(SHAPE, SHAPE_list)

#endif // SHAPE_H