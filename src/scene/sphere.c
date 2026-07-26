#include "sphere.h"


Sphere sphere_create(Vec3 center, double radius, Material material)
{
    Sphere sphere;

    sphere.center = center;
    sphere.radius = radius;
    sphere.material = material;

    return sphere;
}


int sphere_hit(const Sphere *sphere, const Ray *ray, Hit *hit)
{
    Vec3 oc = vec3_sub(ray -> origin, sphere -> center);

    double a = vec3_dot(ray -> direction, ray -> direction);
    double b = 2.0 * vec3_dot(oc, ray -> direction);
    double c = vec3_dot(oc, oc) - sphere -> radius * sphere -> radius;

    double discriminant = b * b - 4.0 * a * c;

    if (discriminant < 1e-8)
    {
        return 0;
    }

    double sqrt_d = sqrt(discriminant);

    double t = (-b - sqrt_d) / (2 * a);

    if (t <= 1e-8)
    {
        t = (-b + sqrt_d) / (2 * a);
    }

    if (t <= 1e-8)
    {
        return 0;
    }

    hit -> t = t;
    hit -> point = ray_at(*ray, t);
    hit -> normal = vec3_normalize(vec3_sub(hit -> point, sphere -> center));
    hit -> material = sphere -> material;

    return 1;
}