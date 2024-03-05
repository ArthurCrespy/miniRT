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

//double	*intersect_with_plane(t_hittable *plane, t_ray ray)
//{
//	double  *intersections;
//	double  denominator;
//	double  t;
//
//	printf("-> plane\n");
//
//	denominator = tuple_dot(plane->normal, ray.direction); // d = n . l
//	if (denominator == 0)
//		return (NULL);
//	plane->point = point_new(0, 0, 0); // Have to compute a point who is not xy-parallel to the plane
//	t = fabs(tuple_dot(tuple_sub(plane->point, ray.origin), plane->normal)) / denominator; // t = |(p0 - o) . n| / d
//	if (t < 0)
//		return (NULL);
//	intersections = malloc(sizeof(double) * 1);
//	if (!intersections)
//		return (NULL);
//	intersections[0] = t;
//	return (intersections);
//}

double	*intersect_with_plane(t_ray ray)
{
	double *intersections;

	(void)ray;

	intersections = malloc(sizeof(double) * 1);
	if (!intersections)
		return (NULL);
	intersections[0] = 0;
	intersections[1] = 0;
	return (intersections);
}