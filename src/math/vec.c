#include "math/vec.h"

VEC4 VEC4_new(const f64 x, const f64 y, const f64 z, const f64 w)
{
    return (VEC4){x, y, z, w};
}

VEC4 VEC4_zero()
{
    VEC4 zero = { 0, 0, 0, 0 };
    return zero;
}

VEC4 VEC4_neg(const VEC4 v)
{
    VEC4 neg = { -v.x, -v.y, -v.z, -v.w };
    return neg;
}

VEC4 VEC4_sub(const VEC4 v1, const VEC4 v2)
{
    VEC4 o;
    o.x = v1.x - v2.x;
    o.y = v1.y - v2.y;
    o.z = v1.z - v2.z;
    o.w = v1.w - v2.w;
    return o;
}

VEC4 VEC4_add(const VEC4 v1, const VEC4 v2)
{
    VEC4 o;
    o.x = v1.x + v2.x;
    o.y = v1.y + v2.y;
    o.z = v1.z + v2.z;
    o.w = v1.w + v2.w;
    return o;
}

VEC4 VEC4_mul(const VEC4 v, const f64 c)
{
    VEC4 o;
    o.x = v.x * c;
    o.y = v.y * c;
    o.z = v.z * c;
    o.w = v.w * c;
    return o;
}

VEC4 VEC4_div(const VEC4 v, const f64 c)
{
    VEC4 o;
    o.x = v.x / c;
    o.y = v.y / c;
    o.z = v.z / c;
    o.w = v.w / c;
    return o;
}

VEC4 VEC4_addc(const VEC4 v, const f64 c)
{
    VEC4 o = { v.x + c, v.y + c, v.z + c, v.w + c };
    return o;
}

f64 VEC4_norm3(const VEC4 v)
{
    return sqrt(VEC4_dot3(v, v));
}

f64 VEC4_dot3(const VEC4 v1, const VEC4 v2)
{
    return (v1.x * v2.x) + (v1.y * v2.y) + (v1.z * v2.z);
}

VEC4 VEC4_cross3(const VEC4 v1, const VEC4 v2)
{
    VEC4 o;
    o.x = (v1.y * v2.z) - (v1.z * v2.y);
    o.y = (v1.z * v2.x) - (v1.x * v2.z);
    o.z = (v1.x * v2.y) - (v1.y * v2.x);
    o.w = 0;
    return o;
}

VEC4 VEC4_normalize3(const VEC4 v)
{
    u32 is_pos = 1;
    if (v.w == 0.0) is_pos = 0;

    f64 norm = VEC4_norm3(v);
    VEC4 o = VEC4_div(v, norm);
    
    if (is_pos) o.w = 1.0;
    else o.w = 0.0;

    return o;
}

void VEC4_print(const VEC4 v)
{
    printf("{ x=%lf, y=%lf, z=%lf, w=%lf }\n", v.x, v.y, v.z, v.w);
}