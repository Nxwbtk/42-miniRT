/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsirikam <bsirikam@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 00:28:17 by bsirikam          #+#    #+#             */
/*   Updated: 2023/11/09 00:45:58 by bsirikam         ###   ########.fr       */
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

void	init_camera(char **split, t_scene *scene, char *line)
{
	if (scene->camera)
		free_double_config(split, scene, line);
	scene->camera = init_camera2();
	if (!scene->camera)
		error_input(line, split, scene);
}
