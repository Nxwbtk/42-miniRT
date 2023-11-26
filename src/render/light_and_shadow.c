/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light_and_shadow.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksaelim <ksaelim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 14:59:22 by ksaelim           #+#    #+#             */
/*   Updated: 2023/11/26 15:09:51 by ksaelim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"


int	is_shadow(t_ray ray_to_light, t_hitpoint hit, t_obj *obj)
{
	t_sp	*sp;
	t_plane	*pl;
	t_obj	*lst;
	int		is_shadow;
	float	t_light;

	t_light = vec_sub(obj->light.origin, hit.origin).len;
	// printf("t_light: %f\n", t_light);
	is_shadow = 0;
	lst = obj;
	while (lst)
	{
		if (obj->type == 1 && hit.id != obj->id)
		{
			pl = (t_plane *)obj->obj;
			if (isHitPlane(&ray_to_light, &pl))
			{
				printf("shadow plane\n");
				is_shadow = 1;
				break ;
			}
		}
		else if (obj->type == 2 && hit.id != obj->id)
		{
			sp = (t_sp *)obj->obj;
			if (isHitSphere(&ray_to_light, &sp))
			{
				printf("shadow sphere\n");
				is_shadow = 1;
				break ;
			}
		}
		else if (obj->type == 3 && hit.id != obj->id)
		{
			if (hit_cylinder(&ray_to_light, (t_cy *)obj->obj, NULL, 1)
			||disk_intersection(&ray_to_light, NULL, (t_cy *)obj->obj, 1))
			{
				printf("shadow sphere\n");
				is_shadow = 1;
				break ;
			}
		}
		lst = lst->next;
	}
	if (ray_to_light.t > t_light)
		is_shadow = 0;
	return (is_shadow);
}
