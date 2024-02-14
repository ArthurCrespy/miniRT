/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_create.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkeraudr <dkeraudr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 14:12:34 by acrespy           #+#    #+#             */
/*   Updated: 2024/02/14 18:51:32 by dkeraudr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../includes/miniRT.h"

t_matrix	matrix_new(double **m, int size)
{
	int			i;
	int			j;
	t_matrix	matrix;

	i = 0;
	matrix.size = size;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			matrix.matrix[i][j] = m[i][j];
			j++;
		}
		i++;
	}
	return (matrix);
}

t_matrix	matrix_identity(void)
{
	int			i;
	int			j;
	t_matrix	m;

	i = 0;
	while (i < MATRIX)
	{
		j = 0;
		while (j < MATRIX)
		{
			if (i == j)
				m.matrix[i][j] = 1;
			else
				m.matrix[i][j] = 0;
			j++;
		}
		i++;
	}
	m.size = MATRIX;
	return (m);
}
