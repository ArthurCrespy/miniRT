/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkeraudr <dkeraudr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 20:46:09 by dkeraudr          #+#    #+#             */
/*   Updated: 2024/02/18 16:50:28 by dkeraudr         ###   ########.fr       */
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
	t_ray	ray_transformed;
	t_matrix	*invert_transform;

	// printf("base_matrix\n");
	// ft_print_matrix(*obj->transform);
	invert_transform = matrix_inverse(*obj->transform);
	ray_transformed = ray_transform(ray, *invert_transform);
	// printf("invert_matrix\n");
	// ft_print_matrix(*invert_transform);
	if (obj->type == SPHERE)
		return (intersect_with_sphere(ray_transformed));
	else if (obj->type == PLANE)
		return (intersect_with_plane(ray_transformed));
	else if (obj->type == CYLINDER)
		return (intersect_with_cylinder(ray_transformed));
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
