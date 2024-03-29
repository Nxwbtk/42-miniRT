/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksaelim <ksaelim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 17:42:43 by bsirikam          #+#    #+#             */
/*   Updated: 2023/11/26 13:52:56 by ksaelim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

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

t_light	init_light2(void)
{
	t_light	light;

	light.origin = new_vec_parsing(0, 0, 0);
	light.clr.r = 0;
	light.clr.g = 0;
	light.clr.b = 0;
	light.ratio = 0;
	light.is_init = 1;
	return (light);
}

void	put_xyz_light(t_scene *scene, char **split)
{
	char	**xyz;

	xyz = ft_split(split[1], ',');
	scene->light.origin = new_vec_parsing(ft_atof(xyz[0]), ft_atof(xyz[1]), \
	ft_atof(xyz[2]));
	free_split(xyz);
	xyz = ft_split(split[3], ',');
	scene->light.clr.r = ft_atoi(xyz[0]);
	scene->light.clr.g = ft_atoi(xyz[1]);
	scene->light.clr.b = ft_atoi(xyz[2]);
	free_split(xyz);
	scene->light.ratio = ft_atof(split[2]);
	scene->light.clr = ratio_clr(scene->light.clr, scene->light.ratio);
}

void	init_light(char **split, t_scene *scene, char *line)
{
	if (scene->light.is_init == 1)
		free_double_config(split, scene, line);
	scene->light = init_light2();
	if (check_arg_light(split) == 0)
		error_input(line, split, scene);
	put_xyz_light(scene, split);
}
