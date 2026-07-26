#ifndef SCENE_H
#define SCENE_H

#include "config.h"
#include "sphere.h"
#include "triangle.h"


typedef struct
{
    Sphere spheres[MAX_SPHERES];
    int spheres_count;

    Triangle triangles[MAX_TRIANGLES];
    int triangles_count;

} Scene;


Scene scene_create(void);

void scene_add_sphere(Scene *scene, Sphere s);
void scene_add_triangle(Scene *scene, Triangle t);


#endif