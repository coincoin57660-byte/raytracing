#ifndef VEC3_H
#define VEC3_H

#include <math.h>
#include "basic.h"


typedef struct
{
    double x;
    double y;
    double z;
    
} Vec3;


Vec3 vec3(double x, double y, double z);
Vec3 random_vec3(double min, double max);

Vec3 vec3_add(Vec3 a, Vec3 b);
Vec3 vec3_sub(Vec3 a, Vec3 b);
Vec3 vec3_mul(Vec3 a, double k);
Vec3 vec3_div(Vec3 a, double k);
Vec3 vec3_pow(Vec3 a, double k);

double vec3_dot(Vec3 a, Vec3 b);
Vec3 vec3_cross(Vec3 a, Vec3 b);
double vec3_length(Vec3 v);
Vec3 vec3_normalize(Vec3 v);

Vec3 vec3_reflect(Vec3 incident, Vec3 normal);


#endif