/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_minor.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acrespy <acrespy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 11:29:55 by acrespy           #+#    #+#             */
/*   Updated: 2024/01/20 11:29:55 by acrespy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../includes/miniRT.h"

double	matrix_4_minor(t_matrix_4 m, int i, int j)
{
	int				x;
	int				x2;
	int				y;
	int				y2;
	t_matrix_3		m3;

	x = 0;
	x2 = 0;
	while (x < 4)
	{
		if (x != i)
		{
			y = 0;
			y2 = 0;
			while (y < 4)
			{
				if (y != j)
				{
					m3.m[x2][y2] = m.m[x][y];
					y2++;
				}
				y++;
			}
			x2++;
		}
		x++;
	}
	return (matrix_3_determinant(m3));
}

double	matrix_3_minor(t_matrix_3 m, int i, int j)
{
	int				x;
	int				x2;
	int				y;
	int				y2;
	t_matrix_2		m2;

	x = 0;
	x2 = 0;
	while (x < 3)
	{
		if (x != i)
		{
			y = 0;
			y2 = 0;
			while (y < 3)
			{
				if (y != j)
				{
					m2.m[x2][y2] = m.m[x][y];
					y2++;
				}
				y++;
			}
			x2++;
		}
		x++;
	}
	return (matrix_2_determinant(m2));
}
