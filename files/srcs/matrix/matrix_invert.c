/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_invert.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acrespy <acrespy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 11:23:25 by acrespy           #+#    #+#             */
/*   Updated: 2024/01/20 11:23:25 by acrespy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../includes/miniRT.h"

bool	matrix_4_invertible(t_matrix_4 m)
{
	return (matrix_4_determinant(m) != 0);
}

bool	matrix_3_invertible(t_matrix_3 m)
{
	return (matrix_3_determinant(m) != 0);
}

t_matrix_4	matrix_4_invert(t_matrix_4 m)
{
	int				i;
	int				j;
	double			det;
	t_matrix_4		m2;

	det = matrix_4_determinant(m);
	m2 = matrix_4_new();
	if (det == 0)
		return (m2);
	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			m2.m[i][j] = matrix_4_cofactor(m, i, j);
			j++;
		}
		i++;
	}
	m2 = matrix_4_transpose(m2);
	m2 = matrix_4_mult(m2, matrix_4_new_value(det));
	return (m2);
}

t_matrix_3	matrix_3_invert(t_matrix_3 m)
{
	int			i;
	int			j;
	double		det;
	t_matrix_3	invert;

	if (!matrix_3_invertible(m))
		return (matrix_3_new());
	det = matrix_3_determinant(m);
	i = 0;
	while (i < 3)
	{
		j = 0;
		while (j < 3)
		{
			invert.m[j][i] = matrix_3_cofactor(m, i, j) / det;
			j++;
		}
		i++;
	}
	return (invert);
}
