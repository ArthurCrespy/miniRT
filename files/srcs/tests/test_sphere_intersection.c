/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_sphere_intersection.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkeraudr <dkeraudr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 16:14:35 by dkeraudr          #+#    #+#             */
/*   Updated: 2024/02/11 20:04:34 by dkeraudr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT_test.h"

void	do_sphere_intersect(t_hittable *sphere, t_ray ray, double *expected)
{
	int			i;
	double		*intersections;

	i = 0;
	intersections = intersect_with_sphere(sphere, ray);
	if (expected == NULL)
	{
		CU_ASSERT_PTR_NULL(intersections);
		return ;
	}
	while (i < 2)
	{
		CU_ASSERT_DOUBLE_EQUAL(intersections[i], expected[i], 0.0001);
		i++;
	}
	if (intersections)
		free(intersections);
	if (sphere)
		free(sphere);
	// if (ray)
	// 	ft_free_ray(ray);
}

void	do_sphere_intersect_00(void)
{
	t_ray		ray;
	t_hittable	*sphere;

	ray = ray_new(point_new(0, 0, -5), vector_new(0, 0, 1));
	sphere = malloc(sizeof(t_hittable));
	sphere->center = point_new(0, 0, 0);
	do_sphere_intersect(sphere, ray, (double [2]){4.0, 6.0});
}

void	do_sphere_intersect_01(void)
{
	t_ray		ray;
	t_hittable	*sphere;

	ray = ray_new(point_new(0, 1, -5), vector_new(0, 0, 1));
	sphere = malloc(sizeof(t_hittable));
	sphere->center = point_new(0, 0, 0);
	do_sphere_intersect(sphere, ray, (double [2]){5.0, 5.0});
}

void	do_sphere_intersect_02(void)
{
	t_ray		ray;
	t_hittable	*sphere;

	ray = ray_new(point_new(0, 2, -5), vector_new(0, 0, 1));
	sphere = malloc(sizeof(t_hittable));
	sphere->center = point_new(0, 0, 0);
	do_sphere_intersect(sphere, ray, NULL);
}
