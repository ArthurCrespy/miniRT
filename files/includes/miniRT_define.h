/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT_define.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkeraudr <dkeraudr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 19:40:18 by dkeraudr          #+#    #+#             */
/*   Updated: 2024/03/01 20:20:25 by dkeraudr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_DEFINE_H
# define MINIRT_DEFINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 50
# endif

# define EPSILON 0.00001
# define WIDHT 500
# define HEIGHT 500

# define SPHERE 1
# define PLANE 2
# define CYLINDER 3

# define ERROR_MALLOC "Malloc error"
# define ERROR_NOT_ENOUGH_ARGS "Not enough arguments"
# define ERROR_WRONG_ARGS_NB "Wrong number of arguments"
# define ERROR_PARSING_ROTATION "Error while parsing rotation"
# define ERROR_PARSING_CENTER "Error while parsing center"
# define ERROR_PARSING_COLOR "Error while parsing color"
# define ERROR_PARSING_PLANE "Could not parse plane, aborting"
# define ERROR_PARSING_SPHERE "Could not parse sphere, aborting"
# define ERROR_PARSING_CYLINDER "Could not parse cylinder, aborting"
# define ERROR_PARSING_LIGHT "Could not parse light, aborting"
# define ERROR_PARSING_AMBIENT "Could not parse ambient, aborting"
# define ERROR_PARSING_CAMERA "Could not parse camera, aborting"
# define ERROR_PARSING_POINT "Could not parse point, aborting"

#endif