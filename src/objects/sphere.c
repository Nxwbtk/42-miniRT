/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsirikam <bsirikam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 14:28:09 by ksaelim           #+#    #+#             */
/*   Updated: 2023/11/25 21:12:30 by bsirikam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

bool	isHitSphere(t_ray *ray, t_sp **sphere)
{
    t_cor oc;
    float a;
    float b;
	float c;
    float distance;
    // float closest;

    (*sphere)->inside = 0;
    oc = vec_sub(ray->oringin, (*sphere)->origin);
    a = vec_dot_product(ray->dir, ray->dir);
    b = vec_dot_product(oc, ray->dir) * 2.0;
    c = vec_dot_product(oc, oc) - ((*sphere)->radius*(*sphere)->radius);
    distance = b*b - 4*a*c;
    if (distance < 0)
        return (false);
    // closest = (-b - sqrtf(distance)) / (2*a);
    // if (closest < 0) {
    //     closest = (-b + sqrtf(distance)) / (2*a);
    //     (*sphere)->inside = 1;
    // }
    // if (closest < 0)
    //     return (false);
    if (distance <= ray->t || ray->t == -1)
    {
        ray->t = distance;
        return (true);
    }
    return (false);
}

void	hitPointSphere(t_ray *ray, t_sp *sphere, t_hitpoint *hitPoint)
{
	// print_topic("hit_object");
	// print_sphere(sphere);
	// exit(0);
    if (!isHitSphere(ray, &sphere))
        return ;
    hitPoint->origin = ray_point(*ray);
    hitPoint->dir = vec_norm(vec_sub(hitPoint->origin, sphere->origin));
    if (sphere->inside == 1)
        hitPoint->dir = vec_multi_scalar(hitPoint->dir, -1);
    // hitPoint->origin = vec_add(hitPoint->origin, sphere->origin);
    hitPoint->obj_origin = sphere->origin;
    hitPoint->clr = sphere->clr;
}
