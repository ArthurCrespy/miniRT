/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shearing_matrix.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acrespy <acrespy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 14:47:46 by acrespy           #+#    #+#             */
/*   Updated: 2024/01/29 14:57:47 by acrespy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../includes/miniRT.h"

t_matrix	matrix_shearing(t_shearing x, t_shearing y, t_shearing z)
{
	t_matrix	m;

	m = matrix_identity();
	m.matrix[0][1] = x.p1;
	m.matrix[0][2] = x.p2;
	m.matrix[1][0] = y.p1;
	m.matrix[1][2] = y.p2;
	m.matrix[2][0] = z.p1;
	m.matrix[2][1] = z.p2;
	return (m);
}
