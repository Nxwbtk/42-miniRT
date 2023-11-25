/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsirikam <bsirikam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 02:23:20 by bsirikam          #+#    #+#             */
/*   Updated: 2023/11/25 21:10:03 by bsirikam         ###   ########.fr       */
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

// void	hit_cylinder(t_ray *ray, t_cy *cylinder, t_hitpoint *hitPoint)
// {
// 	if (!is_cylinder(ray, cylinder))
// 		return ;
// 	hitPoint->origin = ray_point(*ray);
// 	hitPoint->dir = vec_norm(hitPoint->origin);
// 	//if (cylinder->inside == 1)
// 	//	hitPoint->dir = vec_multi_scalar(hitPoint->dir, -1);
// 	// hitPoint->origin = vec_add(hitPoint->origin, sphere->origin);
// 	hitPoint->obj_origin = cylinder->origin;
// 	hitPoint->clr = cylinder->clr;
// }

void	hit_cylinder(t_ray *ray, t_cy *cylinder, t_hitpoint *hitPoint)
{
	t_fml	fml;
	float	disc;
	float	t_closet;
	float	oc;

	
}
