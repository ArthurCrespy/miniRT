/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkeraudr <dkeraudr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 13:48:29 by dkeraudr          #+#    #+#             */
/*   Updated: 2024/01/11 18:59:20 by dkeraudr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

char	*get_window_name(void)
{
	return ("MiniRT");
}

int	attach_vars(t_minirt *mini_struct, t_vars *vars)
{
	mini_struct->vars = vars;
	mini_struct->img_data = (t_data *)malloc(sizeof(t_data));
	if (!mini_struct->img_data)
		return (0);
	mini_struct->img_data->img = mlx_new_image(vars->mlx, WIDTH, HEIGHT);
	mini_struct->img_data->addr = mlx_get_data_addr(mini_struct->img_data->img,
			&mini_struct->img_data->bits_per_pixel,
			&mini_struct->img_data->line_length,
			&mini_struct->img_data->endian);
	return (1);
}

int	main(int argc, char **argv)
{
	t_vars		vars;
	t_minirt	*mini_struct;

	(void)argc;
	(void)argv;
	mini_struct = (t_minirt *)malloc(sizeof(t_minirt));
	vars.mlx = mlx_init();
	if (!vars.mlx)
		return (0);
	if (!attach_vars(mini_struct, &vars))
		return (exit_program(mini_struct));
	vars.win = mlx_new_window(vars.mlx, WIDTH, HEIGHT,
			get_window_name());
	mlx_hook(vars.win, 2, 1L << 0, handle_keys, mini_struct);
	mlx_put_image_to_window(mini_struct->vars->mlx, mini_struct->vars->win,
		mini_struct->img_data->img, 0, 0);
	mlx_loop(vars.mlx);
}
