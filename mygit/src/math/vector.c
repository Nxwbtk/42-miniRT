/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksaelim <ksaelim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 09:15:52 by ksaelim           #+#    #+#             */
/*   Updated: 2023/11/07 09:31:09 by ksaelim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_vec	*new_vec(float x, float y, float z)
{
	t_vec	*vec;

	vec = malloc(sizeof(t_vec));
	if (!vec)
		error_exit(-1);
	vec->x = x;
	vec->y = y;
	vec->z = z;
	return (vec);
}

t_vec	*vec_sub(t_vec *vec1, t_vec *vec2)
{
	return (new_vec(vec1->x - vec2->x, vec1->y - vec2->y, vec1->z - vec2->z));
}

float	vec_length(t_vec *vec)
{
	return (sqrt((vec->x * vec->x) + (vec->y * vec->y) + (vec->z * vec->z)));
}

void	vec_normalize(t_vec *vec)
{
	float length;

	length = vec_length(vec);
	vec->x /= length;
	vec->y /= length;
	vec->z /= length;
}

float	vec_dot_product(t_vec *vec1, t_vec *vec2)
{
	return ((vec1->x * vec2->x) + (vec1->y * vec2->y) + (vec1->z * vec2->z));
}