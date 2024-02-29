/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkeraudr <dkeraudr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 15:19:53 by acrespy           #+#    #+#             */
/*   Updated: 2024/02/18 15:09:21 by dkeraudr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_color	color_add(t_color c1, t_color c2)
{
	t_color	color;

	color.chan_1 = c1.chan_1 + c2.chan_1;
	color.chan_2 = c1.chan_2 + c2.chan_2;
	color.chan_3 = c1.chan_3 + c2.chan_3;
	return (color);
}

t_color	color_sub(t_color c1, t_color c2)
{
	t_color	color;

	color.chan_1 = c1.chan_1 - c2.chan_1;
	color.chan_2 = c1.chan_2 - c2.chan_2;
	color.chan_3 = c1.chan_3 - c2.chan_3;
	return (color);
}

t_color	color_mult(t_color c1, t_color c2)
{
	t_color	color;

	color.chan_1 = c1.chan_1 * c2.chan_1;
	color.chan_2 = c1.chan_2 * c2.chan_2;
	color.chan_3 = c1.chan_3 * c2.chan_3;
	return (color);
}

t_color	color_scalar(t_color c, double scalar)
{
	t_color	color;

	color.chan_1 = c.chan_1 * scalar;
	color.chan_2 = c.chan_2 * scalar;
	color.chan_3 = c.chan_3 * scalar;
	return (color);
}
