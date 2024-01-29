/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maxtrix_minor.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acrespy <acrespy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 14:50:35 by acrespy           #+#    #+#             */
/*   Updated: 2024/01/29 14:57:35 by acrespy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../includes/miniRT.h"

double	matrix_minor(t_matrix m, int row, int col)
{
	t_matrix	m2;

	m2 = matrix_submatrix(m, row, col);
	return (matrix_determinant(m2));
}
