/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkeraudr <dkeraudr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 21:38:59 by dkeraudr          #+#    #+#             */
/*   Updated: 2024/02/18 14:21:41 by dkeraudr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../includes/miniRT.h"

void	ft_print_point(t_point point)
{
	printf("x: %f, y: %f, z: %f\n", point.x, point.y, point.z);
}

void	ft_print_color(t_color color)
{
	printf("chan_1: %f, chan_2: %f, chan_3: %f\n", color.chan_1, color.chan_2, color.chan_3);
}

void	ft_print_vector(t_vector vector)
{
	printf("x: %f, y: %f, z: %f\n", vector.x, vector.y, vector.z);
}

void	ft_print_hittable(t_hittable *hittable)
{
	printf("id: %d\n", hittable->id);
	printf("matrix: ");
	ft_print_matrix(*hittable->transform);
	printf("color: ");
	ft_print_color(hittable->color);
	printf("orientation: ");
}

void	ft_print_camera(t_camera *camera)
{
	printf("matrix: ");
	ft_print_matrix(*camera->transform);
	printf("fov: %f\n", camera->fov);
}

void	ft_print_light(t_light *light)
{
	printf("matrix: ");
	ft_print_matrix(*light->transform);
	printf("brightness: %f\n", light->brightness);
	printf("color: ");
	ft_print_color(light->color);
}

void	ft_print_ambient(t_ambient *ambient)
{
	printf("brightness: %f\n", ambient->brightness);
	printf("color: ");
	ft_print_color(ambient->color);
}

void	ft_print_scene(t_scene *scene)
{
	t_list	*tmp;

	tmp = scene->objects;
	while (tmp)
	{
		ft_print_hittable(tmp->content);
		tmp = tmp->next;
	}
	ft_print_camera(scene->camera);
	tmp = scene->lights;
	while (tmp)
	{
		ft_print_light(tmp->content);
		tmp = tmp->next;
	}
	printf("ambient: ");
	ft_print_ambient(scene->ambient);
}

void	ft_print_matrix(t_matrix matrix)
{
	printf("m00: %f, m01: %f, m02: %f, m03: %f\n", matrix.matrix[0][0], matrix.matrix[0][1], matrix.matrix[0][2], matrix.matrix[0][3]);
	printf("m10: %f, m11: %f, m12: %f, m13: %f\n", matrix.matrix[1][0], matrix.matrix[1][1], matrix.matrix[1][2], matrix.matrix[1][3]);
	printf("m20: %f, m21: %f, m22: %f, m23: %f\n", matrix.matrix[2][0], matrix.matrix[2][1], matrix.matrix[2][2], matrix.matrix[2][3]);
	printf("m30: %f, m31: %f, m32: %f, m33: %f\n", matrix.matrix[3][0], matrix.matrix[3][1], matrix.matrix[3][2], matrix.matrix[3][3]);
}