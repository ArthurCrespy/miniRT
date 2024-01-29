/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tuple_new.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arthur <arthur@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 20:32:53 by arthur            #+#    #+#             */
/*   Updated: 2024/01/28 20:33:02 by arthur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/miniRT.h"

t_tuple	tuple_new(double x, double y, double z, double w)
{
    t_tuple	t;

    t.x = x;
    t.y = y;
    t.z = z;
    t.w = w;
    return (t);
}

t_tuple	point_new(double x, double y, double z)
{
    return (tuple_new(x, y, z, 1.0));
}

t_tuple	vector_new(double x, double y, double z)
{
    return (tuple_new(x, y, z, 0.0));
}
