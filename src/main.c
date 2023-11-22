/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksaelim <ksaelim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 01:21:10 by bsirikam          #+#    #+#             */
/*   Updated: 2023/11/22 15:59:50 by ksaelim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

	// t_cor	ray_direction = vec_sub(pixel_center, camera_center);
	// t_ray	r = new_ray(camera_center, ray_direction);

	// t_rgb pixel_rbg = ray_color(r);
	// // printf("r: %d, g: %d, b: %d/t", pixel_rbg.r, pixel_rbg.g, pixel_rbg.b);
	// pixel.color = rgb_to_clr(pixel_rbg);

// t_camera	new_camera(t_cor origin, t_cor dir, float fov)
// {
// 	t_camera	camera;

// 	camera.origin = origin;
// 	camera.dir = dir;
// 	camera.fov = fov;
// 	return (camera);
// }

// t_sp	new_sphere(t_cor origin, float radius, t_rgb clr)
// {
// 	t_sp	sphere;

// 	sphere.origin = origin;
// 	sphere.radius = radius;
// 	sphere.clr = clr;
// 	return (sphere);
// }

// t_plane	new_plane(t_cor origin, t_cor dir, t_rgb clr)
// {
// 	t_plane	plane;

// 	plane.origin = origin;
// 	plane.dir = dir;
// 	plane.clr = clr;
// 	return (plane);
// }

int	main(int ac, char **av)
{
	t_param	param;

	printf("before parsing\n");
	param.scene = init_struct();
	if (parsing(ac, av, &param.scene))
		return (1);
	printf("after parsing\n");
	(void)ac;
	(void)av;
	// param.scene.plane = new_plane(new_vec(0, -1, 0), new_vec(0, -1, 0), new_rgb(0, 255, 0));
	// param.scene.camera = new_camera(new_vec(0, 0, 0), new_vec(0, 0, -1), 90);
	// param.scene.sphere = new_sphere(new_vec(0, 0, -1), 0.5, new_rgb(255, 0, 0));
	init_viewport(&param.viewport, param.scene.camera);
	create_img(&param);
	render_scene(&param);
	// mlx_loop_hook(param.mlx, &render_scene, &param);
	mlx_hook(param.win, 2, 1L << 0, key_hook, &param);
	mlx_hook(param.win, 17, 0, close_win, &param);
	mlx_loop(param.mlx);
	return (0);
}
