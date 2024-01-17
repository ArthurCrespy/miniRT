/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkeraudr <dkeraudr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 18:30:53 by acrespy           #+#    #+#             */
/*   Updated: 2024/01/16 21:01:59 by dkeraudr         ###   ########.fr       */
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


int	main(int argc, char **argv, char **envp)
{
	t_minirt	minirt;

	printf("Hello, World!\n");

	data_initialize(&minirt);

	args_check(argc, argv, envp);
	// file_save(&minirt, argv[1]);


	mlx_initialize_win(&minirt);


	t_projectile proj;
	t_environment env;

	proj.position = vect_new(0, 0, 0);
	proj.velocity = vect_new(8, 15, 0);
	env.gravity = vect_new(0, -0.3, 0);
	env.wind = vect_new(-0.01, 0, 0);

	while (1)
	{
		proj = tick(proj, env);
		mlx_pixel_put(minirt.mlx->mlx, minirt.mlx->mlx_win,
			(int)pos_correction_x(minirt, proj.position.x),
			(int)pos_correction_y(minirt, proj.position.y), 0xFFFFFF);
		if (proj.position.y <= 0)
			break ;
	}

	mlx_hook_loop(&minirt);

	mlx_free(&minirt);
	data_free(&minirt);

	return (0);
}
