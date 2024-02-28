#include "./../../includes/miniRT.h"

double *intersect_with_cylinder(t_hittable *cylinder, t_ray ray)
{
    double  a[3];
	double  b[3];
	double  c[3];
    double *intersections;
    double discriminant;
    double t1, t2;

    a[0] = pow(ray.direction.x, 2) + pow(ray.direction.z, 2);
    a[1] = 2 * (ray.origin.x * ray.direction.x + ray.origin.z * ray.direction.z);
    a[2] = pow(ray.origin.x, 2) + pow(ray.origin.z, 2) - 1;

    b[0] = 2 * ray.origin.x * ray.direction.x + 2 * ray.origin.z * ray.direction.z;
    b[1] = 2 * (ray.origin.x * ray.direction.x + ray.origin.z * ray.direction.z);
    b[2] = 2 * ray.origin.x * ray.origin.x + 2 * ray.origin.z * ray.origin.z - 2;

    c[0] = pow(ray.origin.x, 2) + pow(ray.origin.z, 2);
    c[1] = 2 * ray.origin.x * ray.origin.x + 2 * ray.origin.z * ray.origin.z;
    c[2] = pow(ray.origin.x, 2) + pow(ray.origin.z, 2) - 1;

    discriminant = pow(b[1], 2) - 4 * a[0] * c[2];
    if (discriminant < 0)
        return (NULL);

    intersections = malloc(sizeof(double) * 2);
    if (!intersections)
        return (NULL);

    t1 = (-b[1] - sqrt(discriminant)) / (2 * a[0]);
    t2 = (-b[1] + sqrt(discriminant)) / (2 * a[0]);

    if (t1 >= 0 && t1 <= cylinder->height)
        intersections[0] = t1;
    else
        intersections[0] = -1;

    if (t2 >= 0 && t2 <= cylinder->height)
        intersections[1] = t2;
    else
        intersections[1] = -1;

    return (intersections);
}