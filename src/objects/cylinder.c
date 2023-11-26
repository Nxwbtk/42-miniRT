/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksaelim <ksaelim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 02:23:20 by bsirikam          #+#    #+#             */
/*   Updated: 2023/11/26 13:15:45 by ksaelim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

// static void	ha_bon_lang(t_cor *tb, t_cy *cylinder)
// {
// 	t_cor	half;

// 	half = vec_multi_scalar(cylinder->dir, cylinder->height / 2);
// 	tb[0] = vec_add(cylinder->origin, half);
// 	tb[1] = vec_sub(cylinder->origin, half);
// }

// int	hit_cap(t_cy *cylinder, t_ray *ray, float *dot)
// {
// 	float	denom;
// 	float	t;
// 	t_cor	tb[2];
// 	t_cor	v;
// 	t_cor	t_dot;

// 	denom = vec_dot_product(cylinder->dir, ray->dir);
// 	ha_bon_lang(tb, cylinder);
// }

// int	hit_body(t_ray *ray, float t, t_cy *cylinder, float *dot)
// {
// 	t_cor	point;
// 	t_cor	origin_diff;

// 	point = vec_add(ray->oringin, vec_multi_scalar(ray->dir, t));
// 	origin_diff = vec_sub(point, cylinder->origin);
// 	*dot = vec_dot_product(origin_diff, cylinder->dir);
// 	if (fabs(*dot) >= cylinder->height)
// 		return (0);
// 	return (1);
// }

// int	is_cylinder(t_ray *ray, t_cy *cylinder)
// {
// 	t_cor	oc;
// 	float	data[3];
// 	float	discriminator;
// 	float	t[3];
// 	float	dot[2];

// 	oc = vec_sub(ray->oringin, cylinder->origin);
// 	data[0] = vec_dot_product(ray->dir, ray->dir) - \
// 		pow(vec_dot_product(ray->dir, vec_norm(cylinder->dir)), 2);
// 	data[1] = 2 * ((vec_dot_product(ray->dir, oc) - vec_dot_product(ray->dir, vec_norm(cylinder->dir)) \
// 		* vec_dot_product(oc, vec_norm(cylinder->dir))));
// 	data[2] = vec_dot_product(oc, oc) - pow(vec_dot_product(oc, vec_norm(cylinder->dir)), 2) \
// 		- (cylinder->radius * cylinder->radius);
// 	discriminator = (data[1] * data[1]) - (4 * data[0] * data[2]);
// 	printf("data[0] = %f\n", data[0]);
// 	printf("data[1] = %f\n", data[1]);
// 	printf("data[2] = %f\n", data[2]);
// 	printf("discriminator = %f\n", discriminator);
// 	if (discriminator < 0)
// 		return (0);
// 	t[1] = ((data[1] * -1) - sqrt(discriminator)) / 2 * data[0];
// 	t[2] = ((data[1] * -1) + sqrt(discriminator)) / 2 * data[0];
// 	t[0] = t[1];
// 	if (t[1] > t[2])
// 		t[0] = t[2];
// 	if (t[0] >= 0.0 && (t[0] <= ray->t || ray->t == -1) \
// 	&& hit_body(ray, t[0], cylinder, &dot[0]))
// 		return (1);
// 	return (0);
// }



static bool	closest_disk(t_hitpoint *hit, t_cy *cy, float denom)
{
	hit->dir = cy->dir;
	if (denom > 0)
		hit->dir = vec_multi_scalar(hit->dir, -1);
	hit->clr = cy->clr;
	return (true);
}

bool	disk_intersection(t_ray *ray, t_hitpoint *hit, t_cy *cy, int mode)
{
	float	denom;
	float	distance;
	float	distance_bot;
	t_cor	tmp_hitpoint;
	t_cor	pos;

	denom = vec_dot_product(ray->dir, cy->dir);
	if (ft_abs(denom) < MIN)
		return (false);
	pos = cy->top;
	distance = vec_dot_product(vec_sub(pos, ray->oringin), cy->dir) / denom;
	distance_bot = vec_dot_product(vec_sub(cy->bot, ray->oringin), cy->dir) / denom;
	if (distance < 0.00f || (distance_bot > 0.00f && distance_bot < distance))
	{
		distance = distance_bot;
		pos = cy->bot;
	}
	if (distance < 0.00f || distance > ray->t)
		return (false);
	tmp_hitpoint = vec_add(ray->oringin, vec_multi_scalar(ray->dir, distance));
	if (vec_sub(tmp_hitpoint, pos).len > cy->radius)
		return (false);
	if (mode)
		return (true);
	ray->t = distance;
	return (hit->origin = tmp_hitpoint, closest_disk(hit, cy, denom));
}

static bool	closest_cylinder(t_ray *ray, t_hitpoint *hit, t_cy *cy, float distance)
{
	ray->t = distance;
	hit->origin = vec_add(ray->oringin, vec_multi_scalar(ray->dir, ray->t));
	hit->dir = vec_norm(hit->origin);
	if (cy->inside)
		hit->dir = vec_multi_scalar(hit->dir, -1);
	hit->origin = vec_add(hit->origin, cy->origin);
	hit->clr = cy->clr;
	hit->obj_origin = cy->origin;
	return (true);
}

float ft_pow2(float num)
{
	return (num * num);
}

bool	hit_cylinder(t_ray *ray, t_cy *cy, t_hitpoint *hit, int mode)
{
	t_cor oc;
    float a;
    float b;
	float c;
    float distance;
	float	t_closest;
	
	cy->inside = false;
	oc = vec_sub(ray->oringin, cy->origin);
	a = vec_dot_product(ray->dir, ray->dir) - ft_pow2(vec_dot_product(ray->dir, cy->dir));
	b = 2 * (vec_dot_product(ray->dir, ray->oringin) - vec_dot_product(ray->dir, cy->dir)
			* vec_dot_product(ray->oringin, cy->dir));
	c = vec_dot_product(ray->oringin, ray->oringin) - ft_pow2(vec_dot_product(ray->oringin, cy->dir))
		- ft_pow2(cy->radius);
	distance = b * b - 4 * a * c;
	if (distance < 0.0f)
		return (false);
	t_closest = (-b - sqrtf(distance)) / (2*a);
    if (t_closest < 0 || t_closest < MIN) {
        t_closest = (-b + sqrtf(distance)) / (2*a);
        cy->inside = true;
    }
	if ((t_closest < 0.00f || t_closest > ray->t) && t_closest < MIN)
		return (false);
	else
		ray->t = t_closest;
	cy->m = vec_dot_product(ray->dir, cy->dir) * t_closest + vec_dot_product(ray->oringin, cy->dir);
	if (ft_abs(cy->m) > cy->height / 2)
		return (false);
	if (mode)
		return (true);
	return (closest_cylinder(ray, hit, cy, t_closest));
}

// void	hit_cylinder(t_ray *ray, t_cy *cylinder, t_hitpoint *hitPoint)
// {
// 	t_fml	fml;
// 	float	t_closest;
// 	t_cor	oc;
// 	float	discriminant;
// 	float	dot;

// 	if (!is_hit_cylinder(ray, cylinder))
// 		return ;
// 	cylinder->inside = false;
// 	oc = vec_sub(ray->oringin, cylinder->origin);
// 	fml.a = vec_dot_product(ray->dir, ray->dir) - pow(vec_dot_product(ray->dir, cylinder->dir), 2);
// 	fml.b = 2 * (vec_dot_product(ray->dir, oc) - vec_dot_product(ray->dir, \
// 	cylinder->dir) * vec_dot_product(oc, cylinder->dir));
// 	fml.c = vec_dot_product(oc, oc) - pow(vec_dot_product(oc, cylinder->dir), 2) \
// 	- pow(cylinder->radius, 2);
// 	discriminant = ft_discriminant(fml.a, fml.b, fml.c);
// 	if (discriminant < 0.0f)
// 		return ;
// 	t_closest = (-fml.b - sqrtf(discriminant)) / (2 * fml.a);
// 	if (t_closest < 0.00f)
// 		t_closest = hit_inside(fml, discriminant, &cylinder->inside);
// 	if (t_closest < 0.00f || t_closest > ray->t)
// 		return ;
// 	dot = vec_dot_product(ray->dir, cylinder->dir) * t_closest + vec_dot_product(oc, cylinder->dir);
// 	printf("dot = %f\n", dot);
// 	// if (fabs(dot) > cylinder->height / 2)V
// 	// 	return ;
// }
