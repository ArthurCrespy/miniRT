/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT_test.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkeraudr <dkeraudr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 19:33:55 by dkeraudr          #+#    #+#             */
/*   Updated: 2024/03/09 16:45:37 by dkeraudr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_TEST_H
# define MINIRT_TEST_H

# include <CUnit/CUnit.h>
# include <CUnit/Basic.h>
# include "miniRT.h"

t_scene			*default_world(void);
t_computation	prepare_computations(t_intersection *intersection, t_ray ray);
t_intersection	*create_intersect(double t, t_hittable *obj);

int		do_sphere_intersect_tests(CU_pSuite suite);
void	do_sphere_intersect_00(void);
void	do_sphere_intersect_01(void);
void	do_sphere_intersect_02(void);

int		do_hit_tests(CU_pSuite suite);
void	do_hit_00(void);
void	do_hit_01(void);
void	do_hit_02(void);
void	do_hit_03(void);
void	do_hit_04(void);

int		do_transform_tests(CU_pSuite suite);
void	do_ray_translate_00(void);
void	do_ray_translate_01(void);
void	do_ray_translate_02(void);
void	do_ray_scaling_00(void);
void	do_ray_scaling_01(void);

int		do_matrix_tests(CU_pSuite suite);
void	do_matrix_multiplication_00(void);
void	do_matrix_transpose(void);
void	do_matrix_determinant_00(void);
void	do_submatrix_3_2(void);
void	do_submatrix_4_3(void);
void	do_minor_3x3(void);
void	do_cofactor_3x3(void);
void	do_matrix_det_3x3(void);
void	do_matrix_det_4x4(void);
void	do_inverse_matrix_4x4(void);

int		do_sphere_normal_tests(CU_pSuite suite);
void	do_sphere_normal_00(void);
void	do_sphere_normal_01(void);
void	do_sphere_normal_02(void);
void	do_sphere_normal_03(void);
void	do_sphere_normal_04(void);
void	do_sphere_normal_05(void);

int		do_reflect_tests(CU_pSuite suite);
void	do_reflect_00(void);
void	do_reflect_01(void);

int		do_lighting_tests(CU_pSuite suite);
void	do_lighting_00(void);
void	do_lighting_01(void);
void	do_lighting_02(void);

int		do_precompute_intersections_tests(CU_pSuite suite);
void	test_precompute_intersections_00(void);
void	test_precompute_intersections_01(void);
void	test_precompute_intersections_02(void);

int		do_shading_tests(CU_pSuite suite);
void	test_shading_00(void);

int		do_shadows_tests(CU_pSuite suite);
void	test_shadows_00(void);
void	test_shadows_01(void);
void	test_shadows_02(void);
void	test_shadows_03(void);

int		do_tuple_tests(CU_pSuite suite);
void	do_tuple_mag_00(void);
void	do_tuple_mag_01(void);
void	do_tuple_mag_02(void);
void	do_tuple_mag_03(void);

void	do_tuple_norm_00(void);
void	do_tuple_norm_01(void);
void	do_tuple_norm_02(void);

#endif