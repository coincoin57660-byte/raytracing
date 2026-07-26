#ifndef HIT_H
#define HIT_H

#include "vec3.h"
#include "material.h"


typedef struct
{
    double t;
    Vec3 point;
    Vec3 normal;
    Material material;

} Hit;


#endif