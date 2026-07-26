#include "camera.h"
#include <stdio.h>

Camera camera_create(Vec3 position, double viewportWidth, double viewportHeight, double focalLength)
{
    Camera cam;

    cam.position = position;
    cam.viewportWidth = viewportWidth;
    cam.viewportHeight = viewportHeight;
    cam.focalLength = focalLength;

    return cam;
}


Ray camera_get_ray(const Camera *camera, int x, int y, int width, int height)
{
    double aspect = (double)width / (double)height;

    double u = (x + 0.5) / width;
    double v = (y + 0.5) / height;

    double px = (2.0 * u - 1.0) * aspect;
    double py = (1.0 - 2.0 * v); 

    Vec3 direction = vec3(px, py, -camera -> focalLength);

    return ray_create(camera -> position, vec3_normalize(direction));
}