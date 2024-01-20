/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_transpose.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acrespy <acrespy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 11:38:11 by acrespy           #+#    #+#             */
/*   Updated: 2024/01/20 11:38:11 by acrespy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../includes/miniRT.h"

t_matrix_4	matrix_4_transpose(t_matrix_4 m)
{
	int			i;
	int			j;
	t_matrix_4	m2;

	i = 0;
	m2 = matrix_4_new();
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			m2.m[i][j] = m.m[j][i];
			j++;
		}
		i++;
	}
	return (m2);
}
