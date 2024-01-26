/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_create.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acrespy <acrespy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 13:39:12 by acrespy           #+#    #+#             */
/*   Updated: 2024/01/20 13:39:12 by acrespy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../includes/miniRT.h"

t_ray	ray_create(t_point origin, t_vector direction)
{
	t_ray	ray;

	ray.origin = origin;
	ray.direction = direction;
	return (ray);
}

t_point	ray_position(t_ray ray, double t)
{
	t_point	point;

	point = point_vector_add(ray.origin, vec_double_mult(ray.direction, t));
	return (point);
}

t_intersect ray_intersect_sphere(t_ray ray, t_hittable sphere)
{
	double		a;
	double		b;
	double		c;
	double		root;
	double		sqrtd;
	double		discriminant;
	t_vector	oc;
	t_intersect	intersect;

	oc = point_point_sub(ray.origin, sphere.center);
	a = vect_dot(ray.direction, ray.direction);
	b = 2.0 * vect_dot(oc, ray.direction);
	c = vect_dot(oc, oc) - sphere.radius * sphere.radius;
	discriminant = b * b - 4 * a * c;
	if (discriminant < 0)
	{
		intersect.hit = false;
		return (intersect);
	}
	sqrtd = sqrt(discriminant);
	root = (-b - sqrtd) / (2.0 * a);
	if (root < 0.001 || root > INFINITY)
	{
		root = (-b + sqrtd) / (2.0 * a);
		if (root < 0.001 || root > INFINITY)
		{
			intersect.hit = false;
			return (intersect);
		}
	}
	intersect.hit = true;
	intersect.t = root;
	intersect.point = ray_position(ray, intersect.t);
	intersect.normal = vec_double_div(point_point_sub(intersect.point, sphere.center), sphere.radius);
	return (intersect);
}

t_ray transform_ray(t_ray ray, t_matrix_4 matrix)
{
	t_ray	new_ray;

	new_ray.origin = matrix_4_mult_point(matrix, ray.origin);
	new_ray.direction = matrix_4_mult_vect(matrix, ray.direction);
	return (new_ray);
}