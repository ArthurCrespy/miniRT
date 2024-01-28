/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_hittable.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkeraudr <dkeraudr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 19:51:55 by dkeraudr          #+#    #+#             */
/*   Updated: 2024/01/28 16:44:56 by dkeraudr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	free_parse_hittable(t_hittable *hittable, char **tab, int id)
{
	if (hittable)
		free(hittable);
	if (tab)
		ft_free_2d_list(tab);
	if (id == SPHERE)
		ft_error(ERROR_PARSING_SPHERE);
	else if (id == CYLINDER)
		ft_error(ERROR_PARSING_CYLINDER);
	else if (id == PLANE)
		ft_error(ERROR_PARSING_PLANE);
}

int	ft_parse_sphere(t_scene *scene, char *line)
{
	t_hittable	*sphere;
	char		**tab;

	sphere = malloc(sizeof(t_hittable));
	if (!sphere)
		return (ft_error(ERROR_MALLOC), 0);
	tab = ft_split(line, ' ');
	if (!tab)
		return (free(sphere), ft_error(ERROR_MALLOC), 0);
	if (ft_tablen(tab) != 4)
		return (ft_error(ERROR_WRONG_ARGS_NB),
			free_parse_hittable(sphere, tab, SPHERE), 0);
	sphere->id = SPHERE;
	if (!ft_parse_point(tab[1], &sphere->center))
		return (free_parse_hittable(sphere, tab, SPHERE), 0);
	if (!ft_isfloat(tab[2]))
		return (free_parse_hittable(sphere, tab, SPHERE), 0);
	sphere->diameter = ft_atof(tab[2]);
	if (!ft_parse_color(tab[3], &sphere->color))
		return (free_parse_hittable(sphere, tab, SPHERE), 0);
	ft_lstadd_back(&scene->objects, ft_lstnew(sphere));
	ft_free_2d_list(tab);
	return (1);
}

int	ft_parse_cylinder(t_scene *scene, char *line)
{
	t_hittable	*cylinder;
	char		**tab;

	cylinder = malloc(sizeof(t_hittable));
	if (!cylinder)
		return (ft_error(ERROR_MALLOC), 0);
	tab = ft_split(line, ' ');
	if (!tab)
		return (ft_error(ERROR_MALLOC), 0);
	if (ft_tablen(tab) != 6)
		return (ft_error(ERROR_WRONG_ARGS_NB),
			free_parse_hittable(cylinder, tab, CYLINDER), 0);
	cylinder->id = CYLINDER;
	if (!ft_parse_point(tab[1], &cylinder->center))
		return (free_parse_hittable(cylinder, tab, CYLINDER), 0);
	if (!ft_parse_vector(tab[2], &cylinder->orientation))
		return (free_parse_hittable(cylinder, tab, CYLINDER), 0);
	if (!ft_isfloat(tab[3]) || !ft_isfloat(tab[4]))
		return (free_parse_hittable(cylinder, tab, CYLINDER), 0);
	cylinder->diameter = ft_atof(tab[3]);
	cylinder->height = ft_atof(tab[4]);
	if (!ft_parse_color(tab[5], &cylinder->color))
		return (free_parse_hittable(cylinder, tab, CYLINDER), 0);
	ft_lstadd_back(&scene->objects, ft_lstnew(cylinder));
	return (ft_free_2d_list(tab), 1);
}

int	ft_parse_plane(t_scene *scene, char *line)
{
	t_hittable	*plane;
	char		**tab;

	plane = malloc(sizeof(t_hittable));
	if (!plane)
		return (ft_error(ERROR_MALLOC), 0);
	tab = ft_split(line, ' ');
	if (!tab)
		return (free(plane), ft_error(ERROR_MALLOC), 0);
	if (ft_tablen(tab) != 4)
		return (ft_error(ERROR_WRONG_ARGS_NB),
			free_parse_hittable(plane, tab, PLANE), 0);
	plane->id = PLANE;
	if (!ft_parse_point(tab[1], &plane->center))
		return (free_parse_hittable(plane, tab, PLANE), 0);
	if (!ft_parse_vector(tab[2], &plane->orientation))
		return (free_parse_hittable(plane, tab, PLANE), 0);
	if (!ft_parse_color(tab[3], &plane->color))
		return (free_parse_hittable(plane, tab, PLANE), 0);
	ft_lstadd_back(&scene->objects, ft_lstnew(plane));
	ft_free_2d_list(tab);
	return (1);
}