/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tuple_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acrespy <acrespy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 14:09:35 by acrespy           #+#    #+#             */
/*   Updated: 2024/01/18 14:09:35 by acrespy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/miniRT.h"

double	tuple_mag(t_tuple v1)
{
	double	mag;

	mag = sqrt(v1.x * v1.x + v1.y * v1.y + v1.z * v1.z + v1.w * v1.w);
	return (mag);
}

double	tuple_dot(t_tuple v1, t_tuple v2)
{
	double	dot;

	dot = v1.x * v2.x + v1.y * v2.y + v1.z * v2.z + v1.w * v2.w;
	return (dot);
}

t_tuple	tuple_norm(t_tuple v1)
{
	t_tuple	v2;
	double		mag;

	mag = tuple_mag(v1);
	v2.x = v1.x / mag;
	v2.y = v1.y / mag;
	v2.z = v1.z / mag;
	v2.w = v1.w / mag;
	return (v2);
}