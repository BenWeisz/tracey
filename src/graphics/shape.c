#include "graphics/shape.h"

GLIST_DEFINE(SHAPE, SHAPE_list)

SHAPE* SHAPE_create(const u32 type)
{
    SHAPE* shape = (SHAPE*)malloc(sizeof(SHAPE));
    if (shape == NULL)
    {
        printf("ERROR: Failed to allocate memory for shape.\n");
        return NULL;
    }

    shape->type = type;

    if (type == SHAPE_TYPE_SPHERE)
    {
        shape->sphere.c = VEC4_zero();
        shape->sphere.r = 0.0;
    }
    else
    {
        printf("ERROR: The form provided does not specify a valid shape.\n");
        free(shape);
        return NULL;
    }

    return shape;
}

void SHAPE_destroy(SHAPE* shape)
{
    free(shape);
}

u32 SHAPE_hit(const SHAPE* shape, const RAY* ray, const f64 t_min, const f64 t_max, SHAPE_HIT* shape_hit)
{
    if (shape->type == SHAPE_TYPE_SPHERE)
    {
        return SPHERE_hit(&(shape->sphere), ray, t_min, t_max, shape_hit);
    }

    return 0;
}

u32 SPHERE_hit(const SPHERE* sphere, const RAY* ray, const f64 t_min, const f64 t_max, SHAPE_HIT* shape_hit)
{
    if (sphere->r <= 1e-6)
    {
        printf("ERROR: Did you forget to initialize this sphere?\n");
        return 0;
    }

    VEC4 oc = VEC4_sub(sphere->c, ray->origin); // o to c
    f64 a = VEC4_dot3(ray->dir, ray->dir);
    f64 h = VEC4_dot3(ray->dir, oc);
    f64 c = VEC4_dot3(oc, oc) - (sphere->r * sphere->r);
    f64 discriminant = (h * h) - (a * c);

    if (discriminant < 0) return 0;

    f64 sqrtd = sqrt(discriminant);
    shape_hit->t = (h - sqrtd) / a;

    if (shape_hit->t < t_min || shape_hit->t > t_max)
    {
        shape_hit->t = (h + sqrtd) / a;
        if (shape_hit->t < t_min || shape_hit->t > t_max)
            return 0;
    }

    shape_hit->p = RAY_at(*ray, shape_hit->t);
    shape_hit->n = VEC4_div(VEC4_sub(shape_hit->p, sphere->c), sphere->r);
    return 1;
}