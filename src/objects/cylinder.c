/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksaelim <ksaelim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 02:23:20 by bsirikam          #+#    #+#             */
/*   Updated: 2023/11/26 17:47:17 by ksaelim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

bool	disk_intersection(t_ray *ray, t_cy **cy)
{
	float	denom;
	float	distance;
	float	distance_bot;
	t_cor	tmp_hitpoint;
	t_cor	pos;

	denom = vec_dot_product(ray->dir, (*cy)->dir);
	if (ft_abs(denom) < MIN)
		return (false);
    if (denom > 0)
    {
        (*cy)->inside_disk = 1;
    }
	pos = (*cy)->top;
	distance = vec_dot_product(vec_sub(pos, ray->oringin), (*cy)->dir) / denom;
	distance_bot = vec_dot_product(vec_sub((*cy)->bot, ray->oringin), (*cy)->dir) / denom;
	if (distance < 0.00f || (distance_bot > 0.00f && distance_bot < distance))
	{
		distance = distance_bot;
		pos = (*cy)->bot;
	}
	if (distance < 0.00f || (distance > ray->t && ray->t != -1))
		return (false);
	tmp_hitpoint = vec_add(ray->oringin, vec_multi_scalar(ray->dir, distance));
	if (vec_sub(tmp_hitpoint, pos).len > (*cy)->radius)
		return (false);
    (*cy)->disk = true;
    ray->t = distance;
	return (true);
}

bool    is_hit_cylinder(t_ray *ray, t_cy **cylinder)
{
    float a;
    float b;
    float c;
    float distance;
    float closest;

    (*cylinder)->inside_body = 0;
    t_cor oc = vec_sub(ray->oringin, (*cylinder)->origin);
    a = vec_dot_product(ray->dir, ray->dir) - pow(vec_dot_product(ray->dir, (*cylinder)->dir), 2);
    b = 2 * (vec_dot_product(ray->dir, oc) - (vec_dot_product(ray->dir, (*cylinder)->dir) * vec_dot_product(oc, (*cylinder)->dir)));
    c = vec_dot_product(oc, oc) - pow(vec_dot_product(oc, (*cylinder)->dir), 2) - ((*cylinder)->radius * (*cylinder)->radius);
    
    distance = (b * b) - (4 * a * c);
    if (distance < 0)
        return (false);

    closest = (-b - sqrtf(distance)) / (2*a);
    if (closest < 0) {
        closest = (-b + sqrtf(distance)) / (2*a);
        (*cylinder)->inside_body = 1;
    }
    if (closest < 0)
        return (false);
    if (closest > ray->t && ray->t != -1)
        return (false);
    (*cylinder)->m = vec_dot_product(ray->dir, (*cylinder)->dir) * closest + vec_dot_product(oc, (*cylinder)->dir);
	if (ft_abs((*cylinder)->m) > (*cylinder)->height / 2)
		return (false);
    return (ray->t = closest, true);
}

void    hitpoint_cylinder(t_ray *ray, t_cy *cylinder, t_hitpoint *hitpoint)
{
    if (!is_hit_cylinder(ray, &cylinder) && !disk_intersection(ray, &cylinder))
        return ;
    hitpoint->origin = ray_point(*ray);
    if (cylinder->disk)
    {
        hitpoint->dir = cylinder->dir;
        if (cylinder->inside_disk)
            hitpoint->dir = vec_multi_scalar(hitpoint->dir, -1);
        hitpoint->origin = vec_add(hitpoint->origin, cylinder->origin);
    }
    else
    {
        hitpoint->dir = vec_norm(hitpoint->origin);
        if (cylinder->inside_body)
            hitpoint->dir = vec_multi_scalar(hitpoint->dir, -1);
    }
    hitpoint->obj_origin = cylinder->origin;
    hitpoint->clr = cylinder->clr;
}