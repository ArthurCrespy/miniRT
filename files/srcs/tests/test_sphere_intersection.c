/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_sphere_intersection.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkeraudr <dkeraudr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 16:14:35 by dkeraudr          #+#    #+#             */
/*   Updated: 2024/02/12 20:31:54 by dkeraudr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT_test.h"

void	do_sphere_intersect(t_hittable *sphere, t_ray ray, double *expected, int expected_cnt)
{
	int			i;
	t_list	*intersections;
	t_list	*tmp;
	t_list	*objects;

	objects = ft_lstnew(sphere);
	i = 0;
	intersections = ft_intersect(objects, ray);
	tmp = intersections;

	CU_ASSERT_EQUAL(expected_cnt, ft_lstsize(intersections));
	if (expected == NULL)
	{
		CU_ASSERT_PTR_NULL(intersections);
		return ;
	}
	while (tmp)
	{
		CU_ASSERT_PTR_NOT_NULL(tmp->content);
		CU_ASSERT_DOUBLE_EQUAL(((t_intersection *)tmp->content)->t, expected[i], 1e-6);
		tmp = tmp->next;
		i++;
	}
	// check if len of expected is the same as len of intersections

	if (intersections)
		free(intersections);
	if (objects)
		ft_lstclear(&objects, free);
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
	sphere->type = SPHERE;
	do_sphere_intersect(sphere, ray, (double [2]){4.0, 6.0}, 2);
}

void	do_sphere_intersect_01(void)
{
	t_ray		ray;
	t_hittable	*sphere;

	ray = ray_new(point_new(0, 1, -5), vector_new(0, 0, 1));
	sphere = malloc(sizeof(t_hittable));
	sphere->center = point_new(0, 0, 0);
	sphere->type = SPHERE;
	do_sphere_intersect(sphere, ray, (double [1]){5.0}, 1);
}

void	do_sphere_intersect_02(void)
{
	t_ray		ray;
	t_hittable	*sphere;

	ray = ray_new(point_new(0, 2, -5), vector_new(0, 0, 1));
	sphere = malloc(sizeof(t_hittable));
	sphere->center = point_new(0, 0, 0);
	sphere->type = SPHERE;
	do_sphere_intersect(sphere, ray, NULL, 0);
}
