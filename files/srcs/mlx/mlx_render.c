/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_render.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkeraudr <dkeraudr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 15:00:18 by acrespy           #+#    #+#             */
/*   Updated: 2024/01/28 19:38:27 by dkeraudr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../includes/miniRT.h"

int	intersecting(t_minirt *data, t_vector *ray)
{
	t_hittable	*obj;
	t_vector	ray2;
	t_list *tmp;

	tmp = data->scene->objects;
	while (tmp)
	{
		obj = tmp->content;
		if (obj->id == SPHERE)
		{
			ray2 = vector_sub(*ray, vector_from_point(obj->center));
			if (vector_dot(ray2, ray2) - obj->diameter * obj->diameter < 0)
				return (1);
		}
		tmp = tmp->next;
	}
	return (0);
}

void	generate_vector(t_vector *vec, t_point *p1, t_point *p2)
{
	vec->x = p2->x - p1->x;
	vec->y = p2->y - p1->y;
	vec->z = p2->z - p1->z;
}

t_vector	*ft_generate_ray(t_minirt *data, int x, int y)
{
	t_point	pixel_center;
	t_point	ray_direction;
	t_vector	*ray;

	pixel_center = pixel_center_viewport(data, x, y);
	ray_direction = point_new(pixel_center.x - data->scene->camera->center.x,
		pixel_center.y - data->scene->camera->center.y,
		pixel_center.z - data->scene->camera->center.z);
	ray = malloc(sizeof(t_vector));
	if (!ray)
		return (NULL);
	generate_vector(ray, &data->scene->camera->center, &ray_direction);
	return (ray);
}

int	mlx_render_frame(t_minirt *data)
{
	int	x;
	int	y;
	t_vector	*ray;

	y = 0;
	while (y < data->mlx->win_height)
	{
		x = 0;
		while (x < data->mlx->win_width)
		{
			ray = ft_generate_ray(data, x, y);
			if (intersecting(data, ray))
				my_mlx_pixel_put(data->mlx, x, y, create_trgb(0, 255, 0, 0));
			else
				my_mlx_pixel_put(data->mlx, x, y, create_trgb(0, 0, 0, 0));
			// my_mlx_pixel_put(data->mlx, x, y, create_trgb(0, x * 255 / data->mlx->win_width, y * 255 / data->mlx->win_height, 0));
			x++;
		}
		y++;
	}
	printf("here\n");
	mlx_put_image_to_window(data->mlx->mlx, data->mlx->mlx_win,
		data->mlx->img, 0, 0);
	usleep(100000 / 10);
	return (0);
}
