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



int	main(int argc, char **argv, char **envp)
{
	t_data	data;

	printf("Hello, World!\n");

	args_check(argc, argv, envp);
	file_save(&data, argv[1]);

	for (int i = 0; data.file->content[i]; i++)
		printf("%s\n", data.file->content[i]);

	mlx_initialize_win(&data);
	mlx_hook_loop(&data);
	mlx_free(&data);

	return (0);
}
