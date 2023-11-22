/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksaelim <ksaelim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 14:28:09 by ksaelim           #+#    #+#             */
/*   Updated: 2023/11/22 15:43:21 by ksaelim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

// double hit_sphere(const point3& center, double radius, const ray& r) {
//     vec3 oc = r.origin() - center;
//     auto a = dot(r.direction(), r.direction());
//     auto b = 2.0 * dot(oc, r.direction());
//     auto c = dot(oc, oc) - radius*radius;
//     auto discriminant = b*b - 4*a*c;

//     if (discriminant < 0) {
//         return -1.0;
//     } else {
//         return (-b - sqrt(discriminant) ) / (2.0*a);
//     }
// }

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
    if (distance <= ray->t)
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