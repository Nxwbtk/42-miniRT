/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksaelim <ksaelim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 22:24:53 by ksaelim           #+#    #+#             */
/*   Updated: 2023/11/21 15:13:22 by ksaelim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_ray new_ray(t_cor oringin, t_cor dir)
{
	t_ray ray;

	ray.oringin = oringin;
	ray.dir = dir;
	return (ray);
}

// now only for sphere
t_rgb ray_tracing(t_param *param, t_ray ray)
{
	if (hit_sphere(new_vec(0, 0, -1), 0.5, ray))
	{
		printf("hit\n");
		return vec_to_rgb(new_vec(1, 0, 0));
	}
printf("not hit\n");
(void)param;
	t_cor unit_dir = vec_norm(ray.dir);
	float a = 0.5 * (unit_dir.y + 1.0);
	return (vec_to_rgb(vec_add(vec_multi_scalar(new_vec(1.0, 1.0, 1.0), 1.0 - a), vec_multi_scalar(new_vec(0.5, 0.7, 1.0), a))));
}

t_ray	ray_to_pixel(t_viewport *viewport, t_pixel pixel)
{
	t_cor pixel_center;

	pixel_center = vec_add(viewport->pixel_upper_left, vec_multi_scalar(viewport->pixel_delta_x, pixel.x));
	pixel_center = vec_add(pixel_center, vec_multi_scalar(viewport->pixel_delta_y, pixel.y));
	pixel_center = vec_sub(pixel_center, viewport->origin);
	pixel_center = vec_norm(pixel_center);
	return (new_ray(viewport->origin, pixel_center));
}

t_cor ray_point(t_ray ray, float t)
{
	return (vec_add(ray.oringin, vec_multi_scalar(ray.dir, t)));
}