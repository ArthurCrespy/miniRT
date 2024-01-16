/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkeraudr <dkeraudr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 19:40:18 by dkeraudr          #+#    #+#             */
/*   Updated: 2024/01/16 19:41:11 by dkeraudr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# include "../libft/includes/libft.h"

typedef struct s_img_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}			t_img_data;

typedef struct s_vars {
	void	*mlx;
	void	*win;
}				t_vars;

typedef struct s_color {
	double	chan_1;
	double	chan_2;
	double	chan_3;
}				t_color;

typedef struct s_vector {
	double	x;
	double	y;
	double	z;
}				t_vector;

typedef struct s_point {
	double	x;
	double	y;
	double	z;
}				t_point;

typedef struct s_hittable {
	int			id;
	t_point		center;
	t_color		color;
	t_vector	orientation;
	double		diameter;
	double		height;
}				t_hittable;

typedef struct s_camera {
	t_point		center;
	t_vector	orientation;
	int			fov;
}				t_camera;

typedef struct s_light {
	t_point	center;
	double	brightness;
	t_color	color;
}				t_light;

typedef struct s_ambiant {
	double	brightness;
	t_color	color;
}				t_ambiant;

typedef struct s_scene {
	t_ambiant	*ambiant;
	t_list		*lights;
	t_list		*objects;
	t_camera	*camera;
}				t_scene;

typedef struct s_minirt {
	t_img_data	*img_data;
	t_vars		*vars;
	t_scene		*scene;
}				t_minirt;


#endif