/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal_at.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkeraudr <dkeraudr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 19:24:12 by dkeraudr          #+#    #+#             */
/*   Updated: 2024/02/21 19:58:35 by dkeraudr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_vector cylinder_normal_at(t_hittable *cylinder, t_tuple object_point)
{
	double y;
	double dist;

	y = 0;
	dist = object_point.x * object_point.x + object_point.z * object_point.z;
	if (dist < 1 && object_point.y >= cylinder->height - EPSILON) // Top
		return (vector_new(0, 1, 0));
	else if (dist < 1 && object_point.y <= EPSILON) // Bottom
		return (vector_new(0, -1, 0));
	else
	{
		if (object_point.y > 0 && object_point.y < cylinder->height)
			y = 0;
		else if (object_point.y >= cylinder->height)
			y = object_point.y - cylinder->height;
		else if (object_point.y <= 0)
			y = object_point.y;
		return (vector_new(object_point.x, y, object_point.z));
	}
}

t_vector	object_normal_at(t_hittable *obj, t_tuple object_point)
{
	t_vector	normal;

	if (obj->type == SPHERE)
		normal = tuple_sub(object_point, point_new(0, 0, 0));
	else if (obj->type == CYLINDER)
		normal = tuple_sub(object_point, point_new(0, 0, 0));
		//normal = cylinder_normal_at(obj, object_point);
	else
		return (vector_new(0, 0, 0));
	return (tuple_normalize(normal));
}

t_vector	normal_at(t_hittable *obj, t_point world_point)
{
	t_tuple		object_point;
	t_tuple		object_normal;
	t_tuple		world_normal;
	t_matrix	transpose;

	object_point = tuple_transform(world_point, *matrix_inverse(*obj->transform));
	object_normal = object_normal_at(obj, object_point);
	transpose = matrix_transpose(*matrix_inverse(*obj->transform));
	world_normal = tuple_transform(object_normal, transpose);
	return (tuple_normalize(world_normal));
}
