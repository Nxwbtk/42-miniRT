/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsirikam <bsirikam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 22:01:08 by ksaelim           #+#    #+#             */
/*   Updated: 2023/11/24 18:25:10 by bsirikam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

static void	put_pixel_to_image(t_img *img, t_pixel pixel)
{
	unsigned int	*dst;
	if (pixel.x >= 0 && pixel.x < WD_WIDTH && pixel.y >= 0 && pixel.y < WD_HEIGHT)
	{
		dst = img->addr + ((int)pixel.y * img->line_len + (int)pixel.x * img->bpp);
		*dst = (unsigned int)pixel.color;
	}
}

static t_ray	ray_to_pixel(t_viewport *viewport, t_pixel pixel)
{
	t_cor pixel_center;

	pixel_center = vec_add(viewport->pixel_upper_left, vec_multi_scalar(viewport->pixel_delta_x, pixel.x));
	pixel_center = vec_add(pixel_center, vec_multi_scalar(viewport->pixel_delta_y, pixel.y));
	pixel_center = vec_sub(pixel_center, viewport->origin);
	pixel_center = vec_norm(pixel_center);
	return (new_ray(viewport->origin, pixel_center));
}

static int ray_tracing(t_ray *ray, t_obj *obj)
{
	t_hitpoint hitPoint;

	// print_topic("ray_tracing");
	// print_obj(obj);
	if (!hit_object(ray, obj, &hitPoint))
		return (rgb_to_clr(obj->ambient));
	// ambient_clr = fill_ambient(hitPoint.clr, obj->ambient);
	// ambient_clr = light_and_shadow(ambient_clr, hitPoint, obj);
	// return (rgb_to_clr(ambient_clr));
	return (rgb_to_clr(hitPoint.clr));
}

int	render_scene(t_param *param)
{
	t_pixel	pixel;
	t_ray	ray;

	//print_topic("render_scene");
	//print_camera(&param->scene.camera);
	//print_obj(param->scene.obj);
	pixel.y = 0;
	while (pixel.y < WD_HEIGHT)
	{
		pixel.x = 0;
		while (pixel.x < WD_WIDTH)
		{
			ray = ray_to_pixel(&param->viewport, pixel);
			pixel.color = ray_tracing(&ray, param->scene.obj);
			put_pixel_to_image(&param->img, pixel);
			pixel.x++;
		}
		pixel.y++;
	}
	mlx_put_image_to_window(param->mlx, param->win, param->img.img, 0, 0);
	return (0);
}
