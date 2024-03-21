/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkeraudr <dkeraudr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 16:14:01 by acrespy           #+#    #+#             */
/*   Updated: 2024/02/18 15:09:21 by dkeraudr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	args_check(int argc, char **argv, char **envp)
{
	if (!envp[0])
		ft_exit("Error: No environment\n", 1);
	if (argc != 2)
		ft_exit("Error: Wrong number of arguments\n", 1);
	if (argv[1][0] == '0')
		return (0);
	file_check_ext(argv[1]);
	file_check_path(argv[1]);
	return (0);
}
