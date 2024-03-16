/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_camera.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkeraudr <dkeraudr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 22:01:44 by dkeraudr          #+#    #+#             */
/*   Updated: 2024/03/16 12:43:38 by dkeraudr         ###   ########.fr       */
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

t_matrix	*view_transform(t_point from, t_point to)
{
	t_vector	right;
	t_vector	up;
	t_vector	default_orientation;
	t_matrix	*result;
	double		**matrix_values;

	default_orientation = vector_new(0, 1, 0);
	printf("from: %f %f %f\n", from.x, from.y, from.z);
	printf("to: %f %f %f\n", to.x, to.y, to.z);
	printf("default_orientation: %f %f %f\n", default_orientation.x, default_orientation.y, default_orientation.z);
	right = tuple_norm(tuple_cross(default_orientation, to));
	printf("right: %f %f %f\n", right.x, right.y, right.z);
	up = tuple_norm(tuple_cross(to, right));

	matrix_values = (double *[]) {
		(double []) {right.x, right.y, right.z, 0},
		(double []) {up.x, up.y, up.z, 0},
		(double []) {to.x, to.y, to.z, 0},
		(double []) {from.x, from.y, from.z, 1}
	};
	result = matrix_new(matrix_values,4);
	return (result);
}

int	ft_parse_camera(t_scene *scene, char *line)
{
	t_camera	*camera;
	char		**tab;
	t_point		*from;
	t_vector	*to;

	camera = ft_init_camera();
	to = malloc(sizeof(t_vector));
	from = malloc(sizeof(t_point));
	if (!camera)
		return (free_parse_camera(camera, NULL), 0);
	tab = ft_split(line, ' ');
	if (!tab)
		return (free(camera), ft_error(ERROR_MALLOC), 0);
	if (ft_tablen(tab) != 4)
		return (ft_error(ERROR_WRONG_ARGS_NB),
			free_parse_camera(camera, tab), 0);
	if (!ft_parse_tuple(tab[1], from))
		return (free_parse_camera(camera, tab), 0);
	if (!ft_parse_tuple(tab[2], to))
		return (free_parse_camera(camera, tab), 0);
	camera->transform = view_transform(*from, *to);
	if (!ft_isint(tab[3]))
		return (free_parse_camera(camera, tab), 0);
	camera->fov = ft_atof(tab[3]);
	scene->camera = camera;
	// camera->transform = matrix_rotation_y(M_PI/4);
	// translate the camera
	// camera->transform =  matrix_mult(*matrix_rotation_y(M_PI/4), *matrix_translation(0, -2, 5));
	// ft_parse_vector(tab[2], camera->orientation);
	// ft_parse_center(tab[1], camera->transform);
	// ft_parse_rotation(tab[2], camera->transform, vector_new(0, 0, -1));
	ft_print_matrix(*camera->transform);
	ft_get_pixel_size(camera);
	ft_free_2d_list(tab);
	free(from);
	free(to);
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