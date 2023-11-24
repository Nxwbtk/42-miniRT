/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsirikam <bsirikam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 02:23:20 by bsirikam          #+#    #+#             */
/*   Updated: 2023/11/25 05:10:02 by bsirikam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	hit_body(t_ray *ray, float t, t_cy *cylinder, float *dot)
{
	t_cor	point;
	t_cor	origin_diff;

	point = vec_add(ray->oringin, vec_multi_scalar(ray->dir, t));
	origin_diff = vec_sub(point, cylinder->origin);
	*dot = vec_dot_product(origin_diff, cylinder->dir);
	if (fabs(*dot) > cylinder->height / 2)
		return (0);
	return (1);
}

int	is_cylinder(t_ray *ray, t_cy *cylinder)
{
	t_cor	oc;
	float	data[3];
	float	discriminator;
	float	t[3];
	float	dot[2];

	oc = vec_sub(ray->oringin, cylinder->origin);
	data[0] = vec_dot_product(ray->dir, ray->dir) - pow(vec_dot_product(ray->dir, cylinder->dir), 2);
	data[1] = (vec_dot_product(ray->dir, oc) - vec_dot_product(ray->dir, cylinder->dir) * vec_dot_product(oc, cylinder->dir));
	data[2] = vec_dot_product(oc, oc) - pow(vec_dot_product(oc, cylinder->dir), 2) - (cylinder->radius * cylinder->radius);
	discriminator = (data[1] * data[1]) - (data[0] * data[2]);
	if (discriminator < 0)
		return (0);
	t[1] = ((data[1] * -1) - sqrt(discriminator)) / data[0];
	t[2] = ((data[1] * -1) + sqrt(discriminator)) / data[0];
	t[0] = t[1];
	if (t[1] > t[2])
		t[0] = t[2];
	if (t[0] < 0.0 && t[0] <= ray->t && hit_body(ray, t[0], cylinder, &dot[0]))
		return (1);
	dot[1] = ray->t;
}

void	hit_cylinder(t_ray *ray, t_cy *cylinder, t_hitpoint *hitPoint)
{
	
}
