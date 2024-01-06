/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkeraudr <dkeraudr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 13:48:29 by dkeraudr          #+#    #+#             */
/*   Updated: 2024/01/06 13:15:42 by dkeraudr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

char	*get_window_name()
{
	return ("MiniRT");
}


int	main(int argc, char **argv)
{
	t_vars		vars;
	t_data *img_data;

	(void)argc;
	(void)argv;
	vars.mlx = mlx_init();
	if (!vars.mlx)
		return (0);
	vars.win = mlx_new_window(vars.mlx, WIDTH, HEIGHT,
			get_window_name());
	img_data = (t_data *)malloc(sizeof(t_data));
	if (!img_data)
		return (0);
	img_data->img = mlx_new_image(vars.mlx, WIDTH, HEIGHT);
	img_data->addr = mlx_get_data_addr(img_data->img,
			&img_data->bits_per_pixel,
			&img_data->line_length,
			&img_data->endian);
	mlx_put_image_to_window(vars.mlx, vars.win,
		img_data->img, 0, 0);
	mlx_loop(vars.mlx);
}
