/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data4.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksaelim <ksaelim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 20:43:19 by bsirikam          #+#    #+#             */
/*   Updated: 2023/11/23 22:45:49 by ksaelim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parsing.h"

void	init_pl(t_scene *scene, char **split, char *line)
{
	t_plane	*plane;
	t_obj	*new_obj;

	plane = new_plane(split);
	if (!plane)
		error_input(line, split, scene);
	new_obj = new_obj_pl(plane);
	if (!new_obj)
	{
		free(plane);
		error_input(line, split, scene);
	}
	obj_addback(scene, new_obj);
}

void	init_sp(t_scene *scene, char **split, char *line)
{
	t_sp		*sphere;
	t_obj		*new_obj;

	sphere = new_sphere(split);
	if (!sphere)
		error_input(line, split, scene);
	new_obj = new_obj_sp(sphere);
	if (!new_obj)
	{
		free(sphere);
		error_input(line, split, scene);
	}
	obj_addback(scene, new_obj);
}

void	init_cy(t_scene *scene, char **split, char *line)
{
	t_cy	*cylinder;
	t_obj	*new_obj;

	cylinder = new_cylinder(split);
	if (!cylinder)
		error_input(line, split, scene);
	new_obj = new_obj_cy(cylinder);
	if (!new_obj)
	{
		free(cylinder);
		error_input(line, split, scene);
	}
	obj_addback(scene, new_obj);
}

void	init_obj(char **split, t_scene *scene, char *line)
{
	if (ft_strncmp("pl", split[0], 3) == 0)
		init_pl(scene, split, line);
	else if (ft_strncmp("sp", split[0], 3) == 0)
		init_sp(scene, split, line);
	else if (ft_strncmp("cy", split[0], 3) == 0)
		init_cy(scene, split, line);
	else
		error_input(line, split, scene);
}
