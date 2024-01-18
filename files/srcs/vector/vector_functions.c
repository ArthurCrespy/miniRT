/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acrespy <acrespy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 13:31:11 by acrespy           #+#    #+#             */
/*   Updated: 2024/01/17 13:31:11 by acrespy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../includes/miniRT.h"

double	vect_mag(t_vector v1)
{
	double	mag;

	mag = sqrt(v1.x * v1.x + v1.y * v1.y + v1.z * v1.z);
	return (mag);
}

double	vect_dot(t_vector v1, t_vector v2)
{
	double	dot;

	dot = v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
	return (dot);
}

t_vector	vect_norm(t_vector v1)
{
	t_vector	v2;
	double		mag;

	mag = vect_mag(v1);
	v2.x = v1.x / mag;
	v2.y = v1.y / mag;
	v2.z = v1.z / mag;
	return (v2);
}

t_vector	vect_cross(t_vector v1, t_vector v2)
{
	t_vector	v3;

	v3.x = v1.y * v2.z - v1.z * v2.y;
	v3.y = v1.z * v2.x - v1.x * v2.z;
	v3.z = v1.x * v2.y - v1.y * v2.x;
	return (v3);
}