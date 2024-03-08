/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal_at.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkeraudr <dkeraudr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 19:24:12 by dkeraudr          #+#    #+#             */
/*   Updated: 2024/03/08 00:30:24 by acrespy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_vector	object_normal_at(t_hittable *obj, t_tuple object_point)
{
	t_vector	normal;
	t_point		cylinder;
	t_vector	axis;
	t_vector	point_to_axis;
	double		dist;

	if (obj->type == SPHERE)
		normal = tuple_sub(object_point, point_new(0, 0, 0));
	else if (obj->type == PLANE)
		normal = vector_new(0, 1, 0);
	else if (obj->type == CYLINDER)
	{
//		axis = tuple_sub(matrix_tuple_mult(*obj->transform, vector_new(0, 1, 0)), point_new(0, 0, 0));
//		axis = tuple_normalize(axis);
//		dist = (object_point.y - (-obj->height / 2)) / obj->height;
//		dist = fmin(fmax(dist, 0), 1);
//		cylinder = tuple_add(matrix_tuple_mult(*obj->transform, point_new(0, -obj->height / 2, 0)), tuple_mult(axis, dist * obj->height));
//		point_to_axis = tuple_sub(object_point, cylinder);
//		normal = tuple_cross(point_to_axis, axis);
//		normal = tuple_normalize(normal);
//		if (tuple_dot(normal, axis) < 0)
//			normal = tuple_negate(normal);
		normal = tuple_sub(object_point, point_new(0, 0, 0));
	}
	return (tuple_normalize(normal));
}


t_vector	normal_at(t_hittable *obj, t_point world_point)
{
	t_tuple		object_point;
	t_tuple		object_normal;
	t_tuple		world_normal;
	t_matrix	*transpose;

	object_point = tuple_transform(world_point, *matrix_inverse(*obj->transform));
	object_normal = object_normal_at(obj, object_point);
	transpose = matrix_transpose(*matrix_inverse(*obj->transform));
	world_normal = tuple_transform(object_normal, *transpose);
//	world_normal = matrix_tuple_mult(transpose, object_normal);
	return (tuple_normalize(world_normal));
}
