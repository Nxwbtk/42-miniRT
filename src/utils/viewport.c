/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   viewport.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksaelim <ksaelim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 14:09:21 by ksaelim           #+#    #+#             */
/*   Updated: 2023/11/26 12:40:56 by ksaelim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

float	ft_radian(int degree)
{
	return ((float)degree * (M_PI / 180));
}

static t_axis	calculate_axis(t_cor axis_z)
{
	t_axis	axis;
	t_cor	y_axis;

	y_axis = new_vec(0, 1.0f, 0);
	axis.z = axis_z;
	if (axis_z.y == -1 || axis_z.y == 1)
		y_axis = new_vec1(0, 0, 1.0f * axis_z.y);
	axis.x = vec_norm(vec_cross(axis.z, y_axis));
	axis.y = vec_norm(vec_cross(axis.x, axis.z));
	return (axis);
}

void	init_viewport(t_viewport *viewport, t_camera camera)
{
	t_cor	viewport_u;
	t_cor	viewport_v;
	t_cor	viewport_upper_left;

	viewport->origin = camera.origin;
	viewport->width = 2 * tanf(ft_radian(camera.fov) / 2);
	viewport->height = viewport->width * ((float)WD_HEIGHT / (float)WD_WIDTH);
	viewport->axis = calculate_axis(vec_norm(camera.dir));
	viewport_u = vec_multi_scalar(viewport->axis.x, viewport->width);
	viewport_v = vec_multi_scalar(viewport->axis.y, viewport->height);
	viewport->pixel_delta_x = vec_div(viewport_u, WD_WIDTH);
	viewport->pixel_delta_y = vec_div(viewport_v, WD_HEIGHT);
	viewport_upper_left = vec_sub(viewport->axis.z, vec_div(viewport_u, 2));
	viewport_upper_left = vec_add(viewport_upper_left, vec_div(viewport_v, 2));
	viewport->pixel_upper_left = vec_add(viewport_upper_left, vec_multi_scalar(vec_add(viewport->pixel_delta_x, viewport->pixel_delta_y), 0.5));
}

// sp 10,10,20    50   255,0,0