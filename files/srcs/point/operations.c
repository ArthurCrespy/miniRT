/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkeraudr <dkeraudr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 19:18:29 by dkeraudr          #+#    #+#             */
/*   Updated: 2024/01/31 19:19:34 by dkeraudr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_point	point_add(t_point v1, t_point v2)
{
	t_point	v;

	v.x = v1.x + v2.x;
	v.y = v1.y + v2.y;
	v.z = v1.z + v2.z;
	return (v);
}

t_point	point_sub(t_point v1, t_point v2)
{
	t_point	v;

	v.x = v1.x - v2.x;
	v.y = v1.y - v2.y;
	v.z = v1.z - v2.z;
	return (v);
}

t_point	point_mult(t_point v1, t_point v2)
{
	t_point	v;

	v.x = v1.x * v2.x;
	v.y = v1.y * v2.y;
	v.z = v1.z * v2.z;
	return (v);
}

t_point	point_div(t_point v1, t_point v2)
{
	t_point	v;

	v.x = v1.x / v2.x;
	v.y = v1.y / v2.y;
	v.z = v1.z / v2.z;
	return (v);
}
