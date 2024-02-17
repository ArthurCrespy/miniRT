/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_subcomponents.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkeraudr <dkeraudr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 21:07:41 by dkeraudr          #+#    #+#             */
/*   Updated: 2024/02/17 14:53:46 by dkeraudr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	ft_parse_center(char *line, t_matrix *transform)
{
	char	**tab;

	tab = ft_split(line, ',');
	if (!tab)
		return (ft_error(ERROR_MALLOC), 0);
	if (ft_tablen(tab) != 3 || !ft_isfloat(tab[0])
		|| !ft_isfloat(tab[1]) || !ft_isfloat(tab[2]))
	{
		ft_free_2d_list(tab);
		ft_error(ERROR_PARSING_CENTER);
		return (0);
	}
	transform->matrix[0][3] = ft_atof(tab[0]);
	transform->matrix[1][3] = ft_atof(tab[1]);
	transform->matrix[2][3] = ft_atof(tab[2]);
	ft_free_2d_list(tab);
	return (1);
}

int	ft_parse_color(char *line, t_color *color)
{
	char	**tab;

	tab = ft_split(line, ',');
	if (!tab)
		return (ft_error(ERROR_MALLOC), 0);
	if (ft_tablen(tab) != 3 || !ft_isint(tab[0])
		|| !ft_isint(tab[1]) || !ft_isint(tab[2]))
	{
		ft_free_2d_list(tab);
		ft_error(ERROR_PARSING_COLOR);
		return (0);
	}
	color->chan_1 = ft_atof(tab[0]);
	color->chan_2 = ft_atof(tab[1]);
	color->chan_3 = ft_atof(tab[2]);
	if (color->chan_1 < 0 || color->chan_1 > 255
		|| color->chan_2 < 0 || color->chan_2 > 255
		|| color->chan_3 < 0 || color->chan_3 > 255)
	{
		ft_free_2d_list(tab);
		ft_error(ERROR_PARSING_COLOR);
		return (0);
	}
	ft_free_2d_list(tab);
	return (1);
}

int	ft_parse_rotation(char *line, t_matrix *transform)
{
	char	**tab;

	tab = ft_split(line, ',');
	if (!tab)
		return (ft_error(ERROR_MALLOC), 0);
	if (ft_tablen(tab) != 3 || !ft_isfloat(tab[0])
		|| !ft_isfloat(tab[1]) || !ft_isfloat(tab[2]))
	{
		ft_free_2d_list(tab);
		ft_error(ERROR_PARSING_ROTATION);
		return (0);
	}
	// roatation is given by a normalized vector
	matrix_rotation(transform, vector_new(ft_atof(tab[0]),
			ft_atof(tab[1]), ft_atof(tab[2])));
	ft_free_2d_list(tab);
	return (1);
}


int	ft_parse_scale(double scale_x, double scale_y, double scale_z,
	t_matrix *transform)
{
	transform->matrix[0][0] = scale_x;
	transform->matrix[1][1] = scale_y;
	transform->matrix[2][2] = scale_z;
	return (1);
}
