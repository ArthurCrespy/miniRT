/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   material_init.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkeraudr <dkeraudr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 18:11:31 by dkeraudr          #+#    #+#             */
/*   Updated: 2024/03/10 18:30:55 by dkeraudr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_material	*material_init(void)
{
	t_material	*material;

	material = malloc(sizeof(t_material));
	if (!material)
		return (NULL);
	material->color = malloc(sizeof(t_color));
	if (!material->color)
	{
		free(material);
		return (NULL);
	}
	material->ambient = NULL;
	material->diffuse = 0.9;
	material->specular = 0.9;
	material->shininess = 200;
	return (material);
}
