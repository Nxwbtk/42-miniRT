/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksaelim <ksaelim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 22:01:08 by ksaelim           #+#    #+#             */
/*   Updated: 2023/12/02 20:32:15 by ksaelim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

static void	put_pixel_to_image(t_img *img, t_pixel pixel)
{
	unsigned int	*dst;

	if (pixel.x >= 0 && pixel.x < WD_WIDTH && pixel.y >= 0 && pixel.y < \
	WD_HEIGHT)
	{
		dst = img->addr + ((int)pixel.y * img->line_len + (int)pixel.x * \
		img->bpp);
		*dst = (unsigned int)pixel.color;
	}
}

static t_ray	ray_to_pixel(t_viewport *viewport, t_pixel pixel)
{
	t_cor	pixel_center;

	pixel_center = vec_add(viewport->pixel_upper_left, \
	vec_multi_scalar(viewport->pixel_delta_x, pixel.x));
	pixel_center = vec_sub(pixel_center, \
	vec_multi_scalar(viewport->pixel_delta_y, pixel.y));
	pixel_center = vec_norm(pixel_center);
	return (new_ray(viewport->origin, pixel_center));
}

// ray_to_light dot normal = |ray_to_light||normal_obj|cos(theta)
// cos(theta) = ray_to_light dot normal_obj / |ray_to_light||normal_obj|
// if we normalize ray_to_light and normal_obj, then |ray_to_light||normal_obj|
//  = 1
// so, we will get cos(theta) = ray_to_light dot normal_obj

static t_rgb	light_and_shadow(t_obj *obj, t_light light, \
t_hitpoint hitPoint)
{
	t_rgb	diffuse;
	float	light_dot_normal;
	t_cor	hitpoint_to_light;
	t_rgb	ambient;

	hitpoint_to_light = vec_norm(vec_sub(light.origin, hitPoint.origin));
	ambient = ratio_clr(hitPoint.clr, obj->ambient);
	// if (is_shadow(new_ray(hitPoint.origin, hitpoint_to_light), hitPoint, obj))
	// 	return (ambient);
	diffuse = ratio_clr(hitPoint.clr, obj->light.ratio);
	light_dot_normal = vec_dot_product(hitpoint_to_light, hitPoint.dir);
	if (light_dot_normal >= 0)
		diffuse = ratio_clr(diffuse, light_dot_normal);
	else
		diffuse = new_rgb(0, 0, 0);
	// don't delete this now
	// return ((void)diffuse, ambient);
	// return ((void)ambient, diffuse);
	return (add_clr(ambient, diffuse));
}

static int	ray_tracing(t_ray *ray, t_obj *obj)
{
	t_hitpoint	hit_point;
	t_rgb		clr;
	static int	i = 0; //del

	clr = new_rgb(0, 0, 0);
	if (!hit_object(ray, obj, &hit_point))
		return (rgb_to_clr(clr));
	if (i++ == 0) //del
		printf("color hit: %d %d %d\n", hit_point.clr.r, hit_point.clr.g, hit_point.clr.b); // del
	clr = light_and_shadow(obj, obj->light, hit_point);
	return (rgb_to_clr(clr));
}

int	render_scene(t_param *param)
{
	t_pixel	pixel;
	t_ray	ray;

	print_light(&param->scene.light);
	print_topic("render_scene");
	print_camera(&param->scene.camera);
	print_obj(param->scene.obj);
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
