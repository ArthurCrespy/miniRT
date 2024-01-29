/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_create.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acrespy <acrespy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 14:12:34 by acrespy           #+#    #+#             */
/*   Updated: 2024/01/29 14:56:42 by acrespy          ###   ########.fr       */
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
	int			k;
	t_matrix	m;

	i = 0;
	k = 0;
	while (i < MATRIX)
	{
		j = 0;
		while (j < MATRIX)
		{
			if (i == k)
				m.matrix[i][j] = 1;
			else
				m.matrix[i][j] = 0;
			j++;
		}
		i++;
		k++;
	}
	m.size = MATRIX;
	return (m);
}
