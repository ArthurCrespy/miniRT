/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkeraudr <dkeraudr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 18:46:26 by dkeraudr          #+#    #+#             */
/*   Updated: 2024/01/11 18:49:35 by dkeraudr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	handle_keys(int keycode, t_minirt	*mini_struct)
{
	if (keycode == 65307)
		exit_program(mini_struct);
	return (0);
}
