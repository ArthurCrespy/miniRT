/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_comparaisons.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acrespy <acrespy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 14:43:59 by acrespy           #+#    #+#             */
/*   Updated: 2024/01/29 14:56:28 by acrespy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../includes/miniRT.h"

bool	matrix_compare(t_matrix m1, t_matrix m2)
{
	int	i;
	int	j;

	i = 0;
	while (i < m1.size)
	{
		j = 0;
		while (j < m1.size)
		{
			if (m1.matrix[i][j] != m2.matrix[i][j])
				return (false);
			j++;
		}
		i++;
	}
	return (true);
}
