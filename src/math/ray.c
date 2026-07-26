#include "ray.h"


Ray ray_create(Vec3 origin, Vec3 direction)
{
    Ray ray;

    ray.origin = origin;
    ray.direction = vec3_normalize(direction);

    return ray;
}


Vec3 ray_at(Ray ray, double t)
{
    return vec3_add(ray.origin, vec3_mul(ray.direction, t));
}