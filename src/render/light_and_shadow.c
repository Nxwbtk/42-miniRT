/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light_and_shadow.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsirikam <bsirikam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 14:59:22 by ksaelim           #+#    #+#             */
/*   Updated: 2023/11/25 21:12:46 by bsirikam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_rgb	fill_ambient(t_rgb obj_clr, t_rgb ambient_clr)
{
	obj_clr = shade_clr(obj_clr, ambient_clr);
	return (clamp_clr(obj_clr));
}

// not sure, it should be to calculate by include distance
// bool	block_object(t_ray *ray, t_obj *obj, float light_distance)
// {
// 	t_sp	*sp;
// 	t_plane	*pl;

// 	ray->t = light_distance;
// 	while (obj)
// 	{
// 		if (obj->type == 1)
// 		{
// 			pl = (t_plane *)obj->obj;
// 			if (isHitPlane(ray, &pl))
// 				return (true);
// 		}
// 		else if (obj->type == 2)
// 		{
// 			sp = (t_sp *)obj->obj;
// 			if (isHitSphere(ray, &sp))
// 				return (true);
// 		}
// 		obj = obj->next;
// 	}
// 	return (false);
// }

t_rgb color_add(t_rgb a, t_rgb b)
{
	t_rgb rgb;

	rgb.r = a.r + b.r;
	rgb.g = a.g + b.g;
	rgb.b = a.b + b.b;
	return (rgb);
}

t_rgb	ratio_clr(t_rgb light, float ratio)
{
	if (ratio < 0)
		ratio = 0;
	light.r *= ratio;
	light.g *= ratio;
	light.b *= ratio;
	return (light);
}

// t_rgb	light_and_shadow(t_rgb origin_clr, t_hitpoint hit, t_obj *obj)
// {
// 	// print_light(&obj->light);
// 	// exit(0);
// 	t_ray	ray_light;

// 	ray_light = new_ray(hit.origin, vec_norm(obj->light.origin));
// 	// t_cor light_pos = vec_add(hit.origin, hit.dir);
// 	float shade_ratio = vec_dot_product(hit.dir, light_dir);
// 	float light_distance = vec_sub(obj->light.origin, hit.origin).len;
// 	t_ray light = new_ray(light_pos, light_dir);
// 	if (block_object(&light, obj, light_distance))
// 		return (origin_clr);
// 	hit.clr = shade_clr(hit.clr, obj->light.clr);
// 	hit.clr = ratio_clr(hit.clr, shade_ratio);
// 	origin_clr = color_add(origin_clr, hit.clr);
// 	return (clamp_clr(origin_clr));
// }

// t_rgb	light_and_shadow(t_rgb origin_clr, t_hitpoint hit, t_obj *obj)
// {
// 	float	shade_ratio;
// 	float	light_distance;
// 	t_ray	light;

// 	light.oringin = vec_add(hit.origin, hit.dir);
// 	light.dir = vec_sub(obj->light.origin, hit.origin);
// 	light.dir = vec_norm(light.dir);
// 	light_distance = vec_sub(light.oringin, obj->light.origin).len;
// 	// if (block_object(&light, obj))
// 	// 	return (origin_clr);
// 	shade_ratio = vec_dot_product(hit.dir, light.dir);
// 	hit.clr = shade_clr(hit.clr, obj->light.clr);
// 	hit.clr = ratio_light(hit.clr, shade_ratio);
// 	origin_clr.r += hit.clr.r;
// 	origin_clr.g += hit.clr.g;
// 	origin_clr.b += hit.clr.b;
// 	return (clamp_clr(origin_clr));
// }