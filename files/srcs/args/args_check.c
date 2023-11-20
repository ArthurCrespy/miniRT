/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acrespy <acrespy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 16:14:01 by acrespy           #+#    #+#             */
/*   Updated: 2023/11/19 16:14:03 by acrespy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/miniRT.h"

int	args_check(int argc, char **argv, char **envp)
{
	if (!envp[0])
		ft_exit("Error: No environment\n", 1);
	if (argc != 2)
		ft_exit("Error: Wrong number of arguments\n", 1);
	file_check_ext(argv[1]);
	file_check_path(argv[1]);
	return (0);
}
