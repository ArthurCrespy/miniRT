/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_translation.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkeraudr <dkeraudr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 14:52:59 by acrespy           #+#    #+#             */
/*   Updated: 2024/02/17 15:23:30 by dkeraudr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../includes/miniRT.h"

t_matrix	*matrix_translation(double x, double y, double z)
{
	t_matrix	*m;

	m = matrix_identity();
	m->matrix[0][3] = x;
	m->matrix[1][3] = y;
	m->matrix[2][3] = z;
	return (m);
}
