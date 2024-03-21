/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_create.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkeraudr <dkeraudr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 14:12:34 by acrespy           #+#    #+#             */
/*   Updated: 2024/02/18 15:09:21 by dkeraudr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_matrix	*matrix_new(double **m, int size)
{
	int			i;
	int			j;
	t_matrix	*matrix;

	matrix = malloc(sizeof(t_matrix));
	if (!matrix)
		return (NULL);
	i = 0;
	matrix->size = size;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			matrix->matrix[i][j] = m[i][j];
			j++;
		}
		i++;
	}
	return (matrix);
}

t_matrix	*matrix_identity(void)
{
	int			i;
	int			j;
	t_matrix	*matrix_return;

	matrix_return = malloc(sizeof(t_matrix));
	if (!matrix_return)
		return (NULL);
	i = 0;
	while (i < MATRIX)
	{
		j = 0;
		while (j < MATRIX)
		{
			if (i == j)
				matrix_return->matrix[i][j] = 1;
			else
				matrix_return->matrix[i][j] = 0;
			j++;
		}
		i++;
	}
	matrix_return->size = MATRIX;
	return (matrix_return);
}

t_matrix	*vector_to_matrix(t_vector v)
{
	t_matrix	*m;

	m = matrix_identity();
	m->matrix[0][3] = v.x;
	m->matrix[1][3] = v.y;
	m->matrix[2][3] = v.z;
	return (m);
}
