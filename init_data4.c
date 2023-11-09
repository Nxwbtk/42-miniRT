/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data4.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsirikam <bsirikam@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 20:43:19 by bsirikam          #+#    #+#             */
/*   Updated: 2023/11/09 22:21:12 by bsirikam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	init_pl(t_scene *scene, char **split)
{
	t_plane	*plane;

	plane = new_plane(split);
}

void	init_sp(t_scene *scene, char **split)
{

}

void	init_cy(t_scene *scene, char **split)
{

}

void	init_obj(char **split, t_scene *scene, char *line)
{
	if (ft_strncmp("pl", split[0], 3) == 0)
		init_pl(scene, split);
	else if (ft_strncmp("sp", split[0], 3) == 0)
		init_sp(scene, split);
	else if (ft_strncmp("cy", split[0], 3) == 0)
		init_cy(scene, split);
	else
		error_input(line, split, scene);
}