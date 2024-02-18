/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_exit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkeraudr <dkeraudr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 14:37:39 by acrespy           #+#    #+#             */
/*   Updated: 2024/02/18 14:25:34 by dkeraudr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../includes/miniRT.h"

void	mlx_free(t_minirt *data)
{
	if (data->mlx->img)
		mlx_destroy_image(data->mlx->mlx, data->mlx->img);
	if (data->mlx->mlx_win)
		mlx_destroy_window(data->mlx->mlx, data->mlx->mlx_win);
	if (data->mlx->mlx_win)
		mlx_destroy_display(data->mlx->mlx);
	if (data->mlx->mlx)
		free(data->mlx->mlx);
}

void	mlx_exit(t_minirt *data, char *msg, int status)
{
	mlx_free(data);
	data_free(data);
	ft_exit(msg, status);
}

void	mlx_error(t_minirt *data)
{
	mlx_free(data);
	ft_exit("Error: Something went wrong with MiniLibX\n", 1);
}

int	mlx_hook_exit(t_minirt *data)
{
	mlx_free(data);
	data_free(data);
	exit(0);
}
