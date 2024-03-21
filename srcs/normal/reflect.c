/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reflect.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkeraudr <dkeraudr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 20:21:21 by dkeraudr          #+#    #+#             */
/*   Updated: 2024/02/21 20:24:09 by dkeraudr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_vector	reflect(t_vector in, t_vector normal)
{
	return (tuple_sub(in, tuple_mult(normal, 2 * tuple_dot(in, normal))));
}
