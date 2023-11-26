/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_object.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksaelim <ksaelim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 14:57:49 by ksaelim           #+#    #+#             */
/*   Updated: 2023/11/26 05:37:10 by ksaelim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

bool	hit_object(t_ray *ray, t_obj *obj, t_hitpoint *hitPoint)
{
	float old_t;
	
	while (obj)
	{
		old_t = ray->t;
		if (obj->type == 1)
		{
			hitPointPlane(ray, (t_plane *)obj->obj, hitPoint);
			if (ray->t != -1 || old_t > ray->t)
				hitPoint->id = obj->id;
		}
		else if (obj->type == 2)
		{
			hitPointSphere(ray, (t_sp *)obj->obj, hitPoint);
			if (ray->t != -1 || old_t > ray->t)
				hitPoint->id = obj->id;
		}
		else if (obj->type == 3)
		{
			hit_cylinder(ray, (t_cy *)obj->obj, hitPoint, 0);
			disk_intersection(ray, hitPoint, (t_cy *)obj->obj, 0);
			if (ray->t != -1 || old_t > ray->t)
				hitPoint->id = obj->id;
		}
		obj = obj->next;
	}
	if (ray->t == -1)
		return (false);
	return (true);
}
