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

#include "math.h"

t_vec	vec_add(t_vec *vec1, t_vec *vec2)
{
	t_vec	result;
	result.x = vec1->x + vec2->x;
	result.y = vec1->y + vec2->y;
	result.z = vec1->z + vec2->z;
	return (result);
}

t_vec	vec_sub(t_vec *vec1, t_vec *vec2)
{
	t_vec	result;
	result.x = vec1->x - vec2->x;
	result.y = vec1->y - vec2->y;
	result.z = vec1->z - vec2->z;
	return (result);
}

t_vec	vec_scalar(t_vec *vec1, t_vec *vec2)
{
	t_vec	result;
	result.x = vec1->x - vec2->x;
	result.y = vec1->y - vec2->y;
	result.z = vec1->z - vec2->z;
	return (result);
}

t_vec	vec_sub(t_vec *vec1, t_vec *vec2)
{
	t_vec	result;
	result.x = vec1->x - vec2->x;
	result.y = vec1->y - vec2->y;
	result.z = vec1->z - vec2->z;
	return (result);
}
