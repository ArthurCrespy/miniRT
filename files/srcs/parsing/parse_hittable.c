/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_hittable.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkeraudr <dkeraudr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 19:51:55 by dkeraudr          #+#    #+#             */
/*   Updated: 2024/01/18 21:26:53 by dkeraudr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	ft_parse_sphere(t_scene *scene, char *line)
{
	t_hittable	*sphere;
	char		**tab;

	sphere = malloc(sizeof(t_hittable));
	if (!sphere)
		return (0);
	tab = ft_split(line, ' ');
	if (!tab)
		return (0);
	if (ft_tablen(tab) != 4)
		return (0);
	sphere->id = SPHERE;
	if (!ft_parse_point(tab[1], &sphere->center))
		return (0);
	sphere->diameter = ft_atof(tab[2]);
	if (!ft_parse_color(tab[3], &sphere->color))
		return (0);
	ft_lstadd_back(&scene->objects, ft_lstnew(sphere));
	return (1);
}

int	ft_parse_cylinder(t_scene *scene, char *line)
{
	t_hittable	*cylinder;
	char		**tab;

	cylinder = malloc(sizeof(t_hittable));
	if (!cylinder)
		return (0);
	tab = ft_split(line, ' ');
	if (!tab)
		return (0);
	if (ft_tablen(tab) != 6)
		return (0);
	cylinder->id = CYLINDER;
	if (!ft_parse_point(tab[1], &cylinder->center))
		return (0);
	if (!ft_parse_vector(tab[2], &cylinder->orientation))
		return (0);
	cylinder->diameter = ft_atof(tab[3]);
	cylinder->height = ft_atof(tab[4]);
	if (!ft_parse_color(tab[5], &cylinder->color))
		return (0);
	ft_lstadd_back(&scene->objects, ft_lstnew(cylinder));
	return (1);
}

int	ft_parse_plane(t_scene *scene, char *line)
{
	t_hittable	*plane;
	char		**tab;

	plane = malloc(sizeof(t_hittable));
	if (!plane)
		return (0);
	tab = ft_split(line, ' ');
	if (!tab)
		return (0);
	if (ft_tablen(tab) != 4)
		return (0);
	plane->id = PLANE;
	if (!ft_parse_point(tab[1], &plane->center))
		return (0);
	if (!ft_parse_vector(tab[2], &plane->orientation))
		return (0);
	if (!ft_parse_color(tab[3], &plane->color))
		return (0);
	ft_lstadd_back(&scene->objects, ft_lstnew(plane));
	return (1);
}
