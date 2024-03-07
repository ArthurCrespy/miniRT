/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_lighting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkeraudr <dkeraudr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 20:33:41 by dkeraudr          #+#    #+#             */
/*   Updated: 2024/03/02 21:57:01 by dkeraudr         ###   ########.fr       */
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
	lighting_info.object->material->ambient->color = color_new(1, 1, 1);
	lighting_info.object->material->ambient->brightness = 0.1;
	lighting_info.object->material->diffuse = 0.9;
	lighting_info.object->material->specular = 0.9;
	lighting_info.object->material->shininess = 200;
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
	CU_ASSERT_DOUBLE_EQUAL(result.chan_1, 1.9, EPSILON);
	CU_ASSERT_DOUBLE_EQUAL(result.chan_2, 1.9, EPSILON);
	CU_ASSERT_DOUBLE_EQUAL(result.chan_3, 1.9, EPSILON);
}

void	do_lighting_01(void)
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
	lighting_info.object->material->ambient->color = color_new(1, 1, 1);
	lighting_info.object->material->ambient->brightness = 0.1;
	lighting_info.object->material->diffuse = 0.9;
	lighting_info.object->material->specular = 0.9;
	lighting_info.object->material->shininess = 200;
	lighting_info.point = point_new(0, 0, 0);
	lighting_info.eye = vector_new(0, sqrt(2) / 2, -sqrt(2) / 2);
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
	CU_ASSERT_DOUBLE_EQUAL(result.chan_1, 1.0, EPSILON);
	CU_ASSERT_DOUBLE_EQUAL(result.chan_2, 1.0, EPSILON);
	CU_ASSERT_DOUBLE_EQUAL(result.chan_3, 1.0, EPSILON);
}


void	do_lighting_02(void)
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
	lighting_info.object->material->ambient->color = color_new(1, 1, 1);
	lighting_info.object->material->ambient->brightness = 0.1;
	lighting_info.object->material->diffuse = 0.9;
	lighting_info.object->material->specular = 0.9;
	lighting_info.object->material->shininess = 200;
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
	lighting_info.light->position = point_new(0, 10, -10);
	lighting_info.light->brightness = 1;
	lighting_info.light->color = color_new(1, 1, 1);
	result = lighting(&lighting_info);
	CU_ASSERT_DOUBLE_EQUAL(result.chan_1, 0.7364, EPSILON);
	CU_ASSERT_DOUBLE_EQUAL(result.chan_2, 0.7364, EPSILON);
	CU_ASSERT_DOUBLE_EQUAL(result.chan_3, 0.7364, EPSILON);
}