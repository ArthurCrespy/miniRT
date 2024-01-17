/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_camera.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkeraudr <dkeraudr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 22:01:44 by dkeraudr          #+#    #+#             */
/*   Updated: 2024/01/17 22:03:39 by dkeraudr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	ft_parse_camera(t_scene *scene, char *line)
{
	t_camera	*camera;
	char		**tab;

	camera = malloc(sizeof(t_camera));
	if (!camera)
		return (0);
	tab = ft_split(line, ' ');
	if (!tab)
		return (0);
	if (ft_tablen(tab) != 4)
		return (0);
	if (!ft_parse_point(tab[1], &camera->center))
		return (0);
	if (!ft_parse_vector(tab[2], &camera->orientation))
		return (0);
	camera->fov = ft_atof(tab[3]);
	scene->camera = camera;
	return (1);
	// todo: add check for fov value
	// todo: add check for orientation value (normalized vector)
}
