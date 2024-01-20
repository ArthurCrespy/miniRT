/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_tick.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acrespy <acrespy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 13:00:03 by acrespy           #+#    #+#             */
/*   Updated: 2024/01/20 13:00:03 by acrespy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/miniRT.h"

typedef struct t_projectile
{
	t_vector	position;
	t_vector	velocity;
}				t_projectile;

typedef struct t_environment
{
	t_vector	gravity;
	t_vector	wind;
}				t_environment;

t_projectile	tick(t_projectile projectile, t_environment environment)
{
	t_projectile new_projectile;

	new_projectile.position = vect_add(projectile.position, projectile.velocity);
	new_projectile.velocity = vect_add(vect_add(projectile.velocity, environment.gravity), environment.wind);
	return (new_projectile);
}

double  pos_correction_x(t_minirt minirt, double x)
{
	(void)minirt;

	return (x);
}

double  pos_correction_y(t_minirt minirt, double y)
{
	return (minirt.mlx->win_height - y);
}

double pos_correction_z(t_minirt minirt, double z)
{
	(void)minirt;

	return (z);
}

void    test_tick(t_minirt *minirt)
{
	t_projectile proj;
	t_environment env;

	proj.position = vect_new(0, 0, 0);
	proj.velocity = vect_new(8, 15, 0);
	env.gravity = vect_new(0, -0.3, 0);
	env.wind = vect_new(-0.01, 0, 0);

	while (1)
	{
		proj = tick(proj, env);
		mlx_pixel_put(minirt->mlx->mlx, minirt->mlx->mlx_win,
			(int)pos_correction_x(*minirt, proj.position.x),
			(int)pos_correction_y(*minirt, proj.position.y), 0xFFFFFF);
		if (proj.position.y <= 0)
			break ;
	}
}

void test_maths(t_minirt *minirt)
{
	(void)minirt;
}