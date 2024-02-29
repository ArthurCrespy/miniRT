/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_scene.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkeraudr <dkeraudr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 15:08:57 by dkeraudr          #+#    #+#             */
/*   Updated: 2024/02/18 16:50:45 by dkeraudr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

// get_ray: get the ray from the camera to the pixel
// origin is the camera center
// lower_left_corner is the bottom left corner of the screen

// function ray_for_pixel(camera, px, py)
// # the offset from the edge of the canvas to the pixel's center
// xoffset ← (px + 0.5) * camera.pixel_size
// yoffset ← (py + 0.5) * camera.pixel_size
// # the untransformed coordinates of the pixel in world space.
// # (remember that the camera looks toward -z, so +x is to the *left*.)
// world_x ← camera.half_width - xoffset
// world_y ← camera.half_height - yoffset
// # using the camera matrix, transform the canvas point and the origin,
// # and then compute the ray's direction vector.
// # (remember that the canvas is at z=-1)
// pixel ← inverse(camera.transform) * point(world_x, world_y, -1)
// origin ← inverse(camera.transform) * point(0, 0, 0)
// direction ← normalize(pixel - origin)
// return ray(origin, direction)
// end function

t_ray	get_ray(t_scene *scene, int x, int y)
{
	t_ray	ray;
	double	xoffset;
	double	yoffset;
	double	world_x;
	double	world_y;
	t_point	pixel;
	t_point	origin;
	t_vector	direction;

	xoffset = (x + 0.5) * scene->camera->pixel_size;
	yoffset = (y + 0.5) * scene->camera->pixel_size;
	world_x = scene->camera->half_width - xoffset;
	world_y = scene->camera->half_height - yoffset;
	pixel = tuple_transform(point_new(world_x, world_y, -1), *matrix_inverse(*scene->camera->transform));
	origin = tuple_transform(point_new(0, 0, 0), *matrix_inverse(*scene->camera->transform));
	direction = tuple_normalize(tuple_sub(pixel, origin));
	ray = ray_new(origin, direction);
	// (void)direction;
	// ray = ray_new(point_new(0, 0, -5), vector_new(0, 0, 1));
	return (ray);
}

int	ray_color(t_minirt *data, t_ray ray)
{
	if (ft_hit(ft_intersect(data->scene->objects, ray)))
		return (0x00FF0000);
	return (0x00000000);
}

int	get_pixel_color(t_minirt *data, int x, int y)
{
	t_ray	ray;
	int	color;

	ray = get_ray(data->scene, x, y);
	// (void)ray;
	ft_print_point(ray.origin);
	ft_print_vector(ray.direction);
	color = ray_color(data, ray);
	return (color);
}

void	render_scene(t_minirt *data)
{
	int	x;
	int	y;
	unsigned int	pxl_rendered;

	// render 10 pixel each call
	pxl_rendered = 0;
	x = data->pxl_rendered % data->mlx->win_width;
	y = data->pxl_rendered / data->mlx->win_width;
	while (y < data->mlx->win_height)
	{
		while (x < data->mlx->win_width)
		{
			my_mlx_pixel_put(data->mlx, x, y, get_pixel_color(data, x, y));
			// my_mlx_pixel_put(data->mlx, x, y, 0x00FF0000);
			x++;
			pxl_rendered++;
			if (pxl_rendered >= 10)
				break;
		}
		if (pxl_rendered >= 10)
		{
			data->pxl_rendered += pxl_rendered;
			break ;
		}
		x = 0;
		y++;
	}
	mlx_put_image_to_window(data->mlx->mlx, data->mlx->mlx_win, data->mlx->img, 0, 0);
	// ft_print_scene(data->scene);
}