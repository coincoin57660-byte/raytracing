#ifndef MATERIAL_H
#define MATERIAL_H

#include "vec3.h"


typedef struct
{
    Vec3 color;

    double reflectivity;
    double roughness;

    double specular;
    double shininess;

} Material;


Material material_creat(Vec3 color, double reflectivity, double roughness, double specular, double shininess);


#endif