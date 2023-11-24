/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_operator1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsirikam <bsirikam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 17:45:40 by ksaelim           #+#    #+#             */
/*   Updated: 2023/11/25 00:01:23 by bsirikam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_cor	vec_add(t_cor vec1, t_cor vec2)
{
	return (new_vec(vec1.x + vec2.x, vec1.y + vec2.y, vec1.z + vec2.z));
}

t_cor	vec_sub(t_cor vec1, t_cor vec2)
{
	return (new_vec(vec1.x - vec2.x, vec1.y - vec2.y, vec1.z - vec2.z));
}

t_cor	vec_multi_scalar(t_cor vec, float t)
{
	return (new_vec(vec.x * t, vec.y * t, vec.z * t));
}

t_cor	vec_div(t_cor vec, float t)
{
	return (new_vec(vec.x / t, vec.y / t, vec.z / t));
}

float	vec_dot_product(t_cor vec1, t_cor vec2)
{
	return ((vec1.x * vec2.x) + (vec1.y * vec2.y) + (vec1.z * vec2.z));
}
