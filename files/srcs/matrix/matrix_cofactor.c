/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_cofactor.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acrespy <acrespy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 11:30:39 by acrespy           #+#    #+#             */
/*   Updated: 2024/01/20 11:30:39 by acrespy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../includes/miniRT.h"

double	matrix_4_cofactor(t_matrix_4 m, int i, int j)
{
	double		minor;

	minor = matrix_4_minor(m, i, j);
	if ((i + j) % 2 == 1)
		minor = -minor;
	return (minor);
}

double	matrix_3_cofactor(t_matrix_3 m, int i, int j)
{
	double		minor;

	minor = matrix_3_minor(m, i, j);
	if ((i + j) % 2 == 1)
		minor = -minor;
	return (minor);
}
