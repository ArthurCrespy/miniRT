/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkeraudr <dkeraudr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 14:31:24 by acrespy           #+#    #+#             */
/*   Updated: 2024/01/24 22:51:48 by dkeraudr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include <../mlx/mlx.h>
# include <../libft/includes/libft.h>
# include "miniRT_struct.h"
# include "constants.h"
# include <stdio.h>
# include <stdlib.h>

# include "./../mlx/mlx.h"
# include "./../mlx/mlx_int.h"

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <limits.h>


int		args_check(int argc, char **argv, char **envp);

void	data_free(t_minirt *data);
void	free_scene(t_scene *scene);

void	data_initialize(t_minirt *data);

int		event_key(int keycode, void *data);

int		event_resize(t_minirt *data);

void	file_check_ext(char *path);
void	file_check_path(char *path);

void	file_save(t_minirt *data, char *path);

void	mlx_free(t_minirt *data);
void	mlx_exit(t_minirt *data, char *msg, int status);
void	mlx_error(t_minirt *data);
void	mlx_hook_exit(t_minirt *data);

void	mlx_initialize_win(t_minirt *data);

void	mlx_hook_loop(t_minirt *data);

int		mlx_render_frame(t_minirt *data);

//char	*ft_calloc(size_t nmemb, size_t size);

void	ft_exit(char *msg, int status);

void	ft_free(char **tab);

//char	*get_next_line(int fd);
//
//void	ft_putchar(char c);
//void	ft_putstr(char *str);
//void	ft_putnbr(int n);
//
//int		ft_strlen(const char *str);
//int		ft_strncmp(char *s1, char *s2, int i);
//char	*ft_strchr(const char *string, int c);
//char	*ft_strdup(char *str);
//char	*ft_strjoin(char const *s1, char const *s2);
# include "./miniRT_include.h"
# include "./miniRT_define.h"
# include "./miniRT_struct.h"
# include "./miniRT_cmd.h"

// parsing

int	ft_parse_rt_file(t_scene *scene, char *file);
int	ft_parse_sphere(t_scene *scene, char *line);
int	ft_parse_plane(t_scene *scene, char *line);
int	ft_parse_cylinder(t_scene *scene, char *line);
int	ft_parse_camera(t_scene *scene, char *line);
int	ft_parse_light(t_scene *scene, char *line);
int	ft_parse_ambient(t_scene *scene, char *line);
int	ft_parse_color(char *line, t_color *color);
int	ft_parse_point(char *line, t_point *point);
int	ft_parse_vector(char *line, t_vector *vector);

// utils

void	ft_print_scene(t_scene *scene);
#endif