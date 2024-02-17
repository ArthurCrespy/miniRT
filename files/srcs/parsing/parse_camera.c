/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_camera.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkeraudr <dkeraudr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 22:01:44 by dkeraudr          #+#    #+#             */
/*   Updated: 2024/02/17 14:44:42 by dkeraudr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../includes/miniRT.h"

void	free_parse_camera(t_camera *camera, char **tab)
{
	if (camera)
		free(camera);
	if (tab)
		ft_free_2d_list(tab);
	ft_error(ERROR_PARSING_CAMERA);
}

int	ft_parse_camera(t_scene *scene, char *line)
{
	t_camera	*camera;
	char		**tab;

	camera = malloc(sizeof(t_camera));
	if (!camera)
		return (ft_error(ERROR_MALLOC), 0);
	tab = ft_split(line, ' ');
	if (!tab)
		return (free(camera), ft_error(ERROR_MALLOC), 0);
	if (ft_tablen(tab) != 4)
		return (ft_error(ERROR_WRONG_ARGS_NB),
			free_parse_camera(camera, tab), 0);
	if (!ft_parse_center(tab[1], &camera->transform))
		return (free_parse_camera(camera, tab), 0);
	if (!ft_parse_rotation(tab[2], &camera->transform))
		return (free_parse_camera(camera, tab), 0);
	if (!ft_isint(tab[3]))
		return (free_parse_camera(camera, tab), 0);
	camera->fov = ft_atof(tab[3]);
	scene->camera = camera;
	ft_free_2d_list(tab);
	return (1);
}

	// todo: add check for fov value
	// todo: add check for orientation value (normalized vector)