/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   passing_utils4.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buntakansirikamonthip <buntakansirikamonth +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 01:19:49 by bsirikam          #+#    #+#             */
/*   Updated: 2023/11/16 03:42:35 by buntakansirikamo ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_obj	*obj_last(t_scene *scene)
{
	while (scene->obj && scene->obj->next)
		scene->obj = scene->obj->next;
	return (scene->obj);
}

void	obj_addback(t_scene *scene, t_obj *new_obj)
{
	t_obj	*last;

	if (scene && new_obj)
	{
		if (!scene->obj)
			scene->obj = new_obj;
		else
		{
			last = obj_last(scene);
			last->next = new_obj;
		}
	}
}