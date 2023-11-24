/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsirikam <bsirikam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 00:30:03 by bsirikam          #+#    #+#             */
/*   Updated: 2023/11/24 23:36:51 by bsirikam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parsing.h"

t_scene	init_struct(void)
{
	t_scene	scene;

	scene.obj = NULL;
	scene.ambient.is_init = 0;
	scene.camera.is_init = 0;
	scene.light.is_init = 0;
	return (scene);
}

t_ambient	init_ambient2(void)
{
	t_ambient	ambient;

	ambient.ratio = 0;
	ambient.clr.r = 0;
	ambient.clr.g = 0;
	ambient.clr.b = 0;
	ambient.is_init = 1;
	return (ambient);
}

void	init_rgb(t_scene *scene, char *line, char **split)
{
	char	**rgb;

	if (!split[2])
		error_input(line, split, scene);
	rgb = ft_split(split[2], ',');
	if (!rgb || !rgb[0] || !rgb[1] || !rgb[2])
	{
		free_split(rgb);
		error_input(line, split, scene);
	}
	scene->ambient.clr.r = ft_atoi(rgb[0]);
	scene->ambient.clr.g = ft_atoi(rgb[1]);
	scene->ambient.clr.b = ft_atoi(rgb[2]);
	if (scene->ambient.clr.r < 0 || scene->ambient.clr.r > 255)
		error_input(line, split, scene);
	if (scene->ambient.clr.g < 0 || scene->ambient.clr.g > 255)
		error_input(line, split, scene);
	if (scene->ambient.clr.b < 0 || scene->ambient.clr.b > 255)
		error_input(line, split, scene);
	free_split(rgb);
}

void	init_ambient(char **split, t_scene *scene, char *line)
{
	if (scene->ambient.is_init == 1)
		free_double_config(split, scene, line);
	scene->ambient = init_ambient2();
	if (!split[1] || !split[2])
		error_input(line, split, scene);
	scene->ambient.ratio = ft_atof(split[1]);
	if (scene->ambient.ratio < 0 || scene->ambient.ratio > 1)
		error_input(line, split, scene);
	init_rgb(scene, line, split);
}
