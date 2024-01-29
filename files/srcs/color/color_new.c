/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_new.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acrespy <acrespy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 15:18:19 by acrespy           #+#    #+#             */
/*   Updated: 2024/01/29 15:18:19 by acrespy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../includes/miniRT.h"

t_color	color_new(double r, double g, double b)
{
	t_color	color;

	color.chan_1 = r;
	color.chan_2 = b;
	color.chan_3 = g;
	return (color);
}