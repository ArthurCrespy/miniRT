/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_position.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acrespy <acrespy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 14:58:20 by acrespy           #+#    #+#             */
/*   Updated: 2024/01/29 14:58:23 by acrespy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../includes/miniRT.h"

t_point	ray_position(t_ray ray, double t)
{
	return (tuple_add(ray.origin, tuple_mult(ray.direction, t)));
}
