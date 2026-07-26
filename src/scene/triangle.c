#include "triangle.h"


Triangle triangle_create(Vec3 a, Vec3 b, Vec3 c, Material material)
{
    Triangle triangle;

    triangle.a = a;
    triangle.b = b;
    triangle.c = c;
    triangle.material = material;

    Vec3 AB = vec3_sub(b, a);
    Vec3 AC = vec3_sub(c, a);
    triangle.normal = vec3_normalize(vec3_cross(AB, AC));

    return triangle;
}

int triangle_hit(const Triangle *triangle, const Ray *ray, Hit *hit)
{
    Vec3 edge1 = vec3_sub(triangle -> b, triangle -> a);
    Vec3 edge2 = vec3_sub(triangle -> c, triangle -> a);

    Vec3 h = vec3_cross(ray -> direction, edge2);
    double a = vec3_dot(edge1, h);

    if (fabs(a) < 1e-8)
    {
        return 0;
    }

    double f = 1.0 / a;

    Vec3 s = vec3_sub(ray -> origin, triangle -> a);

    double u = f * vec3_dot(s, h);

    if (u < 0.0 || u > 1.0)
    {
        return 0;
    }

    Vec3 q = vec3_cross(s, edge1);

    double v = f * vec3_dot(ray -> direction, q);

    if (v < 0.0 || u + v > 1.0)
    {
        return 0;
    }

    double t = f * vec3_dot(edge2, q);

    if (t < 1e-8)
    {
        return 0;
    }

    hit -> t = t;
    hit -> point = ray_at(*ray, t);

    hit -> normal = vec3_mul(triangle -> normal, -1);
    hit -> material = triangle -> material;

    return 1;
}