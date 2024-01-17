/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acrespy <acrespy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 13:50:51 by acrespy           #+#    #+#             */
/*   Updated: 2024/01/17 13:51:06 by acrespy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/miniRT.h"

double	point_mag(t_point v1)
{
	double	mag;

	mag = sqrt(v1.x * v1.x + v1.y * v1.y + v1.z * v1.z);
	return (mag);
}

double	point_dot(t_point v1, t_point v2)
{
	double	dot;

	dot = v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
	return (dot);
}

t_point	point_norm(t_point v1)
{
	t_point	v2;
	double		mag;

	mag = point_mag(v1);
	v2.x = v1.x / mag;
	v2.y = v1.y / mag;
	v2.z = v1.z / mag;
	return (v2);
}

t_point	point_cross(t_point v1, t_point v2)
{
	t_point	v3;

	v3.x = v1.y * v2.z - v1.z * v2.y;
	v3.y = v1.z * v2.x - v1.x * v2.z;
	v3.z = v1.x * v2.y - v1.y * v2.x;
	return (v3);
}