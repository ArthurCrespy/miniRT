/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT_cmd.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkeraudr <dkeraudr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 19:40:18 by dkeraudr          #+#    #+#             */
/*   Updated: 2024/03/19 21:31:24 by dkeraudr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_CMD_H
# define MINIRT_CMD_H

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
int		mlx_hook_exit(t_minirt *data);
void	my_mlx_pixel_put(t_mlx *data, int x, int y, int color);

void	mlx_initialize_win(t_minirt *data);

void	mlx_hook_loop(t_minirt *data);

int		mlx_render_frame(t_minirt *data);
void	render_scene(t_minirt *data);

//char	*ft_calloc(size_t nmemb, size_t size);

void	ft_exit(char *msg, int status);

void	ft_free(char **tab);
void	ft_matrix_free(t_matrix *matrix);

//char	*get_next_line(int fd);

//void	ft_putchar(char c);
//void	ft_putstr(char *str);
//void	ft_putnbr(int n);

//int	ft_strlen(const char *str);
//int	ft_strncmp(char *s1, char *s2, int i);
//char	*ft_strchr(const char *string, int c);
//char	*ft_strdup(char *str);
//char	*ft_strjoin(char const *s1, char const *s2);

void	test_tick(t_minirt *minirt);
void	test_maths(t_minirt *minirt);

// parsing

int		ft_parse_rt_file(t_scene *scene, char *file);
int		ft_parse_sphere(t_scene *scene, char *line);
int		ft_parse_plane(t_scene *scene, char *line);
int		ft_parse_cylinder(t_scene *scene, char *line);
int		ft_parse_camera(t_scene *scene, char *line);
int		ft_parse_light(t_scene *scene, char *line);
int		ft_parse_ambient(t_scene *scene, char *line);
int		ft_parse_color(char *line, t_color *color);
int		ft_parse_translation(char *line, t_matrix *transform);
int		ft_parse_rotation(char *line, t_matrix *transform);
int		ft_parse_scale(double x, double y, double z, t_matrix *matrix);
int		ft_parse_point(char *line, t_point *point);
int		ft_parse_vector(char *line, t_vector *vector);

t_material	*material_init(void);
// utils

void	ft_print_scene(t_scene *scene);
void	ft_print_matrix(t_matrix matrix);
void	ft_print_point(t_point point);
void	ft_print_vector(t_vector vector);

// intersect

t_intersection	*create_intersect(double t, t_hittable *obj);
t_list	*ft_intersect(t_list *objects, t_ray ray);
double	*intersect_with_sphere(t_ray ray);
double *intersect_with_cylinder(t_hittable *cylinder, t_ray ray);
double *intersect_with_plane(t_ray ray);
t_intersection	*ft_hit(t_list *intersections);

// lighting

t_color	lighting(t_computation	*lighting_info, bool	shadowed);
bool	is_shadowed(t_scene *scene, t_point point);

//free

void	free_hittable(void *hittable);
#endif