#include "scene.h"


Scene scene_create(void)
{
    Scene scene;

    scene.spheres_count = 0;
    scene.triangles_count = 0;

    return scene;
}


void scene_add_sphere(Scene *scene, Sphere s)
{
    if (scene -> spheres_count < MAX_SPHERES)
    {
        scene -> spheres[scene -> spheres_count++] = s;
    }
}


void scene_add_triangle(Scene *scene, Triangle t)
{
    if (scene -> triangles_count < MAX_TRIANGLES)
    {
        scene -> triangles[scene -> triangles_count++] = t;
    }
}