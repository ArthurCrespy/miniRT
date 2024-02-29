/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_tests.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkeraudr <dkeraudr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 16:34:21 by dkeraudr          #+#    #+#             */
/*   Updated: 2024/02/17 19:03:13 by dkeraudr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT_test.h"

int	do_tests(void)
{
	CU_pSuite suite;

	if (CUE_SUCCESS != CU_initialize_registry())
		return CU_get_error();

	// matrix
	suite = CU_add_suite("matrix", NULL, NULL);
	if (NULL == suite)
	{
		CU_cleanup_registry();
		return CU_get_error();
	}

	if (NULL == CU_add_test(suite, "do_matrix_multiplication_00", do_matrix_multiplication_00))
	{
		CU_cleanup_registry();
		return CU_get_error();
	}

	if (NULL == CU_add_test(suite, "do_matrix_transpose", do_matrix_transpose))
	{
		CU_cleanup_registry();
		return CU_get_error();
	}
	
	// matrix_determinant
	suite = CU_add_suite("matrix_determinant", NULL, NULL);
	if (NULL == suite)
	{
		CU_cleanup_registry();
		return CU_get_error();
	}

	if (NULL == CU_add_test(suite, "do_matrix_determinant_00", do_matrix_determinant_00))
	{
		CU_cleanup_registry();
		return CU_get_error();
	}

	if (NULL == CU_add_test(suite, "do_matrix_det_3x3", do_matrix_det_3x3))
	{
		CU_cleanup_registry();
		return CU_get_error();
	}

	if (NULL == CU_add_test(suite, "do_matrix_det_4x4", do_matrix_det_4x4))
	{
		CU_cleanup_registry();
		return CU_get_error();
	}

	// submatrix

	suite = CU_add_suite("submatrix", NULL, NULL);
	if (NULL == suite)
	{
		CU_cleanup_registry();
		return CU_get_error();
	}

	if (NULL == CU_add_test(suite, "do_submatrix_3_2", do_submatrix_3_2))
	{
		CU_cleanup_registry();
		return CU_get_error();
	}

	if (NULL == CU_add_test(suite, "do_submatrix_4_3", do_submatrix_4_3))
	{
		CU_cleanup_registry();
		return CU_get_error();
	}

	// minor
	suite = CU_add_suite("minor", NULL, NULL);
	if (NULL == suite)
	{
		CU_cleanup_registry();
		return CU_get_error();
	}

	if (NULL == CU_add_test(suite, "do_minor_3x3", do_minor_3x3))
	{
		CU_cleanup_registry();
		return CU_get_error();
	}

	// cofactor

	suite = CU_add_suite("cofactor", NULL, NULL);
	if (NULL == suite)
	{
		CU_cleanup_registry();
		return CU_get_error();
	}

	if (NULL == CU_add_test(suite, "do_cofactor_3x3", do_cofactor_3x3))
	{
		CU_cleanup_registry();
		return CU_get_error();
	}

	// inverse_matrix

	suite = CU_add_suite("inverse_matrix", NULL, NULL);
	if (NULL == suite)
	{
		CU_cleanup_registry();
		return CU_get_error();
	}

	if (NULL == CU_add_test(suite, "do_inverse_matrix_4x4", do_inverse_matrix_4x4))
	{
		CU_cleanup_registry();
		return CU_get_error();
	}

	// sphere_intersects
	suite = CU_add_suite("sphere_intersects", NULL, NULL);
	if (NULL == suite)
	{
		CU_cleanup_registry();
		return CU_get_error();
	}

	if (NULL == CU_add_test(suite, "sphere_intersect_00", do_sphere_intersect_00))
	{
		CU_cleanup_registry();
		return CU_get_error();
	}
	
	if (NULL == CU_add_test(suite, "sphere_intersect_01", do_sphere_intersect_01))
	{
		CU_cleanup_registry();
		return CU_get_error();
	}
	
	if (NULL == CU_add_test(suite, "sphere_intersect_02", do_sphere_intersect_02))
	{
		CU_cleanup_registry();
		return CU_get_error();
	}

	// hit
	suite = CU_add_suite("hit", NULL, NULL);
	if (NULL == suite)
	{
		CU_cleanup_registry();
		return CU_get_error();
	}

	if (NULL == CU_add_test(suite, "hit_00", do_hit_00))
	{
		CU_cleanup_registry();
		return CU_get_error();
	}

	if (NULL == CU_add_test(suite, "hit_01", do_hit_01))
	{
		CU_cleanup_registry();
		return CU_get_error();
	}

	if (NULL == CU_add_test(suite, "hit_02", do_hit_02))
	{
		CU_cleanup_registry();
		return CU_get_error();
	}

	if (NULL == CU_add_test(suite, "hit_03", do_hit_03))
	{
		CU_cleanup_registry();
		return CU_get_error();
	}

	if (NULL == CU_add_test(suite, "hit_04", do_hit_04))
	{
		CU_cleanup_registry();
		return CU_get_error();
	}

	// ray_transform
	suite = CU_add_suite("ray_transform", NULL, NULL);
	if (NULL == suite)
	{
		CU_cleanup_registry();
		return CU_get_error();
	}

	if (NULL == CU_add_test(suite, "ray_translate_00", do_ray_translate_00))
	{
		CU_cleanup_registry();
		return CU_get_error();
	}

	if (NULL == CU_add_test(suite, "ray_translate_01", do_ray_translate_01))
	{
		CU_cleanup_registry();
		return CU_get_error();
	}

	if (NULL == CU_add_test(suite, "ray_translate_02", do_ray_translate_02))
	{
		CU_cleanup_registry();
		return CU_get_error();
	}

	if (NULL == CU_add_test(suite, "ray_scaling_00", do_ray_scaling_00))
	{
		CU_cleanup_registry();
		return CU_get_error();
	}

	if (NULL == CU_add_test(suite, "ray_scaling_01", do_ray_scaling_01))
	{
		CU_cleanup_registry();
		return CU_get_error();
	}
	
	CU_basic_set_mode(CU_BRM_VERBOSE);
	CU_basic_run_tests();
	CU_cleanup_registry();

	return CU_get_error();
}
