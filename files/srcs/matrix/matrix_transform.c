/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_transform.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkeraudr <dkeraudr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 14:42:21 by dkeraudr          #+#    #+#             */
/*   Updated: 2024/03/12 18:05:12 by acrespy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	ft_matrix_copy(t_matrix *dst, t_matrix *src)
{
	int	i;
	int	j;

	i = 0;
	while (i < MATRIX)
	{
		j = 0;
		while (j < MATRIX)
		{
			dst->matrix[i][j] = src->matrix[i][j];
			j++;
		}
		i++;
	}
}

void	matrix_transform(t_matrix *matrix, t_matrix *transform)
{
	t_matrix	*tmp;

	tmp = matrix_mult(*matrix, *transform);
	ft_matrix_copy(matrix, tmp);
	ft_matrix_free(tmp);
}
