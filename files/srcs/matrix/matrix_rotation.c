/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_rotation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acrespy <acrespy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 13:25:34 by acrespy           #+#    #+#             */
/*   Updated: 2024/01/20 13:25:34 by acrespy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../includes/miniRT.h"

t_matrix_4	matrix_4_rotation_x(double angle)
{
	t_matrix_4	m;

	m = matrix_4_new();
	m.m[0][0] = 1;
	m.m[1][1] = cos(angle);
	m.m[1][2] = -sin(angle);
	m.m[2][1] = sin(angle);
	m.m[2][2] = cos(angle);
	m.m[3][3] = 1;
	return (m);
}

t_matrix_4	matrix_4_rotation_y(double angle)
{
	t_matrix_4	m;

	m = matrix_4_new();
	m.m[0][0] = cos(angle);
	m.m[0][2] = sin(angle);
	m.m[1][1] = 1;
	m.m[2][0] = -sin(angle);
	m.m[2][2] = cos(angle);
	m.m[3][3] = 1;
	return (m);
}

t_matrix_4	matrix_4_rotation_z(double angle)
{
	t_matrix_4	m;

	m = matrix_4_new();
	m.m[0][0] = cos(angle);
	m.m[0][1] = -sin(angle);
	m.m[1][0] = sin(angle);
	m.m[1][1] = cos(angle);
	m.m[2][2] = 1;
	m.m[3][3] = 1;
	return (m);
}