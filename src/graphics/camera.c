#include "graphics/camera.h"

GLIST_DEFINE(RAY, RAY_LIST)

CAMERA CAMERA_new(const VEC4 eye, const VEC4 lookat, const f64 f, const f64 vw, const f64 vh, const u32 iw, const u32 ih)
{
    DEBUG_ASSERT_CLOSE(eye.w, 1.0);
    DEBUG_ASSERT_CLOSE(lookat.w, 1.0);
    DEBUG_ASSERT(f > 0.0);
    DEBUG_ASSERT(vw > 0.0);
    DEBUG_ASSERT(vh > 0.0);
    DEBUG_ASSERT(iw > 0);
    DEBUG_ASSERT(ih > 0);

    CAMERA camera;
    camera.eye = eye;
    camera.lookat = lookat;
    camera.f = f;       // Focal length
    camera.vw = vw;     // Viewport width
    camera.vh = vh;     // Viewport height
    camera.iw = iw;     // Image width
    camera.ih = ih;     // Image height

    return camera;
}

RAY_LIST* CAMERA_get_rays(const CAMERA* camera)
{
    VEC4 view = VEC4_normalize3(VEC4_sub(camera->lookat, camera->eye));
    VEC4 right = VEC4_cross3(view, VEC4_new(0.0, 1.0, 0.0, 1.0));
    if (VEC4_dot3(right, VEC4_new(1.0, 1.0, 1.0, 1.0)) < 1e-6)
        right = VEC4_cross3(view, VEC4_new(0.0, 1.0, -1e-6, 1.0));
    right = VEC4_normalize3(right);

    VEC4 down = VEC4_normalize3(VEC4_cross3(view, right));

    VEC4 viewport_u = VEC4_mul(right, camera->vw);
    VEC4 viewport_v = VEC4_mul(down, camera->vh);

    VEC4 viewport_du = VEC4_div(viewport_u, camera->iw);
    VEC4 viewport_dv = VEC4_div(viewport_v, camera->ih);

    view = VEC4_mul(view, camera->f);
    
    VEC4 viewport_top_left = VEC4_sub(
        VEC4_add(camera->eye, view),
        VEC4_add(VEC4_div(viewport_u, 2.0), VEC4_div(viewport_v, 2.0)));
    VEC4 viewport_p00 = VEC4_add(viewport_top_left, VEC4_div(VEC4_add(viewport_du, viewport_dv), 2.0));

    RAY_LIST* ray_list = RAY_LIST_create();
    for (u32 j = 0; j < camera->ih; j++)
    {
        for (u32 i = 0; i < camera->iw; i++)
        {
            RAY r;
            r.origin = camera->eye;
            
            VEC4 u_offset = VEC4_mul(viewport_du, i);
            VEC4 v_offset = VEC4_mul(viewport_dv, j);
            VEC4 offset = VEC4_add(u_offset, v_offset);
            VEC4 viewport_pij = VEC4_add(viewport_p00, offset);

            r.dir = VEC4_normalize3(VEC4_sub(viewport_pij, camera->eye));

            RAY_LIST_add(ray_list, r);
        }
    }

    return ray_list;
}

