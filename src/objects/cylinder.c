/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsirikam <bsirikam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 02:23:20 by bsirikam          #+#    #+#             */
/*   Updated: 2023/12/02 22:51:47 by bsirikam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

bool	d_inter2(t_ray *ray, t_cy **cy, float distance, t_cor pos)
{
	t_cor	tmp_hitpoint;

	if (distance < 0.00f || (distance > ray->t && ray->t != -1) \
	|| distance < MIN)
		return (false);
	tmp_hitpoint = vec_add(ray->oringin, vec_multi_scalar(ray->dir, distance));
	if (vec_sub(tmp_hitpoint, pos).len > (*cy)->radius)
		return (false);
	(*cy)->disk = true;
	ray->t = distance;
	return (true);
}

bool	disk_intersection(t_ray *ray, t_cy **cy)
{
	float	denom;
	float	distance;
	float	distance_bot;
	t_cor	pos;

	(*cy)->disk = false;
	(*cy)->inside_disk = false;
	denom = vec_dot_product(ray->dir, (*cy)->dir);
	if (ft_abs(denom) < 0.001f)
		return (false);
	if (denom > 0)
		(*cy)->inside_disk = true;
	pos = (*cy)->top;
	distance = vec_dot_product(vec_sub(pos, ray->oringin), (*cy)->dir) / denom;
	distance_bot = vec_dot_product(vec_sub((*cy)->bot, ray->oringin), \
	(*cy)->dir) / denom;
	if (distance < 0.00f || (distance_bot > 0.00f && distance_bot < distance))
	{
		distance = distance_bot;
		pos = (*cy)->bot;
	}
	return (d_inter2(ray, cy, distance, pos));
}

t_abc	find_abc(t_ray *ray, t_cy **cylinder, t_cor oc)
{
	t_abc	abc;

	abc.a = vec_dot_product(ray->dir, ray->dir) - ft_pow(\
	vec_dot_product(ray->dir, (*cylinder)->dir));
	abc.b = 2 * (vec_dot_product(ray->dir, oc) - (vec_dot_product(ray->dir, \
	(*cylinder)->dir) * vec_dot_product(oc, (*cylinder)->dir)));
	abc.c = vec_dot_product(oc, oc) - ft_pow(vec_dot_product(oc, \
	(*cylinder)->dir)) - ((*cylinder)->radius * (*cylinder)->radius);
	return (abc);
}

bool	is_hit_cylinder(t_ray *ray, t_cy **cylinder)
{
	t_abc	abc;
	float	distance;
	float	closest;
	t_cor	oc;

	(*cylinder)->inside_body = false;
	oc = vec_sub(ray->oringin, (*cylinder)->origin);
	abc = find_abc(ray, cylinder, oc);
	distance = (abc.b * abc.b) - (4 * abc.a * abc.c);
	if (distance < 0.0f)
		return (false);
	closest = (-abc.b - sqrtf(distance)) / (2 * abc.a);
	if (closest < 0.0f)
	{
		closest = (-abc.b + sqrtf(distance)) / (2 * abc.a);
		(*cylinder)->inside_body = true;
	}
	if (closest < 0.00f || (closest > ray->t && ray->t != -1) || closest < MIN)
		return (false);
	(*cylinder)->m = vec_dot_product(ray->dir, (*cylinder)->dir) * \
	closest + vec_dot_product(oc, (*cylinder)->dir);
	if (ft_abs((*cylinder)->m) > (*cylinder)->height / 2)
		return (false);
	ray->t = closest;
	return (true);
}

void	hitpoint_cylinder(t_ray *ray, t_cy *cylinder, t_hitpoint *hitpoint)
{
	if (!is_hit_cylinder(ray, &cylinder) && !disk_intersection(ray, &cylinder))
		return ;
	hitpoint->origin = ray_point(*ray);
	if (cylinder->disk)
	{
		hitpoint->dir = cylinder->dir;
		if (cylinder->inside_disk)
			hitpoint->dir = vec_multi_scalar(hitpoint->dir, -1);
	}
	else
	{
		hitpoint->dir = vec_norm(vec_sub(hitpoint->origin, cylinder->origin));
		if (cylinder->inside_body)
			hitpoint->dir = vec_multi_scalar(hitpoint->dir, -1);
		hitpoint->origin = vec_add(hitpoint->origin, cylinder->origin);
	}
	hitpoint->obj_origin = cylinder->origin;
	hitpoint->clr = cylinder->clr;
}
