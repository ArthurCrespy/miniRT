/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_cofactor.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acrespy <acrespy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 14:51:24 by acrespy           #+#    #+#             */
/*   Updated: 2024/01/29 14:56:35 by acrespy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../includes/miniRT.h"

double	matrix_cofactor(t_matrix m, int row, int col)
{
	double		minor;

	minor = matrix_minor(m, row, col);
	if ((row + col) % 2 == 0)
		return (minor);
	else
		return (-minor);
}
