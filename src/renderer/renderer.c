#include "renderer.h"


void render(Camera *camera, Scene *scene)
{
    BMPImage *image = bmp_create(IMAGE_WIDTH, IMAGE_HEIGHT);
    srand(time(NULL));

    for (int y = 0; y < image -> height; y++)
    {
        for (int x = 0; x < image -> width; x++)
        {
            Ray ray = camera_get_ray(camera, x, y, image -> width, image -> height);
            Vec3 color = ray_color(&ray, scene, 5);

            unsigned char r = (unsigned char)(color.x * 255);
            unsigned char g = (unsigned char)(color.y * 255);
            unsigned char b = (unsigned char)(color.z * 255);

            bmp_set_pixel(image, x, y, r, g, b);
        }
    }

    bmp_save(image, "build/render.bmp");
    bmp_destroy(image);
}


Vec3 ray_color(const Ray *ray, const Scene *scene, int depth)
{
    if (depth <= 0)
    {
        return vec3(0.0, 0.0, 0.0);
    }

    Hit hit;
    Vec3 light_dir = vec3_normalize(vec3(1, 1, 1));

    if (!scene_hit(scene, ray, &hit))
    {
        Vec3 unit_dir = vec3_normalize(ray -> direction);
        double t = 0.5 * (unit_dir.y + 1.0);
        Vec3 sky = vec3_add(vec3_mul(vec3(1, 1, 1), (1.0 - t)), vec3_mul(vec3(0.5, 0.7, 1.0), t));

        // double sun = vec3_dot(unit_dir, light_dir);
        // if (sun > 0.9995)
        // {
        //     double glow = pow(fmax(0.0, sun), 512.0);
        //     sky = vec3_add(sky, vec3_mul(vec3(6.0, 5.8, 4.8), glow));
        // }

        return sky;
    }
    
    double diffuse = vec3_dot(hit.normal, light_dir);
    diffuse = fmax(0.0, diffuse);

    Vec3 shadow_origin = vec3_add(hit.point, vec3_mul(hit.normal, 1e-4));
    Ray shadow_ray = ray_create(shadow_origin, light_dir);;
    Hit shadow_hit;

    if (scene_hit(scene, &shadow_ray, &shadow_hit))
    {
        diffuse = 0;
    }
    
    Vec3 color = hit.material.color;
    color = vec3_mul(color, diffuse);
    color.x = fmin(color.x, 1.0);
    color.y = fmin(color.y, 1.0);
    color.z = fmin(color.z, 1.0);

    double r = hit.material.reflectivity * hit.material.reflectivity;
    if (r <= 1e-8)
    {
        return color;
    }

    // reflectivity
    Vec3 reflected = vec3_reflect(ray -> direction, hit.normal);
    reflected = vec3_add(reflected, vec3_mul(random_vec3(-1, 1), hit.material.roughness));
    Ray reflected_ray = ray_create(vec3_add(hit.point, vec3_mul(hit.normal, 1e-4)), vec3_normalize(reflected));
    Vec3 reflected_color = ray_color(&reflected_ray, scene, depth - 1);

    // // specular
    // Vec3 reflected_light = vec3_reflect(vec3_mul(light_dir, -1), hit.normal);
    // double spec = fmax(0.0, vec3_dot(ray -> direction, reflected_light));
    // spec = pow(spec, hit.material.shininess);

    Vec3 final = vec3_add(vec3_mul(color, 1 - r), vec3_mul(reflected_color, r));
    // final = vec3_add(final, vec3_mul(vec3(1, 1, 1), spec * hit.material.specula);
    final = vec3_pow(final, 1.0 / 2.2);
    return final;
}


int scene_hit(const Scene *scene, const Ray *ray, Hit *closest_hit)
{
    int hit_anything = 0;
    double closest_t = 1e30;

    Hit temp;

    for (int i = 0; i < scene -> spheres_count; i++)
    {
        if (sphere_hit(&scene -> spheres[i], ray, &temp))
        {
            if (temp.t < closest_t)
            {
                closest_t = temp.t;
                *closest_hit = temp;
                hit_anything = 1;
            }
        }
    }

    for (int i = 0; i < scene -> triangles_count; i++)
    {
        if (triangle_hit(&scene -> triangles[i], ray, &temp))
        {
            if (temp.t < closest_t)
            {
                closest_t = temp.t;
                *closest_hit = temp;
                hit_anything = 1;
            }
        }
    }

    return hit_anything;
}