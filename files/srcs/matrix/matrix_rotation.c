/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_rotation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkeraudr <dkeraudr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 14:34:06 by acrespy           #+#    #+#             */
/*   Updated: 2024/03/12 21:41:31 by dkeraudr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_matrix	*matrix_rotation_x(double angle)
{
	t_matrix	*m;

	m = matrix_identity();
	m->matrix[1][1] = cos(angle);
	m->matrix[1][2] = -sin(angle);
	m->matrix[2][1] = sin(angle);
	m->matrix[2][2] = cos(angle);
	return (m);
}

t_matrix	*matrix_rotation_y(double angle)
{
	t_matrix	*m;

	m = matrix_identity();
	m->matrix[0][0] = cos(angle);
	m->matrix[0][2] = sin(angle);
	m->matrix[2][0] = -sin(angle);
	m->matrix[2][2] = cos(angle);
	return (m);
}

t_matrix	*matrix_rotation_z(double angle)
{
	t_matrix	*m;

	m = matrix_identity();
	m->matrix[0][0] = cos(angle);
	m->matrix[0][1] = -sin(angle);
	m->matrix[1][0] = sin(angle);
	m->matrix[1][1] = cos(angle);
	return (m);
}

// return a new matrix with the rotation applied
t_matrix	*matrix_rotation(t_vector orientation)
{
	t_matrix	*rx;
	t_matrix	*ry;
	t_matrix	*rz;
	t_matrix	*tmp;
	t_matrix	*res;
	double		x_angle;
	double		y_angle;
	double		z_angle;


	x_angle = acos(tuple_dot(orientation, vector_new(1, 0, 0)));
	y_angle = acos(tuple_dot(orientation, vector_new(0, 1, 0)));
	z_angle = acos(tuple_dot(orientation, vector_new(0, 0, 1)));
	// x_angle = (M_PI/180) * 15;
	// y_angle = (M_PI/180) * 0;
	// z_angle = (M_PI/180) * 0;
	printf("x_angle = %f\n", x_angle*180/M_PI);
	printf("y_angle = %f\n", y_angle*180/M_PI);
	printf("z_angle = %f\n", z_angle*180/M_PI);
	rx = matrix_rotation_x(x_angle);
	// ft_print_matrix(*rx);
	ry = matrix_rotation_y(y_angle);
	// ft_print_matrix(*ry);
	rz = matrix_rotation_z(z_angle);
	// ft_print_matrix(*rz);
	tmp = matrix_mult(*rx, *ry);
	res = matrix_mult(*tmp, *rz);
	ft_matrix_free(rx);
	ft_matrix_free(ry);
	ft_matrix_free(rz);
	ft_matrix_free(tmp);
	return (res);
}

// t_matrix	*matrix_rotation(t_vector orientation)
// {
// 	t_matrix	*rotation;
// 	t_vector	axis;
// 	double		angle;
// 	double		cos_theta;
// 	double		sin_theta;
// 	double		one_minus_cos_theta;
// 	double		**matrix_values;

// 	orientation = tuple_norm(orientation);
// 	axis = tuple_norm(orientation);
// 	angle = tuple_mag(orientation);
// 	cos_theta = cos(angle);
// 	sin_theta = sin(angle);
// 	one_minus_cos_theta = 1 - cos_theta;
// 	matrix_values = (double *[]) {
// 		(double []) {cos_theta + axis.x * axis.x * one_minus_cos_theta,
// 			axis.x * axis.y * one_minus_cos_theta - axis.z * sin_theta,
// 			axis.x * axis.z * one_minus_cos_theta + axis.y * sin_theta, 0},
// 		(double []) {axis.y * axis.x * one_minus_cos_theta + axis.z * sin_theta,
// 			cos_theta + axis.y * axis.y * one_minus_cos_theta,
// 			axis.y * axis.z * one_minus_cos_theta - axis.x * sin_theta, 0},
// 		(double []) {axis.z * axis.x * one_minus_cos_theta - axis.y * sin_theta,
// 			axis.z * axis.y * one_minus_cos_theta + axis.x * sin_theta,
// 			cos_theta + axis.z * axis.z * one_minus_cos_theta, 0},
// 		(double []) {0, 0, 0, 1}
// 	};
// 	rotation = matrix_new(matrix_values, 4);
// 	return (rotation);
// }