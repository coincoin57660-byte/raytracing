#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "vec3.h"
#include "material.h"
#include "ray.h"
#include "hit.h"


typedef struct
{
    Vec3 a;
    Vec3 b;
    Vec3 c;

    Material material;
    Vec3 normal;

} Triangle;


Triangle triangle_create(Vec3 a, Vec3 b, Vec3 c, Material material);

int triangle_hit(const Triangle *triangle, const Ray *ray, Hit *hit);


#endif