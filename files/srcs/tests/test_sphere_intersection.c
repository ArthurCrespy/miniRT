/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_sphere_intersection.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkeraudr <dkeraudr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 16:14:35 by dkeraudr          #+#    #+#             */
/*   Updated: 2024/02/11 19:36:07 by dkeraudr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>
#include "miniRT.h"

double *intersects(t_ray ray, t_hittable *hittable)
{
	double *intersections;

	intersections = malloc(sizeof(double) * 2);
	if (!intersections)
		return (ft_error(ERROR_MALLOC), NULL);
	intersections[0] = 4.0;
	intersections[1] = 6.0;
	return (intersections);
}

int	do_sphere_intersect_00(void)
{
	t_ray		ray;
	t_hittable	*sphere;
	double		*intersections;
	double		expected[2] = {4.0, 6.0};

	ray = ray_new(point_new(0, 0, -5), vector_new(0, 0, 1));
	sphere = malloc(sizeof(t_hittable));
	if (!sphere)
		return (ft_error(ERROR_MALLOC), 0);
	intersections = intersects(ray, sphere);
	for (int i = 0; i < 2; i++)
		CU_ASSERT_DOUBLE_EQUAL(intersections[i], expected[i], 0.0001);
	return (1);
}

int	do_sphere_intersect_01(void)
{
	t_ray		ray;
	t_hittable	*sphere;
	double		*intersections;
	double		expected[2] = {5.0, 5.0};

	ray = ray_new(point_new(0, 1, -5), vector_new(0, 0, 1));
	sphere = malloc(sizeof(t_hittable));
	if (!sphere)
		return (ft_error(ERROR_MALLOC), 0);
	intersections = intersects(ray, sphere);
	for (int i = 0; i < 2; i++)
		CU_ASSERT_DOUBLE_EQUAL(intersections[i], expected[i], 0.0001);
	return (1);
}