/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_scene.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkeraudr <dkeraudr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 15:08:57 by dkeraudr          #+#    #+#             */
/*   Updated: 2024/03/17 17:36:16 by dkeraudr         ###   ########.fr       */
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

t_vector	look_at(t_vector	direction, t_vector	camera_normal)
{
		t_vector	x_axis;
	t_vector	y_axis;
	t_vector	z_axis;
	t_vector	up;
	t_point		to;

	up = vector_new(0, 1, 0);
	z_axis = camera_normal;
	if (camera_normal.y == 1 || camera_normal.y == -1)
		x_axis = vector_new(camera_normal.y, 0, 0);
	else
		x_axis = tuple_cross(up, z_axis);
	y_axis = tuple_cross(z_axis, x_axis);
	to.x = direction.x * x_axis.x + direction.y * y_axis.x + direction.z * z_axis.x;
	to.y = direction.x * x_axis.y + direction.y * y_axis.y + direction.z * z_axis.y;
	to.z = direction.x * x_axis.z + direction.y * y_axis.z + direction.z * z_axis.z;
	return (to);
}

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
	direction = tuple_norm(tuple_sub(pixel, origin));
	direction = look_at(direction, scene->camera->normal);
	ray = ray_new(origin, direction);
	// (void)direction;
	// ray = ray_new(point_new(0, 0, -5), vector_new(0, 0, 1));
	if (x == 100 && y == 50)
	// if (x == 0 && y == 0)
	{
		// ft_print_point(pixel);
		ft_printf("X: %d, Y: %d\n", x, y);
		ft_printf("Origin: ");
		ft_print_point(origin);
		ft_printf("Direction: ");
		ft_print_vector(direction);
		ft_print_matrix(*scene->camera->transform);
		ft_printf("\n");
		ft_print_matrix(*matrix_inverse(*scene->camera->transform));
		ft_printf("\n");

	}
	return (ray);
}

t_point	ft_point_at(t_ray ray, double t)
{
	return (tuple_add(ray.origin, tuple_mult(ray.direction, t)));
}


t_computation	prepare_computations(t_intersection *intersection, t_ray ray)
{
	t_computation	comps;

	comps.object = intersection->obj;
	comps.point = ft_point_at(ray, intersection->t);
	comps.eye = tuple_negate(ray.direction);
	// comps.eye = ray.direction;
	comps.normal = normal_at(comps.object, comps.point);
//	normal < 0 → angle +90° → intersection point inside the object
	if (tuple_dot(comps.normal, comps.eye) < 0)
	{
		comps.normal = tuple_negate(comps.normal);
		comps.inside = true;
		comps.over_point = tuple_sub(comps.point, tuple_mult(comps.normal, EPSILON));
	}
	else
	{
		comps.inside = false;
		comps.over_point = tuple_add(comps.point, tuple_mult(comps.normal, EPSILON));
	}
	// comps.over_point = tuple_add(comps.point, tuple_mult(comps.normal, EPSILON));
	return (comps);
}

int	ray_color(t_minirt *data, t_ray ray)
{
	t_computation	comps;
	t_intersection	*intersection;
	t_color			color;

	intersection = ft_hit(ft_intersect(data->scene->objects, ray));
	if (intersection)
	{
		// actual color
		comps = prepare_computations(intersection, ray);
		comps.light = data->scene->lights->content; // SEGFAULT HERE WHEN NO LIGHT
		comps.scene = data->scene;
		color = lighting(&comps, is_shadowed(data->scene, comps.over_point));
		return (color_to_int(color));
	}
	return (0x00000000);
}

int	get_pixel_color(t_minirt *data, int x, int y)
{
	t_ray	ray;
	int	color;

	ray = get_ray(data->scene, x, y);
	// (void)ray;
	// ft_print_point(ray.origin);
	// ft_print_vector(ray.direction);
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