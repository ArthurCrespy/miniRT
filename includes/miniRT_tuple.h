/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_tuple.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acrespy <acrespy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 11:23:55 by acrespy           #+#    #+#             */
/*   Updated: 2024/03/22 11:23:55 by acrespy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_TUPLE_H
# define MINIRT_TUPLE_H

# include "./miniRT_struct.h"

typedef struct s_tuple
{
	double	x;
	double	y;
	double	z;
	double	w;
}		t_tuple;

typedef t_tuple	t_point;
typedef t_tuple	t_vector;

#endif
