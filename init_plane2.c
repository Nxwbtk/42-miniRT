/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_plane2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsirikam <bsirikam@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 00:14:45 by bsirikam          #+#    #+#             */
/*   Updated: 2023/11/16 01:55:17 by bsirikam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	isel_valid(t_plane *plane)
{
	if (!plane->cord || !plane->normal || !plane->rgb)
	{
		if (plane->cord)
			free(plane->cord);
		if (plane->normal)
			free(plane->normal);
		if (plane->rgb)
			free(plane->rgb);
		return (0);
	}
	return (1);
}

t_obj	*new_obj_pl(t_plane *plane)
{
	t_obj	*new_obj;

	new_obj = (t_obj *)malloc(sizeof(t_obj));
	if (!new_obj)
		return (NULL);
	new_obj->type = 1;
	new_obj->obj = (void *)plane;
	new_obj->next = NULL;
	return (new_obj);
}