/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT_struct.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkeraudr <dkeraudr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 19:40:18 by dkeraudr          #+#    #+#             */
/*   Updated: 2024/02/18 16:10:37 by dkeraudr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_STRUCT_H
# define MINIRT_STRUCT_H

# define MATRIX 4

# include "./miniRT_include.h"

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
	double	matrix[MATRIX][MATRIX];
	int		size;
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
	int			type;
	t_color		color;
	t_vector	orientation;
	t_vector 	normal;
	t_matrix	transform;
	double		radius;
	double		diameter;
	double		height;
	t_matrix	*transform;
}				t_hittable;

typedef struct s_camera
{
	t_matrix		*transform;
	double			fov;
	double			pixel_size;
	double			half_view;
	double			half_width;
	double			half_height;
}				t_camera;

typedef struct s_light
{
	t_matrix	*transform;
	double		brightness;
	t_color		color;
}				t_light;

typedef struct s_ambient
{
	double	brightness;
	t_color	color;
}				t_ambient;

typedef struct s_scene
{
	t_ambient	*ambient;
	t_list		*lights;
	t_list		*objects;
	t_camera	*camera;
}				t_scene;

typedef struct s_intersection
{
	// bool		hit;
	double		t;
	t_hittable	*obj;
	// t_point		point;
	// t_vector	normal;
}				t_intersection;

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
	unsigned int	pxl_rendered;
}				t_minirt;

#endif