/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_camera.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkeraudr <dkeraudr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 22:01:44 by dkeraudr          #+#    #+#             */
/*   Updated: 2024/03/14 21:17:10 by dkeraudr         ###   ########.fr       */
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
	camera->orientation = malloc(sizeof(t_vector));
	return (camera);
}

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

t_matrix	*view_transform(t_point from, t_point to, t_vector up)
{
	t_vector	forward;
	t_vector	up_normalized;
	t_vector	left;
	t_vector	true_up;
	t_matrix	*orientation;
	t_matrix	*translation;
	t_matrix	*result;
	double		**matrix_values;

	forward = tuple_norm(tuple_sub(to, from));
	up_normalized = tuple_norm(up);
	left = tuple_cross(forward, up_normalized);
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

int	ft_parse_camera(t_scene *scene, char *line)
{
	t_camera	*camera;
	char		**tab;
	// t_point		*from;
	// t_vector	*to;

	camera = ft_init_camera();
	// to = malloc(sizeof(t_vector));
	// from = malloc(sizeof(t_point));
	if (!camera)
		return (free_parse_camera(camera, NULL), 0);
	tab = ft_split(line, ' ');
	if (!tab)
		return (free(camera), ft_error(ERROR_MALLOC), 0);
	if (ft_tablen(tab) != 4)
		return (ft_error(ERROR_WRONG_ARGS_NB),
			free_parse_camera(camera, tab), 0);
	// if (!ft_parse_tuple(tab[1], from))
		// // return (free_parse_camera(camera, tab), 0);
	// if (!ft_parse_tuple(tab[2], to))
		// return (free_parse_camera(camera, tab), 0);
	// camera->transform = view_transform(*from, *to, vector_new(0, 1, 0));
	if (!ft_isint(tab[3]))
		return (free_parse_camera(camera, tab), 0);
	camera->fov = ft_atof(tab[3]);
	scene->camera = camera;
	// camera->transform = matrix_rotation_y(M_PI/4);
	// translate the camera
	// camera->transform =  matrix_mult(*matrix_rotation_y(M_PI/4), *matrix_translation(0, -2, 5));
	// ft_parse_vector(tab[2], camera->orientation);
	ft_parse_center(tab[1], camera->transform);
	ft_parse_rotation(tab[2], camera->transform, vector_new(0, 0, -1));
	ft_print_matrix(*camera->transform);
	ft_get_pixel_size(camera);
	ft_free_2d_list(tab);
	// free(from);
	// free(to);
	return (1);
}

// int	ft_parse_camera(t_scene *scene, char *line)
// {
// 	t_camera	*camera;
// 	char		**tab;
// 	// t_point		*from;
// 	// t_vector	*to;

// 	if (scene->camera)
// 		return (ft_error(ERROR_MULTIPLE_CAMERA));
// 	camera = ft_init_camera();
// 	// to = malloc(sizeof(t_vector));
// 	// from = malloc(sizeof(t_point));
// 	if (!camera)
// 		return (free_parse_camera(camera, NULL), 0);
// 	tab = ft_split(line, ' ');
// 	if (!tab)
// 		return (free(camera), ft_error(ERROR_MALLOC), 0);
// 	if (ft_tablen(tab) != 4)
// 		return (ft_error(ERROR_WRONG_ARGS_NB),
// 			free_parse_camera(camera, tab), 0);
// 	if (!ft_parse_rotation(tab[2], camera->transform))
// 		return (free_parse_camera(camera, tab), 0);
// 	if (!ft_parse_center(tab[1], camera->transform))
// 		return (free_parse_camera(camera, tab), 0);
// 	// camera->transform = view_transform(*from, *to, vector_new(0, 1, 0));
// 	if (!ft_isint(tab[3]))
// 		return (free_parse_camera(camera, tab), 0);
// 	camera->fov = ft_atof(tab[3]);
// 	scene->camera = camera;
// 	ft_get_pixel_size(camera);
// 	ft_free_2d_list(tab);
// 	// free(from);
// 	// free(to);
// 	return (1);
// }

	// todo: add check for fov value
	// todo: add check for orientation value (normalized vector)