/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_submatrix.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acrespy <acrespy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 14:48:47 by acrespy           #+#    #+#             */
/*   Updated: 2024/01/29 14:57:17 by acrespy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../includes/miniRT.h"

t_matrix	matrix_submatrix(t_matrix m, int row, int col)
{
	int			i;
	int			j;
	t_matrix	m2;

	i = 0;
	while (i < m.size)
	{
		j = 0;
		while (j < m.size)
		{
			if (i != row && j != col)
				m2.matrix[i][j] = m.matrix[i][j];
			j++;
		}
		i++;
	}
	m2.size = m.size - 1;
	return (m2);
}
