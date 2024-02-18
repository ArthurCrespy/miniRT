/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_initialize.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkeraudr <dkeraudr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 07:46:43 by acrespy           #+#    #+#             */
/*   Updated: 2024/02/18 15:45:13 by dkeraudr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	init_scene(t_scene *scene)
{
	scene->camera = NULL;
	scene->ambient = NULL;
	scene->lights = NULL;
	scene->objects = NULL;
}

void	data_initialize(t_minirt *data)
{
	data->mlx = malloc(sizeof(t_mlx));
	if (!data->mlx)
		ft_exit("Error: malloc failed\n", 1);
	data->scene = malloc(sizeof(t_scene));
	if (!data->scene)
		ft_exit("Error: malloc failed\n", 1);
	init_scene(data->scene);
	data->pxl_rendered = 0;
}
