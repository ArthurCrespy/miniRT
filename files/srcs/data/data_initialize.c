/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_initialize.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkeraudr <dkeraudr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 07:46:43 by acrespy           #+#    #+#             */
/*   Updated: 2024/01/16 21:02:31 by dkeraudr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../includes/miniRT.h"

void	data_initialize(t_minirt *data)
{
	data->mlx = malloc(sizeof(t_mlx));
	if (!data->mlx)
		ft_exit("Error: malloc failed\n", 1);
}
