/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lighting.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acrespy <acrespy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 20:21:14 by dkeraudr          #+#    #+#             */
/*   Updated: 2024/03/07 17:12:54 by acrespy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_color	lighting(t_computation	*lighting_info)
{
	t_color		effective_color;
	t_color		ambient;
	t_color		diffuse;
	t_color		specular;
	t_vector	reflectv;
	t_vector	lightv;
	double		light_dot_normal;
	double		reflect_dot_eye;

	effective_color = color_scalar(color_mult(*lighting_info->object->material->color, *lighting_info->light->color), lighting_info->light->brightness);
	ambient = color_scalar(effective_color, lighting_info->object->material->ambient->brightness);
	lightv = tuple_normalize(tuple_sub(lighting_info->point, lighting_info->light->position));
	light_dot_normal = tuple_dot(lightv, lighting_info->normal);
	// diffuse = malloc(sizeof(t_color));
	// specular = malloc(sizeof(t_color));
	// if (!diffuse || !specular)
	// {
	// 	if (diffuse)
	// 		free(diffuse);
	// 	if (specular)
	// 		free(specular);
	// 	return (*color_new(0, 0, 0));
	// }
	if (light_dot_normal < 0)
	{
		diffuse = *color_new(0, 0, 0);
		specular = *color_new(0, 0, 0);
	}
	else
	{
		diffuse = color_scalar(*lighting_info->object->material->color, lighting_info->object->material->diffuse * light_dot_normal);
		reflectv = reflect(tuple_negate(lightv), lighting_info->normal);
		reflect_dot_eye = tuple_dot(reflectv, lighting_info->eye);
		if (reflect_dot_eye <= 0)
			specular = *color_new(0, 0, 0);
		else
		{
			double	factor = pow(reflect_dot_eye, lighting_info->object->material->shininess);
			specular = color_scalar(*lighting_info->light->color, lighting_info->object->material->specular * factor);
		}
	}
	return (color_add(color_add(ambient, diffuse), specular));
}
