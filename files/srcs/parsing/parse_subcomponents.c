/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_subcomponents.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkeraudr <dkeraudr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 21:07:41 by dkeraudr          #+#    #+#             */
/*   Updated: 2024/03/14 20:21:41 by dkeraudr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	ft_parse_tuple(char *line, t_tuple *tuple)
{
	char	**tab;

	tab = ft_split(line, ',');
	if (!tab)
		return (ft_error(ERROR_MALLOC), 0);
	if (ft_tablen(tab) != 3 || !ft_isfloat(tab[0])
		|| !ft_isfloat(tab[1]) || !ft_isfloat(tab[2]))
	{
		ft_free_2d_list(tab);
		ft_error(ERROR_PARSING_POINT);
		return (0);
	}
	tuple->x = ft_atof(tab[0]);
	tuple->y = ft_atof(tab[1]);
	tuple->z = ft_atof(tab[2]);
	tuple->w = 1;
	ft_free_2d_list(tab);
	return (1);
}

int	ft_parse_center(char *line, t_matrix *transform)
{
	char	**tab;
	t_matrix	*translation;

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
	translation = matrix_translation(ft_atof(tab[0]),
			ft_atof(tab[1]), ft_atof(tab[2]));
	if (!translation)
	{
		ft_free_2d_list(tab);
		ft_error(ERROR_MALLOC);
		return (0);
	}
	matrix_transform(transform, translation);
	ft_free_2d_list(tab);
	free(translation);
	return (1);
}

int	ft_apply_rotation(t_vector orientation, t_matrix *transform, t_vector default_up)
{
	t_matrix	*rotation;

	rotation = matrix_rotation(orientation, default_up);
	// (void)orientation;
	// rotation = matrix_identity();
	if (!rotation)
	{
		ft_error(ERROR_MALLOC);
		return 0;
	}
	matrix_transform(transform, rotation);
	free(rotation);
	return 1;
}

int	ft_parse_rotation(char *line, t_matrix *transform, t_vector default_up)
{
	char	**tab;
	t_vector	orientation;
	// t_matrix	*rotation;

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
	orientation = vector_new(ft_atof(tab[0]), ft_atof(tab[1]), ft_atof(tab[2]));
	// if (tuple_mag(orientation) != 1)
	// {
	// 	ft_free_2d_list(tab);
	// 	ft_error(ERROR_ORIENTATION_NORMALIZED);
	// 	return (0);
	// }
	ft_apply_rotation(orientation, transform, default_up);
	return (1);
}


int	ft_parse_scale(double scale_x, double scale_y, double scale_z,
	t_matrix *transform)
{
	t_matrix	*scale;

	scale = matrix_scale(scale_x, scale_y, scale_z);
	if (!scale)
	{
		ft_error(ERROR_MALLOC);
		return (0);
	}
	matrix_transform(transform, scale);
	free(scale);
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
	color->chan_1 = 1 / 255.0 * ft_atoi(tab[0]);
	color->chan_2 = 1 / 255.0 * ft_atoi(tab[1]);
	color->chan_3 = 1 / 255.0 * ft_atoi(tab[2]);
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
int	ft_parse_vector(char *line, t_vector *vector)
{
	char	**tab;

	tab = ft_split(line, ',');
	if (!tab)
		return (ft_error(ERROR_MALLOC));
	if (ft_tablen(tab) != 3 || !ft_isfloat(tab[0])
		|| !ft_isfloat(tab[1]) || !ft_isfloat(tab[2]))
	{
		ft_free_2d_list(tab);
		ft_error(ERROR_PARSING_VECTOR);
		return (0);
	}
	vector->x = ft_atof(tab[0]);
	vector->y = ft_atof(tab[1]);
	vector->z = ft_atof(tab[2]);
	vector->w = 0;
	ft_free_2d_list(tab);
	return (1);
}