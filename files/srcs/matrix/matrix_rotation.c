/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_rotation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkeraudr <dkeraudr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 14:34:06 by acrespy           #+#    #+#             */
/*   Updated: 2024/03/05 18:26:17 by dkeraudr         ###   ########.fr       */
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
t_matrix	*matrix_rotation(t_vector v)
{
	t_matrix	*rx;
	t_matrix	*ry;
	t_matrix	*rz;
	t_matrix	*tmp;
	t_matrix	*res;

	rx = matrix_rotation_x(v.x);
	//ft_print_matrix(*rx);
	ry = matrix_rotation_y(v.y);
	//ft_print_matrix(*ry);
	rz = matrix_rotation_z(v.z);
	//ft_print_matrix(*rz);
	tmp = matrix_mult(*rx, *ry);
	res = matrix_mult(*tmp, *rz);
	ft_matrix_free(rx);
	ft_matrix_free(ry);
	ft_matrix_free(rz);
	ft_matrix_free(tmp);
	return (res);
}
