/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   material_init.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkeraudr <dkeraudr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 18:11:31 by dkeraudr          #+#    #+#             */
/*   Updated: 2024/03/10 18:11:49 by dkeraudr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_material	*material_init(void)
{
	t_material	*material;

	material = malloc(sizeof(t_material));
	if (!material)
		return (NULL);
	material->color = (t_color){0, 0, 0};
	material->ambient = 0.1;
	material->diffuse = 0.9;
	material->specular = 0.9;
	material->shininess = 200;
	return (material);
}