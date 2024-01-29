/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shearing_create.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acrespy <acrespy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 14:47:00 by acrespy           #+#    #+#             */
/*   Updated: 2024/01/29 14:57:42 by acrespy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../includes/miniRT.h"

t_shearing	shearing_new(double p1, double p2)
{
	t_shearing	s;

	s.p1 = p1;
	s.p2 = p2;
	return (s);
}
