/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_lighting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkeraudr <dkeraudr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 20:33:41 by dkeraudr          #+#    #+#             */
/*   Updated: 2024/02/28 21:50:02 by dkeraudr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT_test.h"

void	do_lighting_00(void)
{
	t_computation	lighting_info;
	t_color			result;

	lighting_info.object = malloc(sizeof(t_hittable));
	if (!lighting_info.object)
	{
		CU_FAIL("malloc failed");
		return ;
	}
	lighting_info.object->material = malloc(sizeof(t_material));
	if (!lighting_info.object->material)
	{
		free(lighting_info.object);
		CU_FAIL("malloc failed");
		return ;
	}
	lighting_info.object->material->ambient = malloc(sizeof(t_ambient));
	if (!lighting_info.object->material->ambient)
	{
		free(lighting_info.object->material);
		free(lighting_info.object);
		CU_FAIL("malloc failed");
		return ;
	}
	lighting_info.object->material->color = color_new(1, 1, 1);
	lighting_info.object->material->ambient->color = color_new(0.1, 0.1, 0.1);
	lighting_info.object->material->ambient->brightness = 1;
	lighting_info.object->material->diffuse = 1;
	lighting_info.object->material->specular = 1;
	lighting_info.object->material->shininess = 1;
	lighting_info.point = point_new(0, 0, 0);
	lighting_info.eye = vector_new(0, 0, -1);
	lighting_info.normal = vector_new(0, 0, -1);
	lighting_info.light = malloc(sizeof(t_light));
	if (!lighting_info.light)
	{
		free(lighting_info.object);
		CU_FAIL("malloc failed");
		return ;
	}
	lighting_info.light->position = point_new(0, 0, -10);
	lighting_info.light->brightness = 1;
	lighting_info.light->color = color_new(1, 1, 1);
	result = lighting(&lighting_info);
	printf("result: ");
	ft_print_color(&result);
	CU_ASSERT_DOUBLE_EQUAL(result.chan_1, 1.5, 1e-6);
	CU_ASSERT_DOUBLE_EQUAL(result.chan_2, 1.5, 1e-6);
	CU_ASSERT_DOUBLE_EQUAL(result.chan_3, 1.5, 1e-6);
}