/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_render.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkeraudr <dkeraudr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 15:00:18 by acrespy           #+#    #+#             */
/*   Updated: 2024/01/16 21:00:56 by dkeraudr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/miniRT.h"

int	mlx_render_frame(t_minirt *data)
{
	mlx_string_put(data->mlx->mlx, data->mlx->mlx_win, 50, 50, 0x00FFFFFF,
		"Hello, World!");
	mlx_string_put(data->mlx->mlx, data->mlx->mlx_win, 50, 70, 0x00FFFFFF,
		"Welcome in miniRT!");
	usleep(100000 / 60);
	return (0);
}
