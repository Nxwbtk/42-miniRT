/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_operator.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksaelim <ksaelim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 17:45:40 by ksaelim           #+#    #+#             */
/*   Updated: 2023/11/20 00:52:13 by ksaelim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_vec3f   new_vec3f(float x, float y, float z)
{
	t_vec3f   vec;

	vec.x = x;
	vec.y = y;
	vec.z = z;
	vec.length = vec3f_length(vec);
	vec.normalize = vec3f_normalize(vec);
	return (vec);
}
t_vec3f   *vec3f_normalize(t_vec3f vec)
{
	t_vec3f   *normalize;

	normalize = malloc(sizeof(t_vec3f));
	normalize->x = vec.x / vec.length;
	normalize->y = vec.y / vec.length;
	normalize->z = vec.z / vec.length;
	normalize->length = 1;
	normalize->normalize = NULL;
	return (normalize);
}

t_vec3f	vec3f_add(t_vec3f vec1, t_vec3f vec2)
{
	return (new_vec3f(vec1.x + vec2.x, vec1.y + vec2.y, vec1.z + vec2.z));
}

t_vec3f	vec3f_addNum(t_vec3f vec1, float t)
{
	return (new_vec3f(vec1.x + t, vec1.y + t, vec1.z + t));
}

t_vec3f	vec3f_sub(t_vec3f vec1, t_vec3f vec2)
{
	return (new_vec3f(vec1.x - vec2.x, vec1.y - vec2.y, vec1.z - vec2.z));
}

t_vec3f	vec3f_multi_scalar(t_vec3f vec, float t)
{
	return (new_vec3f(vec.x * t, vec.y * t, vec.z * t));
}

t_vec3f   vec3f_div(t_vec3f vec, float t)
{
	return (new_vec3f(vec.x / t, vec.y / t, vec.z / t));
}

float	vec3f_length(t_vec3f vec)
{
	return (sqrt((vec.x * vec.x) + (vec.y * vec.y) + (vec.z * vec.z)));
}

float	vec3f_dot_product(t_vec3f vec1, t_vec3f vec2)
{
	return ((vec1.x * vec2.x) + (vec1.y * vec2.y) + (vec1.z * vec2.z));
}

t_vec3f	vec3f_cross(t_vec3f vec1, t_vec3f vec2)
{
	t_vec3f	result;

	result.x = vec1.y * vec2.z - vec1.z * vec2.y;
	result.y = vec1.z * vec2.x - vec1.x * vec2.z;
	result.z = vec1.x * vec2.y - vec1.y * vec2.x;
	return (result);
}
