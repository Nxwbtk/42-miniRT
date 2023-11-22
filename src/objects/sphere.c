/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksaelim <ksaelim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 14:28:09 by ksaelim           #+#    #+#             */
/*   Updated: 2023/11/21 16:00:33 by ksaelim          ###   ########.fr       */
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

float   hit_sphere(t_cor center, float radius, t_ray r)
{
    t_cor oc = vec_sub(r.oringin, center);
    float a = vec_dot_product(r.dir, r.dir);
    float b = vec_dot_product(oc, r.dir) * 2.0;
	float c = vec_dot_product(oc, oc) - (radius*radius);
    float discriminant = b*b - 4*a*c;

    if (discriminant >= 0)
        return (1);
    return 0;
    // if (discriminant < 0) {
    //     return -1.0;
    // } else {
    //     return (-b - sqrt(discriminant) ) / (2.0*a);
    // }
}