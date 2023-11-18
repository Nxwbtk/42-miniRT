/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsirikam <bsirikam@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 00:28:17 by bsirikam          #+#    #+#             */
/*   Updated: 2023/11/09 17:07:17 by bsirikam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	init_camera_xyz(t_camera *camera)
{
	camera->cord->x = 0;
	camera->cord->y = 0;
	camera->cord->z = 0;
	camera->normal->x = 0;
	camera->normal->y = 0;
	camera->normal->z = 0;
	camera->fov = 0;
}

t_camera	*init_camera2(void)
{
	t_camera	*camera;

	camera = (t_camera *)malloc(sizeof(t_camera));
	if (!camera)
		return (NULL);
	camera->cord = (t_cord *)malloc(sizeof(t_cord));
	if (!camera->cord)
	{
		if (camera)
			free(camera);
		return (NULL);
	}
	camera->normal = (t_normal *)malloc(sizeof(t_normal));
	if (!camera->normal)
	{
		if (camera->cord)
			free(camera->cord);
		if (camera)
			free(camera);
		return (NULL);
	}
	init_camera_xyz(camera);
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
	scene->camera->cord->x = ft_atof(xyz[0]);
	scene->camera->cord->y = ft_atof(xyz[1]);
	scene->camera->cord->z = ft_atof(xyz[2]);
	free_split(xyz);
	xyz = ft_split(split[2], ',');
	scene->camera->normal->x = ft_atof(xyz[0]);
	scene->camera->normal->y = ft_atof(xyz[1]);
	scene->camera->normal->z = ft_atof(xyz[2]);
	free_split(xyz);
}

void	init_camera(char **split, t_scene *scene, char *line)
{
	if (scene->camera)
		free_double_config(split, scene, line);
	scene->camera = init_camera2();
	if (!scene->camera || check_arg(split))
		error_input(line, split, scene);
	scene->camera->fov = ft_atof(split[3]);
	if (scene->camera->fov < 0 || scene->camera->fov > 180)
		error_input(line, split, scene);
	scene->camera->cord = (t_cord *)malloc(sizeof(t_cord));
	if (!scene->camera->cord)
		error_input(line, split, scene);
	scene->camera->normal = (t_normal *)malloc(sizeof(t_normal));
	if (!scene->camera->normal)
	{
		if (scene->camera->cord)
			free(scene->camera->cord);
		error_input(line, split, scene);
	}
	put_xyz(scene, split);
}
