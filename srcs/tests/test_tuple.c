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