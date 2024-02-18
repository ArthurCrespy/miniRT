/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_transform.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkeraudr <dkeraudr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 18:37:16 by dkeraudr          #+#    #+#             */
/*   Updated: 2024/02/18 13:38:11 by dkeraudr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT_test.h"

void	do_ray_translate_00(void)
{
	t_matrix	*transform;
	t_ray		r;
	t_ray		r2;

	transform = matrix_translation(3, 4, 5);
	r = ray_new(point_new(1, 2, 3), vector_new(0, 1, 0));
	r2 = ray_transform(r, *transform);
	free(transform);
	CU_ASSERT_DOUBLE_EQUAL(r2.origin.x, 4.0, 1e-6);
	CU_ASSERT_DOUBLE_EQUAL(r2.origin.y, 6.0, 1e-6);
	CU_ASSERT_DOUBLE_EQUAL(r2.origin.z, 8.0, 1e-6);
	CU_ASSERT_DOUBLE_EQUAL(r2.direction.x, 0.0, 1e-6);
	CU_ASSERT_DOUBLE_EQUAL(r2.direction.y, 1.0, 1e-6);
	CU_ASSERT_DOUBLE_EQUAL(r2.direction.z, 0.0, 1e-6);
}


void	do_ray_scaling_00(void)
{
	t_matrix	*transform;
	t_ray		r;
	t_ray		r2;

	transform = matrix_scale(2, 3, 4);
	r = ray_new(point_new(1, 2, 3), vector_new(0, 1, 0));
	r2 = ray_transform(r, *transform);
	free(transform);
	CU_ASSERT_DOUBLE_EQUAL(r2.origin.x, 2.0, 1e-6);
	CU_ASSERT_DOUBLE_EQUAL(r2.origin.y, 6.0, 1e-6);
	CU_ASSERT_DOUBLE_EQUAL(r2.origin.z, 12.0, 1e-6);
	CU_ASSERT_DOUBLE_EQUAL(r2.direction.x, 0.0, 1e-6);
	CU_ASSERT_DOUBLE_EQUAL(r2.direction.y, 3.0, 1e-6);
	CU_ASSERT_DOUBLE_EQUAL(r2.direction.z, 0.0, 1e-6);
}

void	do_ray_translate_01(void)
{
	t_ray		r;
	t_ray		r2;
	t_hittable	*sphere;

	sphere = malloc(sizeof(t_hittable));
	sphere->transform = matrix_translation(2, 3, 4);
	sphere->type = SPHERE;
	r = ray_new(point_new(0, 0, -5), vector_new(0, 0, 1));
	r2 = ray_transform(r, *sphere->transform);
	CU_ASSERT_DOUBLE_EQUAL(r2.origin.x, 2.0, 1e-6);
	CU_ASSERT_DOUBLE_EQUAL(r2.origin.y, 3.0, 1e-6);
	CU_ASSERT_DOUBLE_EQUAL(r2.origin.z, -1.0, 1e-6);
	CU_ASSERT_DOUBLE_EQUAL(r2.direction.x, 0.0, 1e-6);
	CU_ASSERT_DOUBLE_EQUAL(r2.direction.y, 0.0, 1e-6);
	CU_ASSERT_DOUBLE_EQUAL(r2.direction.z, 1.0, 1e-6);
}

void	do_ray_scaling_01(void)
{
	t_ray		r;
	t_hittable	*sphere;
	t_list	*hit;

	sphere = malloc(sizeof(t_hittable));
	sphere->transform = matrix_scale(2, 2, 2);
	sphere->type = SPHERE;
	r = ray_new(point_new(0, 0, -5), vector_new(0, 0, 1));
	hit = ft_intersect(ft_lstnew(sphere), r);
	CU_ASSERT_DOUBLE_EQUAL(ft_lstsize(hit), 2, 1e-6);
	CU_ASSERT_DOUBLE_EQUAL(((t_intersection *)hit->content)->t, 3.0, 1e-6);
	CU_ASSERT_DOUBLE_EQUAL(((t_intersection *)hit->next->content)->t, 7.0, 1e-6);
}

void	do_ray_translate_02(void)
{
	t_ray		r;
	t_hittable	*sphere;
	t_list	*hit;

	sphere = malloc(sizeof(t_hittable));
	sphere->transform = matrix_translation(5, 0, 0);
	sphere->type = SPHERE;
	r = ray_new(point_new(0, 0, -5), vector_new(0, 0, 1));
	hit = ft_intersect(ft_lstnew(sphere), r);
	CU_ASSERT_PTR_NULL(hit);
}