/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkeraudr <dkeraudr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 18:30:53 by acrespy           #+#    #+#             */
/*   Updated: 2024/02/06 20:46:45 by dkeraudr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/miniRT.h"

int	init_minirt(t_minirt *minirt)
{
	minirt->scene = malloc(sizeof(t_scene));
	if (!minirt->scene)
		return (0);
	minirt->scene->camera = NULL;
	minirt->scene->ambient = NULL;
	minirt->scene->lights = NULL;
	minirt->scene->objects = NULL;
	return (1);
}


int	main(int argc, char **argv, char **envp)
{
	t_minirt	minirt;

	data_initialize(&minirt);
	args_check(argc, argv, envp);
//	file_save(&minirt, argv[1]);
	if (!init_minirt(&minirt))
		return (0);
	if (!ft_parse_rt_file(minirt.scene, argv[1]))
	{
		data_free(&minirt);
		ft_printf("Error while parsing\n");
		return (0);
	}
	mlx_initialize_win(&minirt);
//	test_tick(&minirt);
//	test_maths(&minirt);
	mlx_hook_loop(&minirt);
	mlx_free(&minirt);
	data_free(&minirt);
	ft_print_scene(minirt.scene);
	// mlx_initialize_win(&minirt);
	// mlx_hook_loop(&minirt);
	// mlx_free(&minirt);
	// data_free(&minirt);

	return (0);
}
