/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsirikam <bsirikam@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 14:51:57 by ksaelim           #+#    #+#             */
/*   Updated: 2023/11/30 22:44:42 by bsirikam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

float	ft_abs(float num)
{
	if (num < 0)
		return (-num);
	return (num);
}

bool	is_hit_plane(t_ray *ray, t_plane **plane)
{
	float	distance;
	t_cor	ray0_plane0;

	(*plane)->denom = vec_dot_product(ray->dir, (*plane)->dir);
	if (ft_abs((*plane)->denom) > MIN)
	{
		ray0_plane0 = vec_sub((*plane)->origin, ray->oringin);
		distance = vec_dot_product(ray0_plane0, \
		(*plane)->dir) / (*plane)->denom;
		if (distance < 0)
			return (false);
		if (distance > MIN && (distance < ray->t || ray->t == -1))
			return (ray->t = distance, true);
	}
	return (false);
}

void	hit_point_plane(t_ray *ray, t_plane *plane, t_hitpoint *hitPoint)
{
	if (!is_hit_plane(ray, &plane))
		return ;
	hitPoint->origin = ray_point(*ray);
	hitPoint->dir = plane->dir;
	if (plane->denom > 0)
		hitPoint->dir = vec_multi_scalar(hitPoint->dir, -1);
	hitPoint->clr = plane->clr;
}
