/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkeraudr <dkeraudr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 19:09:03 by dkeraudr          #+#    #+#             */
/*   Updated: 2024/03/20 19:25:03 by dkeraudr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	free_light(void *light)
{
	t_light	*tmp;

	tmp = (t_light *)light;
//	if (tmp->color)
//		free(tmp->color);
	free(tmp);
}

void	free_ambient(t_ambient *ambient)
{
//	if (ambient->color)
//		free(ambient->color);
	free(ambient);
}

void	free_material(t_material *material)
{
//	if (material->color)
//		free(material->color);
//	if (material->ambient)
//		free(material->ambient);
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
	if (!camera)
		return ;
	if (camera->transform)
		free(camera->transform);
	free(camera);
}

void	free_scene(t_scene *scene)
{
	if (scene->ambient)
		free_ambient(scene->ambient);
	if (scene->lights)
		ft_lstclear(&scene->lights, free_light);
	if (scene->objects)
		ft_lstclear(&scene->objects, free_hittable);
	if (scene->camera)
		free_camera(scene->camera);
	free(scene);
}
