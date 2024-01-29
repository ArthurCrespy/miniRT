/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_create.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acrespy <acrespy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 13:39:12 by acrespy           #+#    #+#             */
/*   Updated: 2024/01/20 13:39:12 by acrespy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../includes/miniRT.h"

t_ray				ray_new(t_point origin, t_vector direction)
{
    t_ray	ray;

    ray.origin = origin;
    ray.direction = direction;
    return (ray);
}

t_point				ray_position(t_ray ray, double t)
{
    return (tuple_add(ray.origin, tuple_mult(ray.direction, t)));
}

t_ray	transform(t_ray r, t_matrix m)
{
    return (
        new_ray(
            multiply_tp_mx(m, r.origin),
            multiply_tp_mx(m, r.direction))
    );
}
