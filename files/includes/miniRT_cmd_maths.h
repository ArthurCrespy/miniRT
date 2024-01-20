/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT_cmd_maths.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acrespy <acrespy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 12:48:54 by acrespy           #+#    #+#             */
/*   Updated: 2024/01/20 10:17:51 by acrespy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_CMD_MATHS_H
# define MINIRT_CMD_MATHS_H

bool			double_equal(double nb1, double nb2);
bool			double_inf(double nb1, double nb2);
bool			double_sup(double nb1, double nb2);

/* -- */

double			matrix_4_cofactor(t_matrix_4 m, int i, int j);
double			matrix_3_cofactor(t_matrix_3 m, int i, int j);

bool			matrix_4_equal(t_matrix_4 m);

t_matrix_4		matrix_4_new_value(double value);
t_matrix_4		matrix_4_new_identity(void);
t_matrix_4		matrix_4_new(void);
t_matrix_3		matrix_3_new(void);
t_matrix_2		matrix_2_new(void);

double			matrix_4_determinant(t_matrix_4 m);
double			matrix_3_determinant(t_matrix_3 m);
double			matrix_2_determinant(t_matrix_2 m);

bool			matrix_4_invertible(t_matrix_4 m);
bool			matrix_3_invertible(t_matrix_3 m);

t_matrix_4		matrix_4_invert(t_matrix_4 m);
t_matrix_3		matrix_3_invert(t_matrix_3 m);

double			matrix_4_minor(t_matrix_4 m, int i, int j);
double			matrix_3_minor(t_matrix_3 m, int i, int j);

t_matrix_4		matrix_4_mult(t_matrix_4 m1, t_matrix_4 m2);

t_matrix_4		matrix_4_reflection(t_vector v);

t_matrix_4		matrix_4_rotation_x(double angle);
t_matrix_4		matrix_4_rotation_y(double angle);
t_matrix_4		matrix_4_rotation_z(double angle);

t_matrix_4		matrix_4_scale(t_vector v, double scale);
t_matrix_4		matrix_4_unscale(t_vector v, double scale);


t_matrix_4		matrix_4_shearing(t_vector v);

t_matrix_3		matrix_4_sub(t_matrix_4 m, int row, int col);
t_matrix_2		matrix_3_sub(t_matrix_3 m, int row, int col);

t_matrix_4		matrix_4_translation(t_vector v);
t_matrix_4		matrix_4_translation_inv(t_vector v);

t_matrix_4		matrix_4_transpose(t_matrix_4 m);

/* -- */

bool			point_equal(t_point v1, t_point v2);
bool			point_inf(t_point v1, t_point v2);
bool			point_sup(t_point v1, t_point v2);

t_point			point_new(double x, double y, double z);
t_point			point_zero(void);

t_point			point_add(t_point v1, t_point v2);
t_point			point_sub(t_point v1, t_point v2);
t_point			point_mult(t_point v1, t_point v2);
t_point			point_div(t_point v1, t_point v2);
t_point			point_invert(t_point v1);

t_point			point_scale(t_point v1, double scale);
t_point			point_unscale(t_point v1, double scale);

t_point			point_vector_add(t_point p, t_vector v);
t_point			vector_point_add(t_vector v, t_point p);
t_point			point_vector_sub(t_point p, t_vector v);

/* -- */

bool			vect_equal(t_vector v1, t_vector v2);
bool			vect_inf(t_vector v1, t_vector v2);
bool			vect_sup(t_vector v1, t_vector v2);

t_vector		vect_new(double x, double y, double z);
t_vector		vect_zero(void);

t_vector		vec_double_mult(t_vector v, double nb);
t_vector		vec_double_div(t_vector v, double nb);

double			vect_mag(t_vector v1);
double			vect_dot(t_vector v1, t_vector v2);
t_vector		vect_norm(t_vector v1);
t_vector		vect_cross(t_vector v1, t_vector v2);

t_vector		vect_add(t_vector v1, t_vector v2);
t_vector		vect_sub(t_vector v1, t_vector v2);
t_vector		vect_mult(t_vector v1, t_vector v2);
t_vector		vect_div(t_vector v1, t_vector v2);
t_vector		vect_invert(t_vector v1);

t_vector		vect_scale(t_vector v1, double scale);
t_vector		vect_unscale(t_vector v1, double scale);

t_vector		point_point_sub(t_point p1, t_point p2);

#endif
