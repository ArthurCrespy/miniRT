/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tuple_transform.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkeraudr <dkeraudr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 16:24:11 by dkeraudr          #+#    #+#             */
/*   Updated: 2024/03/20 21:26:30 by dkeraudr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_tuple	tuple_transform(t_tuple tuple, t_matrix matrix)
{
	t_tuple	res;

	res.x = matrix.matrix[0][0] * tuple.x + matrix.matrix[0][1] * tuple.y
		+ matrix.matrix[0][2] * tuple.z + matrix.matrix[0][3] * tuple.w;
	res.y = matrix.matrix[1][0] * tuple.x + matrix.matrix[1][1] * tuple.y
		+ matrix.matrix[1][2] * tuple.z + matrix.matrix[1][3] * tuple.w;
	res.z = matrix.matrix[2][0] * tuple.x + matrix.matrix[2][1] * tuple.y
		+ matrix.matrix[2][2] * tuple.z + matrix.matrix[2][3] * tuple.w;
	res.w = matrix.matrix[3][0] * tuple.x + matrix.matrix[3][1] * tuple.y
		+ matrix.matrix[3][2] * tuple.z + matrix.matrix[3][3] * tuple.w;
	return (res);
}
