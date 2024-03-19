/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_transforms.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkeraudr <dkeraudr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 21:29:51 by dkeraudr          #+#    #+#             */
/*   Updated: 2024/03/19 21:30:58 by dkeraudr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "miniRT.h"

int	ft_apply_rotation(t_vector orientation, t_matrix *transform)
{
	t_matrix	*rotation;

	rotation = matrix_rotation(orientation);
	if (!rotation)
	{
		ft_error(ERROR_MALLOC);
		return (0);
	}
	matrix_transform(transform, rotation);
	free(rotation);
	return (1);
}

int	ft_parse_rotation(char *line, t_matrix *transform)
{
	char		**tab;
	t_vector	orientation;

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
	if (tuple_mag(orientation) != 1)
	{
		ft_free_2d_list(tab);
		ft_error(ERROR_ORIENTATION_NORMALIZED);
		return (0);
	}
	ft_apply_rotation(orientation, transform);
	ft_free_2d_list(tab);
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

int	ft_parse_translation(char *line, t_matrix *transform)
{
	char		**tab;
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