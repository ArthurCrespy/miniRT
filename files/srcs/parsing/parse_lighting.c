/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_lighting.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkeraudr <dkeraudr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 22:05:20 by dkeraudr          #+#    #+#             */
/*   Updated: 2024/01/17 22:07:48 by dkeraudr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	ft_parse_light(t_scene *scene, char *line)
{
	t_light	*light;
	char	**tab;

	light = malloc(sizeof(t_light));
	if (!light)
		return (0);
	tab = ft_split(line, ' ');
	if (!tab)
		return (0);
	if (ft_tablen(tab) != 4)
		return (0);
	if (!ft_parse_point(tab[1], &light->center))
		return (0);
	light->brightness = ft_atof(tab[2]);
	if (!ft_parse_color(tab[3], &light->color))
		return (0);
	ft_lstadd_back(&scene->lights, ft_lstnew(light));
	return (1);
}

int	ft_parse_ambient(t_scene *scene, char *line)
{
	t_ambient	*ambient;
	char		**tab;

	ambient = malloc(sizeof(t_ambient));
	if (!ambient)
		return (0);
	tab = ft_split(line, ' ');
	if (!tab)
		return (0);
	if (ft_tablen(tab) != 3)
		return (0);
	ambient->brightness = ft_atof(tab[1]);
	if (!ft_parse_color(tab[2], &ambient->color))
		return (0);
	scene->ambient = ambient;
	return (1);
}
