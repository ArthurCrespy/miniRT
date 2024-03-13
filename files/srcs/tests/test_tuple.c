/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_tuple.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acrespy <acrespy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 17:16:56 by acrespy           #+#    #+#             */
/*   Updated: 2024/03/12 17:16:56 by acrespy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT_test.h"

int		do_tuple_tests(CU_pSuite suite)
{
	suite = CU_add_suite("Tuple", NULL, NULL);
	if (suite == NULL)
		return (CU_cleanup_registry(), CU_get_error());

	if (!CU_add_test(suite, "Tuple magnitude 00", do_tuple_mag_00)
		|| !CU_add_test(suite, "Tuple magnitude 01", do_tuple_mag_01)
		|| !CU_add_test(suite, "Tuple magnitude 02", do_tuple_mag_02)
		|| !CU_add_test(suite, "Tuple magnitude 03", do_tuple_mag_03))
		return (CU_cleanup_registry(), CU_get_error());

	if (!CU_add_test(suite, "Tuple normalize 00", do_tuple_norm_00)
		|| !CU_add_test(suite, "Tuple normalize 01", do_tuple_norm_01)
		|| !CU_add_test(suite, "Tuple normalize 02", do_tuple_norm_02))
		return (CU_cleanup_registry(), CU_get_error());

	if (!CU_add_test(suite, "Tuple dot 00", do_tuple_dot_00))
		return (CU_cleanup_registry(), CU_get_error());

	if (!CU_add_test(suite, "Tuple cross 00", do_tuple_cross_00))
		return (CU_cleanup_registry(), CU_get_error());

	if (!CU_add_test(suite, "Tuple normal 00", do_tuple_normal_00)
		|| !CU_add_test(suite, "Tuple normal 01", do_tuple_normal_01)
		|| !CU_add_test(suite, "Tuple normal 02", do_tuple_normal_02)
		|| !CU_add_test(suite, "Tuple normal 03", do_tuple_normal_03))
		return (CU_cleanup_registry(), CU_get_error());

	return (0);
}

void    do_tuple_mag_00(void)
{
	CU_ASSERT_DOUBLE_EQUAL(tuple_mag(vector_new(0, 1, 0)), 1, EPSILON);
}

void    do_tuple_mag_01(void)
{
	CU_ASSERT_DOUBLE_EQUAL(tuple_mag(vector_new(0, 0, 1)), 1, EPSILON);
}

void    do_tuple_mag_02(void)
{
	CU_ASSERT_DOUBLE_EQUAL(tuple_mag(vector_new(1, 2, 3)), sqrt(14), EPSILON);
}

void    do_tuple_mag_03(void)
{
	CU_ASSERT_DOUBLE_EQUAL(tuple_mag(vector_new(-1, -2, -3)), sqrt(14), EPSILON);
}

void	do_tuple_norm_00(void)
{
	t_vector	v;
	t_vector	norm;

	v = vector_new(4, 0, 0);
	norm = tuple_norm(v);
	CU_ASSERT_DOUBLE_EQUAL(norm.x, 1, EPSILON);
	CU_ASSERT_DOUBLE_EQUAL(norm.y, 0, EPSILON);
	CU_ASSERT_DOUBLE_EQUAL(norm.z, 0, EPSILON);
}

void	do_tuple_norm_01(void)
{
	t_vector	v;
	t_vector	norm;

	v = vector_new(1, 2, 3);
	norm = tuple_norm(v);
	CU_ASSERT_DOUBLE_EQUAL(norm.x, 1 / sqrt(14), EPSILON);
	CU_ASSERT_DOUBLE_EQUAL(norm.y, 2 / sqrt(14), EPSILON);
	CU_ASSERT_DOUBLE_EQUAL(norm.z, 3 / sqrt(14), EPSILON);
}

void	do_tuple_norm_02(void)
{
	t_vector	v;
	t_vector	norm;

	v = vector_new(1, 2, 3);
	norm = tuple_norm(v);
	CU_ASSERT_DOUBLE_EQUAL(tuple_mag(norm), 1, EPSILON);
}

void	do_tuple_dot_00(void)
{
	t_vector	v1;
	t_vector	v2;

	v1 = vector_new(1, 2, 3);
	v2 = vector_new(2, 3, 4);
	CU_ASSERT_DOUBLE_EQUAL(tuple_dot(v1, v2), 20, EPSILON);
}

void    do_tuple_cross_00(void)
{
	t_vector	v1;
	t_vector	v2;
	t_vector	cross;

	v1 = vector_new(1, 2, 3);
	v2 = vector_new(2, 3, 4);
	cross = tuple_cross(v1, v2);
	CU_ASSERT_DOUBLE_EQUAL(cross.x, -1, EPSILON);
	CU_ASSERT_DOUBLE_EQUAL(cross.y, 2, EPSILON);
	CU_ASSERT_DOUBLE_EQUAL(cross.z, -1, EPSILON);
}

void    do_tuple_normal_00(void)
{
	t_scene	*scene;
	t_vector	n;

	scene = default_world();
	n = normal_at(scene->objects->content, point_new(1, 0, 0));
	CU_ASSERT_DOUBLE_EQUAL(n.x, 1, EPSILON);
	CU_ASSERT_DOUBLE_EQUAL(n.y, 0, EPSILON);
	CU_ASSERT_DOUBLE_EQUAL(n.z, 0, EPSILON);
}

void    do_tuple_normal_01(void)
{
	t_scene	*scene;
	t_vector	n;

	scene = default_world();
	n = normal_at(scene->objects->content, point_new(0, 1, 0));
	CU_ASSERT_DOUBLE_EQUAL(n.x, 0, EPSILON);
	CU_ASSERT_DOUBLE_EQUAL(n.y, 1, EPSILON);
	CU_ASSERT_DOUBLE_EQUAL(n.z, 0, EPSILON);
}

void    do_tuple_normal_02(void)
{
	t_scene	*scene;
	t_vector	n;

	scene = default_world();
	n = normal_at(scene->objects->content, point_new(0, 0, 1));
	CU_ASSERT_DOUBLE_EQUAL(n.x, 0, EPSILON);
	CU_ASSERT_DOUBLE_EQUAL(n.y, 0, EPSILON);
	CU_ASSERT_DOUBLE_EQUAL(n.z, 1, EPSILON);
}

void    do_tuple_normal_03(void)
{
	t_scene	*scene;
	t_vector	n;

	scene = default_world();
	n = normal_at(scene->objects->content, point_new(sqrt(3) / 3, sqrt(3) / 3, sqrt(3) / 3));
	CU_ASSERT_DOUBLE_EQUAL(n.x, sqrt(3) / 3, EPSILON);
	CU_ASSERT_DOUBLE_EQUAL(n.y, sqrt(3) / 3, EPSILON);
	CU_ASSERT_DOUBLE_EQUAL(n.z, sqrt(3) / 3, EPSILON);
}