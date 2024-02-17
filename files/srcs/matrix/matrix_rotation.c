/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_rotation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkeraudr <dkeraudr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 14:34:06 by acrespy           #+#    #+#             */
/*   Updated: 2024/02/17 15:16:05 by dkeraudr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../includes/miniRT.h"

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

t_matrix	*matrix_rotation(t_matrix *m, t_vector v)
{
	t_matrix	*mx;
	t_matrix	*my;
	t_matrix	*mz;
	t_matrix	*matrix_temp;

	mx = matrix_rotation_x(v.x);
	my = matrix_rotation_y(v.y);
	mz = matrix_rotation_z(v.z);
	matrix_temp = matrix_mult(*mx, *my);
	free(m);
	m = matrix_mult(*matrix_temp, *mz);
	free(matrix_temp);
	free(mx);
	free(my);
	free(mz);
	return (m);
}
