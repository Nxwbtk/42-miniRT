/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksaelim <ksaelim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 22:01:08 by ksaelim           #+#    #+#             */
/*   Updated: 2023/05/03 00:01:17 by ksaelim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"
// #include "input.h"
// #include <stdio.h>
// #include <stdlib.h>

// void	ft_rendering(t_data *data)
// {
// 	ft_draw_line(data);
// 	mlx_put_image_to_window(data->mlx, data->win, data->img.img, 0, 0);
// }
static int	ray_tracing(t_param *param, t_ray ray)
{
	hit_sphere(ray, )
	return (rgb_to_clr(clr));
}

int	render_scene(t_param *param)
{
	t_pixel	pixel;
	t_ray	ray;

	pixel = new_pixel(0, 0, 0);
	while (pixel.y < WD_HEIGHT)
	{
		pixel.x = 0;
		while (pixel.x < WD_WIDTH)
		{
			ray = ray_to_pixel(&param->viewport, pixel);
			pixel.color = ray_tracing(param, ray);
			put_pixel_to_image(&param->img, pixel);
			pixel.x++;
		}
		pixel.y++;
	}
	mlx_put_image_to_window(param->mlx, param->win, param->img.img, 0, 0);
	return (0);
}