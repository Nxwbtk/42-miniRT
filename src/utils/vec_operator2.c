/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_operator2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksaelim <ksaelim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 18:38:26 by ksaelim           #+#    #+#             */
/*   Updated: 2023/11/24 15:41:55 by ksaelim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

static float vec_len(t_cor vec)
{
	return (sqrt((vec.x * vec.x) + (vec.y * vec.y) + (vec.z * vec.z)));
}

t_cor	vec_norm(t_cor vec)
{
	register float	length;

	length = vec_len(vec);
	vec.x /= length;
	vec.y /= length;
	vec.z /= length;
	vec.len = 1;
	return (vec);
}

t_cor new_vec(float x, float y, float z)
{
	t_cor vec;

	vec.x = x;
	vec.y = y;
	vec.z = z;
	vec.len= vec_len(vec);
	return (vec);
}

t_cor	new_vec1(float x, float y, float z)
{
	t_cor	vec;

	vec = new_vec(x, y, z);
	return (vec_norm(vec));
}

t_cor vec_cross(t_cor vec1, t_cor vec2)
{
	t_cor result;

	result.x = vec1.y * vec2.z - vec1.z * vec2.y;
	result.y = vec1.z * vec2.x - vec1.x * vec2.z;
	result.z = vec1.x * vec2.y - vec1.y * vec2.x;
	return (result);
}
