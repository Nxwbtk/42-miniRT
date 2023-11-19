/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_plane2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsirikam <bsirikam@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 00:14:45 by bsirikam          #+#    #+#             */
/*   Updated: 2023/11/16 03:17:06 by bsirikam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	isel_valid(t_plane *plane)
{
	if (!plane->origin || !plane->dir || !plane->rgb)
	{
		if (plane->origin)
			free(plane->origin);
		if (plane->dir)
			free(plane->dir);
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