/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_comparaisons.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkeraudr <dkeraudr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 13:48:38 by acrespy           #+#    #+#             */
/*   Updated: 2024/02/18 15:09:21 by dkeraudr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

bool	double_equal(double nb1, double nb2)
{
	if (nb1 - nb2 < EPSILON)
		return (true);
	return (false);
}

bool	double_inf(double nb1, double nb2)
{
	if (nb1 - nb2 < EPSILON || nb1 - nb2 > -EPSILON)
		return (true);
	return (false);
}

bool	double_sup(double nb1, double nb2)
{
	if (nb1 - nb2 > EPSILON || nb1 - nb2 < -EPSILON)
		return (true);
	return (false);
}
