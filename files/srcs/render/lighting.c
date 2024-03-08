/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lighting.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkeraudr <dkeraudr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 20:21:14 by dkeraudr          #+#    #+#             */
/*   Updated: 2024/03/08 22:23:54 by dkeraudr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

bool	is_shadowed(t_scene *scene, t_light *light, t_point point)
{
	t_vector	v;
	t_vector	direction;
	double		distance;
	t_ray		ray;
	t_list	*intersections;
	t_intersection	*hit;

	v = tuple_sub(light->position, point);
	distance = tuple_mag(v);
	direction = tuple_normalize(v);
	ray = ray_new(point, direction);
	intersections = ft_intersect(scene->objects, ray);
	hit = ft_hit(intersections);
	if (hit != NULL && hit->t < distance)
	{
		free(hit);
		return (true);
	}
	free(hit);
	return (false);
}

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

	effective_color = color_mult(*lighting_info->object->material->color, color_scalar(*lighting_info->light->color, lighting_info->light->brightness));
	lightv = tuple_normalize(tuple_sub(lighting_info->light->position, lighting_info->point));
	ambient = color_scalar(effective_color, lighting_info->object->material->ambient->brightness);
	if (is_shadowed(lighting_info->scene, lighting_info->light, lighting_info->over_point))
		return (ambient);
	light_dot_normal = tuple_dot(lightv, lighting_info->normal);
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
