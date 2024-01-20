/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_create.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acrespy <acrespy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 11:11:29 by acrespy           #+#    #+#             */
/*   Updated: 2024/01/20 11:11:29 by acrespy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../includes/miniRT.h"

t_matrix_4	matrix_4_new_value(double value)
{
	int			i;
	int			j;
	t_matrix_4	m;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
			m.m[i][j++] = value;
		i++;
	}
	return (m);
}

t_matrix_4	matrix_4_new_identity(void)
{
	int			i;
	t_matrix_4	m;

	i = 0;
	m = matrix_4_new();
	while (i < 4)
	{
		m.m[i][i] = 1;
		i++;
	}
	return (m);
}

t_matrix_4	matrix_4_new(void)
{
	int			i;
	int			j;
	t_matrix_4	m;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
			m.m[i][j++] = 0;
		i++;
	}
	return (m);
}

t_matrix_3	matrix_3_new(void)
{
	int			i;
	int			j;
	t_matrix_3	m;

	i = 0;
	while (i < 3)
	{
		j = 0;
		while (j < 3)
			m.m[i][j++] = 0;
		i++;
	}
	return (m);
}

t_matrix_2	matrix_2_new(void)
{
	int			i;
	int			j;
	t_matrix_2	m;

	i = 0;
	while (i < 2)
	{
		j = 0;
		while (j < 2)
			m.m[i][j++] = 0;
		i++;
	}
	return (m);
}
