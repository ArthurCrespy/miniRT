/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkeraudr <dkeraudr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 18:30:53 by acrespy           #+#    #+#             */
/*   Updated: 2024/01/16 21:01:59 by dkeraudr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/miniRT.h"

int	main(int argc, char **argv, char **envp)
{
	t_minirt	minirt;

	printf("Hello, World!\n");
	data_initialize(&minirt);
	args_check(argc, argv, envp);
	file_save(&minirt, argv[1]);
	mlx_initialize_win(&minirt);
	mlx_hook_loop(&minirt);
	mlx_free(&minirt);
	data_free(&minirt);
	return (0);
}
