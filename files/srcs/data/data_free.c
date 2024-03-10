/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_free.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkeraudr <dkeraudr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 07:46:01 by acrespy           #+#    #+#             */
/*   Updated: 2024/03/10 18:26:57 by dkeraudr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	free_light(void *light)
{
	t_light	*tmp;

	tmp = (t_light *)light;
	if (tmp->color)
		free(tmp->color);
	free(tmp);
}

void	free_ambient(t_ambient *ambient)
{
	if (ambient->color)
		free(ambient->color);
	free(ambient);
}

void	free_material(t_material *material)
{
	if (material->color)
		free(material->color);
	free(material);
}

void	free_hittable(void *hittable)
{
	t_hittable	*tmp;

	tmp = (t_hittable *)hittable;
	if (tmp->material)
		free_material(tmp->material);
	if (tmp->transform)
		free(tmp->transform);
	free(tmp);
}

void	free_camera(t_camera *camera)
{
	if (camera->transform)
		free(camera->transform);
	if (camera)
		free(camera);
}

void	free_scene(t_scene *scene)
{
	if (scene->camera)
		free_camera(scene->camera);
	if (scene->ambient)
		free_ambient(scene->ambient);
	if (scene->lights)
		ft_lstclear(&scene->lights, free_light);
	if (scene->objects)
		ft_lstclear(&scene->objects, free_hittable);
	if (scene)
		free(scene);
}

void	data_free(t_minirt *data)
{
	if (data->mlx)
		free(data->mlx);
	if (data->scene)
		free_scene(data->scene);
	free(data);
}
