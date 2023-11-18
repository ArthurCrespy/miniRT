/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acrespy <acrespy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 18:30:53 by acrespy           #+#    #+#             */
/*   Updated: 2023/11/18 19:17:22 by acrespy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/miniRT.h"

int	key_press(int keycode, void *data)
{
	(void)data;
	if (keycode == 65307)
		exit(0);
	return (0);
}

int	mlx_hook_exit(void *data)
{
	(void)data;
	exit(0);
}

int main(void)
{
	void		*mlx;
	void		*mlx_win;
	int         win_width;
	int         win_height;
	void		*img;

	printf("Hello, World!\n");

	mlx = NULL;
	mlx_win = NULL;
	img = NULL;

	mlx = mlx_init();
	if (!mlx)
		return (1);
	mlx_get_screen_size(mlx, &win_width, &win_height);
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello, World!");
	if (!mlx_win)
		return (1);

	img = mlx_new_image(mlx, 1920, 1080);
	if (!img)
		return (1);

	mlx_put_image_to_window(mlx, mlx_win, img, 0, 0);

	mlx_hook(mlx_win, 2, 1L << 0, (int (*)(void)) key_press, NULL);
	mlx_hook(mlx_win, 17, 1L << 17, (int (*)(void)) mlx_hook_exit, NULL);
	mlx_loop(mlx);

	mlx_destroy_display(mlx);
	free(mlx);

	return (0);
}
