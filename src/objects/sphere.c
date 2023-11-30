/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsirikam <bsirikam@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 14:28:09 by ksaelim           #+#    #+#             */
/*   Updated: 2023/11/30 22:50:57 by bsirikam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

bool	is_hit_sphere(t_ray *ray, t_sp **sphere)
{
	t_cor	oc;
	t_abc	abc;
	float	distance;
	float	closest;

	(*sphere)->inside = 0;
	oc = vec_sub(ray->oringin, (*sphere)->origin);
	abc.a = vec_dot_product(ray->dir, ray->dir);
	abc.b = vec_dot_product(oc, ray->dir) * 2.0;
	abc.c = vec_dot_product(oc, oc) - ((*sphere)->radius * (*sphere)->radius);
	distance = abc.b * abc.b - 4 * abc.a * abc.c;
	if (distance < 0)
		return (false);
	closest = (-abc.b - sqrtf(distance)) / (2 * abc.a);
	if (closest < 0 || closest < MIN)
	{
		closest = (-abc.b + sqrtf(distance)) / (2 * abc.a);
		(*sphere)->inside = 1;
	}
	if (closest < 0 || closest < MIN)
		return (false);
	if (closest <= ray->t || ray->t == -1)
		return (ray->t = closest, true);
	return (false);
}

void	hp_sphere(t_ray *ray, t_sp *sphere, t_hitpoint *hitPoint)
{
	if (!is_hit_sphere(ray, &sphere))
		return ;
	hitPoint->origin = ray_point(*ray);
	hitPoint->dir = vec_norm(vec_sub(hitPoint->origin, sphere->origin));
	if (sphere->inside == 1)
		hitPoint->dir = vec_multi_scalar(hitPoint->dir, -1);
	hitPoint->origin = vec_add(hitPoint->origin, sphere->origin);
	hitPoint->obj_origin = sphere->origin;
	hitPoint->clr = sphere->clr;
}
