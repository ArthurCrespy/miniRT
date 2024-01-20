/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_double_operations.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acrespy <acrespy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 13:48:23 by acrespy           #+#    #+#             */
/*   Updated: 2024/01/20 13:48:23 by acrespy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../includes/miniRT.h"

t_vector	vec_double_mult(t_vector v, double nb)
{
	t_vector	res;

	res.x = v.x * nb;
	res.y = v.y * nb;
	res.z = v.z * nb;
	return (res);
}

t_vector	vec_double_div(t_vector v, double nb)
{
	t_vector	res;

	res.x = v.x / nb;
	res.y = v.y / nb;
	res.z = v.z / nb;
	return (res);
}