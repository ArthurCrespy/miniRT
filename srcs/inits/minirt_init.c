/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkeraudr <dkeraudr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 22:54:17 by dkeraudr          #+#    #+#             */
/*   Updated: 2024/03/22 20:54:02 by dkeraudr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	init_minirt(t_minirt *minirt)
{
	if (!minirt->scene)
		return (0);
	minirt->scene->camera = NULL;
	minirt->scene->ambient = NULL;
	minirt->scene->lights = NULL;
	minirt->scene->objects = NULL;
	return (1);
}
