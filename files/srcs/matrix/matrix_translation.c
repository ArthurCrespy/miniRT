/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_translation.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acrespy <acrespy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 13:27:04 by acrespy           #+#    #+#             */
/*   Updated: 2024/01/20 13:27:04 by acrespy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../includes/miniRT.h"

t_matrix_4	matrix_4_translation(t_vector v)
{
	t_matrix_4	m;

	m = matrix_4_new();
	m.m[0][0] = 1;
	m.m[0][3] = v.x;
	m.m[1][1] = 1;
	m.m[1][3] = v.y;
	m.m[2][2] = 1;
	m.m[2][3] = v.z;
	m.m[3][3] = 1;
	return (m);
}

t_matrix_4	matrix_4_translation_inv(t_vector v)
{
	t_matrix_4	m;

	m = matrix_4_new();
	m.m[0][0] = 1;
	m.m[0][3] = -v.x;
	m.m[1][1] = 1;
	m.m[1][3] = -v.y;
	m.m[2][2] = 1;
	m.m[2][3] = -v.z;
	m.m[3][3] = 1;
	return (m);
}
