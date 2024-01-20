/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point_vector_operations.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acrespy <acrespy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 10:09:52 by acrespy           #+#    #+#             */
/*   Updated: 2024/01/20 10:09:52 by acrespy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../includes/miniRT.h"

t_point	point_vector_add(t_point p, t_vector v)
{
	t_point	res;

	res.x = p.x + v.x;
	res.y = p.y + v.y;
	res.z = p.z + v.z;
	return (res);
}

t_point	vector_point_add(t_vector v, t_point p)
{
	t_point	res;

	res.x = p.x + v.x;
	res.y = p.y + v.y;
	res.z = p.z + v.z;
	return (res);
}

t_point	point_vector_sub(t_point p, t_vector v)
{
	t_point	res;

	res.x = p.x - v.x;
	res.y = p.y - v.y;
	res.z = p.z - v.z;
	return (res);
}
