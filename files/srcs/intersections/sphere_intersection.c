/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere_intersection.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acrespy <acrespy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 20:04:37 by dkeraudr          #+#    #+#             */
/*   Updated: 2024/03/07 17:10:06 by acrespy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

double	*intersect_with_sphere(t_ray ray)
{
	double		*intersections;
	double		a;
	double		b;
	double		c;
	t_tuple		sphere_to_ray;
	double		discriminant;

	sphere_to_ray = tuple_sub(ray.origin, point_new(0, 0, 0));
	a = tuple_dot(ray.direction, ray.direction);
	b = 2 * tuple_dot(ray.direction, sphere_to_ray);
	c = tuple_dot(sphere_to_ray, sphere_to_ray) - 1;
	discriminant = (b * b) - (4 * a * c);
	if (discriminant < 0)
		return (NULL);
	intersections = malloc(sizeof(double) * 2);
	if (!intersections)
		return (NULL);
	intersections[0] = (-b - sqrt(discriminant)) / (2 * a);
	intersections[1] = (-b + sqrt(discriminant)) / (2 * a);
	//printf("sp - i0: %f, i1: %f\n", intersections[0], intersections[1]);
	return (intersections);
}
