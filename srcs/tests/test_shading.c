/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_shading.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkeraudr <dkeraudr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 20:09:07 by dkeraudr          #+#    #+#             */
/*   Updated: 2024/03/09 16:35:00 by dkeraudr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT_test.h"

int		do_shading_tests(CU_pSuite suite)
{
	suite = CU_add_suite("Shading", NULL, NULL);
	if (NULL == suite)
		return (CU_cleanup_registry(), CU_get_error());

	if (!CU_add_test(suite, "Shading 00", test_shading_00))
		return (CU_cleanup_registry(), CU_get_error());

	return (0);
}


// Scenario: Shading an intersection
// Given w ← default_world()
// And r ← ray(point(0, 0, -5), vector(0, 0, 1))
// And shape ← the first object in w
// And i ← intersection(4, shape)
// When comps ← prepare_computations(i, r)
// And c ← shade_hit(w, comps)
// Then c = color(0.38066, 0.47583, 0.2855)

void	test_shading_00(void)
{
	t_scene	*scene;
	t_ray	r;
	t_intersection	*inter;
	t_computation	comps;
	t_color	c;

	scene = default_world();
	r = ray_new(point_new(0, 0, -5), vector_new(0, 0, 1));
	inter = create_intersect(4, scene->objects->content);
	comps = prepare_computations(inter, r);
	comps.light = scene->lights->content;
	comps.scene = scene;
	comps.object = scene->objects->content;
	c = lighting(&comps, false);
	CU_ASSERT_DOUBLE_EQUAL(c.chan_1, 0.38066, EPSILON);
	CU_ASSERT_DOUBLE_EQUAL(c.chan_2, 0.47583, EPSILON);
	CU_ASSERT_DOUBLE_EQUAL(c.chan_3, 0.2855, EPSILON);
}