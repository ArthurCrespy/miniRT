/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_initialize.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkeraudr <dkeraudr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 14:40:43 by acrespy           #+#    #+#             */
/*   Updated: 2024/01/16 21:00:56 by dkeraudr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../includes/miniRT.h"

void	mlx_initialize_win(t_minirt *data)
{
	data->mlx->mlx = NULL;
	data->mlx->mlx_win = NULL;
	data->mlx->mlx = mlx_init();
	if (!data->mlx->mlx)
		mlx_error(data);
	mlx_get_screen_size(data->mlx->mlx,
		&data->mlx->screen_width, &data->mlx->screen_height);
	if (data->mlx->screen_width <= 0 || data->mlx->screen_height <= 0)
		mlx_error(data);
	data->mlx->screen_width /= 2;
	data->mlx->screen_height -= 200;
	data->mlx->win_width = data->mlx->screen_width;
	data->mlx->win_height = data->mlx->screen_height;
	data->mlx->mlx_win = mlx_new_window(data->mlx->mlx, data->mlx->win_width,
			data->mlx->win_height, "miniRT | acrespy");
	if (!data->mlx->mlx_win)
		mlx_error(data);
	data->mlx->img = mlx_new_image(data->mlx->mlx,
			data->mlx->win_width, data->mlx->win_height);
	if (!data->mlx->img)
		mlx_error(data);
}
