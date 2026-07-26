#ifndef RENDERER_H
#define RENDERER_H

#include <stdlib.h>
#include <time.h>
#include "bmp.h"
#include "config.h"

#include "basic.h"
#include "ray.h"
#include "hit.h"
#include "camera.h"
#include "scene.h"


void render(Camera *camera, Scene *scene);

int scene_hit(const Scene *scene, const Ray *ray, Hit *closest_hit);

Vec3 ray_color(const Ray *ray, const Scene *scene, int depth);


#endif