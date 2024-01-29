/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tuple_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arthur <arthur@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 20:33:36 by arthur            #+#    #+#             */
/*   Updated: 2024/01/28 20:33:37 by arthur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/miniRT.h"

t_tuple tuple_add(t_tuple t1, t_tuple t2)
{
    return (tuple_new(t1.x + t2.x, t1.y + t2.y, t1.z + t2.z, t1.w + t2.w));
}

t_tuple tuple_sub(t_tuple t1, t_tuple t2)
{
    return (tuple_new(t1.x - t2.x, t1.y - t2.y, t1.z - t2.z, t1.w - t2.w));
}

t_tuple tuple_mult(t_tuple t1, double nb)
{
    return (tuple_new(t1.x * nb, t1.y * nb, t1.z * nb, t1.w * nb));
}

t_tuple tuple_div(t_tuple t1, t_tuple t2)
{
    return (tuple_new(t1.x / t2.x, t1.y / t2.y, t1.z / t2.z, t1.w / t2.w));
}

t_tuple tuple_negate(t_tuple t1)
{
    return (tuple_new(-t1.x, -t1.y, -t1.z, -t1.w));
}
