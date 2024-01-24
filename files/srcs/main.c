/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkeraudr <dkeraudr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 18:30:53 by acrespy           #+#    #+#             */
/*   Updated: 2024/01/24 21:42:03 by dkeraudr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/miniRT.h"

int	init_minirt(t_minirt *minirt)
{
	minirt->scene = malloc(sizeof(t_scene));
	if (!minirt->scene)
		return (0);
	minirt->scene->camera = malloc(sizeof(t_camera));
	if (!minirt->scene->camera)
		return (0);
	minirt->scene->ambient = malloc(sizeof(t_ambient));
	if (!minirt->scene->ambient)
		return (0);
	minirt->scene->lights = NULL;
	minirt->scene->objects = NULL;
	return (1);
}


int	main(int argc, char **argv, char **envp)
{
	t_minirt	minirt;

	data_initialize(&minirt);

	args_check(argc, argv, envp);
	if (!init_minirt(&minirt))
		return (0);
	if (!ft_parse_rt_file(minirt.scene, argv[1]))
	{
		data_free(&minirt);
		ft_printf("Error while parsing\n");
		return (0);
	}
	ft_print_scene(minirt.scene);
	// mlx_initialize_win(&minirt);
	// mlx_hook_loop(&minirt);
	// mlx_free(&minirt);
	// data_free(&minirt);

	return (0);
}
