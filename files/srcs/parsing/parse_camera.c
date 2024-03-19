/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_camera.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkeraudr <dkeraudr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 22:01:44 by dkeraudr          #+#    #+#             */
/*   Updated: 2024/03/19 22:38:11 by dkeraudr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	ft_get_pixel_size(t_camera *camera)
{
	double		aspect_ratio;

	camera->half_view = tan(camera->fov * M_PI / 360);
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

t_matrix	*view_transform(t_point from, t_vector direction)
{
	t_vector	forward;
	t_vector	left;
	t_vector	true_up;
	t_matrix	*orientation;
	t_matrix	*translation;
	t_matrix	*result;
	double		**matrix_values;

	forward = direction;

	left = tuple_cross(forward, vector_new(0, 1, 0));
	if (left.x == 0 && left.y == 0 && left.z == 0)
		left = tuple_cross(forward, vector_new(0, 0, 1));
	true_up = tuple_cross(left, forward);
	matrix_values = (double *[]) {
		(double []) {left.x, left.y, left.z, 0},
		(double []) {true_up.x, true_up.y, true_up.z, 0},
		(double []) {-forward.x, -forward.y, -forward.z, 0},
		(double []) {0, 0, 0, 1}
	};
	orientation = matrix_new(matrix_values, 4);
	if (!orientation)
		return (NULL);
	translation = matrix_translation(-from.x, -from.y, -from.z);
	if (!translation)
	{
		free(orientation);
		return (NULL);
	}
	result = matrix_mult(*orientation, *translation);
	free(translation);
	free(orientation);
	return (result);
	}

int	ft_parse_camera_transform(t_camera *camera, char **tab)
{
	t_point		*origin;
	t_vector	*direction;

	origin = malloc(sizeof(t_point));
	direction = malloc(sizeof(t_vector));
	if (!origin || !direction)
		return (free_parse_camera(camera, NULL), 0);
	if (!ft_parse_point(tab[1], origin))
	{
		free(origin);
		free(direction);
		return (free_parse_camera(camera, NULL), 0);
	}
	if (!ft_parse_vector(tab[2], direction))
	{
		free(origin);
		free(direction);
		return (free_parse_camera(camera, NULL), 0);
	}
	camera->transform = view_transform(*origin, *direction);
	free(origin);
	free(direction);
	return (1);
}

int	ft_parse_camera(t_scene *scene, char *line)
{
	t_camera	*camera;
	char		**tab;

	if (scene->camera)
		return (ft_error(ERROR_CAMERA_ALREADY_DEFINED), 0);
	camera = ft_init_camera();
	if (!camera)
		return (free_parse_camera(camera, NULL), 0);
	tab = ft_split(line, ' ');
	if (!tab)
		return (free(camera), ft_error(ERROR_MALLOC), 0);
	if (ft_tablen(tab) != 4)
		return (ft_error(ERROR_WRONG_ARGS_NB),
			free_parse_camera(camera, tab), 0);
	if (!ft_isint(tab[3]))
		return (free_parse_camera(camera, tab), 0);
	camera->fov = ft_atof(tab[3]);
	if (!ft_parse_camera_transform(camera, tab))
		return (free_parse_camera(camera, tab), 0);
	scene->camera = camera;
	ft_get_pixel_size(camera);
	ft_free_2d_list(tab);
	return (1);
}
