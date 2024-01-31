/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_render.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkeraudr <dkeraudr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 15:00:18 by acrespy           #+#    #+#             */
/*   Updated: 2024/01/31 19:31:39 by dkeraudr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../includes/miniRT.h"

// bool hit_sphere(const point3& center, double radius, const ray& r) {
//     vec3 oc = r.origin() - center;
//     auto a = dot(r.direction(), r.direction());
//     auto b = 2.0 * dot(oc, r.direction());
//     auto c = dot(oc, oc) - radius*radius;
//     auto discriminant = b*b - 4*a*c;
//     return (discriminant >= 0);
// }

int	intersecting(t_minirt *data, t_ray *ray)
{
	t_hittable	*obj;
	t_point	oc;
	t_list *tmp;
	double a;
	double b;
	double	c;

	tmp = data->scene->objects;
	while (tmp)
	{
		obj = tmp->content;
		if (obj->id == SPHERE)
		{
			// ft_print_scene(data->scene);
			oc = point_sub(*ray->origin, obj->center);
			a = vector_dot(*ray->direction,*ray->direction);
			b = 2.0 * vector_dot(vector_from_point(oc), *ray->direction);
			c = vector_dot(vector_from_point(oc), vector_from_point(oc)) - ((obj->diameter/2)*(obj->diameter/2));
			return ( b*b - 4*a*c >= 0);
			// if ((vector_dot(ray2, ray2) - obj->diameter * obj->diameter) < 0)
			// 	return (1);
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

t_ray	*ft_generate_ray(t_minirt *data, int x, int y)
{
	t_point	pixel_center;
	t_vector	ray_direction;
	t_ray	*ray;

	pixel_center = pixel_center_viewport(data, x, y);
	ray_direction = vector_new(pixel_center.x - data->scene->camera->center.x,
		pixel_center.y - data->scene->camera->center.y,
		pixel_center.z - data->scene->camera->center.z);
	ray = malloc(sizeof(t_ray));
	if (!ray)
		return (NULL);
	// generate_vector(ray, &data->scene->camera->center, &ray_direction);
	ray->origin = &data->scene->camera->center;
	ray->direction = &ray_direction;
	return (ray);
}

int	mlx_render_frame(t_minirt *data)
{
	int	x;
	int	y;
	t_ray	*ray;

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
				my_mlx_pixel_put(data->mlx, x, y, create_trgb(0, 0, 255, 0));
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
