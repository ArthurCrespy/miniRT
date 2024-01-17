/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_scalar.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acrespy <acrespy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 13:36:22 by acrespy           #+#    #+#             */
/*   Updated: 2024/01/17 13:36:22 by acrespy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/miniRT.h"

t_vector	vect_scale(t_vector v1, double scale)
{
	t_vector	v3;

	v3.x = v1.x * scale;
	v3.y = v1.y * scale;
	v3.z = v1.z * scale;
	return (v3);
}

t_vector	vect_unscale(t_vector v1, double scale)
{
	t_vector	v3;

	v3.x = v1.x / scale;
	v3.y = v1.y / scale;
	v3.z = v1.z / scale;
	return (v3);
}