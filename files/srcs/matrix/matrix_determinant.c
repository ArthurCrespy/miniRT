/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_determinant.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkeraudr <dkeraudr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 20:37:02 by acrespy           #+#    #+#             */
/*   Updated: 2024/02/17 18:41:25 by dkeraudr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../includes/miniRT.h"

double	matrix_determinant(t_matrix m)
{
	int		i;
	double	det;

	i = 0;
	det = 0;
	if (m.size == 2)
		return (m.matrix[0][0] * m.matrix[1][1]
				- m.matrix[0][1] * m.matrix[1][0]);
	while (i < m.size)
	{
		det += m.matrix[0][i] * matrix_cofactor(m, 0, i);
		i++;
	}
	return (det);
}
