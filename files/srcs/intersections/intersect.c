/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkeraudr <dkeraudr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 20:46:09 by dkeraudr          #+#    #+#             */
/*   Updated: 2024/02/12 20:31:30 by dkeraudr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_intersection	*create_intersect(double t, t_hittable *obj)
{
	t_intersection	*inter;

	inter = malloc(sizeof(t_intersection));
	if (!inter)
		return (NULL);
	inter->t = t;
	inter->obj = obj;
	return (inter);
}

double	*intersect_with(t_hittable *obj, t_ray ray)
{
	if (obj->type == SPHERE)
		return (intersect_with_sphere(obj, ray));
	return (NULL);
}

void	add_intersections(t_list **intersections, t_hittable *obj, t_ray ray)
{
	t_list	*new;
	double	*inter;

	inter = intersect_with(obj, ray);
	if (inter)
	{
		new = ft_lstnew(create_intersect(inter[0], obj));
		ft_lstadd_back(intersections, new);
		if (inter[0] != inter[1])
		{
			new = ft_lstnew(create_intersect(inter[1], obj));
			ft_lstadd_back(intersections, new);
		}
	}
}

t_list	*ft_intersect(t_list *objects, t_ray ray)
{
	t_list		*intersections;
	t_list		*tmp;
	t_hittable	*obj;

	intersections = NULL;
	tmp = objects;
	while (tmp)
	{
		obj = tmp->content;
		add_intersections(&intersections, obj, ray);
		tmp = tmp->next;
	}
	return (intersections);
}
