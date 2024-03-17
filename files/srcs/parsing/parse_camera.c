/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_camera.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkeraudr <dkeraudr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 22:01:44 by dkeraudr          #+#    #+#             */
/*   Updated: 2024/03/17 17:28:40 by dkeraudr         ###   ########.fr       */
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
	camera->normal = vector_new(0, 1, 0);
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

// t_matrix	*view_transform(t_point from, t_vector normal)
// {
// 	t_vector	x_axis;
// 	t_vector	y_axis;
// 	t_vector	z_axis;
// 	t_vector	up;
// 	t_point		to;

// 	up = vector_new(0, 1, 0);
// 	z_axis = normal;
// 	if (normal.y == 1 || normal.y == -1)
// 		x_axis = vector_new(normal.y, 0, 0);
// 	else
// 		x_axis = tuple_cross(up, z_axis);
// 	y_axis = tuple_cross(z_axis, x_axis);
// 	to.x = from.x * x_axis.x + from.y * y_axis.x + from.z * z_axis.x;
// 	to.y = from.x * x_axis.y + from.y * y_axis.y + from.z * z_axis.y;
// 	to.z = from.x * x_axis.z + from.y * y_axis.z + from.z * z_axis.z;
// 	to.y = 1;
// 	printf("x: %f, y: %f, z: %f\n", x_axis.x, x_axis.y, x_axis.z);
// 	return (matrix_new((double[]){x_axis.x, x_axis.y, x_axis.z, 0,
// 		y_axis.x, y_axis.y, y_axis.z, 0,
// 		-z_axis.x, -z_axis.y, -z_axis.z, 0,
// 		0, 0, 0, 1}, 4));
// }

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
		// return (free_parse_camera(camera, tab), 0);
	// if (!ft_parse_tuple(tab[2], to))
		// return (free_parse_camera(camera, tab), 0);
	ft_parse_center(tab[1], camera->transform);
	ft_parse_vector(tab[2], &camera->normal);
	if (!ft_isint(tab[3]))
		return (free_parse_camera(camera, tab), 0);
	camera->fov = ft_atof(tab[3]);
	scene->camera = camera;
	// camera->transform = matrix_rotation_y(M_PI/4);
	// translate the camera
	// camera->transform =  matrix_mult(*matrix_rotation_y(M_PI/4), *matrix_translation(0, -2, 5));
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