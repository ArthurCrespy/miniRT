/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_determinant.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acrespy <acrespy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 11:22:44 by acrespy           #+#    #+#             */
/*   Updated: 2024/01/20 11:22:44 by acrespy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../includes/miniRT.h"

double	matrix_4_determinant(t_matrix_4 m)
{
	int			i;
	double		det;

	i = 0;
	det = 0;
	while (i < 4)
	{
		det += m.m[0][i] * matrix_4_cofactor(m, 0, i);
		i++;
	}
	return (det);
}

double	matrix_3_determinant(t_matrix_3 m)
{
	int			i;
	double		det;

	i = 0;
	det = 0;
	while (i < 3)
	{
		det += m.m[0][i] * matrix_3_cofactor(m, 0, i);
		i++;
	}
	return (det);
}

double	matrix_2_determinant(t_matrix_2 m)
{
	return (m.m[0][0] * m.m[1][1] - m.m[0][1] * m.m[1][0]);
}
