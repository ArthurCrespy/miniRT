/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_comparisons.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acrespy <acrespy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 11:12:00 by acrespy           #+#    #+#             */
/*   Updated: 2024/01/20 11:12:00 by acrespy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../includes/miniRT.h"

bool	matrix_4_equal(t_matrix_4 m)
{
	int	i;
	int	j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4 && m.m[i][j] == 0)
			j++;
		if (j != 4)
			return (false);
		i++;
	}
	return (true);
}
