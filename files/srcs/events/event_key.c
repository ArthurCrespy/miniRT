/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_key.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkeraudr <dkeraudr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 14:39:43 by acrespy           #+#    #+#             */
/*   Updated: 2024/02/18 14:01:46 by dkeraudr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../includes/miniRT.h"

int	event_key(int keycode, void *data)
{
	if (keycode == 65307)
		mlx_exit(data, "NULL", 0);
	return (0);
}
