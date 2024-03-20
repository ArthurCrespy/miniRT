/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_scene.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkeraudr <dkeraudr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 15:08:57 by dkeraudr          #+#    #+#             */
/*   Updated: 2024/03/20 21:21:42 by dkeraudr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_ray	get_ray(t_scene *scene, int x, int y)
{
	t_ray	ray;
	double	xoffset;
	double	yoffset;
	double	world_x;
	double	world_y;
	t_point	pixel;
	t_point	origin;

	xoffset = (x + 0.5) * scene->camera->pixel_size;
	yoffset = (y + 0.5) * scene->camera->pixel_size;
	world_x = scene->camera->half_width - xoffset;
	world_y = scene->camera->half_height - yoffset;
	pixel = tuple_transform(point_new(world_x, world_y, -1), matrix_inverse(*scene->camera->transform));
	origin = tuple_transform(point_new(0, 0, 0), matrix_inverse(*scene->camera->transform));
	ray = ray_new(origin, tuple_norm(tuple_sub(pixel, origin)));
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
	// normal < 0 → angle +90° → intersection point inside the object
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
	t_list			*intersections;
	t_color			color;
	int				result;

	intersections = ft_intersect(data->scene->objects, ray);
	intersection = ft_hit(intersections);
	result = 0;
	if (intersection)
	{
		// actual color
		comps = prepare_computations(intersection, ray);
		comps.light = data->scene->lights->content; // SEGFAULT HERE WHEN NO LIGHT
		comps.scene = data->scene;
		ft_lstclear(&intersections, free_intersection);
		color = lighting(&comps, is_shadowed(data->scene, comps.over_point));
		result = color_to_int(color);
	}
	if (intersections)
		ft_lstclear(&intersections, free_intersection);
	return (result);
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
				break ;
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
