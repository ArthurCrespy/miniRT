/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_matrix.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkeraudr <dkeraudr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 18:32:34 by dkeraudr          #+#    #+#             */
/*   Updated: 2024/03/09 16:08:36 by dkeraudr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT_test.h"

int	do_matrix_tests(CU_pSuite suite)
{
	// matrix
	suite = CU_add_suite("Matrix", NULL, NULL);
	if (suite == NULL)
		return (CU_cleanup_registry(), CU_get_error());


	if (!CU_add_test(suite, "Matrix multiplication 00", do_matrix_multiplication_00))
		return (CU_cleanup_registry(), CU_get_error());

	if (!CU_add_test(suite, "Matrix transpose 00", do_matrix_transpose))
		return (CU_cleanup_registry(), CU_get_error());

	// matrix_determinant
	if (!CU_add_test(suite, "Matrix determinant 2x2 00", do_matrix_determinant_00))
		return (CU_cleanup_registry(), CU_get_error());

	if (!CU_add_test(suite, "Matrix determinant 3x3 00", do_matrix_det_3x3))
		return (CU_cleanup_registry(), CU_get_error());

	if (!CU_add_test(suite, "Matrix determinant 4x4 00", do_matrix_det_4x4))
		return (CU_cleanup_registry(), CU_get_error());

	// submatrix

	if (!CU_add_test(suite, "Matrix submatix 3>2", do_submatrix_3_2))
		return (CU_cleanup_registry(), CU_get_error());

	if (!CU_add_test(suite, "Matrix submatrix 4>3", do_submatrix_4_3))
		return (CU_cleanup_registry(), CU_get_error());

	// minor
	if (!CU_add_test(suite, "Matrix minor 3x3", do_minor_3x3))
		return (CU_cleanup_registry(), CU_get_error());

	// cofactor
	if (!CU_add_test(suite, "Matrix cofactor 3x3", do_cofactor_3x3))
		return (CU_cleanup_registry(), CU_get_error());

	// inverse_matrix
	if (!CU_add_test(suite, "Matrix inverse 4x4", do_inverse_matrix_4x4))
		return (CU_cleanup_registry(), CU_get_error());

	return (0);
}

void	do_matrix_multiplication_00(void)
{
	t_matrix	*m1;
	double **m1_values;
	t_matrix	*m2;
	double **m2_values;
	t_matrix	*res;

	// | 1 | 2 | 3 | 4 |
	// | 5 | 6 | 7 | 8 |
	// | 9 | 8 | 7 | 6 |
	// | 5 | 4 | 3 | 2 | = m1;

	// | -2 | 1 | 2 | 3 |
	// | 3 | 2 | 1 | -1 |
	// | 4 | 3 | 6 | 5 |
	// | 1 | 2 | 7 | 8 |
	m1_values = (double *[]){(double[]){1, 2, 3, 4}, (double[]){5, 6, 7, 8}, (double[]){9, 8, 7, 6}, (double[]){5, 4, 3, 2}};
	m1 = matrix_new(m1_values, 4);
	m2_values = (double *[]){(double[]){-2, 1, 2, 3}, (double[]){3, 2, 1, -1}, (double[]){4, 3, 6, 5}, (double[]){1, 2, 7, 8}};
	m2 = matrix_new(m2_values, 4);
	res = matrix_mult(*m1, *m2);
	CU_ASSERT_DOUBLE_EQUAL(res->matrix[0][0], 20, 1e-6);
	CU_ASSERT_DOUBLE_EQUAL(res->matrix[0][1], 22, 1e-6);
	CU_ASSERT_DOUBLE_EQUAL(res->matrix[0][2], 50, 1e-6);
	CU_ASSERT_DOUBLE_EQUAL(res->matrix[0][3], 48, 1e-6);
	CU_ASSERT_DOUBLE_EQUAL(res->matrix[1][0], 44, 1e-6);
	CU_ASSERT_DOUBLE_EQUAL(res->matrix[1][1], 54, 1e-6);
	CU_ASSERT_DOUBLE_EQUAL(res->matrix[1][2], 114, 1e-6);
	CU_ASSERT_DOUBLE_EQUAL(res->matrix[1][3], 108, 1e-6);
	CU_ASSERT_DOUBLE_EQUAL(res->matrix[2][0], 40, 1e-6);
	CU_ASSERT_DOUBLE_EQUAL(res->matrix[2][1], 58, 1e-6);
	CU_ASSERT_DOUBLE_EQUAL(res->matrix[2][2], 110, 1e-6);
	CU_ASSERT_DOUBLE_EQUAL(res->matrix[2][3], 102, 1e-6);
	CU_ASSERT_DOUBLE_EQUAL(res->matrix[3][0], 16, 1e-6);
	CU_ASSERT_DOUBLE_EQUAL(res->matrix[3][1], 26, 1e-6);
	CU_ASSERT_DOUBLE_EQUAL(res->matrix[3][2], 46, 1e-6);
	CU_ASSERT_DOUBLE_EQUAL(res->matrix[3][3], 42, 1e-6);
}

void	do_matrix_transpose(void)
{
	t_matrix	*m1;
	double **m1_values;
	t_matrix	res;

	// | 0 | 9 | 3 | 0 |
	// | 9 | 8 | 0 | 8 |
	// | 1 | 8 | 5 | 3 |
	// | 0 | 0 | 5 | 8 | = m1;

	m1_values = (double *[]){(double[]){0, 9, 3, 0}, (double[]){9, 8, 0, 8}, (double[]){1, 8, 5, 3}, (double[]){0, 0, 5, 8}};
	m1 = matrix_new(m1_values, 4);
	res = matrix_transpose(*m1);
	CU_ASSERT_DOUBLE_EQUAL(res.matrix[0][0], 0, 1e-6);
	CU_ASSERT_DOUBLE_EQUAL(res.matrix[0][1], 9, 1e-6);
	CU_ASSERT_DOUBLE_EQUAL(res.matrix[0][2], 1, 1e-6);
	CU_ASSERT_DOUBLE_EQUAL(res.matrix[0][3], 0, 1e-6);
	CU_ASSERT_DOUBLE_EQUAL(res.matrix[1][0], 9, 1e-6);
	CU_ASSERT_DOUBLE_EQUAL(res.matrix[1][1], 8, 1e-6);
	CU_ASSERT_DOUBLE_EQUAL(res.matrix[1][2], 8, 1e-6);
	CU_ASSERT_DOUBLE_EQUAL(res.matrix[1][3], 0, 1e-6);
	CU_ASSERT_DOUBLE_EQUAL(res.matrix[2][0], 3, 1e-6);
	CU_ASSERT_DOUBLE_EQUAL(res.matrix[2][1], 0, 1e-6);
	CU_ASSERT_DOUBLE_EQUAL(res.matrix[2][2], 5, 1e-6);
	CU_ASSERT_DOUBLE_EQUAL(res.matrix[2][3], 5, 1e-6);
	CU_ASSERT_DOUBLE_EQUAL(res.matrix[3][0], 0, 1e-6);
	CU_ASSERT_DOUBLE_EQUAL(res.matrix[3][1], 0, 1e-6);
	CU_ASSERT_DOUBLE_EQUAL(res.matrix[3][2], 0, 1e-6);
	CU_ASSERT_DOUBLE_EQUAL(res.matrix[3][3], 1, 1e-6);
}

void	do_matrix_determinant_00(void)
{
	t_matrix	*m1;
	double **m1_values;
	double		res;

	// | 1 | 5 |
	// | -3 | 2 | = m1;
	m1_values = (double *[]){(double[]){1, 5}, (double[]){-3, 2}};
	m1 = matrix_new(m1_values, 2);
	res = matrix_determinant(*m1);
	CU_ASSERT_DOUBLE_EQUAL(res, 17, 1e-6);
}

void	do_submatrix_3_2(void)
{
	t_matrix	*m1;
	double **m1_values;
	t_matrix	res;

	// | 1 | 5 | 0 |
	// | -3 | 2 | 7 |
	// | 0 | 6 | -3 | = m1;
	m1_values = (double *[]){(double[]){1, 5, 0}, (double[]){-3, 2, 7}, (double[]){0, 6, -3}};
	m1 = matrix_new(m1_values, 3);
	res = matrix_submatrix(*m1, 0, 2);
	CU_ASSERT_DOUBLE_EQUAL(res.matrix[0][0], -3, 1e-6);
	CU_ASSERT_DOUBLE_EQUAL(res.matrix[0][1], 2, 1e-6);
	CU_ASSERT_DOUBLE_EQUAL(res.matrix[1][0], 0, 1e-6);
	CU_ASSERT_DOUBLE_EQUAL(res.matrix[1][1], 6, 1e-6);
}

void	do_submatrix_4_3(void)
{
	t_matrix	*m1;
	double **m1_values;
	t_matrix	res;

	// | -6 | 1 | 1 | 6 |
	// | -8 | 5 | 8 | 6 |
	// | -1 | 0 | 8 | 2 |
	// | -7 | 1 | -1 | 1 | = m1;
	m1_values = (double *[]){(double[]){-6, 1, 1, 6}, (double[]){-8, 5, 8, 6}, (double[]){-1, 0, 8, 2}, (double[]){-7, 1, -1, 1}};
	m1 = matrix_new(m1_values, 4);
	res = matrix_submatrix(*m1, 2, 1);
	CU_ASSERT_DOUBLE_EQUAL(res.matrix[0][0], -6, 1e-6);
	CU_ASSERT_DOUBLE_EQUAL(res.matrix[0][1], 1, 1e-6);
	CU_ASSERT_DOUBLE_EQUAL(res.matrix[0][2], 6, 1e-6);
	CU_ASSERT_DOUBLE_EQUAL(res.matrix[1][0], -8, 1e-6);
	CU_ASSERT_DOUBLE_EQUAL(res.matrix[1][1], 8, 1e-6);
	CU_ASSERT_DOUBLE_EQUAL(res.matrix[1][2], 6, 1e-6);
	CU_ASSERT_DOUBLE_EQUAL(res.matrix[2][0], -7, 1e-6);
	CU_ASSERT_DOUBLE_EQUAL(res.matrix[2][1], -1, 1e-6);
	CU_ASSERT_DOUBLE_EQUAL(res.matrix[2][2], 1, 1e-6);
}

void	do_minor_3x3(void)
{
	t_matrix	*m1;
	t_matrix	sub_m1;
	double **m1_values;
	double		sub_m1_det;
	double		minor_m1;

	// | 3 | 5 | 0 |
	// | 2 | -1 | -7 |
	// | 6 | -1 | 5 | = m1;
	m1_values = (double *[]){(double[]){3, 5, 0}, (double[]){2, -1, -7}, (double[]){6, -1, 5}};
	m1 = matrix_new(m1_values, 3);
	sub_m1 = matrix_submatrix(*m1, 1, 0);
	sub_m1_det = matrix_determinant(sub_m1);
	minor_m1 = matrix_minor(*m1, 1, 0);
	CU_ASSERT_DOUBLE_EQUAL(sub_m1_det, 25, 1e-6);
	CU_ASSERT_DOUBLE_EQUAL(minor_m1, 25, 1e-6);
}

void	do_cofactor_3x3(void)
{
	t_matrix	*m1;
	double **m1_values;
	double		cofactor_m1;
	double	minor_m1;
	double	cofactor_m1_2;
	double	minor_m1_2;

	// | 3 | 5 | 0 |
	// | 2 | -1 | -7 |
	// | 6 | -1 | 5 | = m1;
	m1_values = (double *[]){(double[]){3, 5, 0}, (double[]){2, -1, -7}, (double[]){6, -1, 5}};
	m1 = matrix_new(m1_values, 3);
	cofactor_m1 = matrix_cofactor(*m1, 0, 0);
	minor_m1 = matrix_minor(*m1, 0, 0);
	cofactor_m1_2 = matrix_cofactor(*m1, 1, 0);
	minor_m1_2 = matrix_minor(*m1, 1, 0);
	CU_ASSERT_DOUBLE_EQUAL(cofactor_m1, -12, 1e-6);
	CU_ASSERT_DOUBLE_EQUAL(minor_m1, -12, 1e-6);
	CU_ASSERT_DOUBLE_EQUAL(cofactor_m1_2, -25, 1e-6);
	CU_ASSERT_DOUBLE_EQUAL(minor_m1_2, 25, 1e-6);
}

void	do_matrix_det_3x3(void)
{
	t_matrix	*m1;
	double **m1_values;
	double		det_m1;
	double	cofactor_m1;
	double	cofactor_m1_2;
	double	cofactor_m1_3;

	// | 1 | 2 | 6 |
	// | -5 | 8 | -4 |
	// | 2 | 6 | 4 | = m1;
	m1_values = (double *[]){(double[]){1, 2, 6}, (double[]){-5, 8, -4}, (double[]){2, 6, 4}};
	m1 = matrix_new(m1_values, 3);
	det_m1 = matrix_determinant(*m1);
	cofactor_m1 = matrix_cofactor(*m1, 0, 0);
	cofactor_m1_2 = matrix_cofactor(*m1, 0, 1);
	cofactor_m1_3 = matrix_cofactor(*m1, 0, 2);
	CU_ASSERT_DOUBLE_EQUAL(det_m1, -196, 1e-6);
	CU_ASSERT_DOUBLE_EQUAL(cofactor_m1, 56, 1e-6);
	CU_ASSERT_DOUBLE_EQUAL(cofactor_m1_2, 12, 1e-6);
	CU_ASSERT_DOUBLE_EQUAL(cofactor_m1_3, -46, 1e-6);
}

void	do_matrix_det_4x4(void)
{
	t_matrix	*m1;
	double **m1_values;
	double		det_m1;
	double	cofactor_m1;
	double	cofactor_m1_2;
	double	cofactor_m1_3;
	double	cofactor_m1_4;

	// | -2 | -8 | 3 | 5 |
	// | -3 | 1 | 7 | 3 |
	// | 1 | 2 | -9 | 6 |
	// | -6 | 7 | 7 | -9 | = m1;
	m1_values = (double *[]){(double[]){-2, -8, 3, 5}, (double[]){-3, 1, 7, 3}, (double[]){1, 2, -9, 6}, (double[]){-6, 7, 7, -9}};
	m1 = matrix_new(m1_values, 4);
	det_m1 = matrix_determinant(*m1);
	cofactor_m1 = matrix_cofactor(*m1, 0, 0);
	cofactor_m1_2 = matrix_cofactor(*m1, 0, 1);
	cofactor_m1_3 = matrix_cofactor(*m1, 0, 2);
	cofactor_m1_4 = matrix_cofactor(*m1, 0, 3);
	CU_ASSERT_DOUBLE_EQUAL(det_m1, -4071, 1e-6);
	CU_ASSERT_DOUBLE_EQUAL(cofactor_m1, 690, 1e-6);
	CU_ASSERT_DOUBLE_EQUAL(cofactor_m1_2, 447, 1e-6);
	CU_ASSERT_DOUBLE_EQUAL(cofactor_m1_3, 210, 1e-6);
	CU_ASSERT_DOUBLE_EQUAL(cofactor_m1_4, 51, 1e-6);
}

void	do_inverse_matrix_4x4(void)
{
	t_matrix	*m1;
	double **m1_values;
	t_matrix	*inverse_m1;
	double		det_m1;
	double	cofactor_m1;
	double	cofactor_m1_2;

	// | -5 | 2 | 6 | -8 |
	// | 1 | -5 | 1 | 8 |
	// | 7 | 7 | -6 | -7 |
	// | 1 | -3 | 7 | 4 | = m1;
	m1_values = (double *[]){(double[]){-5, 2, 6, -8}, (double[]){1, -5, 1, 8}, (double[]){7, 7, -6, -7}, (double[]){1, -3, 7, 4}};
	m1 = matrix_new(m1_values, 4);
	det_m1 = matrix_determinant(*m1);
	inverse_m1 = matrix_inverse(*m1);
	cofactor_m1 = matrix_cofactor(*m1, 2, 3);
	cofactor_m1_2 = matrix_cofactor(*m1, 3, 2);
	CU_ASSERT_DOUBLE_EQUAL(det_m1, 532, 1e-6);
	CU_ASSERT_DOUBLE_EQUAL(cofactor_m1, -160, 1e-6);
	CU_ASSERT_DOUBLE_EQUAL(cofactor_m1_2, 105, 1e-6);
	CU_ASSERT_DOUBLE_EQUAL(inverse_m1->matrix[0][0], 0.21805, EPSILON);
	CU_ASSERT_DOUBLE_EQUAL(inverse_m1->matrix[0][1], 0.45113, EPSILON);
	CU_ASSERT_DOUBLE_EQUAL(inverse_m1->matrix[0][2], 0.24060, EPSILON);
	CU_ASSERT_DOUBLE_EQUAL(inverse_m1->matrix[0][3], -0.04511, EPSILON);
	CU_ASSERT_DOUBLE_EQUAL(inverse_m1->matrix[1][0], -0.80827, EPSILON);
	CU_ASSERT_DOUBLE_EQUAL(inverse_m1->matrix[1][1], -1.45677, EPSILON);
	CU_ASSERT_DOUBLE_EQUAL(inverse_m1->matrix[1][2], -0.44361, EPSILON);
	CU_ASSERT_DOUBLE_EQUAL(inverse_m1->matrix[1][3], 0.52068, EPSILON);
	CU_ASSERT_DOUBLE_EQUAL(inverse_m1->matrix[2][0], -0.07895, EPSILON);
	CU_ASSERT_DOUBLE_EQUAL(inverse_m1->matrix[2][1], -0.22368, EPSILON);
	CU_ASSERT_DOUBLE_EQUAL(inverse_m1->matrix[2][2], -0.05263, EPSILON);
	CU_ASSERT_DOUBLE_EQUAL(inverse_m1->matrix[2][3], 0.19737, EPSILON);
	CU_ASSERT_DOUBLE_EQUAL(inverse_m1->matrix[3][0], -0.52256, EPSILON);
	CU_ASSERT_DOUBLE_EQUAL(inverse_m1->matrix[3][1], -0.81391, EPSILON);
	CU_ASSERT_DOUBLE_EQUAL(inverse_m1->matrix[3][2], -0.30075, EPSILON);
	CU_ASSERT_DOUBLE_EQUAL(inverse_m1->matrix[3][3], 0.30639, EPSILON);
}

void    do_matrix_cofactor_4x4(void)
{
	t_matrix	*m1;
	double **m1_values;
	double	cofactor_m1;
	double	cofactor_m1_2;

	// | -5 | 2 | 6 | -8 |
	// | 1 | -5 | 1 | 8 |
	// | 7 | 7 | -6 | -7 |
	// | 1 | -3 | 7 | 4 | = m1;
	m1_values = (double *[]){(double[]){-5, 2, 6, -8}, (double[]){1, -5, 1, 8}, (double[]){7, 7, -6, -7}, (double[]){1, -3, 7, 4}};
	m1 = matrix_new(m1_values, 4);
	cofactor_m1 = matrix_cofactor(*m1, 2, 3);
	cofactor_m1_2 = matrix_cofactor(*m1, 3, 2);
	CU_ASSERT_DOUBLE_EQUAL(cofactor_m1, -160, 1e-6);
	CU_ASSERT_DOUBLE_EQUAL(cofactor_m1_2, 105, 1e-6);
}

void    do_matrix_identity_4x4(void)
{
	t_matrix	*id;

	// | 1 | 0 | 0 | 0 |
	// | 0 | 1 | 0 | 0 |
	// | 0 | 0 | 1 | 0 |
	// | 0 | 0 | 0 | 1 | = id;
	id = matrix_identity();
	CU_ASSERT_DOUBLE_EQUAL(id->matrix[0][0], 1, EPSILON);
	CU_ASSERT_DOUBLE_EQUAL(id->matrix[1][1], 1, EPSILON);
	CU_ASSERT_DOUBLE_EQUAL(id->matrix[2][2], 1, EPSILON);
	CU_ASSERT_DOUBLE_EQUAL(id->matrix[3][3], 1, EPSILON);
}

void    do_matrix_translation_4x4(void)
{
	t_matrix	*translation;

	// | 1 | 0 | 0 | 5 |
	// | 0 | 1 | 0 | -3 |
	// | 0 | 0 | 1 | 2 |
	// | 0 | 0 | 0 | 1 | = translation;
	translation = matrix_translation(5, -3, 2);
	CU_ASSERT_DOUBLE_EQUAL(translation->matrix[0][3], 5, EPSILON);
	CU_ASSERT_DOUBLE_EQUAL(translation->matrix[1][3], -3, EPSILON);
	CU_ASSERT_DOUBLE_EQUAL(translation->matrix[2][3], 2, EPSILON);
	CU_ASSERT_DOUBLE_EQUAL(translation->matrix[3][3], 1, EPSILON);
}

void    do_matrix_scaling_4x4(void)
{
	t_matrix	*scaling;

	// | 4 | 0 | 0 | 0 |
	// | 0 | 9 | 0 | 0 |
	// | 0 | 0 | 2 | 0 |
	// | 0 | 0 | 0 | 1 | = scaling;
	scaling = matrix_scale(4, 9, 2);
	CU_ASSERT_DOUBLE_EQUAL(scaling->matrix[0][0], 4, EPSILON);
	CU_ASSERT_DOUBLE_EQUAL(scaling->matrix[1][1], 0, EPSILON);
	CU_ASSERT_DOUBLE_EQUAL(scaling->matrix[2][2], 0, EPSILON);
	CU_ASSERT_DOUBLE_EQUAL(scaling->matrix[3][3], 1, EPSILON);
}