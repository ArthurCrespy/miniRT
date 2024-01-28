/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkeraudr <dkeraudr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 16:31:59 by dkeraudr          #+#    #+#             */
/*   Updated: 2024/01/28 17:07:30 by dkeraudr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	ft_main_loop(t_minirt *ministruct)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < ministruct->mlx->win_height)
	{
		while (x < ministruct->mlx->win_width)
		{
			printf("x: %d\n", x);
			printf("y: %d\n", y);
			my_mlx_pixel_put(ministruct->mlx, x, y, 0x00FF0000);
			// my_mlx_pixel_put(ministruct->mlx, 0, 0, 0x00FF0000);
			// my_mlx_pixel_put(ministruct->mlx, 1, 1, 0x00FF0000);
			x++;
		}
	}
	
}
