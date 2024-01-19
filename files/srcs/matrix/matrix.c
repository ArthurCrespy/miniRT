/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acrespy <acrespy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 14:19:19 by acrespy           #+#    #+#             */
/*   Updated: 2024/01/19 14:19:19 by acrespy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../includes/miniRT.h"

t_matrix_4		matrix_new(void)
{
	int i;
	int j;
	t_matrix_4 m;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
			m.m[i][j++] = 0;
		i++;
	}
	return (m);
}

t_matrix_4		matrix_identity(void)
{
	t_matrix_4 m;

	m = matrix_new();
	m.m[0][0] = 1;
	m.m[1][1] = 1;
	m.m[2][2] = 1;
	m.m[3][3] = 1;
	return (m);
}

t_matrix_4		matrix_mult(t_matrix_4 m1, t_matrix_4 m2)
{
	t_matrix_4	m;
	int			row;
	int			col;

	m = matrix_new();
	row = 0;
	while (row < 4)
	{
		col = 0;
		while (col < 4)
		{
			m.m[row][col] = m1.m[row][0] * m2.m[0][col] +
			                m1.m[row][1] * m2.m[1][col] +
			                m1.m[row][2] * m2.m[2][col] +
					m1.m[row][3] * m2.m[3][col];
			col++;
		}
		row++;
	}
}

t_matrix_4		matrix_transpose(t_matrix_4 m)
{
	t_matrix_4	mt;
	int			row;
	int			col;

	mt = matrix_new();
	row = 0;
	while (row < 4)
	{
		col = 0;
		while (col < 4)
		{
			mt.m[row][col] = m.m[col][row];
			col++;
		}
		row++;
	}
	return (mt);
}

double  matrix_2_det(t_matrix_2 m)
{
	return (m.m[0][0] * m.m[1][1] - m.m[0][1] * m.m[1][0]);
}

t_matrix_4		matrix_cofactor(t_matrix_4 m)
{
	t_matrix_4	cof;
	int			i;
	int			j;
	t_matrix_4	sub;

	cof = matrix_new();
	i = 0;
	while (i < 4)
	{
		sub = matrix_new();
		j = 0;
		while (j < 4)
		{
			if (j != i)
				sub.m[i][j] = m.m[i][j];
			j++;
		}
		cof.m[0][i] = matrix_det(sub) * pow(-1, i);
		i++;
	}
	return (cof);
}

t_matrix_4 		matrix_inverse(t_matrix_4 m)
{
	t_matrix_4	mi;
	double		det;
	int			i;
	int			j;

	mi = matrix_new();
	det = matrix_det(m);
	if (det == 0)
		return (mi);
	mi = matrix_cofactor(m);
	mi = matrix_transpose(mi);
	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
			mi.m[i][j++] /= det;
		i++;
	}
	return (mi);
}