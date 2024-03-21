/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane_intersection.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkeraudr <dkeraudr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 15:59:09 by acrespy           #+#    #+#             */
/*   Updated: 2024/03/20 20:42:40 by dkeraudr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../includes/miniRT.h"

double	*intersect_with_plane(t_ray ray)
{
	double	*intersections;
	double	denominator;
	double	t;

	denominator = tuple_dot(ray.direction, vector_new(0, 1, 0));
	if (fabs(denominator) < EPSILON)
		return (NULL);
	t = -ray.origin.y / denominator;
	if (t < 0)
		return (NULL);
	intersections = malloc(sizeof(double) * 2);
	if (!intersections)
		return (NULL);
	intersections[0] = t;
	intersections[1] = 0;
	return (intersections);
}
