/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_shadow.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkeraudr <dkeraudr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 16:17:53 by dkeraudr          #+#    #+#             */
/*   Updated: 2024/03/10 17:13:28 by dkeraudr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT_test.h"

// Scenario: Lighting with the surface in shadow
// Given eyev ← vector(0, 0, -1)
// And normalv ← vector(0, 0, -1)
// And light ← point_light(point(0, 0, -10), color(1, 1, 1))
// And in_shadow ← true
// When result ← lighting(m, light, position, eyev, normalv, in_shadow)
// Then result = color(0.1, 0.1, 0.1)

void	test_shadows_00(void)
{
	t_computation	lighting_info;
	t_color			result;
	t_scene			*scene;

	scene = default_world();
	((t_hittable *)scene->objects->content)->material->color = color_new(1, 1, 1);
	lighting_info.point = point_new(0, 0, 0);
	lighting_info.eye = vector_new(0, 0, -1);
	lighting_info.normal = vector_new(0, 0, -1);
	lighting_info.light = malloc(sizeof(t_light));
	if (!lighting_info.light)
	{
		CU_FAIL("malloc failed");
		return ;
	}
	lighting_info.light->position = point_new(0, 0, -10);
	lighting_info.light->brightness = 1;
	lighting_info.light->color = color_new(1, 1, 1);
	lighting_info.object = scene->objects->content;
	result = lighting(&lighting_info, true);
	printf("result: %f %f %f\n", result.chan_1, result.chan_2, result.chan_3);
	CU_ASSERT_DOUBLE_EQUAL(result.chan_1, 0.1, 0.0001);
	CU_ASSERT_DOUBLE_EQUAL(result.chan_2, 0.1, 0.0001);
	CU_ASSERT_DOUBLE_EQUAL(result.chan_3, 0.1, 0.0001);
	free(lighting_info.light);
}

// Scenario: There is no shadow when nothing is collinear with point and light
// Given w ← default_world()
// And p ← point(0, 10, 0)
// Then is_shadowed(w, p) is false

void	test_shadows_01(void)
{
	t_scene	*scene;
	t_point	p;

	scene = default_world();
	p = point_new(0, 10, 0);
	CU_ASSERT_FALSE(is_shadowed(scene, p));
}

void	test_shadows_02(void)
{
	t_scene	*scene;
	t_point	p;

	scene = default_world();
	ft_print_scene(scene);
	p = point_new(10, -10, 10);
	printf("is_shadowed: %d\n", is_shadowed(scene, p));
	// CU_ASSERT_TRUE(is_shadowed(scene, p));
}

void	test_shadows_03(void)
{
	t_scene	*scene;
	t_point	p;

	scene = default_world();
	p = point_new(-20, 20, -20);
	printf("is_shadowed: %d\n", is_shadowed(scene, p));
	// CU_ASSERT_FALSE(is_shadowed(scene, p));
}
