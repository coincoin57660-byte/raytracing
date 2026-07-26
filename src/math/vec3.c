#include "vec3.h"


Vec3 vec3(double x, double y, double z)
{
    Vec3 v;

    v.x = x;
    v.y = y;
    v.z = z;

    return v;
}

Vec3 random_vec3(double min, double max)
{
    return vec3(
        random_double_range(min, max),
        random_double_range(min, max),
        random_double_range(min, max)
    );
}


Vec3 vec3_add(Vec3 a, Vec3 b)
{
    return vec3(a.x + b.x, a.y + b.y, a.z + b.z);
}

Vec3 vec3_sub(Vec3 a, Vec3 b)
{
    return vec3(a.x - b.x, a.y - b.y, a.z - b.z);
}

Vec3 vec3_mul(Vec3 a, double k)
{
    return vec3(a.x * k, a.y * k, a.z * k);
}

Vec3 vec3_div(Vec3 a, double k)
{
    return vec3(a.x / k, a.y / k, a.z / k);
}

Vec3 vec3_pow(Vec3 a, double k)
{
    return vec3(pow(a.x, k), pow(a.y, k), pow(a.z, k));
}


double vec3_dot(Vec3 a, Vec3 b)
{
    return a.x * b.x + a.y * b.y + a.z * b.z;
}

Vec3 vec3_cross(Vec3 a, Vec3 b)
{
    return vec3(a.y * b.z - a.z * b.y, a.z * b.x - a.x * b.z, a.x * b.y - a.y * b.x);
}

double vec3_length(Vec3 v)
{
    return sqrt(v.x * v.x + v.y * v.y + v.z * v.z);
}

Vec3 vec3_normalize(Vec3 v)
{
    double len = vec3_length(v);

    if (len < 1e-8)
    {
        return vec3(0, 0, 0);
    }

    return vec3(v.x / len, v.y / len, v.z / len);
}


Vec3 vec3_reflect(Vec3 incident, Vec3 normal)
{
    Vec3 incident_n = vec3_normalize(incident);
    Vec3 normal_n = vec3_normalize(normal);

    Vec3 R = vec3_sub(incident_n, vec3_mul(normal_n, 2 * vec3_dot(incident_n, normal_n)));

    return R;
}