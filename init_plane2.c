/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_plane2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsirikam <bsirikam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 00:14:45 by bsirikam          #+#    #+#             */
/*   Updated: 2023/11/11 00:21:46 by bsirikam         ###   ########.fr       */
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