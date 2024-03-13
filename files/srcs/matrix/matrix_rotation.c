/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_rotation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkeraudr <dkeraudr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 14:34:06 by acrespy           #+#    #+#             */
/*   Updated: 2024/03/13 19:57:11 by dkeraudr         ###   ########.fr       */
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

// // return a new matrix with the rotation applied
// t_matrix	*matrix_rotation(t_vector orientation)
// {
// 	t_matrix	*rx;
// 	t_matrix	*ry;
// 	t_matrix	*rz;
// 	t_matrix	*tmp;
// 	t_matrix	*res;
// 	double		x_angle;
// 	double		y_angle;
// 	double		z_angle;


// 	x_angle = acos(tuple_dot(orientation, vector_new(1, 0, 0)));
// 	y_angle = acos(tuple_dot(orientation, vector_new(0, -1, 0)));
// 	z_angle = acos(tuple_dot(orientation, vector_new(0, 0, 1)));
// 	// x_angle = (M_PI/180) * 15;
// 	// y_angle = (M_PI/180) * 0;
// 	// z_angle = (M_PI/180) * 0;
// 	printf("x_angle = %f\n", x_angle*180/M_PI);
// 	printf("y_angle = %f\n", y_angle*180/M_PI);
// 	printf("z_angle = %f\n", z_angle*180/M_PI);
// 	rx = matrix_rotation_x(x_angle);
// 	// ft_print_matrix(*rx);
// 	ry = matrix_rotation_y(y_angle);
// 	// ft_print_matrix(*ry);
// 	rz = matrix_rotation_z(z_angle);
// 	// ft_print_matrix(*rz);
// 	tmp = matrix_mult(*rx, *ry);
// 	res = matrix_mult(*tmp, *rz);
// 	ft_matrix_free(rx);
// 	ft_matrix_free(ry);
// 	ft_matrix_free(rz);
// 	ft_matrix_free(tmp);
// 	return (res);
// }

t_matrix	*matrix_from_euler(double x, double y, double z)
{
	t_matrix	*rx;
	t_matrix	*ry;
	t_matrix	*rz;
	t_matrix	*tmp;
	t_matrix	*res;

	rx = matrix_rotation_x(x);
	ry = matrix_rotation_y(y);
	rz = matrix_rotation_z(z);
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
// 	double		yaw;
// 	double		pitch;
// 	double		roll;

// 	orientation = tuple_norm(orientation);
// 	pitch = atan2(orientation.y, sqrt(orientation.x * orientation.x + orientation.z * orientation.z));

// 	yaw = atan2(orientation.x, orientation.z);
	
// 	roll = atan2(orientation.y, orientation.z);

// 	// roll = 0.0;
// 	printf("x_angle = %f\n", pitch*180/M_PI);
// 	printf("y_angle = %f\n", yaw*180/M_PI);
// 	printf("z_angle = %f\n", roll*180/M_PI);
// 	return (matrix_from_euler(pitch, yaw, roll));
// }

t_matrix	*matrix_skew_sym(t_vector axis)
{
	t_matrix	*res;

	res = matrix_identity();
	res->matrix[0][0] = 0;
	res->matrix[0][1] = -axis.z;
	res->matrix[0][2] = axis.y;
	res->matrix[1][0] = axis.z;
	res->matrix[1][1] = 0;
	res->matrix[1][2] = -axis.x;
	res->matrix[2][0] = -axis.y;
	res->matrix[2][1] = axis.x;
	res->matrix[2][2] = 0;
	return (res);
}

t_matrix	*matrix_rotation(t_vector axis)
{
	double		dot;
	double		angle;
	t_matrix	*res;
	double		cos_theta;
	double		sin_theta;
	t_matrix	*skew_sym;
	t_matrix	*identity;
	int			i;
	int			j;

	axis = tuple_norm(axis);
	skew_sym = matrix_skew_sym(axis);
	dot = tuple_dot(axis, vector_new(0, 1, 0));
	angle = acos(dot);
	sin_theta = sin(angle);
	cos_theta = cos(angle);
	res = matrix_identity();
	identity = matrix_identity();
	i=0;
	while (i < 3)
	{
		j = 0;
		while (j < 3)
		{
			res->matrix[i][j] = cos_theta * identity->matrix[i][j] + (1 - cos_theta) * skew_sym->matrix[i][j] + sin_theta * skew_sym->matrix[i][j];
			j++;
		}
		i++;
	}
	ft_matrix_free(skew_sym);
	ft_matrix_free(identity);
	return (res);
}