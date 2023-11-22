/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   viewport.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksaelim <ksaelim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 14:09:21 by ksaelim           #+#    #+#             */
/*   Updated: 2023/11/23 00:59:18 by ksaelim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

float	ft_radian(int degree)
{
	return ((float)degree * (M_PI / 180));
}

void	init_viewport(t_viewport *viewport, t_camera camera)
{
	t_cor	viewport_u;
	t_cor	viewport_v;
	t_cor viewport_upper_left;

	viewport->origin = camera.origin;
	// viewport->width = 2 * tanf(ft_radian(camera.fov) / 2);
	// viewport->height = viewport->width * ((float)WD_HEIGHT / (float)WD_WIDTH);
	viewport->height = 2.0;
    viewport->width = viewport->height * ((float)WD_WIDTH / (float)WD_HEIGHT);
	// viewport->axis = calculate_axis(vec_norm(camera.dir));
	// viewport_u = vec_multi_scalar(viewport->axis.hor, viewport->width);
	// viewport_v = vec_multi_scalar(viewport->axis.ver, viewport->height);
	viewport_u = new_vec(viewport->width, 0, 0);
	viewport_v = new_vec(0, -viewport->height, 0);
	viewport->pixel_delta_x = vec_div(viewport_u, WD_WIDTH);
	viewport->pixel_delta_y = vec_div(viewport_v, WD_HEIGHT);
	viewport_upper_left = vec_sub(vec_sub(camera.dir, new_vec(0, 0, 1.0)), vec_div(viewport_u, 2));
	viewport_upper_left = vec_sub(viewport_upper_left, vec_div(viewport_v, 2));
	viewport->pixel_upper_left = vec_add(viewport_upper_left, vec_multi_scalar(vec_add(viewport->pixel_delta_x, viewport->pixel_delta_y), 0.5));
	// cmr.axis = calculate_axis(vec_norm(cam.dir));
	// cmr.hor = vec_scalar(cmr.axis.hor, cmr.vp_width);
	// cmr.ver = vec_scalar(cmr.axis.ver, cmr.vp_height);
	// cmr.fpro = cmr.axis.dir;
	// cmr.fpro = vec_sub(cmr.axis.dir, vec_scalar(cmr.hor, 0.5));
	// cmr.fpro = vec_add(cmr.fpro, vec_scalar(cmr.ver, 0.5));
	// camera_set_movement(&cmr);
}