/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_free.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acrespy <acrespy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 07:46:01 by acrespy           #+#    #+#             */
/*   Updated: 2023/11/20 07:46:01 by acrespy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/miniRT.h"

void	data_free(t_data *data)
{
	if (data->mlx)
		free(data->mlx);
	if (data->file->content)
		ft_free(data->file->content);
	if (data->file)
		free(data->file);
}
