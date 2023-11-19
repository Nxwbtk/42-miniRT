/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksaelim <ksaelim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 01:21:10 by bsirikam          #+#    #+#             */
/*   Updated: 2023/10/24 11:58:24 by ksaelim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

	t_vec3f	ray_direction = vec3f_sub(pixel_center, camera_center);
	t_ray	r = new_ray(camera_center, ray_direction);

	t_rgb pixel_rbg = ray_color(r);
	// printf("r: %d, g: %d, b: %d/t", pixel_rbg.r, pixel_rbg.g, pixel_rbg.b);
	pixel.color = rgb_to_clr(pixel_rbg);

t_ray	ray_to_pixel(t_viewport *viewport, t_pixel pixel)
{
	t_vec3f pixel_center;

	pixel_center = vec3f_add(viewport->pixel_upper_left, vec3f_multi_scalar(viewport->pixel_delta_x, pixel.x));
	pixel_center = vec3f_sub(pixel_center, vec3f_multi_scalar(viewport->pixel_delta_y, pixel.y));
	return (new_ray(viewport->origin, pixel_center));
}

float	ft_radian(float degree)
{
	return (degree * M_PI / 180);
}



int	main(int ac, char **av)
{
	t_param	param;

	if (parsing(ac, av, &par.rt))
		return (1);
	init_viewport(&param.viewport, param.scene->camera);
	create_image(&par);
	render_scene(&param);
	mlx_loop_hook(par.mlx, &render_scene, &par);
	mlx_hook(param.win, 2, 1L << 0, key_hook, &param);
	mlx_hook(param.win, 17, 0, close_win, &param);
	mlx_loop(param.mlx);
	return (0);
}
