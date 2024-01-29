/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_lighting.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkeraudr <dkeraudr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 22:05:20 by dkeraudr          #+#    #+#             */
/*   Updated: 2024/01/24 22:37:37 by dkeraudr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../includes/miniRT.h"

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

int	ft_parse_light(t_scene *scene, char *line)
{
	t_light	*light;
	char	**tab;

	light = malloc(sizeof(t_light));
	if (!light)
		return (ft_error(ERROR_MALLOC), 0);
	tab = ft_split(line, ' ');
	if (!tab)
		return (free(light), ft_error(ERROR_MALLOC), 0);
	if (ft_tablen(tab) != 4)
		return (ft_error(ERROR_WRONG_ARGS_NB),
			free_parse_light(light, tab), 0);
	if (!ft_parse_point(tab[1], &light->center))
		return (free_parse_light(light, tab), 0);
	if (!ft_isfloat(tab[2]))
		return (free_parse_light(light, tab), 0);
	light->brightness = ft_atof(tab[2]);
	if (!ft_parse_color(tab[3], &light->color))
		return (free_parse_light(light, tab), 0);
	ft_lstadd_back(&scene->lights, ft_lstnew(light));
	ft_free_2d_list(tab);
	return (1);
}

int	ft_parse_ambient(t_scene *scene, char *line)
{
	t_ambient	*ambient;
	char		**tab;

	ambient = malloc(sizeof(t_ambient));
	if (!ambient)
		return (ft_error(ERROR_MALLOC), 0);
	tab = ft_split(line, ' ');
	if (!tab)
		return (free(ambient), ft_error(ERROR_MALLOC), 0);
	if (ft_tablen(tab) != 3)
		return (ft_error(ERROR_WRONG_ARGS_NB),
			free_parse_ambient(ambient, tab), 0);
	if (!ft_isfloat(tab[1]))
		return (free_parse_ambient(ambient, tab), 0);
	ambient->brightness = ft_atof(tab[1]);
	if (!ft_parse_color(tab[2], &ambient->color))
		return (free_parse_ambient(ambient, tab), 0);
	scene->ambient = ambient;
	ft_free_2d_list(tab);
	free(ambient);
	return (1);
}