/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   viewport.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkeraudr <dkeraudr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 18:09:36 by dkeraudr          #+#    #+#             */
/*   Updated: 2024/01/28 19:21:17 by dkeraudr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_point	pixel_center_viewport(t_minirt *data, int x, int y)
{
	t_point upper_left_corner;
	double focal_length;
	double viewport_height;
	double viewport_width;
	t_vector viewport_u;
	t_vector viewport_v;
	t_vector pixel_delta_u;
	t_vector pixel_delta_v;
	t_point pixel00_center;
	t_point pixel_center;

	focal_length = 1;
	viewport_height = 2.0;
	viewport_width = viewport_height * data->mlx->win_width / data->mlx->win_height;
	viewport_u = vector_new(viewport_width, 0, 0);
	viewport_v = vector_new(0, -viewport_height, 0);
	pixel_delta_u = vector_new(viewport_u.x / data->mlx->win_width, 0, 0);
	pixel_delta_v = vector_new(0, viewport_v.y / data->mlx->win_height, 0);
	upper_left_corner = point_new(data->scene->camera->center.x - focal_length - viewport_u.x / 2 - viewport_v.x / 2,
		data->scene->camera->center.y - focal_length - viewport_u.y / 2 - viewport_v.y / 2,
		data->scene->camera->center.z - focal_length - viewport_u.z / 2 - viewport_v.z / 2);
	pixel00_center = point_new(upper_left_corner.x + x * pixel_delta_u.x + y * pixel_delta_v.x,
		upper_left_corner.y + x * pixel_delta_u.y + y * pixel_delta_v.y,
		upper_left_corner.z + x * pixel_delta_u.z + y * pixel_delta_v.z);
	pixel_center = point_new(pixel00_center.x + x * pixel_delta_u.x + y * pixel_delta_v.x,
		pixel00_center.y + x * pixel_delta_u.y + y * pixel_delta_v.y,
		pixel00_center.z + x * pixel_delta_u.z + y * pixel_delta_v.z);
	return (pixel_center);
}
