/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_subcomponents.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkeraudr <dkeraudr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 21:07:41 by dkeraudr          #+#    #+#             */
/*   Updated: 2024/01/22 22:40:12 by dkeraudr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	ft_parse_point(char *line, t_point *point)
{
	char	**tab;

	tab = ft_split(line, ',');
	if (!tab)
		return (ft_error(ERROR_MALLOC), 0);
	if (ft_tablen(tab) != 3 || ft_isfloat(tab[0])
		|| ft_isfloat(tab[1]) || ft_isfloat(tab[2]))
	{
		free(tab);
		ft_error(ERROR_PARSING_POINT);
		return (0);
	}
	point->x = ft_atof(tab[0]);
	point->y = ft_atof(tab[1]);
	point->z = ft_atof(tab[2]);
	free(tab);
	return (1);
}

int	ft_parse_color(char *line, t_color *color)
{
	char	**tab;

	tab = ft_split(line, ',');
	if (!tab)
		return (ft_error(ERROR_MALLOC), 0);
	if (ft_tablen(tab) != 3 || ft_isfloat(tab[0])
		|| ft_isfloat(tab[1]) || ft_isfloat(tab[2]))
	{
		free(tab);
		ft_error(ERROR_PARSING_COLOR);
		return (0);
	}
	color->chan_1 = ft_atof(tab[0]);
	color->chan_2 = ft_atof(tab[1]);
	color->chan_3 = ft_atof(tab[2]);
	free(tab);
	return (1);
}

int	ft_parse_vector(char *line, t_vector *vector)
{
	char	**tab;

	tab = ft_split(line, ',');
	if (!tab)
		return (ft_error(ERROR_MALLOC), 0);
	if (ft_tablen(tab) != 3 || ft_isfloat(tab[0])
		|| ft_isfloat(tab[1]) || ft_isfloat(tab[2]))
	{
		free(tab);
		ft_error(ERROR_PARSING_VECTOR);
		return (0);
	}
	vector->x = ft_atof(tab[0]);
	vector->y = ft_atof(tab[1]);
	vector->z = ft_atof(tab[2]);
	free(tab);
	return (1);
}
