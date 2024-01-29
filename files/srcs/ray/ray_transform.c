/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_transform.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acrespy <acrespy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 15:16:09 by acrespy           #+#    #+#             */
/*   Updated: 2024/01/29 15:16:09 by acrespy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../includes/miniRT.h"

t_ray	ray_transform(t_ray r, t_matrix m)
{
    return (ray_new(matrix_tuple_mult(m, r.origin),matrix_tuple_mult(m, r.direction)));
}