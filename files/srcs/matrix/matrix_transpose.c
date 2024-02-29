/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_transpose.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkeraudr <dkeraudr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 14:44:43 by acrespy           #+#    #+#             */
/*   Updated: 2024/02/18 15:09:21 by dkeraudr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_matrix	matrix_transpose(t_matrix m)
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
			m2.matrix[i][j] = m.matrix[j][i];
			j++;
		}
		i++;
	}
	m2.size = m.size;
	return (m2);
}
