/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_inverse.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkeraudr <dkeraudr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 14:37:48 by acrespy           #+#    #+#             */
/*   Updated: 2024/02/17 19:09:21 by dkeraudr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../includes/miniRT.h"

bool	matrix_invertible(t_matrix m)
{
	return (matrix_determinant(m) != 0);
}

t_matrix	*matrix_inverse(t_matrix m)
{
	int			row;
	int			col;
	double		det;
	t_matrix	*m2;

	printf("is invertible: %d\n", matrix_invertible(m));
	if (!matrix_invertible(m))
		return (matrix_identity());
	m2 = malloc(sizeof(t_matrix));
	if (!m2)
		return (NULL);
	det = matrix_determinant(m);
	row = 0;
	while (row < m.size)
	{
		col = 0;
		while (col < m.size)
		{
			m2->matrix[col][row] = matrix_cofactor(m, row, col) / det;
			col++;
		}
		row++;
	}
	m2->size = m.size;
	matrix_transpose(*m2);
	return (m2);
}
