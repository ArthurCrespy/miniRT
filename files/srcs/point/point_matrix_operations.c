/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point_matrix_operations.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acrespy <acrespy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 15:49:28 by acrespy           #+#    #+#             */
/*   Updated: 2024/01/23 15:49:28 by acrespy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../includes/miniRT.h"

t_point	matrix_4_mult_point(t_matrix_4 matrix, t_point point)
{
	t_point	new_point;

	new_point.x = matrix.m[0][0] * point.x + matrix.m[0][1] * point.y
		+ matrix.m[0][2] * point.z + matrix.m[0][3] * 1;
	new_point.y = matrix.m[1][0] * point.x + matrix.m[1][1] * point.y
		+ matrix.m[1][2] * point.z + matrix.m[1][3] * 1;
	new_point.z = matrix.m[2][0] * point.x + matrix.m[2][1] * point.y
		+ matrix.m[2][2] * point.z + matrix.m[2][3] * 1;
	return (new_point);
}

t_vector	matrix_4_mult_vector(t_matrix_4 matrix, t_vector vector)
{
	t_vector	new_vector;

	new_vector.x = matrix.m[0][0] * vector.x + matrix.m[0][1] * vector.y
		+ matrix.m[0][2] * vector.z + matrix.m[0][3] * 0;
	new_vector.y = matrix.m[1][0] * vector.x + matrix.m[1][1] * vector.y
		+ matrix.m[1][2] * vector.z + matrix.m[1][3] * 0;
	new_vector.z = matrix.m[2][0] * vector.x + matrix.m[2][1] * vector.y
		+ matrix.m[2][2] * vector.z + matrix.m[2][3] * 0;
	return (new_vector);
}