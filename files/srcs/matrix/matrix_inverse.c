/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_inverse.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acrespy <acrespy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 14:37:48 by acrespy           #+#    #+#             */
/*   Updated: 2024/01/29 14:56:53 by acrespy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../includes/miniRT.h"

bool	matrix_invertible(t_matrix m)
{
	return (matrix_determinant(m) != 0);
}

t_matrix	matrix_inverse(t_matrix m)
{
    int			i;
    int			j;
    double		det;
    t_matrix	m2;

    if (!matrix_invertible(m))
	    return (matrix_identity());
	det = matrix_determinant(m);
	i = 0;
	while (i < m.size)
	{
		j = 0;
		while (j < m.size)
		{
			m2.matrix[i][j] = matrix_cofactor(m, i, j) / det;
			j++;
		}
		i++;
	}
	m2.size = m.size;
	return (matrix_transpose(m2));
}
