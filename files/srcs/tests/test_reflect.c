/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_reflect.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkeraudr <dkeraudr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 20:22:06 by dkeraudr          #+#    #+#             */
/*   Updated: 2024/02/21 20:24:30 by dkeraudr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT_test.h"

int	do_reflect_tests(CU_pSuite suite)
{
	suite = CU_add_suite("Reflect", NULL, NULL);
	if (NULL == suite)
		return (CU_cleanup_registry(), CU_get_error());

	if (!CU_add_test(suite, "Reflect 00", do_reflect_00)
		|| !CU_add_test(suite, "Reflect 01", do_reflect_01))
		return (CU_cleanup_registry(), CU_get_error());

	return (0);
}

void	do_reflect_00(void)
{
	t_vector	in;
	t_vector	normal;
	t_vector	reflected;

	in = vector_new(1, -1, 0);
	normal = vector_new(0, 1, 0);
	reflected = reflect(in, normal);
	CU_ASSERT_DOUBLE_EQUAL(reflected.x, 1, 1e-6);
	CU_ASSERT_DOUBLE_EQUAL(reflected.y, 1, 1e-6);
	CU_ASSERT_DOUBLE_EQUAL(reflected.z, 0, 1e-6);
}

void	do_reflect_01(void)
{
	t_vector	in;
	t_vector	normal;
	t_vector	reflected;

	in = vector_new(0, -1, 0);
	normal = vector_new(sqrt(2) / 2, sqrt(2) / 2, 0);
	reflected = reflect(in, normal);
	CU_ASSERT_DOUBLE_EQUAL(reflected.x, 1, 1e-6);
	CU_ASSERT_DOUBLE_EQUAL(reflected.y, 0, 1e-6);
	CU_ASSERT_DOUBLE_EQUAL(reflected.z, 0, 1e-6);
}
