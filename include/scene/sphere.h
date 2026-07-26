#ifndef SPHERE_H
#define SPHERE_H

#include "vec3.h"
#include "material.h"
#include "ray.h"
#include "hit.h"


typedef struct
{
    Vec3 center;
    double radius;
    Material material;

} Sphere;


Sphere sphere_create(Vec3 center, double radius, Material material);

int sphere_hit(const Sphere *sphere, const Ray *ray, Hit *hit);


#endif