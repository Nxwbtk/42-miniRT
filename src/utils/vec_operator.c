/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_operator.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksaelim <ksaelim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 17:45:40 by ksaelim           #+#    #+#             */
/*   Updated: 2023/11/20 23:20:21 by ksaelim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"


t_cor vec_add(t_cor vec1, t_cor vec2)
{
	return (new_vec(vec1.x + vec2.x, vec1.y + vec2.y, vec1.z + vec2.z));
}

t_axis	calculate_axis(t_cor dir)
{
	t_axis	axis;
	t_cor	y_axis;

	y_axis = new_vec(0, 1.0f, 0);
	axis.dir = dir;
	if (dir.y == -1 || dir.y == 1)
		y_axis = new_vec1(0, 0, 1.0f * dir.y);
	axis.hor = vec_norm(vec_cross(axis.dir, y_axis));
	axis.ver = vec_norm(vec_cross(axis.hor, axis.dir));
	return (axis);
}

t_cor vec_sub(t_cor vec1, t_cor vec2)
{
	return (new_vec(vec1.x - vec2.x, vec1.y - vec2.y, vec1.z - vec2.z));
}

t_cor vec_multi_scalar(t_cor vec, float t)
{
	return (new_vec(vec.x * t, vec.y * t, vec.z * t));
}

t_cor vec_div(t_cor vec, float t)
{
	return (new_vec(vec.x / t, vec.y / t, vec.z / t));
}


float vec_dot_product(t_cor vec1, t_cor vec2)
{
	return ((vec1.x * vec2.x) + (vec1.y * vec2.y) + (vec1.z * vec2.z));
}

t_cor vec_cross(t_cor vec1, t_cor vec2)
{
	t_cor result;

	result.x = vec1.y * vec2.z - vec1.z * vec2.y;
	result.y = vec1.z * vec2.x - vec1.x * vec2.z;
	result.z = vec1.x * vec2.y - vec1.y * vec2.x;
	return (result);
}
