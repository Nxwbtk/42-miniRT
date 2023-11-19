/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_operator.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksaelim <ksaelim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 17:45:40 by ksaelim           #+#    #+#             */
/*   Updated: 2023/10/19 10:22:38 by ksaelim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

t_vec3f   new_vec3f(float x, float y, float z)
{
	t_vec3f   vec;

	vec.x = x;
	vec.y = y;
	vec.z = z;
	vec.length = vec3f_length(vec);
	vec.normalize = vec3f_div(vec, vec.length);
	return (vec);
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

#include <stdio.h>

t_vec3f print_vec3f(char *point_name, t_vec3f vec)
{
	printf("%s (%f, %f, %f)\n", point_name, vec.x, vec.y, vec.z);
	return (vec);
}