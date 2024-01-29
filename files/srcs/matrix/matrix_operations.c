/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_operations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acrespy <acrespy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 22:44:39 by acrespy           #+#    #+#             */
/*   Updated: 2024/01/29 14:56:58 by acrespy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "./../../includes/miniRT.h"

t_matrix	matrix_mult(t_matrix m1, t_matrix m2)
{
    int			i;
    int			j;
    t_matrix	m3;

    i = 0;
    while (i < MATRIX)
    {
        j = 0;
        while (j < MATRIX)
        {
            m3.matrix[i][j] = m1.matrix[i][0] * m2.matrix[0][j]
                + m1.matrix[i][1] * m2.matrix[1][j]
                + m1.matrix[i][2] * m2.matrix[2][j]
                + m1.matrix[i][3] * m2.matrix[3][j];
            j++;
        }
        i++;
    }
	m3.size = m1.size;
    return (m3);
}

t_tuple	matrix_tuple_mult(t_matrix m, t_tuple t)
{
    int		i;
	double	result[MATRIX];

	i = 0;
	while (i < MATRIX)
	{
		result[i] = m.matrix[i][0] * t.x
			+ m.matrix[i][1] * t.y
			+ m.matrix[i][2] * t.z
			+ m.matrix[i][3] * t.w;
		i++;
	}
	return (tuple_new(result[0], result[1], result[2], result[3]));
}
