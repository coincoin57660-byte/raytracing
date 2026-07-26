#ifndef CAMERA_H
#define CAMERA_H

#include "config.h"
#include "vec3.h"
#include "ray.h"


typedef struct
{
    Vec3 position;

    double viewportWidth;
    double viewportHeight;

    double focalLength;
    
} Camera;


Camera camera_create(Vec3 position, double viewportWidth, double viewportHeight, double focalLength);


Ray camera_get_ray(const Camera *camera, int x, int y, int width, int height);


#endif