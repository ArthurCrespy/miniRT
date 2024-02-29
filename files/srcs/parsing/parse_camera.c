/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_camera.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkeraudr <dkeraudr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 22:01:44 by dkeraudr          #+#    #+#             */
/*   Updated: 2024/02/18 16:33:18 by dkeraudr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	free_parse_camera(t_camera *camera, char **tab)
{
	if (camera)
		free(camera);
	if (tab)
		ft_free_2d_list(tab);
	ft_error(ERROR_PARSING_CAMERA);
}

t_camera	*ft_init_camera(void)
{
	t_camera	*camera;

	camera = malloc(sizeof(t_camera));
	if (!camera)
		return (NULL);
	camera->fov = 0;
	camera->transform = matrix_identity();
	if (!camera->transform)
	{
		free(camera);
		return (ft_error(ERROR_MALLOC), NULL);
	}
	return (camera);
}

void	ft_get_pixel_size(t_camera *camera)
{
	// double		half_view;
	double		aspect_ratio;

	// fov is in degree
	camera->half_view = tan(camera->fov * M_PI / 360);
	printf("half_view: %f\n", camera->half_view);
	aspect_ratio = (double)WIDHT / (double)HEIGHT;
	if (aspect_ratio >= 1)
	{
		camera->half_width = camera->half_view;
		camera->half_height = camera->half_view / aspect_ratio;
	}
	else
	{
		camera->half_width = camera->half_view * aspect_ratio;
		camera->half_height = camera->half_view;
	}
	camera->pixel_size = (camera->half_width * 2) / (double)WIDHT;
}

int	ft_parse_camera(t_scene *scene, char *line)
{
	t_camera	*camera;
	char		**tab;

	camera = ft_init_camera();
	tab = ft_split(line, ' ');
	if (!tab)
		return (free(camera), ft_error(ERROR_MALLOC), 0);
	if (ft_tablen(tab) != 4)
		return (ft_error(ERROR_WRONG_ARGS_NB),
			free_parse_camera(camera, tab), 0);
	if (!ft_parse_center(tab[1], camera->transform))
		return (free_parse_camera(camera, tab), 0);
	if (!ft_parse_rotation(tab[2], camera->transform))
		return (free_parse_camera(camera, tab), 0);
	if (!ft_isint(tab[3]))
		return (free_parse_camera(camera, tab), 0);
	camera->fov = ft_atof(tab[3]);
	scene->camera = camera;
	ft_get_pixel_size(camera);
	ft_free_2d_list(tab);
	return (1);
}

	// todo: add check for fov value
	// todo: add check for orientation value (normalized vector)