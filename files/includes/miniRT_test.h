/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT_test.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkeraudr <dkeraudr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 19:33:55 by dkeraudr          #+#    #+#             */
/*   Updated: 2024/02/17 19:02:58 by dkeraudr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_TEST_H
# define MINIRT_TEST_H

# include <CUnit/CUnit.h>
# include <CUnit/Basic.h>
# include "miniRT.h"

void	do_sphere_intersect_00(void);
void	do_sphere_intersect_01(void);
void	do_sphere_intersect_02(void);

void	do_hit_00(void);
void	do_hit_01(void);
void	do_hit_02(void);
void	do_hit_03(void);
void	do_hit_04(void);

void	do_ray_translate_00(void);
void	do_ray_translate_01(void);
void	do_ray_translate_02(void);
void	do_ray_scaling_00(void);
void	do_ray_scaling_01(void);

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

#endif