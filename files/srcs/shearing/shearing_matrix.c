/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shearing_matrix.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkeraudr <dkeraudr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 14:47:46 by acrespy           #+#    #+#             */
/*   Updated: 2024/02/18 15:09:21 by dkeraudr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_matrix	*matrix_shearing(t_shearing x, t_shearing y, t_shearing z)
{
	t_matrix	*m;

	m = matrix_identity();
	m->matrix[0][1] = x.p1;
	m->matrix[0][2] = x.p2;
	m->matrix[1][0] = y.p1;
	m->matrix[1][2] = y.p2;
	m->matrix[2][0] = z.p1;
	m->matrix[2][1] = z.p2;
	return (m);
}
