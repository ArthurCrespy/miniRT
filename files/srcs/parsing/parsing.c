/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkeraudr <dkeraudr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 07:17:07 by acrespy           #+#    #+#             */
/*   Updated: 2024/01/17 19:53:58 by dkeraudr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	ft_parse_rt_file(t_scene *scene, char *file)
{
	int		fd;
	char	*line;
	int		ret;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (0);
	line = get_next_line(fd);
	while (line)
	{
		ret = ft_parse_line(scene, line);
		free(line);
		if (ret == 0)
			return (0);
		line = get_next_line(fd);
	}
}

int	ft_parse_line(t_scene *scene, char *line)
{
	if (line[0] == 'A')
		return (ft_parse_ambient(scene, line));
	else if (line[0] == 'C')
		return (ft_parse_camera(scene, line));
	else if (line[0] == 'L')
		return (ft_parse_light(scene, line));
	else if (line[0] == 's' && line[1] == 'p')
		return (ft_parse_sphere(scene, line));
	else if (line[0] == 'p' && line[1] == 'l')
		return (ft_parse_plane(scene, line));
	else if (line[0] == 'c' && line[1] == 'y')
		return (ft_parse_cylinder(scene, line));
	else if (line[0] == '\n' || line[0] == '\0')
		return (1);
	return (0);
}
