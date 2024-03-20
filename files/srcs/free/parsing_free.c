/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_free.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkeraudr <dkeraudr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 22:24:45 by dkeraudr          #+#    #+#             */
/*   Updated: 2024/03/20 19:57:51 by dkeraudr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	free_parse_camera(t_camera *camera, char **tab)
{
	free_camera(camera);
	if (tab)
		ft_free_2d_list(tab);
	ft_error(ERROR_PARSING_CAMERA);
}

void	free_parse_hittable(t_hittable *hittable, char **tab, int id)
{
	if (hittable)
		free_hittable(hittable);
	if (tab)
		ft_free_2d_list(tab);
	if (id == SPHERE)
		ft_error(ERROR_PARSING_SPHERE);
	else if (id == CYLINDER)
		ft_error(ERROR_PARSING_CYLINDER);
	else if (id == PLANE)
		ft_error(ERROR_PARSING_PLANE);
}

void	free_parse_light(t_light *light, char **tab)
{
	if (light)
		free(light);
	if (tab)
		ft_free_2d_list(tab);
	ft_error(ERROR_PARSING_LIGHT);
}

void	free_parse_ambient(t_ambient *ambient, char **tab)
{
	if (ambient)
		free(ambient);
	if (tab)
		ft_free_2d_list(tab);
	ft_error(ERROR_PARSING_AMBIENT);
}
