/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_render.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkeraudr <dkeraudr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 15:00:18 by acrespy           #+#    #+#             */
/*   Updated: 2024/01/28 17:33:40 by dkeraudr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../includes/miniRT.h"

int	mlx_render_frame(t_minirt *data)
{
	int	x;
	int	y;

	y = 0;
	while (y < data->mlx->win_height)
	{
		x = 0;
		while (x < data->mlx->win_width)
		{
			my_mlx_pixel_put(data->mlx, x, y, 0x00FFFFFF);
			x++;
		}
		y++;
		printf("here\n");
	}
	mlx_put_image_to_window(data->mlx->mlx, data->mlx->mlx_win,
		data->mlx->img, 0, 0);
	usleep(100000 / 10);
	return (0);
}
