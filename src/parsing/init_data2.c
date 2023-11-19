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

#include "parsing.h"

void	init_camera_xyz(t_camera *camera)
{
	camera->origin->x = 0;
	camera->origin->y = 0;
	camera->origin->z = 0;
	camera->dir = new_vec3f(0, 0, 0);
	camera->fov = 0;
}

t_camera	*init_camera2(void)
{
	t_camera	*camera;

	camera = (t_camera *)malloc(sizeof(t_camera));
	if (!camera)
		return (NULL);
	camera->origin = (t_cord3f *)malloc(sizeof(t_cord3f));
	if (!camera->origin)
	{
		if (camera)
			free(camera);
		return (NULL);
	}
	camera->dir = (t_vec3f *)malloc(sizeof(t_vec3f));
	if (!camera->dir)
	{
		if (camera->origin)
			free(camera->origin);
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
	scene->camera->origin->x = ft_atof(xyz[0]);
	scene->camera->origin->y = ft_atof(xyz[1]);
	scene->camera->origin->z = ft_atof(xyz[2]);
	free_split(xyz);
	xyz = ft_split(split[2], ',');
	scene->camera->dir.x = ft_atof(xyz[0]);
	scene->camera->dir.y = ft_atof(xyz[1]);
	scene->camera->dir.z = ft_atof(xyz[2]);
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
	scene->camera->origin = (t_cord3f *)malloc(sizeof(t_cord3f));
	if (!scene->camera->origin)
		error_input(line, split, scene);
	scene->camera->dir = (t_vec3f *)malloc(sizeof(t_vec3f));
	if (!scene->camera->dir)
	{
		if (scene->camera->origin)
			free(scene->camera->origin);
		error_input(line, split, scene);
	}
	put_xyz(scene, split);
}
