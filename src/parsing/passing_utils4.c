/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   passing_utils4.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsirikam <bsirikam@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 01:19:49 by bsirikam          #+#    #+#             */
/*   Updated: 2023/11/30 23:30:10 by bsirikam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_obj	*obj_last(t_obj *obj)
{
	while (obj && obj->next)
		obj = obj->next;
	return (obj);
}

int	obj_size(t_obj *obj)
{
	int	i;

	i = 0;
	while (obj)
	{
		obj = obj->next;
		i++;
	}
	return (i);
}

void	obj_addback(t_scene *scene, t_obj *new_obj)
{
	t_obj	*last;

	if (scene && new_obj)
	{
		new_obj->light = scene->light;
		new_obj->ambient = scene->ambient.ratio;
		if (!scene->obj)
			scene->obj = new_obj;
		else
		{
			last = obj_last(scene->obj);
			last->next = new_obj;
		}
		new_obj->id = obj_size(scene->obj);
	}
}

static float	vec_len_parsing(t_cor vec)
{
	return (sqrt((vec.x * vec.x) + (vec.y * vec.y) + (vec.z * vec.z)));
}

t_cor	new_vec_parsing(float x, float y, float z)
{
	t_cor	vec;

	vec.x = x;
	vec.y = y;
	vec.z = z;
	vec.len = vec_len_parsing(vec);
	return (vec);
}
