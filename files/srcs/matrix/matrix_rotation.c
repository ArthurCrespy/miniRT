/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_rotation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkeraudr <dkeraudr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 14:34:06 by acrespy           #+#    #+#             */
/*   Updated: 2024/03/20 21:24:49 by dkeraudr         ###   ########.fr       */
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

void	ft_fill_rotation_matrix(t_matrix *m, double cos_theta, double sin_theta,
	t_matrix *skew_sym)
{
	int	i;
	int	j;

	i = 0;
	while (i < 3)
	{
		j = 0;
		while (j < 3)
		{
			m->matrix[i][j] = cos_theta * m->matrix[i][j]
				+ (1 - cos_theta) * skew_sym->matrix[i][j]
				+ sin_theta * skew_sym->matrix[i][j];
			j++;
		}
		i++;
	}
}

t_matrix	*matrix_rotation(t_vector axis)
{
	double		angle;
	t_matrix	*res;
	double		cos_theta;
	double		sin_theta;
	t_matrix	*skew_sym;

	axis = tuple_norm(axis);
	skew_sym = matrix_skew_sym(axis);
	angle = acos(tuple_dot(axis, vector_new(0, 1, 0)));
	sin_theta = sin(angle);
	cos_theta = cos(angle);
	res = matrix_identity();
	ft_fill_rotation_matrix(res, cos_theta, sin_theta, skew_sym);
	free(skew_sym);
	return (res);
}
