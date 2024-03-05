/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder_intersection.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acrespy <acrespy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 13:34:47 by acrespy           #+#    #+#             */
/*   Updated: 2024/02/29 13:46:37 by acrespy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../includes/miniRT.h"

double *intersect_with_cylinder(t_ray ray)
{
    double *intersections;
    double a;
    double b;
    double c;
	double t;
	double y;
	double t_top;
	double t_bottom;
	double x_top;
	double z_top;
	double x_bottom;
	double z_bottom;
    double discriminant;
	int i;

	i = 0;
    a = pow(ray.direction.x, 2) + pow(ray.direction.z, 2);
    b = 2 * (ray.origin.x * ray.direction.x + ray.origin.z * ray.direction.z);
    c = pow(ray.origin.x, 2) + pow(ray.origin.z, 2) - 1;
    discriminant = pow(b, 2) - 4 * a * c;
    if (discriminant < 0)
        return (NULL);
    intersections = malloc(sizeof(double) * 2);
    if (!intersections)
        return (NULL);
    intersections[0] = (-b - sqrt(discriminant)) / (2 * a);
    intersections[1] = (-b + sqrt(discriminant)) / (2 * a);

    t_top = (1 - ray.origin.y) / ray.direction.y;
    t_bottom = (-1 - ray.origin.y) / ray.direction.y;

    if (t_top >= 0)
    {
        x_top = ray.origin.x + t_top * ray.direction.x;
        z_top = ray.origin.z + t_top * ray.direction.z;
        if (x_top * x_top + z_top * z_top <= 1)
            intersections[0] = t_top;
    }

    if (t_bottom >= 0)
    {
        x_bottom = ray.origin.x + t_bottom * ray.direction.x;
        z_bottom = ray.origin.z + t_bottom * ray.direction.z;
        if (x_bottom * x_bottom + z_bottom * z_bottom <= 1)
            intersections[1] = t_bottom;
    }

	while (i < 2)
    {
        t = intersections[i];
        y = ray.origin.y + t * ray.direction.y;
        if (t > 0 && (y < 0 || y > 1))
            intersections[i] = -1;
		i++;
    }

    printf("cy - i0: %f, i1: %f\n", intersections[0], intersections[1]);
    return intersections;
}

