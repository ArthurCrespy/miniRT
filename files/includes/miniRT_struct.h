/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkeraudr <dkeraudr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 19:40:18 by dkeraudr          #+#    #+#             */
/*   Updated: 2024/01/16 20:59:14 by dkeraudr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_STRUCT_H
# define MINIRT_STRUCT_H

typedef struct s_tuple
{
	double	x;
	double	y;
	double	z;
	double	w;
}	t_tuple;

typedef t_tuple	t_point;

typedef t_tuple	t_vector;

typedef struct s_ray
{
	t_point		origin;
	t_vector	direction;
}				t_ray;

typedef struct s_matrix
{
	double	matrix[4][4];
	size_t	size;
}	t_matrix;

typedef struct s_shearing
{
	double	p1;
	double	p2;
}				t_shearing;

typedef struct s_img_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}			t_img_data;

typedef struct s_vars
{
	void	*mlx;
	void	*win;
}				t_vars;

typedef struct s_color
{
	double	chan_1;
	double	chan_2;
	double	chan_3;
}				t_color;

typedef struct s_hittable
{
	int			id;
	int 		type;
	t_point		center;
	t_color		color;
	t_vector	orientation;
	double		radius;
	double		height;
}				t_hittable;

typedef struct s_camera
{
	t_point		center;
	t_vector	orientation;
	int			fov;
}				t_camera;

typedef struct s_light
{
	t_point	center;
	double	brightness;
	t_color	color;
}				t_light;

typedef struct s_ambiant
{
	double	brightness;
	t_color	color;
}				t_ambiant;

typedef struct s_scene
{
	t_ambiant	*ambiant;
	t_list		*lights;
	t_list		*objects;
	t_camera	*camera;
}				t_scene;

typedef struct s_intersect
{
	bool		hit;
	double		t;
	t_point		point;
	t_vector	normal;
}				t_intersect;

typedef struct s_mlx
{
	void		*mlx;
	void		*mlx_win;
	void		*img;
	char		*addr;
	int			screen_width;
	int			screen_height;
	int			win_width;
	int			win_height;
	int			line_length;
	int			endian;
	int			bpp;
}				t_mlx;

typedef struct s_minirt {
	t_mlx		*mlx;
	t_scene		*scene;
}				t_minirt;

#endif