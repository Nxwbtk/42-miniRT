/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsirikam <bsirikam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 22:01:08 by ksaelim           #+#    #+#             */
/*   Updated: 2023/11/25 22:22:34 by bsirikam         ###   ########.fr       */
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
	pixel_center = vec_sub(pixel_center, vec_multi_scalar(viewport->pixel_delta_y, pixel.y));
	// pixel_center = vec_sub(pixel_center, viewport->origin);
	pixel_center = vec_norm(pixel_center);
	return (new_ray(viewport->origin, pixel_center));
}

// static float vec_len(t_cor vec)
// {
// 	return (sqrt((vec.x * vec.x) + (vec.y * vec.y) + (vec.z * vec.z)));
// }

// static t_rgb	shading(t_rgb color, t_hitpoint hitPoint, t_obj *obj)
// {
// 	// t_shading	shading;
// 	t_cor		light_dir;
// 	t_ray	light_ray;

// 	printf("in shading\n");
// 	light_ray.oringin = hitPoint.origin;
// 	light_ray.dir = vec_norm(vec_sub(obj->light.origin, hitPoint.origin));
// 	light_dir = vec_sub(obj->light.origin, hitPoint.origin);
// 	float angle = vec_dot_product(hitPoint.dir, light_ray.dir); // ratio, light dot normal object
// 	printf("brazzzzzz\n");
// 	printf("unfunct len: %f\n", light_ray.dir.len);
// 	printf("funct len: %f\n", vec_len(light_dir));
// 	exit(0);
// 	angle /= (light_ray.dir.len * hitPoint.dir.len);
// 	// float cam_len = hitPoint.dir.len;
// 	// float light_len = light_dir.len;
// 	// float angle = acosf(two_dot / (cam_len * light_len));
// 	// angle = 1 - (angle * 2.0 / PI);
// 	color = multi_clr(color, obj->light.clr);
// 	// color = add_clr(ratio_clr(color, angle), \
// 	// 	ratio_clr(obj->light.clr, angle * 0.2));
// 	color = ratio_clr(color, angle);
// 	return (color);
// }

t_rgb	rgb_add(t_rgb a, t_rgb b)
{
	t_rgb rgb;

	rgb.r = a.r + b.r;
	rgb.g = a.g + b.g;
	rgb.b = a.b + b.b;
	return (rgb);
}

// not sure, it should be to calculate by include distance
bool	block_object(t_ray *ray, t_obj *obj, float light_distance)
{
	t_sp	*sp;
	t_plane	*pl;

	ray->t = light_distance;
	// (void)light_distance;
	while (obj)
	{
		if (obj->type == 1)
		{
			pl = (t_plane *)obj->obj;
			if (isHitPlane(ray, &pl))
				return (true);
		}
		else if (obj->type == 2)
		{
			sp = (t_sp *)obj->obj;
			if (isHitSphere(ray, &sp))
				return (true);
		}
		obj = obj->next;
	}
	return (false);
}

// a dot b = |a||b|cos(theta)
// cos(theta) = a dot b / |a||b|
// hit_to_light dot normal = |hit_to_light||normal|cos(theta)
// cos(theta) = hit_to_light dot normal / |hit_to_light||normal|
int	is_shadow(t_cor hitOrigin, t_obj *obj)
{
	t_ray	shadow_ray;
	t_sp	*sp;
	t_plane	*pl;
	// t_ray	tmp;
	t_obj	*lst;
	int		is_shadow;

	shadow_ray.oringin= hitOrigin;
	shadow_ray.dir = vec_norm(vec_sub(obj->light.origin,
				hitOrigin));
	shadow_ray.t = vec_sub(obj->light.origin, hitOrigin).len;
	is_shadow = 0;
	lst = obj;
	while (lst)
	{
		if (obj->type == 1)
		{
			pl = (t_plane *)obj->obj;
			if (isHitPlane(&shadow_ray, &pl))
			{
				printf("shadow\n");
				is_shadow = 1;
				break ;
			}
		}
		else if (obj->type == 2)
		{
			sp = (t_sp *)obj->obj;
			if (isHitSphere(&shadow_ray, &sp))
			{
				printf("shadow\n");
				is_shadow = 1;
				break ;
			}
		}
		// if (is_intersect((t_obj *)(lst->content), &shadow_ray, &tmp) == 1)
		// {
		// 	is_shadow = 1;
		// 	break ;
		// }
		lst = lst->next;
	}
	return (is_shadow);
}

static t_rgb lighting(t_obj *obj, t_light light, t_hitpoint hitPoint, t_cor normal)
{
	// int is_shadow;

	// t_ray shadow_ray;
	t_cor hit_to_light = vec_norm(vec_sub(light.origin, hitPoint.origin));
	
	// shadow_ray = new_ray(hitPoint.origin, vec_norm(vec_sub(obj->light.origin, hitPoint.origin))); // ray from hitpoint to light
	// print_ray(&shadow_ray);
	// 	if (block_object(&shadow_ray, obj, vec_sub(obj->light.origin, hitPoint.origin).len)) // if hit object between hitpoint and light
	// 		return (obj->ambient);
	//ambient
	t_rgb ambient = multi_clr(hitPoint.clr, obj->ambient);
	if (is_shadow(hitPoint.origin, obj))
			return (ambient);
	//diffuse
	t_rgb diffuse = multi_clr(hitPoint.clr, light.clr);
	float light_dot_normal = vec_dot_product(hit_to_light, normal);
	// t_rgb diffuse = new_rgb(0, 0, 0);
	if (light_dot_normal >= 0)
		diffuse = ratio_clr(diffuse, light_dot_normal);
	else
		diffuse = new_rgb(0, 0, 0);
	// return ((void)diffuse, ambient);
	// return ((void)ambient, diffuse);
	return (rgb_add(ambient, diffuse));
}

static int ray_tracing(t_ray *ray, t_obj *obj)
{
	t_hitpoint	hitPoint;
	// t_hitpoint	hitBlock;
	// t_ray	shadow_ray;
	// t_rgb ambient_clr;
	t_rgb clr;

	clr = new_rgb(0, 0, 0);
	// print_topic("ray_tracing");
	// print_obj(obj);
	if (!hit_object(ray, obj, &hitPoint))
		return (rgb_to_clr(clr));
	clr = lighting(obj, obj->light, hitPoint, hitPoint.dir);
	return (rgb_to_clr(clr));
	// if (hit_object(ray, obj, &hitPoint))
	// {
	// 	clr = rgb_add(hitPoint.clr, obj->ambient);
	// 	shadow_ray = new_ray(hitPoint.origin, vec_norm(vec_sub(obj->light.origin, hitPoint.origin))); // ray from hitpoint to light
	// 	if (hit_object(&shadow_ray, obj, &hitBlock)) // if hit object between hitpoint and light
	// 		return (rgb_to_clr(obj->ambient));
	// 	return (rgb_to_clr(shading(clr, hitPoint, obj) ));
	// 	// return (rgb_to_clr(clr));
	// }
	// return (rgb_to_clr(clr));
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