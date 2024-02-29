/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_submatrix.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkeraudr <dkeraudr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 14:48:47 by acrespy           #+#    #+#             */
/*   Updated: 2024/02/18 15:09:21 by dkeraudr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_matrix	matrix_submatrix(t_matrix m, int row, int col)
{
	int			i;
	int			j;
	t_matrix	m2;

	i = 0;
	m2.size = m.size - 1;
	while (i < m2.size)
	{
		j = 0;
		while (j < m2.size)
		{
			if (i < row)
			{
				if (j < col)
					m2.matrix[i][j] = m.matrix[i][j];
				else
					m2.matrix[i][j] = m.matrix[i][j + 1];
			}
			else
			{
				if (j < col)
					m2.matrix[i][j] = m.matrix[i + 1][j];
				else
					m2.matrix[i][j] = m.matrix[i + 1][j + 1];
			}
			j++;
		}
		i++;
	}
	return (m2);
}
