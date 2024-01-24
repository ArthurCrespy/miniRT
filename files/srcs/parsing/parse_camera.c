/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_camera.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkeraudr <dkeraudr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 22:01:44 by dkeraudr          #+#    #+#             */
/*   Updated: 2024/01/24 22:04:31 by dkeraudr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

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
		return (free(camera), ft_free_2d_list(tab), ft_error(ERROR_WRONG_ARGS_NB),
			ft_error(ERROR_PARSING_CAMERA), 0);
	if (!ft_parse_point(tab[1], &camera->center))
		return (free(camera), ft_free_2d_list(tab), ft_error(ERROR_PARSING_CAMERA), 0);
	if (!ft_parse_vector(tab[2], &camera->orientation))
		return (free(camera), ft_free_2d_list(tab), ft_error(ERROR_PARSING_CAMERA), 0);
	if (!ft_isint(tab[3]))
		return (free(camera), ft_free_2d_list(tab), ft_error(ERROR_PARSING_CAMERA), 0);
	camera->fov = ft_atoi(tab[3]);
	scene->camera = camera;
	ft_free_2d_list(tab);
	return (1);
	// todo: add check for fov value
	// todo: add check for orientation value (normalized vector)
}
