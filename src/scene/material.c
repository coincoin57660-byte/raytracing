#include "material.h"


Material material_creat(Vec3 color, double reflectivity, double roughness, double specular, double shininess)
{
    Material material;

    material.color = color;
    material.reflectivity = reflectivity;
    material.roughness = roughness;
    material.specular = specular;
    material.shininess = shininess;

    return material;
}