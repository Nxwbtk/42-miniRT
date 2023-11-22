/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksaelim <ksaelim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 22:01:08 by ksaelim           #+#    #+#             */
/*   Updated: 2023/11/21 17:11:25 by ksaelim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

// void	ft_rendering(t_data *data)
// {
// 	ft_draw_line(data);
// 	mlx_put_image_to_window(data->mlx, data->win, data->img.img, 0, 0);
// }
// static int	ray_tracing(t_param *param, t_ray ray)
// {
// 	// hit_sphere(ray, );
// 	return (rgb_to_clr(clr));
// }

int	render_scene(t_param *param)
{
	t_pixel	pixel;
	t_ray	ray;
	static int a = 0;

	pixel = new_pixel(0, 0, 0);
	print_cor("position_plane", param->scene.plane.origin);
	print_cor("direction_plane", param->scene.plane.dir);
	print_cor("position_camera", param->scene.camera.origin);
	print_cor("direction_camera", param->scene.camera.dir);

	while (pixel.y < WD_HEIGHT)
	{
		pixel.x = 0;
		while (pixel.x < WD_WIDTH)
		{
			ray = ray_to_pixel(&param->viewport, pixel);
			if (a++ < 5)
				print_cor("ray.dir", ray.dir);
			pixel.color = ray_color(ray, param->scene.sphere, param->scene.plane);
			put_pixel_to_image(&param->img, pixel);
			// printf("after put_pixel_to_image\n");
			pixel.x++;
		}
		pixel.y++;
	}
	mlx_put_image_to_window(param->mlx, param->win, param->img.img, 0, 0);
	return (0);
}