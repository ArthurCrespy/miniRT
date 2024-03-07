/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_pixel_put.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acrespy <acrespy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 15:42:40 by dkeraudr          #+#    #+#             */
/*   Updated: 2024/03/07 17:13:57 by acrespy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	my_mlx_pixel_put(t_mlx *data, int pixel_x, int pixel_y, int color)
{
    int		mapped_x;
    int		mapped_y;
    char	*dst;

	mapped_x = data->win_width - pixel_x;
	mapped_y = data->win_height - pixel_y;

	dst = data->addr + (mapped_y * data->line_length + mapped_x * (data->bpp / 8));
	*(unsigned int *)dst = color;
}
