/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_scalar.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acrespy <acrespy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 13:30:12 by acrespy           #+#    #+#             */
/*   Updated: 2024/01/20 13:30:12 by acrespy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../includes/miniRT.h"

t_matrix_4	matrix_4_scale(t_vector v, double scale)
{
	t_matrix_4	m;

	m = matrix_4_new();
	m.m[0][0] = v.x * scale;
	m.m[1][1] = v.y * scale;
	m.m[2][2] = v.z * scale;
	m.m[3][3] = 1;
	return (m);
}

t_matrix_4	matrix_4_unscale(t_vector v, double scale)
{
	t_matrix_4	m;

	m = matrix_4_new();
	m.m[0][0] = v.x / scale;
	m.m[1][1] = v.y / scale;
	m.m[2][2] = v.z / scale;
	m.m[3][3] = 1;
	return (m);
}