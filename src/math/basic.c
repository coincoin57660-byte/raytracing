#include "basic.h"


double fmax(double a, double b)
{
    if (a > b)
    {
        return a;
    }
    return b;
}

double fmin(double a, double b)
{
    if (a < b)
    {
        return a;
    }
    return b;
}

double fabs(double a)
{
    if (a <= 0.0)
    {
        return -a;
    }
    return a;
}


double random_double(void)
{
    return (double)rand() / (double)RAND_MAX;
}

double random_double_range(double min, double max)
{
    return min + (max - min) * random_double();
}