/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_exit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acrespy <acrespy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 14:37:39 by acrespy           #+#    #+#             */
/*   Updated: 2023/11/19 14:37:42 by acrespy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/miniRT.h"

void	mlx_free(t_data *data)
{
	if (data->mlx->mlx_win)
		mlx_destroy_window(data->mlx->mlx, data->mlx->mlx_win);
	if (data->mlx->mlx_win)
		mlx_destroy_display(data->mlx->mlx);
	if (data->mlx->mlx)
		free(data->mlx->mlx);
}

void	mlx_exit(t_data *data, char *msg, int status)
{
	mlx_free(data);
	ft_exit(msg, status);
}

void	mlx_error(t_data *data)
{
	mlx_free(data);
	ft_exit("Error: Something went wrong with MiniLibX\n", 1);
}

void	mlx_hook_exit(t_data *data)
{
	mlx_free(data);
	exit(0);
}