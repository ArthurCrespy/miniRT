/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkeraudr <dkeraudr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 19:01:03 by dkeraudr          #+#    #+#             */
/*   Updated: 2024/01/28 19:36:32 by dkeraudr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_vector	vector_new(double x, double y, double z)
{
	t_vector	v;

	v.x = x;
	v.y = y;
	v.z = z;
	return (v);
}

t_point	point_new(double x, double y, double z)
{
	t_point		p;

	p.x = x;
	p.y = y;
	p.z = z;
	return (p);
}
t_point	point_from_vector(t_vector v)
{
	t_point		p;

	p.x = v.x;
	p.y = v.y;
	p.z = v.z;
	return (p);
}

t_vector	vector_from_point(t_point p)
{
	t_vector	v;

	v.x = p.x;
	v.y = p.y;
	v.z = p.z;
	return (v);
}