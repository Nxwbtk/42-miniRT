/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksaelim <ksaelim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 22:01:08 by ksaelim           #+#    #+#             */
/*   Updated: 2023/11/22 18:12:32 by ksaelim          ###   ########.fr       */
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

void print_sphere(t_sp *sphere)
{
	printf("origin: (%f, %f, %f)\n", sphere->origin.x, sphere->origin.y, sphere->origin.z);
	printf("radius: %f\n", sphere->radius);
	printf("color: %d, %d, %d\n", sphere->clr.r, sphere->clr.g, sphere->clr.b);
}

void print_plane(t_plane *plane)
{
	printf("origin: (%f, %f, %f)\n", plane->origin.x, plane->origin.y, plane->origin.z);
	printf("direction: (%f, %f, %f)\n", plane->dir.x, plane->dir.y, plane->dir.z);
	printf("color: %d, %d, %d\n", plane->clr.r, plane->clr.g, plane->clr.b);
}

void print_obj(t_obj *obj)
{
	printf("obj->type: %d\n", obj->type);
	if (obj->type == 1)
		print_plane(obj->obj);
	else if (obj->type == 2)
		print_spherej(obj->obj);
}

int	render_scene(t_param *param)
{
	t_pixel	pixel;
	t_ray	ray;

	pixel = new_pixel(0, 0, 0);
	while (param->scene.obj)
	{
		printf("\n");
		print_obj(param->scene.obj);
		param->scene.obj = param->scene.obj->next;

	}
	// print_obj(param->scene.obj);
	while (pixel.y < WD_HEIGHT)
	{
		pixel.x = 0;
		while (pixel.x < WD_WIDTH)
		{
			ray = ray_to_pixel(&param->viewport, pixel);
			pixel.color = ray_tracing(&ray, param->scene.obj);
			put_pixel_to_image(&param->img, pixel);
			// printf("after put_pixel_to_image\n");
			pixel.x++;
		}
		pixel.y++;
	}
	mlx_put_image_to_window(param->mlx, param->win, param->img.img, 0, 0);
	return (0);
}