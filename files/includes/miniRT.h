/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acrespy <acrespy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 14:31:24 by acrespy           #+#    #+#             */
/*   Updated: 2023/02/23 13:00:06 by acrespy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 50
# endif

#ifndef MINIRT_H
# define MINIRT_H

# include "./../mlx/mlx.h"
# include "./../mlx/mlx_int.h"

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <limits.h>

typedef struct	s_mlx
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

typedef struct s_file
{
	char		**content;
}				t_file;

typedef struct	s_data
{
	t_mlx		*mlx;
	t_file		*file;
}				t_data;


int		args_check(int argc, char **argv, char **envp);

int		event_key(int keycode, void *data);

int		event_resize(t_data *data);

void	file_check_ext(char *path);
void	file_check_path(char *path);

void	file_save(t_data *data, char *path);

void	mlx_free(t_data *data);
void	mlx_exit(t_data *data, char *msg, int status);
void	mlx_error(t_data *data);
void	mlx_hook_exit(t_data *data);

void	mlx_initialize_win(t_data *data);

void	mlx_hook_loop(t_data *data);

int		mlx_render_frame(t_data *data);

char	*ft_calloc(size_t nmemb, size_t size);

void	ft_exit(char *msg, int status);

char	*get_next_line(int fd);

void	ft_putchar(char c);
void	ft_putstr(char *str);
void	ft_putnbr(int n);

int		ft_strlen(const char *str);
int		ft_strncmp(char *s1, char *s2, int i);
char	*ft_strchr(const char *string, int c);
char	*ft_strdup(char *str);
char	*ft_strjoin(char const *s1, char const *s2);

#endif