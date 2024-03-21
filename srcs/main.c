/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkeraudr <dkeraudr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 18:30:53 by acrespy           #+#    #+#             */
/*   Updated: 2024/03/21 22:55:37 by dkeraudr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

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
		ft_error(ERROR_PARSING_FILE);
		return (0);
	}
	mlx_initialize_win(&minirt);
	mlx_hook_loop(&minirt);
	mlx_free(&minirt);
	data_free(&minirt);
	return (1);
}
