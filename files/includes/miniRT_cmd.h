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

#ifndef MINIRT_CMD_H
# define MINIRT_CMD_H

int		args_check(int argc, char **argv, char **envp);

void	data_free(t_minirt *data);

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

//void	ft_putchar(char c);
//void	ft_putstr(char *str);
//void	ft_putnbr(int n);

//int		ft_strlen(const char *str);
//int		ft_strncmp(char *s1, char *s2, int i);
//char	*ft_strchr(const char *string, int c);
//char	*ft_strdup(char *str);
//char	*ft_strjoin(char const *s1, char const *s2);

#endif