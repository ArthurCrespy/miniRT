/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_loop.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkeraudr <dkeraudr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 15:02:08 by acrespy           #+#    #+#             */
/*   Updated: 2024/02/18 14:24:47 by dkeraudr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../includes/miniRT.h"

void	mlx_hook_loop(t_minirt *data)
{
	// mlx_loop_hook(data->mlx->mlx,
	// 	(int (*)(void)) mlx_render_frame, data);
	mlx_hook(data->mlx->mlx_win, 2, 1L << 0,
		event_key, data);
	mlx_hook(data->mlx->mlx_win, 25, 1L << 18,
		event_resize, data);
	mlx_hook(data->mlx->mlx_win, 17, 1L << 17,
		mlx_hook_exit, data);
	mlx_loop(data->mlx->mlx);
}
