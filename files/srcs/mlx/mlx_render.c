/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_render.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkeraudr <dkeraudr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 15:00:18 by acrespy           #+#    #+#             */
/*   Updated: 2024/02/18 15:50:02 by dkeraudr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

char	*get_percent(double percent)
{
	char	*str;
	char	*tmp;

	str = ft_itoa((int)percent);
	tmp = ft_strjoin(str, "%");
	free(str);
	return (tmp);
}

int	mlx_render_frame(t_minirt *data)
{
	render_scene(data);
	mlx_string_put(data->mlx->mlx, data->mlx->mlx_win, 50, 50, 0x00FFFFFF,
		get_percent((double)data->pxl_rendered * 100 / (data->mlx->win_width * data->mlx->win_height)));
	return (0);
}
