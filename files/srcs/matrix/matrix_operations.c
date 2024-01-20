/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_operations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acrespy <acrespy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 11:12:39 by acrespy           #+#    #+#             */
/*   Updated: 2024/01/20 11:12:39 by acrespy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../includes/miniRT.h"

t_matrix_4	matrix_4_mult(t_matrix_4 m1, t_matrix_4 m2)
{
	int			i;
	int			j;
	int			k;
	t_matrix_4	m;

	m = matrix_4_new();
	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			k = 0;
			while (k < 4)
			{
				m.m[i][j] += m1.m[i][k] * m2.m[k][j];
				k++;
			}
			j++;
		}
		i++;
	}
	return (m);
}
