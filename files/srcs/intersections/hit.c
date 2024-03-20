/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkeraudr <dkeraudr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 20:33:47 by dkeraudr          #+#    #+#             */
/*   Updated: 2024/03/20 20:39:10 by dkeraudr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_intersection	*ft_hit(t_list *intersections)
{
	t_list			*tmp;
	t_intersection	*hit;

	tmp = intersections;
	hit = NULL;
	while (tmp)
	{
		if (tmp->content
			&& (!hit || ((t_intersection *)tmp->content)->t < hit->t)
			&& ((t_intersection *)tmp->content)->t > 0)
			hit = tmp->content;
		tmp = tmp->next;
	}
	return (hit);
}
