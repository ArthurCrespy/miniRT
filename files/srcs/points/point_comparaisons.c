/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point_comparaisons.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acrespy <acrespy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 13:50:51 by acrespy           #+#    #+#             */
/*   Updated: 2024/01/17 13:50:51 by acrespy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/miniRT.h"

bool	point_equal(t_point v1, t_point v2)
{
	if (double_equal(v1.x, v2.x)
		&& double_equal(v1.y, v2.y)
		&& double_equal(v1.z, v2.z))
		return (true);
	return (false);
}

bool	point_inf(t_point v1, t_point v2)
{
	if (double_inf(v1.x, v2.x)
		&& double_inf(v1.y, v2.y)
		&& double_inf(v1.z, v2.z))
		return (true);
	return (false);
}

bool	point_sup(t_point v1, t_point v2)
{
	if (double_sup(v1.x, v2.x)
		&& double_sup(v1.y, v2.y)
		&& double_sup(v1.z, v2.z))
		return (true);
	return (false);
}
