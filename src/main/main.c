#include "config.h"
#include "camera.h"
#include "scene.h"
#include "renderer.h"


int main(void)
{
    Camera cam = camera_create(vec3(0, 0, 2), VIEWPORT_WIDTH, VIEWPORT_HEIGHT, FOCAL_LENGTH);

    Scene scene = scene_create();
    // scene_add_sphere(&scene, sphere_create(vec3(0.0, -0.5, -3.0), 1, material_creat(vec3(1, 1, 1), 0.99, 0.0, 0.2, 0.0)));
    scene_add_sphere(&scene, sphere_create(vec3(-1.0, -0.5, -1.0), 0.5, material_creat(vec3(1, 0, 0), 0.0, 0.0, 0.2, 4.0)));
    scene_add_sphere(&scene, sphere_create(vec3(0.8, 0.2, -1.0), 0.5, material_creat(vec3(0, 1, 0), 0.2, 0.0, 0.2, 0.0)));
    scene_add_sphere(&scene, sphere_create(vec3(-1.5, 0.5, -2.0), 0.5, material_creat(vec3(0, 0, 1), 0.0, 0.0, 0.2, 0.0)));
    // scene_add_sphere(&scene, sphere_create(vec3(0, -203, -1.5), 200, material_creat(vec3(0.2, 0.2, 0.2), 0.0, 0.0, 0.2, 0.0)));
    scene_add_triangle(&scene, triangle_create(vec3(-1, -1, -2), vec3(0, 1, -3), vec3(1, -1, -2), material_creat(vec3(1, 0, 0), 0.2, 0.0, 0.0, 0.0)));

    render(&cam, &scene);

    return 0;
}


// gcc src/main/main.c src/math/*.c src/renderer/*.c src/scene/*.c external/bmp/src/bmp.c -Iinclude/config -Iinclude/math -Iinclude/renderer -Iinclude/scene -Iexternal/bmp/include -o build/raytracing.exe