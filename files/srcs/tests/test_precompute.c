/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_precompute.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acrespy <acrespy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 13:07:23 by acrespy           #+#    #+#             */
/*   Updated: 2024/03/12 13:07:23 by acrespy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT_test.h"

int		do_precompute_intersections_tests(CU_pSuite suite)
{
	suite = CU_add_suite("precompute_intersections", NULL, NULL);
	if (NULL == suite)
	{
		CU_cleanup_registry();
		return CU_get_error();
	}

	if (NULL == CU_add_test(suite, "test_precompute_intersections_00", test_precompute_intersections_00))
	{
		CU_cleanup_registry();
		return CU_get_error();
	}

	if (NULL == CU_add_test(suite, "test_precompute_intersections_01", test_precompute_intersections_01))
	{
		CU_cleanup_registry();
		return CU_get_error();
	}

	if (NULL == CU_add_test(suite, "test_precompute_intersections_02", test_precompute_intersections_02))
	{
		CU_cleanup_registry();
		return CU_get_error();
	}

	return (0);
}


// Scenario: Precomputing the state of an intersection
// Given r ← ray(point(0, 0, -5), vector(0, 0, 1))
// And shape ← sphere()
// And i ← intersection(4, shape)
// When comps ← prepare_computations(i, r)
// Then comps.t = i.t
// And comps.object = i.object
// And comps.point = point(0, 0, -1)
// And comps.eyev = vector(0, 0, -1)
// And comps.normalv = vector(0, 0, -1)

void	test_precompute_intersections_00(void)
{
	t_hittable	*obj;
	t_intersection	*inter;
	t_computation	comps;
	t_ray	r;

	obj = malloc(sizeof(t_hittable));
	if (!obj)
	{
		CU_FAIL("malloc failed");
		return ;
	}
	obj->type = SPHERE;
	obj->transform = matrix_identity();
	inter = create_intersect(4, obj);
	r = ray_new(point_new(0, 0, -5), vector_new(0, 0, 1));
	comps = prepare_computations(inter, r);
	// CU_ASSERT_DOUBLE_EQUAL(comps.t, inter->t, EPSILON);
	CU_ASSERT_PTR_EQUAL(comps.object, inter->obj);
	CU_ASSERT_DOUBLE_EQUAL(comps.point.x, 0, EPSILON);
	CU_ASSERT_DOUBLE_EQUAL(comps.point.y, 0, EPSILON);
	CU_ASSERT_DOUBLE_EQUAL(comps.point.z, -1, EPSILON);
	CU_ASSERT_DOUBLE_EQUAL(comps.eye.x, 0, EPSILON);
	CU_ASSERT_DOUBLE_EQUAL(comps.eye.y, 0, EPSILON);
	CU_ASSERT_DOUBLE_EQUAL(comps.eye.z, -1, EPSILON);
	CU_ASSERT_DOUBLE_EQUAL(comps.normal.x, 0, EPSILON);
	CU_ASSERT_DOUBLE_EQUAL(comps.normal.y, 0, EPSILON);
	CU_ASSERT_DOUBLE_EQUAL(comps.normal.z, -1, EPSILON);
}

// Scenario: The hit, when an intersection occurs on the outside
// Given r ← ray(point(0, 0, -5), vector(0, 0, 1))
// And shape ← sphere()
// And i ← intersection(4, shape)
// When comps ← prepare_computations(i, r)
// Then comps.inside = false

void	test_precompute_intersections_01(void)
{
	t_hittable	*obj;
	t_intersection	*inter;
	t_computation	comps;
	t_ray	r;

	obj = malloc(sizeof(t_hittable));
	if (!obj)
	{
		CU_FAIL("malloc failed");
		return ;
	}
	obj->type = SPHERE;
	obj->transform = matrix_identity();
	inter = create_intersect(4, obj);
	r = ray_new(point_new(0, 0, -5), vector_new(0, 0, 1));
	comps = prepare_computations(inter, r);
	CU_ASSERT_FALSE(comps.inside);
}

// Scenario: The hit, when an intersection occurs on the inside
// Given r ← ray(point(0, 0, 0), vector(0, 0, 1))
// And shape ← sphere()
// And i ← intersection(1, shape)
// When comps ← prepare_computations(i, r)
// Then comps.point = point(0, 0, 1)
// And comps.eyev = vector(0, 0, -1)
// And comps.inside = true
// # normal would have been (0, 0, 1), but is inverted!
// And comps.normalv = vector(0, 0, -1)

void	test_precompute_intersections_02(void)
{
	t_hittable	*obj;
	t_intersection	*inter;
	t_computation	comps;
	t_ray	r;

	obj = malloc(sizeof(t_hittable));
	if (!obj)
	{
		CU_FAIL("malloc failed");
		return ;
	}
	obj->type = SPHERE;
	obj->transform = matrix_identity();
	inter = create_intersect(1, obj);
	r = ray_new(point_new(0, 0, 0), vector_new(0, 0, 1));
	comps = prepare_computations(inter, r);
	CU_ASSERT_DOUBLE_EQUAL(comps.point.x, 0, EPSILON);
	CU_ASSERT_DOUBLE_EQUAL(comps.point.y, 0, EPSILON);
	CU_ASSERT_DOUBLE_EQUAL(comps.point.z, 1, EPSILON);
	CU_ASSERT_DOUBLE_EQUAL(comps.eye.x, 0, EPSILON);
	CU_ASSERT_DOUBLE_EQUAL(comps.eye.y, 0, EPSILON);
	CU_ASSERT_DOUBLE_EQUAL(comps.eye.z, -1, EPSILON);
	CU_ASSERT_TRUE(comps.inside);
	CU_ASSERT_DOUBLE_EQUAL(comps.normal.x, 0, EPSILON);
	CU_ASSERT_DOUBLE_EQUAL(comps.normal.y, 0, EPSILON);
	CU_ASSERT_DOUBLE_EQUAL(comps.normal.z, -1, EPSILON);
}