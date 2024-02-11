/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkeraudr <dkeraudr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 20:46:09 by dkeraudr          #+#    #+#             */
/*   Updated: 2024/02/11 21:43:18 by dkeraudr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_intersect	*intersect_with(t_hittable *obj, t_ray ray)
{
	if (obj->type == SPHERE)
		return (intersect_with_sphere(obj, ray));
	return (NULL);
}

t_list	*intersect(t_list *objects, t_ray ray)
{
	t_list		*intersections;
	t_list		*tmp;
	t_list		*new;
	t_hittable	*obj;

	intersections = NULL;
	tmp = objects;
	while (tmp)
	{
		obj = tmp->content;
		new = ft_lstnew(intersect_with(obj, ray));
		ft_lstadd_back(&intersections, new);
		tmp = tmp->next;
	}
	return (intersections);
}
