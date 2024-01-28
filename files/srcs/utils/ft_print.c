/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkeraudr <dkeraudr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 21:38:59 by dkeraudr          #+#    #+#             */
/*   Updated: 2024/01/18 21:46:46 by dkeraudr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	ft_print_point(t_point point)
{
	printf("x: %f, y: %f, z: %f\n", point.x, point.y, point.z);
}

void	ft_print_color(t_color color)
{
	printf("chan_1: %f, chan_2: %f, chan_3: %f\n", color.chan_1, color.chan_2, color.chan_3);
}

void	ft_print_vector(t_vector vector)
{
	printf("x: %f, y: %f, z: %f\n", vector.x, vector.y, vector.z);
}

void	ft_print_hittable(t_hittable *hittable)
{
	printf("id: %d\n", hittable->id);
	printf("center: ");
	ft_print_point(hittable->center);
	printf("color: ");
	ft_print_color(hittable->color);
	printf("orientation: ");
	ft_print_vector(hittable->orientation);
	printf("diameter: %f\n", hittable->diameter);
	printf("height: %f\n", hittable->height);
}

void	ft_print_camera(t_camera *camera)
{
	printf("center: ");
	ft_print_point(camera->center);
	printf("orientation: ");
	ft_print_vector(camera->orientation);
	printf("fov: %d\n", camera->fov);
}

void	ft_print_light(t_light *light)
{
	printf("center: ");
	ft_print_point(light->center);
	printf("brightness: %f\n", light->brightness);
	printf("color: ");
	ft_print_color(light->color);
}

void	ft_print_ambient(t_ambient *ambient)
{
	printf("brightness: %f\n", ambient->brightness);
	printf("color: ");
	ft_print_color(ambient->color);
}

void	ft_print_scene(t_scene *scene)
{
	t_list	*tmp;

	tmp = scene->objects;
	while (tmp)
	{
		ft_print_hittable(tmp->content);
		tmp = tmp->next;
	}
	ft_print_camera(scene->camera);
	tmp = scene->lights;
	while (tmp)
	{
		ft_print_light(tmp->content);
		tmp = tmp->next;
	}
	printf("ambient: ");
	ft_print_ambient(scene->ambient);
}