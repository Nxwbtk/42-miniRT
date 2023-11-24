/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light_and_shadow.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsirikam <bsirikam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 14:59:22 by ksaelim           #+#    #+#             */
/*   Updated: 2023/11/24 23:53:10 by bsirikam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_rgb	fill_ambient(t_rgb obj_clr, t_rgb ambient_clr)
{
	obj_clr = shade_clr(obj_clr, ambient_clr);
	return (clamp_clr(obj_clr));
}

// not sure, it should be to calculate by include distance
bool	block_object(t_ray *ray, t_obj *obj)
{
	t_sp	*tmp;

	while (obj)
	{
		if (obj->type == 1)
		{
			tmp = (t_sp *)obj->obj;
			if (isHitSphere(ray, &tmp))
				return (true);
		}
		else if (obj->type == 2)
		{
			if (isHitPlane(ray, (t_plane *)obj->obj))
				return (true);
		}
		obj = obj->next;
	}
	return (false);
}

t_rgb	light_and_shadow(t_rgb origin_clr, t_hitpoint hit, t_obj *obj)
{
	float	shade_ratio;
	float	light_distance;
	t_ray	light;

	light.oringin = vec_add(hit.origin, hit.dir);
	light.dir = vec_sub(obj->light.origin, hit.origin);
	light.dir = vec_norm(light.dir);
	light_distance = vec_sub(light.oringin, obj->light.origin).len;
	if (block_object(&light, obj))
		return (origin_clr);
	shade_ratio = vec_dot_product(hit.dir, light.dir);
	hit.clr = shade_clr(hit.clr, obj->light.clr);
	hit.clr = ratio_light(hit.clr, shade_ratio);
	origin_clr.r += hit.clr.r;
	origin_clr.g += hit.clr.g;
	origin_clr.b += hit.clr.b;
	return (clamp_clr(origin_clr));
}
