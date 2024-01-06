/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkeraudr <dkeraudr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 15:14:02 by dkeraudr          #+#    #+#             */
/*   Updated: 2024/01/06 13:13:09 by dkeraudr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <../minilibx-linux/mlx.h>
# include <../libft/includes/libft.h>
# include <stdio.h>
# include <stdlib.h>

# define WIDTH 512
# define HEIGHT 512

typedef struct s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct s_vars {
	void	*mlx;
	void	*win;
}				t_vars;

typedef struct s_color {
	double	chan_1;
	double	chan_2;
	double	chan_3;
}				t_color;

typedef struct s_complex {
	double	real;
	double	imaginary;
}				t_complex;

#endif