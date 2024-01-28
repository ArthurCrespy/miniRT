/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_free.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkeraudr <dkeraudr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 07:46:01 by acrespy           #+#    #+#             */
/*   Updated: 2024/01/28 16:25:34 by dkeraudr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	free_scene(t_scene *scene)
{
	if (scene->camera)
		free(scene->camera);
	if (scene->ambient)
		free(scene->ambient);
	if (scene->lights)
		ft_lstclear(&scene->lights, free);
	if (scene->objects)
		ft_lstclear(&scene->objects, free);
	if (scene)
		free(scene);
}

void	data_free(t_minirt *data)
{
	if (data->mlx)
		free(data->mlx);
	if (data->scene)
		free_scene(data->scene);
}
