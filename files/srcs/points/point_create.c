/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point_create.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acrespy <acrespy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 14:05:42 by acrespy           #+#    #+#             */
/*   Updated: 2024/01/18 14:05:42 by acrespy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/miniRT.h"

t_point	point_new(double x, double y, double z)
{
	t_point	v;

	v.x = x;
	v.y = y;
	v.z = z;
	return (v);
}

t_point	point_zero(void)
{
	t_point	v;

	v.x = 0;
	v.y = 0;
	v.z = 0;
	return (v);
}