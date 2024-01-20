/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_operations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acrespy <acrespy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 12:44:09 by acrespy           #+#    #+#             */
/*   Updated: 2024/01/17 12:44:12 by acrespy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../includes/miniRT.h"

t_vector	vect_add(t_vector v1, t_vector v2)
{
	t_vector	v3;

	v3.x = v1.x + v2.x;
	v3.y = v1.y + v2.y;
	v3.z = v1.z + v2.z;
	return (v3);
}

t_vector	vect_sub(t_vector v1, t_vector v2)
{
	t_vector	v3;

	v3.x = v1.x - v2.x;
	v3.y = v1.y - v2.y;
	v3.z = v1.z - v2.z;
	return (v3);
}

t_vector	vect_mult(t_vector v1, t_vector v2)
{
	t_vector	v3;

	v3.x = v1.x * v2.x;
	v3.y = v1.y * v2.y;
	v3.z = v1.z * v2.z;
	return (v3);
}

t_vector	vect_div(t_vector v1, t_vector v2)
{
	t_vector	v3;

	v3.x = v1.x / v2.x;
	v3.y = v1.y / v2.y;
	v3.z = v1.z / v2.z;
	return (v3);
}

t_vector	vect_invert(t_vector v1)
{
	t_vector	v2;

	v2.x = -v1.x;
	v2.y = -v1.y;
	v2.z = -v1.z;
	return (v2);
}
