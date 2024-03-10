/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_tests.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkeraudr <dkeraudr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 20:36:43 by dkeraudr          #+#    #+#             */
/*   Updated: 2024/03/09 16:55:38 by dkeraudr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT_test.h"

void	do_tests(void);
// void	do_lighting_00(void);
void	test_world_intersections(void);
void	test_precompute_intersections(void);

int	main(void)
{
	// do_tests();
	test_shadows_02();
	// test_world_intersections();
	// test_precompute_intersections();
	return (1);
}
