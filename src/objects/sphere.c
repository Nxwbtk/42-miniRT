/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsirikam <bsirikam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 14:28:09 by ksaelim           #+#    #+#             */
/*   Updated: 2023/11/24 17:15:43 by bsirikam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

bool    isHitSphere(t_ray *ray, t_sp *sphere)
{
    t_cor oc;
    float a;
    float b;
	float c;
    float distance;

    oc = vec_sub(ray->oringin, sphere->origin);
    a = vec_dot_product(ray->dir, ray->dir);
    b = vec_dot_product(oc, ray->dir) * 2.0;
    c = vec_dot_product(oc, oc) - (sphere->radius*sphere->radius);
    distance = b*b - 4*a*c;
    if (distance < 0)
        return (false);
    // distance = (-b - sqrt(distance)) / (2.0*a);
    if (distance <= ray->t || ray->t == -1)
        ray->t = distance;
    return (true);
}

void hitPointSphere(t_ray *ray, t_sp *sphere, t_hitpoint *hitPoint)
{
    if (!isHitSphere(ray, sphere))
        return ;
    hitPoint->origin = ray_point(*ray);
    hitPoint->dir = sphere->origin;
    hitPoint->clr = sphere->clr;
}