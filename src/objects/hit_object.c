/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_object.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksaelim <ksaelim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 14:57:49 by ksaelim           #+#    #+#             */
/*   Updated: 2023/11/24 15:47:02 by ksaelim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

bool hit_object(t_ray *ray, t_obj *obj, t_hitpoint *hitPoint)
{
	while (obj)
	{
		if (obj->type == 1)
			hitPointSphere(ray, (t_sp *)obj->obj, hitPoint);
		else if (obj->type == 2)
			hitPointPlane(ray, (t_plane *)obj->obj, hitPoint);
		// else
		// 	hit_cylinder(ray, (t_cy *)tmp->obj, hitPoint);
		obj = obj->next;
	}
	if (ray->t == -1)
		return (false);
	return (true);
}
