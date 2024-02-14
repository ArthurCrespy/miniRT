/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT_test.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkeraudr <dkeraudr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 19:33:55 by dkeraudr          #+#    #+#             */
/*   Updated: 2024/02/14 18:43:47 by dkeraudr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_TEST_H
# define MINIRT_TEST_H

# include <CUnit/CUnit.h>
# include <CUnit/Basic.h>
# include "miniRT.h"

void	do_sphere_intersect_00(void);
void	do_sphere_intersect_01(void);
void	do_sphere_intersect_02(void);

void	do_hit_00(void);
void	do_hit_01(void);
void	do_hit_02(void);
void	do_hit_03(void);
void	do_hit_04(void);

void	do_ray_translate_00(void);
void	do_ray_scaling_00(void);

#endif