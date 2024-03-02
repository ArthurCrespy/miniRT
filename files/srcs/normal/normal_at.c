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

t_vector	object_normal_at(t_hittable *obj, t_tuple object_point)
{
	t_vector	normal;

	if (obj->type == SPHERE)
	{
		normal = tuple_sub(object_point, point_new(0, 0, 0));
		return (tuple_normalize(normal));
	}
	return (vector_new(0, 0, 0));
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