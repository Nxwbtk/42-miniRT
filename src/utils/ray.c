/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsirikam <bsirikam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 22:24:53 by ksaelim           #+#    #+#             */
/*   Updated: 2023/11/25 00:01:48 by bsirikam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_ray	new_ray(t_cor oringin, t_cor dir)
{
	t_ray	ray;

	ray.oringin = oringin;
	ray.dir = dir;
	ray.t = -1;
	return (ray);
}

t_cor	ray_point(t_ray ray)
{
	return (vec_add(ray.oringin, vec_multi_scalar(ray.dir, ray.t)));
}
