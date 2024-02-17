/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_scale.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkeraudr <dkeraudr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 14:53:37 by acrespy           #+#    #+#             */
/*   Updated: 2024/02/17 15:25:21 by dkeraudr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../includes/miniRT.h"

t_matrix	*matrix_scale(double x, double y, double z)
{
	t_matrix	*m;

	m = matrix_identity();
	m->matrix[0][0] = x;
	m->matrix[1][1] = y;
	m->matrix[2][2] = z;
	return (m);
}
