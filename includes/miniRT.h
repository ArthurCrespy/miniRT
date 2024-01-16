/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkeraudr <dkeraudr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 15:14:02 by dkeraudr          #+#    #+#             */
/*   Updated: 2024/01/16 19:42:16 by dkeraudr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include <../minilibx-linux/mlx.h>
# include <../libft/includes/libft.h>
# include "structs.h"
# include <stdio.h>
# include <stdlib.h>

# define WIDTH 512
# define HEIGHT 512



int	exit_program(t_minirt *mini_struct);
int	handle_keys(int keycode, t_minirt	*mini_struct);

#endif