/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_save.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkeraudr <dkeraudr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 15:33:43 by acrespy           #+#    #+#             */
/*   Updated: 2024/02/18 15:09:21 by dkeraudr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

// void	file_save(t_minirt *data, char *path)
// {
// 	int		i;
// 	int		fd_line;
// 	int		fd_save;
// 	char	*line;

// 	i = 0;
// 	fd_line = open(path, O_RDONLY);
// 	fd_save = open(path, O_RDONLY);
// 	if (fd_line <= 0 || fd_save <= 0)
// 		ft_exit("Error: Can't open file\n", 1);
// 	while ((line = get_next_line(fd_line)) != NULL)
// 	{
// 		i += ft_strlen(line) + 1;
// 		free(line);
// 	}
// 	data->file->content = malloc(sizeof(char *) * (i + 1));
// 	if (!data->file->content)
// 		ft_exit("Error: malloc failed\n", 1);
// 	i = 0;
// 	while ((line = get_next_line(fd_save)) != NULL)
// 	{
// 		data->file->content[i] = ft_strdup(line);
// 		if (!data->file->content[i])
// 			ft_exit("Error: malloc failed\n", 1);
// 		free(line);
// 		i++;
// 	}
// 	data->file->content[i] = NULL;
// 	close(fd_line);
// 	close(fd_save);
// }
