/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acrespy <acrespy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 13:50:51 by acrespy           #+#    #+#             */
/*   Updated: 2024/01/17 13:50:51 by acrespy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../includes/miniRT.h"

t_point	point_add(t_point v1, t_point v2)
{
	t_point	v3;

	v3.x = v1.x + v2.x;
	v3.y = v1.y + v2.y;
	v3.z = v1.z + v2.z;
	return (v3);
}

t_point	point_sub(t_point v1, t_point v2)
{
	t_point	v3;

	v3.x = v1.x - v2.x;
	v3.y = v1.y - v2.y;
	v3.z = v1.z - v2.z;
	return (v3);
}

t_point	point_mult(t_point v1, t_point v2)
{
	t_point	v3;

	v3.x = v1.x * v2.x;
	v3.y = v1.y * v2.y;
	v3.z = v1.z * v2.z;
	return (v3);
}

t_point	point_div(t_point v1, t_point v2)
{
	t_point	v3;

	v3.x = v1.x / v2.x;
	v3.y = v1.y / v2.y;
	v3.z = v1.z / v2.z;
	return (v3);
}

t_point	point_invert(t_point v1)
{
	t_point	v2;

	v2.x = -v1.x;
	v2.y = -v1.y;
	v2.z = -v1.z;
	return (v2);
}
