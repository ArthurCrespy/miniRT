/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT_cmd_maths.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkeraudr <dkeraudr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 12:48:54 by acrespy           #+#    #+#             */
/*   Updated: 2024/02/18 16:28:39 by dkeraudr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_CMD_MATHS_H
# define MINIRT_CMD_MATHS_H

/* -- */

t_color			color_new(double r, double g, double b);

t_color			color_add(t_color c1, t_color c2);
t_color			color_sub(t_color c1, t_color c2);
t_color			color_mult(t_color c1, t_color c2);
t_color			color_scalar(t_color c, double scalar);

/* -- */

bool			double_equal(double nb1, double nb2);
bool			double_inf(double nb1, double nb2);
bool			double_sup(double nb1, double nb2);

/* -- */

double			matrix_cofactor(t_matrix m, int row, int col);

bool			matrix_compare(t_matrix m1, t_matrix m2);

t_matrix		*matrix_new(double **m, int size);
t_matrix		*matrix_identity(void);

double			matrix_determinant(t_matrix m);

bool			matrix_invertible(t_matrix m);
t_matrix		*matrix_inverse(t_matrix m);

double			matrix_minor(t_matrix m, int row, int col);

t_matrix		*matrix_mult(t_matrix m1, t_matrix m2);
t_tuple			matrix_tuple_mult(t_matrix m, t_tuple t);

t_matrix		*matrix_rotation_x(double angle);
t_matrix		*matrix_rotation_y(double angle);
t_matrix		*matrix_rotation_z(double angle);

t_matrix		*matrix_translation(double x, double y, double z);
t_matrix		*matrix_rotation(t_vector v);
t_matrix		*matrix_scale(double x, double y, double z);
void			ft_matrix_transform(t_matrix *matrix, t_matrix *transform);

t_matrix		matrix_submatrix(t_matrix m, int row, int col);


t_matrix		matrix_transpose(t_matrix m);

/* -- */

t_ray			ray_new(t_point origin, t_vector direction);
t_ray			ray_transform(t_ray ray, t_matrix m);

t_point			ray_position(t_ray ray, double t);

/* -- */

t_matrix		*matrix_shearing(t_shearing x, t_shearing y, t_shearing z);

/* -- */

t_tuple			tuple_new(double x, double y, double z, double w);
t_tuple			point_new(double x, double y, double z);
t_tuple			vector_new(double x, double y, double z);

bool			tuple_equal(t_tuple t1, t_tuple t2);
bool			tuple_inf(t_tuple t1, t_tuple t2);
bool			tuple_sup(t_tuple t1, t_tuple t2);

t_tuple			tuple_add(t_tuple t1, t_tuple t2);
t_tuple			tuple_sub(t_tuple t1, t_tuple t2);
t_tuple			tuple_mult(t_tuple t1, double nb);
t_tuple			tuple_div(t_tuple t1, t_tuple t2);
t_tuple			tuple_negate(t_tuple t1);

double			tuple_mag(t_tuple t1);
t_tuple			tuple_norm(t_tuple t1);
double			tuple_dot(t_tuple t1, t_tuple t2);
t_tuple			tuple_cross(t_tuple t1, t_tuple t2);
t_tuple			tuple_reflect(t_tuple t, t_tuple normal);

t_tuple	tuple_transform(t_tuple tuple, t_matrix matrix);
t_tuple	tuple_normalize(t_tuple tuple);

#endif
