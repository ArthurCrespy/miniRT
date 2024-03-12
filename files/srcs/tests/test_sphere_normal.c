/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_sphere_normal.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkeraudr <dkeraudr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 19:21:18 by dkeraudr          #+#    #+#             */
/*   Updated: 2024/02/21 20:06:54 by dkeraudr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT_test.h"

int	do_sphere_normal_tests(CU_pSuite suite)
{
	suite = CU_add_suite("Sphere normal", NULL, NULL);
	if (suite == NULL)
		return (CU_cleanup_registry(), CU_get_error());

	if (!CU_add_test(suite, "Sphere normal 00", do_sphere_normal_00)
		|| !CU_add_test(suite, "Sphere normal 01", do_sphere_normal_01)
		|| !CU_add_test(suite, "Sphere normal 02", do_sphere_normal_02)
		|| !CU_add_test(suite, "Sphere normal 03", do_sphere_normal_03)
		|| !CU_add_test(suite, "Sphere normal 04", do_sphere_normal_04)
		|| !CU_add_test(suite, "Sphere normal 05", do_sphere_normal_05))
		return (CU_cleanup_registry(), CU_get_error());

	return (0);
}

void	do_sphere_normal_00(void)
{
	t_hittable	*sphere;
	t_tuple		point;
	t_vector	normal;

	sphere = malloc(sizeof(t_hittable));
	if (!sphere)
	{
		CU_FAIL("malloc failed");
		return ;
	}
	sphere->type = SPHERE;
	sphere->transform = matrix_identity();
	point = point_new(1, 0, 0);
	normal = normal_at(sphere, point);
	CU_ASSERT_DOUBLE_EQUAL(normal.x, 1, 1e-6);
	CU_ASSERT_DOUBLE_EQUAL(normal.y, 0, 1e-6);
	CU_ASSERT_DOUBLE_EQUAL(normal.z, 0, 1e-6);
}

void	do_sphere_normal_01(void)
{
	t_hittable	*sphere;
	t_tuple		point;
	t_vector	normal;

	sphere = malloc(sizeof(t_hittable));
	if (!sphere)
	{
		CU_FAIL("malloc failed");
		return ;
	}
	sphere->type = SPHERE;
	sphere->transform = matrix_identity();
	point = point_new(0, 1, 0);
	normal = normal_at(sphere, point);
	CU_ASSERT_DOUBLE_EQUAL(normal.x, 0, 1e-6);
	CU_ASSERT_DOUBLE_EQUAL(normal.y, 1, 1e-6);
	CU_ASSERT_DOUBLE_EQUAL(normal.z, 0, 1e-6);
}

void	do_sphere_normal_02(void)
{
	t_hittable	*sphere;
	t_tuple		point;
	t_vector	normal;

	sphere = malloc(sizeof(t_hittable));
	if (!sphere)
	{
		CU_FAIL("malloc failed");
		return ;
	}
	sphere->type = SPHERE;
	sphere->transform = matrix_identity();
	point = point_new(0, 0, 1);
	normal = normal_at(sphere, point);
	CU_ASSERT_DOUBLE_EQUAL(normal.x, 0, 1e-6);
	CU_ASSERT_DOUBLE_EQUAL(normal.y, 0, 1e-6);
	CU_ASSERT_DOUBLE_EQUAL(normal.z, 1, 1e-6);
}

void	do_sphere_normal_03(void)
{
	t_hittable	*sphere;
	t_tuple		point;
	t_vector	normal;

	sphere = malloc(sizeof(t_hittable));
	if (!sphere)
	{
		CU_FAIL("malloc failed");
		return ;
	}
	sphere->type = SPHERE;
	sphere->transform = matrix_identity();
	point = point_new(sqrt(3) / 3, sqrt(3) / 3, sqrt(3) / 3);
	normal = normal_at(sphere, point);
	CU_ASSERT_DOUBLE_EQUAL(normal.x, sqrt(3) / 3, 1e-6);
	CU_ASSERT_DOUBLE_EQUAL(normal.y, sqrt(3) / 3, 1e-6);
	CU_ASSERT_DOUBLE_EQUAL(normal.z, sqrt(3) / 3, 1e-6);
}

// Scenario: Computing the normal on a translated sphere
// Given s ← sphere()
// And set_transform(s, translation(0, 1, 0))
// When n ← normal_at(s, point(0, 1.70711, -0.70711))
// Then n = vector(0, 0.70711, -0.70711)

void	do_sphere_normal_04(void)
{
	t_hittable	*sphere;
	t_tuple		point;
	t_vector	normal;

	sphere = malloc(sizeof(t_hittable));
	if (!sphere)
	{
		CU_FAIL("malloc failed");
		return ;
	}
	sphere->type = SPHERE;
	sphere->transform = matrix_translation(0, 1, 0);
	point = point_new(0, 1.70711, -0.70711);
	normal = normal_at(sphere, point);
	CU_ASSERT_DOUBLE_EQUAL(normal.x, 0, EPSILON);
	CU_ASSERT_DOUBLE_EQUAL(normal.y, 0.70711, EPSILON);
	CU_ASSERT_DOUBLE_EQUAL(normal.z, -0.70711, EPSILON);
}

// Scenario: Computing the normal on a transformed sphere
// Given s ← sphere()
// And m ← scaling(1, 0.5, 1) * rotation_z(π/5)
// And set_transform(s, m)
// When n ← normal_at(s, point(0, √2/2, -√2/2))
// Then n = vector(0, 0.97014, -0.24254)

void	do_sphere_normal_05(void)
{
	t_hittable	*sphere;
	t_tuple		point;
	t_vector	normal;
	t_matrix	*scaling;
	t_matrix	*rotation;

	sphere = malloc(sizeof(t_hittable));
	if (!sphere)
	{
		CU_FAIL("malloc failed");
		return ;
	}
	sphere->type = SPHERE;
	scaling = matrix_scale(1, 0.5, 1);
	rotation = matrix_rotation_z(M_PI / 5);
	sphere->transform = matrix_mult(*scaling, *rotation);
	point = point_new(0, sqrt(2) / 2, -sqrt(2) / 2);
	normal = normal_at(sphere, point);
	CU_ASSERT_DOUBLE_EQUAL(normal.x, 0, EPSILON);
	CU_ASSERT_DOUBLE_EQUAL(normal.y, 0.97014, EPSILON);
	CU_ASSERT_DOUBLE_EQUAL(normal.z, -0.24254, EPSILON);
}
