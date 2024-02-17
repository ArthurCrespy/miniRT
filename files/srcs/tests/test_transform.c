/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_transform.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkeraudr <dkeraudr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 18:37:16 by dkeraudr          #+#    #+#             */
/*   Updated: 2024/02/17 15:25:47 by dkeraudr         ###   ########.fr       */
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
	printf("r2.origin.x: %f\n", r2.origin.x);
	printf("r2.origin.y: %f\n", r2.origin.y);
	printf("r2.origin.z: %f\n", r2.origin.z);
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
	CU_ASSERT_DOUBLE_EQUAL(r2.origin.x, 2.0, 1e-6);
	CU_ASSERT_DOUBLE_EQUAL(r2.origin.y, 6.0, 1e-6);
	CU_ASSERT_DOUBLE_EQUAL(r2.origin.z, 12.0, 1e-6);
	CU_ASSERT_DOUBLE_EQUAL(r2.direction.x, 0.0, 1e-6);
	CU_ASSERT_DOUBLE_EQUAL(r2.direction.y, 3.0, 1e-6);
	CU_ASSERT_DOUBLE_EQUAL(r2.direction.z, 0.0, 1e-6);
}
