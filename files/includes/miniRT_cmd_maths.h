/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT_cmd_maths.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acrespy <acrespy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 12:48:54 by acrespy           #+#    #+#             */
/*   Updated: 2024/01/20 10:17:51 by acrespy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_CMD_MATHS_H
# define MINIRT_CMD_MATHS_H

bool			double_equal(double nb1, double nb2);
bool			double_inf(double nb1, double nb2);
bool			double_sup(double nb1, double nb2);

/* -- */

bool			point_equal(t_point v1, t_point v2);
bool			point_inf(t_point v1, t_point v2);
bool			point_sup(t_point v1, t_point v2);

t_point			point_new(double x, double y, double z);
t_point			point_zero(void);

t_point			point_add(t_point v1, t_point v2);
t_point			point_sub(t_point v1, t_point v2);
t_point			point_mult(t_point v1, t_point v2);
t_point			point_div(t_point v1, t_point v2);
t_point			point_invert(t_point v1);

t_point			point_scale(t_point v1, double scale);
t_point			point_unscale(t_point v1, double scale);

t_point			point_vector_add(t_point p, t_vector v);
t_point			vector_point_add(t_vector v, t_point p);
t_point			point_vector_sub(t_point p, t_vector v);

/* -- */

bool			vect_equal(t_vector v1, t_vector v2);
bool			vect_inf(t_vector v1, t_vector v2);
bool			vect_sup(t_vector v1, t_vector v2);

t_vector		vect_new(double x, double y, double z);
t_vector		vect_zero(void);

double			vect_mag(t_vector v1);
double			vect_dot(t_vector v1, t_vector v2);
t_vector		vect_norm(t_vector v1);
t_vector		vect_cross(t_vector v1, t_vector v2);

t_vector		vect_add(t_vector v1, t_vector v2);
t_vector		vect_sub(t_vector v1, t_vector v2);
t_vector		vect_mult(t_vector v1, t_vector v2);
t_vector		vect_div(t_vector v1, t_vector v2);
t_vector		vect_invert(t_vector v1);

t_vector		vect_scale(t_vector v1, double scale);
t_vector		vect_unscale(t_vector v1, double scale);

t_vector		point_point_sub(t_point p1, t_point p2);

#endif
