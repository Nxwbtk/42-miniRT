/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_object.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsirikam <bsirikam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 14:57:49 by ksaelim           #+#    #+#             */
/*   Updated: 2023/12/01 21:28:29 by bsirikam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	type_one(t_ray *ray, t_obj *obj, t_hitpoint *hit_point, float old_t)
{
	hit_point_plane(ray, (t_plane *)obj->obj, hit_point);
	if (ray->t != -1 || old_t > ray->t)
		hit_point->id = obj->id;
}

void	type_two(t_ray *ray, t_obj *obj, t_hitpoint *hit_point, float old_t)
{
	hp_sphere(ray, (t_sp *)obj->obj, hit_point);
	if (ray->t != -1 || old_t > ray->t)
		hit_point->id = obj->id;
}

void	type_three(t_ray *ray, t_obj *obj, t_hitpoint *hit_point, float old_t)
{
	hitpoint_cylinder(ray, (t_cy *)obj->obj, hit_point);
	if (ray->t != -1 || old_t > ray->t)
		hit_point->id = obj->id;
}

bool	hit_object(t_ray *ray, t_obj *obj, t_hitpoint *hitPoint)
{
	float	old_t;

	while (obj)
	{
		old_t = ray->t;
		if (obj->type == 1)
			type_one(ray, obj, hitPoint, old_t);
		else if (obj->type == 2)
			type_two(ray, obj, hitPoint, old_t);
		else if (obj->type == 3)
			type_three(ray, obj, hitPoint, old_t);
		obj = obj->next;
	}
	if (ray->t == -1)
		return (false);
	return (true);
}
