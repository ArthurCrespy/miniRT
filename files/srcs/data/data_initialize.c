/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_initialize.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acrespy <acrespy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 07:46:43 by acrespy           #+#    #+#             */
/*   Updated: 2023/11/20 07:46:43 by acrespy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/miniRT.h"

void	data_initialize(t_data *data)
{
	data->mlx = malloc(sizeof(t_mlx));
	if (!data->mlx)
		ft_exit("Error: malloc failed\n", 1);
	data->file = malloc(sizeof(t_file));
	if (!data->file)
		ft_exit("Error: malloc failed\n", 1);
}
