/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksaelim <ksaelim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 00:28:17 by bsirikam          #+#    #+#             */
/*   Updated: 2023/11/22 15:58:17 by ksaelim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parsing.h"

t_camera	init_camera2(void)
{
	t_camera	camera;

	camera.origin = new_vec_parsing(0, 0, 0);
	camera.dir = new_vec_parsing(0, 0, 0);
	camera.fov = 0;
	camera.is_init = 1;
	return (camera);
}

int	check_arg(char **split)
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
	check_split = ft_split(split[2], ',');
	if (!check_split[0] || !check_split[1] || !check_split[2])
	{
		free_split(check_split);
		return (0);
	}
	free_split(check_split);
	return (0);
}

void	put_xyz(t_scene *scene, char **split)
{
	char	**xyz;

	xyz = ft_split(split[1], ',');
	scene->camera.origin = new_vec_parsing(ft_atof(xyz[0]), ft_atof(xyz[1]), \
	ft_atof(xyz[2]));
	free_split(xyz);
	xyz = ft_split(split[2], ',');
	scene->camera.dir = new_vec_parsing(ft_atof(xyz[0]), ft_atof(xyz[1]), \
	ft_atof(xyz[2]));
	free_split(xyz);
}

void	init_camera(char **split, t_scene *scene, char *line)
{
	if (scene->camera.is_init == 1)
		free_double_config(split, scene, line);
	scene->camera = init_camera2();
	if (scene->camera.is_init == 0 || check_arg(split))
		error_input(line, split, scene);
	scene->camera.fov = ft_atof(split[3]);
	if (scene->camera.fov < 0 || scene->camera.fov > 180)
		error_input(line, split, scene);
	put_xyz(scene, split);
}
