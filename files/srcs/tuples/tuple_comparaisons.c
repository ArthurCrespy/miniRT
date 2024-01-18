/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tuple_comparaisons.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acrespy <acrespy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 14:07:59 by acrespy           #+#    #+#             */
/*   Updated: 2024/01/18 14:07:59 by acrespy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/miniRT.h"

bool	tuple_equal(t_tuple v1, t_tuple v2)
{
	if (double_equal(v1.x, v2.x)
		&& double_equal(v1.y, v2.y)
		&& double_equal(v1.z, v2.z)
		&& double_equal(v1.w, v2.w))
		return (true);
	return (false);
}

bool	tuple_inf(t_tuple v1, t_tuple v2)
{
	if (double_inf(v1.x, v2.x)
		&& double_inf(v1.y, v2.y)
		&& double_inf(v1.z, v2.z)
		&& double_inf(v1.w, v2.w))
		return (true);
	return (false);
}

bool	tuple_sup(t_tuple v1, t_tuple v2)
{
	if (double_sup(v1.x, v2.x)
		&& double_sup(v1.y, v2.y)
		&& double_sup(v1.z, v2.z)
		&& double_sup(v1.w, v2.w))
		return (true);
	return (false);
}
