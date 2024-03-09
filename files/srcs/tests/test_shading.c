/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_shading.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkeraudr <dkeraudr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 20:09:07 by dkeraudr          #+#    #+#             */
/*   Updated: 2024/03/09 16:16:32 by dkeraudr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT_test.h"

t_computation	prepare_computations(t_intersection *intersection, t_ray ray);

t_scene		*default_world(void)
{
	t_scene	*scene;
	t_list	*tmp;

	scene = malloc(sizeof(t_scene));
	if (!scene)
		return (NULL);
	ft_parse_rt_file(scene, "default_world.rt");
	tmp = scene->objects;
	while (tmp)
	{
		((t_hittable *)tmp->content)->material->diffuse = 0.7;
		((t_hittable *)tmp->content)->material->specular = 0.2;
		((t_hittable *)tmp->content)->material->shininess = 200;
		tmp = tmp->next;
	}

	return (scene);
}


void	test_world_intersections(void)
{
	t_scene	*scene;
	t_ray	r;
	// t_intersection	*intersections;
	t_list	*intersections;
	t_list	*tmp;

	scene = default_world();
	r = ray_new(point_new(0, 0, -5), vector_new(0, 0, 1));
	intersections = ft_intersect(scene->objects, r);
	tmp = intersections;
	while (tmp)
	{
		printf("t: %f\n", ((t_intersection *)tmp->content)->t);
		tmp = tmp->next;
	}
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
t_intersection	*create_intersect(double t, t_hittable *obj);

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
	c = lighting(&comps, false);
	CU_ASSERT_DOUBLE_EQUAL(c.chan_1, 0.38066, EPSILON);
	CU_ASSERT_DOUBLE_EQUAL(c.chan_2, 0.47583, EPSILON);
	CU_ASSERT_DOUBLE_EQUAL(c.chan_3, 0.2855, EPSILON);
}