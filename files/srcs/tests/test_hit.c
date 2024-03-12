/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_hit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkeraudr <dkeraudr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 20:34:48 by dkeraudr          #+#    #+#             */
/*   Updated: 2024/02/17 15:14:58 by dkeraudr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT_test.h"

int	do_hit_tests(CU_pSuite suite)
{
	suite = CU_add_suite("hit", NULL, NULL);
	if (NULL == suite)
	{
		CU_cleanup_registry();
		return CU_get_error();
	}

	if (NULL == CU_add_test(suite, "do_hit_00", do_hit_00))
	{
		CU_cleanup_registry();
		return CU_get_error();
	}

	if (NULL == CU_add_test(suite, "do_hit_01", do_hit_01))
	{
		CU_cleanup_registry();
		return CU_get_error();
	}

	if (NULL == CU_add_test(suite, "do_hit_02", do_hit_02))
	{
		CU_cleanup_registry();
		return CU_get_error();
	}

	if (NULL == CU_add_test(suite, "do_hit_03", do_hit_03))
	{
		CU_cleanup_registry();
		return CU_get_error();
	}

	if (NULL == CU_add_test(suite, "do_hit_04", do_hit_04))
	{
		CU_cleanup_registry();
		return CU_get_error();
	}

	return (0);
}

void	do_hit_00(void)
{
	t_list			*intersections;
	t_intersection	*hit;
	t_hittable		*obj;

	obj = malloc(sizeof(t_hittable));
	obj->transform = matrix_identity();
	obj->type = SPHERE;
	intersections = ft_lstnew(create_intersect(1.0, obj));
	ft_lstadd_back(&intersections, ft_lstnew(create_intersect(2.0, obj)));
	hit = ft_hit(intersections);
	CU_ASSERT_PTR_NOT_NULL(hit);
	CU_ASSERT_DOUBLE_EQUAL(hit->t, 1.0, 1e-6);
	if (intersections)
		free(intersections);
	if (obj)
		free(obj);
}

void	do_hit_01(void)
{
	t_list			*intersections;
	t_intersection	*hit;
	t_hittable		*obj;

	obj = malloc(sizeof(t_hittable));
	obj->transform = matrix_identity();
	obj->type = SPHERE;
	intersections = ft_lstnew(create_intersect(-1, obj));
	ft_lstadd_back(&intersections, ft_lstnew(create_intersect(1, obj)));
	hit = ft_hit(intersections);
	CU_ASSERT_PTR_NOT_NULL(hit);
	CU_ASSERT_DOUBLE_EQUAL(hit->t, 1.0, 1e-6);
	if (intersections)
		free(intersections);
	if (obj)
		free(obj);
}

void	do_hit_02(void)
{
	t_list			*intersections;
	t_intersection	*hit;
	t_hittable		*obj;

	obj = malloc(sizeof(t_hittable));
	obj->transform = matrix_identity();
	obj->type = SPHERE;
	intersections = ft_lstnew(create_intersect(-2, obj));
	ft_lstadd_back(&intersections, ft_lstnew(create_intersect(-1, obj)));
	hit = ft_hit(intersections);
	// hit = NULL;
	CU_ASSERT_PTR_NULL(hit);
	if (intersections)
		free(intersections);
	if (obj)
		free(obj);
}

void	do_hit_03(void)
{
	t_list			*intersections;
	t_intersection	*hit;
	t_hittable		*obj;

	obj = malloc(sizeof(t_hittable));
	obj->transform = matrix_identity();
	obj->type = SPHERE;
	intersections = NULL;
	hit = ft_hit(intersections);
	CU_ASSERT_PTR_NULL(hit);
	if (intersections)
		free(intersections);
	if (obj)
		free(obj);
}

void	do_hit_04(void)
{
	t_list			*intersections;
	t_intersection	*hit;
	t_hittable		*obj;

	obj = malloc(sizeof(t_hittable));
	obj->transform = matrix_identity();
	obj->type = SPHERE;
	intersections = ft_lstnew(create_intersect(5.0, obj));
	ft_lstadd_back(&intersections, ft_lstnew(create_intersect(7.0, obj)));
	ft_lstadd_back(&intersections, ft_lstnew(create_intersect(-3.0, obj)));
	ft_lstadd_back(&intersections, ft_lstnew(create_intersect(2.0, obj)));
	hit = ft_hit(intersections);
	CU_ASSERT_PTR_NOT_NULL(hit);
	CU_ASSERT_DOUBLE_EQUAL(hit->t, 2.0, 1e-6);
	if (intersections)
		free(intersections);
	if (obj)
		free(obj);
}