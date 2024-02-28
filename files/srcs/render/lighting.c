/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lighting.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkeraudr <dkeraudr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 20:21:14 by dkeraudr          #+#    #+#             */
/*   Updated: 2024/02/28 22:13:33 by dkeraudr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_color	lighting(t_computation	*lighting_info)
{
	t_color	effective_color;
	t_color	ambient;
	t_color	diffuse;
	t_color	specular;
	double	light_dot_normal;
	t_vector	lightv;

	effective_color = color_scalar(color_mult(*lighting_info->object->material->color, *lighting_info->light->color), lighting_info->light->brightness);
	lightv = tuple_normalize(tuple_sub(lighting_info->light->position, lighting_info->point));
	ambient = color_scalar(*lighting_info->object->material->ambient->color, lighting_info->object->material->ambient->brightness);
	light_dot_normal = tuple_dot(lightv, lighting_info->normal);
	if (light_dot_normal < 0)
	{
		diffuse = color_new(0, 0, 0);
		specular = color_new(0, 0, 0);
	}
	else
	{
		diffuse = color_scalar(*lighting_info->object->material->color, lighting_info->object->material->diffuse * light_dot_normal);
		specular = color_new(0, 0, 0);
	}
}
