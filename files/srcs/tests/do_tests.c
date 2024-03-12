/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_tests.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkeraudr <dkeraudr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 16:34:21 by dkeraudr          #+#    #+#             */
/*   Updated: 2024/03/09 16:45:03 by dkeraudr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT_test.h"

int	do_tests(void)
{
	CU_pSuite suite;

	if (CUE_SUCCESS != CU_initialize_registry())
		return CU_get_error();

	// matrix
	do_matrix_tests(suite);

	// tuple
	do_tuple_tests(suite);

	// sphere_intersects
	do_sphere_intersect_tests(suite);

	// hit
	do_hit_tests(suite);

	// ray_transform
	do_transform_tests(suite);
	
	// sphere_normal
	do_sphere_normal_tests(suite);

	// reflect
	do_reflect_tests(suite);

	// lighting
	do_lighting_tests(suite);

	// precompute
	do_precompute_intersections_tests(suite);

	// shading
	do_shading_tests(suite);

	// shadows
	do_shadows_tests(suite);
	
	CU_basic_set_mode(CU_BRM_VERBOSE);
	CU_basic_run_tests();
	CU_cleanup_registry();

	return CU_get_error();
}

t_scene		*default_world(void)
{
	t_scene	*scene;
	t_list	*tmp;

	scene = malloc(sizeof(t_scene));
	if (!scene)
		return (NULL);
	ft_parse_rt_file(scene, "/mnt/nfs/homes/acrespy/42/42Cursus/42Projets/miniRT/files/default_world.rt");
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