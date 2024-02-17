/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_inverse.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkeraudr <dkeraudr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 14:37:48 by acrespy           #+#    #+#             */
/*   Updated: 2024/02/17 18:28:11 by dkeraudr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../includes/miniRT.h"

bool	matrix_invertible(t_matrix m)
{
	return (matrix_determinant(m) != 0);
}

t_matrix	*matrix_inverse(t_matrix m)
{
	int			i;
	int			j;
	double		det;
	t_matrix	*m2;

	if (!matrix_invertible(m))
		return (matrix_identity());
	m2 = malloc(sizeof(t_matrix));
	if (!m2)
		return (NULL);
	det = matrix_determinant(m);
	i = 0;
	while (i < m.size)
	{
		j = 0;
		while (j < m.size)
		{
			m2->matrix[i][j] = matrix_cofactor(m, i, j) / det;
			j++;
		}
		i++;
	}
	m2->size = m.size;
	matrix_transpose(*m2);
	return (m2);
}
