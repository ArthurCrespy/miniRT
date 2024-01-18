/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acrespy <acrespy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 14:27:51 by acrespy           #+#    #+#             */
/*   Updated: 2024/01/18 14:27:51 by acrespy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/miniRT.h"
#include "./../criterion/include/criterion/criterion.h"

Test(tuple, tuple_new)
{
	t_tuple v;

	v = tuple_new(1, 2, 3, 4);
	cr_assert_eq(v.x, 1);
	cr_assert_eq(v.y, 2);
	cr_assert_eq(v.z, 3);
	cr_assert_eq(v.w, 4);
}
