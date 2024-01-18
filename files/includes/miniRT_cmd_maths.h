/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT_cmd_maths.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acrespy <acrespy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 12:48:54 by acrespy           #+#    #+#             */
/*   Updated: 2024/01/17 12:48:54 by acrespy          ###   ########.fr       */
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

double			point_mag(t_point v1);
double			point_dot(t_point v1, t_point v2);
t_point 		point_norm(t_point v1);
t_point			point_cross(t_point v1, t_point v2);

t_point			point_add(t_point v1, t_point v2);
t_point			point_sub(t_point v1, t_point v2);
t_point			point_mult(t_point v1, t_point v2);
t_point			point_div(t_point v1, t_point v2);
t_point			point_invert(t_point v1);

t_point			point_scale(t_point v1, double scale);
t_point			point_unscale(t_point v1, double scale);

/* -- */

bool			tuple_equal(t_tuple v1, t_tuple v2);
bool			tuple_inf(t_tuple v1, t_tuple v2);
bool			tuple_sup(t_tuple v1, t_tuple v2);

t_tuple			tuple_new(double x, double y, double z, double w);
t_tuple			tuple_zero(void);

double			tuple_mag(t_tuple v1);
double			tuple_dot(t_tuple v1, t_tuple v2);
t_tuple 		tuple_norm(t_tuple v1);
t_tuple			tuple_cross(t_tuple v1, t_tuple v2);

t_tuple			tuple_add(t_tuple v1, t_tuple v2);
t_tuple			tuple_sub(t_tuple v1, t_tuple v2);
t_tuple			tuple_mult(t_tuple v1, t_tuple v2);
t_tuple			tuple_div(t_tuple v1, t_tuple v2);
t_tuple			tuple_invert(t_tuple v1);

t_tuple			tuple_scale(t_tuple v1, double scale);
t_tuple			tuple_unscale(t_tuple v1, double scale);

/* -- */

bool			vect_equal(t_vector v1, t_vector v2);
bool			vect_inf(t_vector v1, t_vector v2);
bool			vect_sup(t_vector v1, t_vector v2);

t_vector		vect_new(double x, double y, double z);
t_vector		vect_zero(void);


double			vect_mag(t_vector v1);
double			vect_dot(t_vector v1, t_vector v2);
t_vector 		vect_norm(t_vector v1);
t_vector		vect_cross(t_vector v1, t_vector v2);

t_vector		vect_add(t_vector v1, t_vector v2);
t_vector		vect_sub(t_vector v1, t_vector v2);
t_vector		vect_mult(t_vector v1, t_vector v2);
t_vector		vect_div(t_vector v1, t_vector v2);
t_vector		vect_invert(t_vector v1);

t_vector		vect_scale(t_vector v1, double scale);
t_vector		vect_unscale(t_vector v1, double scale);



#endif
