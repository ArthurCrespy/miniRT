/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_subcomponents.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkeraudr <dkeraudr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 21:07:41 by dkeraudr          #+#    #+#             */
/*   Updated: 2024/01/18 21:24:11 by dkeraudr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	ft_parse_point(char *line, t_point *point)
{
	char	**tab;

	tab = ft_split(line, ',');
	if (!tab)
		return (0);
	if (ft_tablen(tab) != 3)
		return (0);
	point->x = ft_atof(tab[0]);
	point->y = ft_atof(tab[1]);
	point->z = ft_atof(tab[2]);
	return (1);
}

int	ft_parse_color(char *line, t_color *color)
{
	char	**tab;

	tab = ft_split(line, ',');
	if (!tab)
		return (0);
	if (ft_tablen(tab) != 3)
		return (0);
	color->chan_1 = ft_atof(tab[0]);
	color->chan_2 = ft_atof(tab[1]);
	color->chan_3 = ft_atof(tab[2]);
	return (1);
}

int	ft_parse_vector(char *line, t_vector *vector)
{
	char	**tab;

	tab = ft_split(line, ',');
	if (!tab)
		return (0);
	if (ft_tablen(tab) != 3)
		return (0);
	vector->x = ft_atof(tab[0]);
	vector->y = ft_atof(tab[1]);
	vector->z = ft_atof(tab[2]);
	return (1);
}
