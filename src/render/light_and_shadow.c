/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light_and_shadow.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksaelim <ksaelim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 14:59:22 by ksaelim           #+#    #+#             */
/*   Updated: 2023/12/02 12:07:09 by ksaelim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	check_pl(t_obj *obj, t_hitpoint hit, t_ray *ray_to_light)
{
	(void)hit;
	t_plane	*pl;

	pl = (t_plane *)obj->obj;
	if (is_hit_plane(ray_to_light, &pl))
	{
		// printf("shadow plane\n");
		return (1);
	}
	return (0);
}

int	check_sp(t_obj *obj, t_hitpoint hit, t_ray *ray_to_light)
{
	(void)hit;
	t_sp	*sp;

	sp = (t_sp *)obj->obj;
	if (is_hit_sphere(ray_to_light, &sp))
	{
		return (1);
	}
	return (0);
}

int	check_cy(t_obj *obj, t_hitpoint hit, t_ray *ray_to_light)
{
	(void)hit;
	t_cy	*cy;

	cy = (t_cy *)obj->obj;
	if (is_hit_cylinder(ray_to_light, &cy) || \
	disk_intersection(ray_to_light, &cy))
		return (1);
	return (0);
}

int	loop_handle(t_obj *obj, t_hitpoint hit, t_ray *ray_to_light)
{
	t_obj	*lst;

	lst = obj;
	while (lst)
	{
		if (lst->type == 1)
		{
			if (check_pl(lst, hit, ray_to_light))
				return (1);
		}
		else if (lst->type == 2)
		{
			if (check_sp(lst, hit, ray_to_light))
				return (1);
		}
		else if (lst->type == 3)
		{
			if (check_cy(lst, hit, ray_to_light))
				return (1);
		}
		lst = lst->next;
	}
	return (0);
}

int	is_shadow(t_ray ray_to_light, t_hitpoint hit, t_obj *obj)
{
	int		is_shadow;
	float	t_light;

	t_light = vec_sub(obj->light.origin, hit.origin).len;
	is_shadow = loop_handle(obj, hit, &ray_to_light);
	if (ray_to_light.t > t_light || ray_to_light.t == -1)
		is_shadow = 0;
	return (is_shadow);
}
