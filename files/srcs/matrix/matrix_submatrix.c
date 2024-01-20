/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_submatrix.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acrespy <acrespy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 11:22:06 by acrespy           #+#    #+#             */
/*   Updated: 2024/01/20 11:22:06 by acrespy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../includes/miniRT.h"

t_matrix_3	matrix_4_sub(t_matrix_4 m, int row, int col)
{
	int			i;
	int			j;
	t_matrix_3	sub;

	i = 0;
	while (i < 4)
	{
		if (i != row)
		{
			j = 0;
			while (j < 4)
			{
				if (j != col)
					sub.m[i][j] = m.m[i][j];
				j++;
			}
		}
		i++;
	}
	return (sub);
}

t_matrix_2	matrix_3_sub(t_matrix_3 m, int row, int col)
{
	int			i;
	int			j;
	t_matrix_2	sub;

	i = 0;
	while (i < 3)
	{
		if (i != row)
		{
			j = 0;
			while (j < 3)
			{
				if (j != col)
					sub.m[i][j] = m.m[i][j];
				j++;
			}
		}
		i++;
	}
	return (sub);
}
