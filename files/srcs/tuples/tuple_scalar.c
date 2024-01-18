/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tuple_scalar.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acrespy <acrespy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 14:16:34 by acrespy           #+#    #+#             */
/*   Updated: 2024/01/18 14:16:34 by acrespy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../includes/miniRT.h"

t_tuple	tuple_scale(t_tuple v1, double scale)
{
	t_tuple	v3;

	v3.x = v1.x * scale;
	v3.y = v1.y * scale;
	v3.z = v1.z * scale;
	v3.w = v1.w * scale;
	return (v3);
}

t_tuple	tuple_unscale(t_tuple v1, double scale)
{
	t_tuple	v3;

	v3.x = v1.x / scale;
	v3.y = v1.y / scale;
	v3.z = v1.z / scale;
	v3.w = v1.w / scale;
	return (v3);
}