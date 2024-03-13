/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_transpose.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkeraudr <dkeraudr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 14:44:43 by acrespy           #+#    #+#             */
/*   Updated: 2024/03/08 20:21:16 by dkeraudr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_matrix	*matrix_transpose(t_matrix m)
{
	int			i;
	int			j;
	t_matrix	*m2;

	i = 0;
	m2 = malloc(sizeof(t_matrix));
	if (!m2)
		return (NULL);
	while (i < m.size)
	{
		j = 0;
		while (j < m.size)
		{
			m2->matrix[i][j] = m.matrix[j][i];
			j++;
		}
		i++;
	}
	m2->size = m.size;
	m2->matrix[3][0] = 0;
	m2->matrix[3][1] = 0;
	m2->matrix[3][2] = 0;
	m2->matrix[3][3] = 1;
	return (m2);
}
