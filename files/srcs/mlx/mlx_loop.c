/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_loop.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acrespy <acrespy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 15:02:08 by acrespy           #+#    #+#             */
/*   Updated: 2023/11/19 15:02:11 by acrespy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/miniRT.h"

void	mlx_hook_loop(t_data *data)
{
	mlx_loop_hook(data->mlx->mlx,
		(int (*)(void)) mlx_render_frame, data);
	mlx_hook(data->mlx->mlx_win, 2, 1L << 0,
		(int (*)(void)) event_key, data);
	mlx_hook(data->mlx->mlx_win, 25, 1L << 18,
		(int (*)(void)) event_resize, data);
	mlx_hook(data->mlx->mlx_win, 17, 1L << 17,
		(int (*)(void)) mlx_hook_exit, data);
	mlx_loop(data->mlx->mlx);
}