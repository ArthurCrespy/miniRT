/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_free.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkeraudr <dkeraudr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 07:46:01 by acrespy           #+#    #+#             */
/*   Updated: 2024/03/20 20:34:29 by dkeraudr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	free_intersection(void *content)
{
	t_intersection	*inter;

	inter = (t_intersection *)content;
	free(inter);
}

void	data_free(t_minirt *data)
{
	if (data->mlx)
		free(data->mlx);
	if (data->scene)
		free_scene(data->scene);
}
