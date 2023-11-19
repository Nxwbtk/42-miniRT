/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsirikam <bsirikam@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 17:42:43 by bsirikam          #+#    #+#             */
/*   Updated: 2023/11/09 20:28:22 by bsirikam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	check_arg_light(char **split)
{
	char	**check_split;

	if (!split[1] || !split[2] || !split[3])
		return (0);
	check_split = ft_split(split[1], ',');
	if (!check_split[0] || !check_split[1] || !check_split[2])
	{
		free_split(check_split);
		return (0);
	}
	free_split(check_split);
	check_split = ft_split(split[3], ',');
	if (!check_split[0] || !check_split[1] || !check_split[2])
	{
		free_split(check_split);
		return (0);
	}
	free_split(check_split);
	return (1);
}

t_light	*init_light2(void)
{
	t_light	*light;

	light = (t_light *)malloc(sizeof(t_light));
	if (!light)
		return (NULL);
	light->origin = NULL;
	light->rgb = NULL;
	light->ratio = 0;
	return (light);
}

void	put_xyz_light(t_scene *scene, char **split)
{
	char	**xyz;

	xyz = ft_split(split[1], ',');
	scene->light->origin->x = ft_atof(xyz[0]);
	scene->light->origin->y = ft_atof(xyz[1]);
	scene->light->origin->z = ft_atof(xyz[2]);
	free_split(xyz);
	xyz = ft_split(split[3], ',');
	scene->light->rgb->r = ft_atof(xyz[0]);
	scene->light->rgb->g = ft_atof(xyz[1]);
	scene->light->rgb->b = ft_atof(xyz[2]);
	free_split(xyz);
	scene->light->ratio = ft_atof(split[2]);
}

void	init_light(char **split, t_scene *scene, char *line)
{
	if (scene->light)
		free_double_config(split, scene, line);
	scene->light = init_light2();
	if (!scene->light || check_arg_light(split) == 0)
		error_input(line, split, scene);
	scene->light->origin = (t_cord3f *)malloc(sizeof(t_cord3f));
	if (!scene->light->origin)
		error_input(line, split, scene);
	scene->light->rgb = (t_rgb *)malloc(sizeof(t_rgb));
	if (!scene->light->rgb)
		error_input(line, split, scene);
	put_xyz_light(scene, split);
}