/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksaelim <ksaelim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 14:51:57 by ksaelim           #+#    #+#             */
/*   Updated: 2023/11/24 15:47:18 by ksaelim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

float ft_abs(float num)
{
	if (num < 0)
		return (-num);
	return (num);
}

bool isHitPlane(t_ray *ray, t_plane *plane)
{
	float denom = vec_dot_product(ray->dir, plane->dir);
	float distance;
	if (denom > 1e-6)
	{
		t_cor ray0_plane0 = vec_sub(plane->origin, ray->oringin);
		distance = ft_abs(vec_dot_product(ray0_plane0, plane->dir)) / denom;
		if (distance < 0)
			return (false);
		if (distance <= ray->t || ray->t == -1)
			ray->t = distance;
		return (true);
	}
	return (false);
}

void hitPointPlane(t_ray *ray, t_plane *plane, t_hitpoint *hitPoint)
{
	if (!isHitPlane(ray, plane))
		return;
	hitPoint->origin = ray_point(*ray);
	hitPoint->dir = plane->origin;
	hitPoint->clr = plane->clr;
}