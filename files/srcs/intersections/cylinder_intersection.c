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

// I may have to compute the normal of the cylinder before computing the intersection

double *intersect_with_cylinder(t_ray ray)
{
    double  a[3];
    double  b[3];
    double *intersections;
    double discriminant;

    printf("-> cylinder\n");

	// t = (-b ± sqrt(b² - 4ac)) / 2a

    a[0] = pow(ray.direction.x, 2) + pow(ray.direction.z, 2); // a[0] = dx^2 + dz^2
    a[1] = 2 * (ray.origin.x * ray.direction.x + ray.origin.z * ray.direction.z); // a[1] = 2 * (ox * dx + oz * dz)
//    a[2] = pow(ray.origin.x, 2) + pow(ray.origin.z, 2) - pow(cylinder->radius, 2); // a[2] = ox^2 + oz^2 - r^2
	a[2] = 0;

    b[0] = a[1]; // b[0] = dx^2 + dz^2
    b[1] = 2 * (ray.origin.x * ray.direction.x + ray.origin.z * ray.direction.z); // b[0] = 2 * (ox * dx + oz * dz)
    b[2] = 0; // b[2] = 0

    discriminant = pow(b[0], 2) - 4 * a[2] * (a[0] - pow(ray.direction.y, 2));
    if (discriminant < 0)
        return (NULL);

    intersections = malloc(sizeof(double) * 2);
    if (!intersections)
        return (NULL);

    intersections[0] = (-b[0] - sqrt(discriminant)) / (2 * a[2]);
    intersections[1] = (-b[0] + sqrt(discriminant)) / (2 * a[2]);

	printf("i0 = %f\n", intersections[0]);
	printf("i1 = %f\n", intersections[1]);

    return (intersections);
}
