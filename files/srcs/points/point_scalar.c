/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point_scalar.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acrespy <acrespy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 13:50:51 by acrespy           #+#    #+#             */
/*   Updated: 2024/01/17 13:50:51 by acrespy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/miniRT.h"

t_point	point_scale(t_point v1, double scale)
{
	t_point	v3;

	v3.x = v1.x * scale;
	v3.y = v1.y * scale;
	v3.z = v1.z * scale;
	return (v3);
}

t_point	point_unscale(t_point v1, double scale)
{
	t_point	v3;

	v3.x = v1.x / scale;
	v3.y = v1.y / scale;
	v3.z = v1.z / scale;
	return (v3);
}