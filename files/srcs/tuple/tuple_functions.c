/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tuple_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arthur <arthur@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 20:38:32 by arthur            #+#    #+#             */
/*   Updated: 2024/01/28 20:38:32 by arthur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/miniRT.h"

double  tuple_mag(t_tuple t1)
{
    return (sqrt(pow(t1.x, 2) + pow(t1.y, 2) + pow(t1.z, 2) + pow(t1.w, 2)));
}

t_tuple tuple_norm(t_tuple t1)
{
    double  mag;

    mag = tuple_mag(t1);
    return (tuple_new(t1.x / mag, t1.y / mag, t1.z / mag, t1.w / mag));
}

double  tuple_dot(t_tuple t1, t_tuple t2)
{
    return (t1.x * t2.x + t1.y * t2.y + t1.z * t2.z + t1.w * t2.w);
}

t_tuple tuple_cross(t_tuple t1, t_tuple t2)
{
    return (tuple_new_vector(t1.y * t2.z - t1.z * t2.y,
                       t1.z * t2.x - t1.x * t2.z,
                       t1.x * t2.y - t1.y * t2.x));
}

t_tuple tuple_reflect(t_tuple t, t_tuple normal)
{
    return (tuple_sub(t, tuple_mult(normal, 2 * tuple_dot(t, normal))));
}
