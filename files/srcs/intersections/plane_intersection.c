/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane_intersections.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acrespy <acrespy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 15:59:09 by acrespy           #+#    #+#             */
/*   Updated: 2024/02/28 15:59:09 by acrespy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../includes/miniRT.h"

double	*intersect_with_plane(t_hittable *plane, t_ray ray)
{
	double  *intersections;
	double  denominator;
	double  t;

	denominator = tuple_dot(plane->normal, ray.direction);
	if (denominator == 0)
		return (NULL);
	t = tuple_dot(tuple_sub(plane->center, ray.origin), plane->normal) / denominator;
	if (t < 0)
		return (NULL);
	intersections = malloc(sizeof(double) * 1);
	if (!intersections)
		return (NULL);
	intersections[0] = t;
	return (intersections);
}