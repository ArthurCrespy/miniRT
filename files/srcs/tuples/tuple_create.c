/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tuple_create.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acrespy <acrespy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 14:08:49 by acrespy           #+#    #+#             */
/*   Updated: 2024/01/18 14:08:49 by acrespy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/miniRT.h"

t_tuple	tuple_new(double x, double y, double z, double w)
{
	t_tuple	v;

	v.x = x;
	v.y = y;
	v.z = z;
	v.w = w;
	return (v);
}

t_tuple	tuple_zero(void)
{
	t_tuple	v;

	v.x = 0;
	v.y = 0;
	v.z = 0;
	v.w = 0;
	return (v);
}