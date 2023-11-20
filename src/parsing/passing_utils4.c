/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   passing_utils4.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buntakansirikamonthip <buntakansirikamonth +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 01:19:49 by bsirikam          #+#    #+#             */
/*   Updated: 2023/11/20 19:31:10 by buntakansirikamo ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parsing.h"

t_obj	*obj_last(t_obj *obj)
{
	while (obj && obj->next)
		obj = obj->next;
	return (obj);
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
			last = obj_last(scene->obj);
			last->next = new_obj;
		}
	}
}
