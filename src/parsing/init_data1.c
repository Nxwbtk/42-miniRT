/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsirikam <bsirikam@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 00:30:03 by bsirikam          #+#    #+#             */
/*   Updated: 2023/11/09 17:40:41 by bsirikam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

t_scene	*init_struct(void)
{
	t_scene	*scene;

	scene = (t_scene *)malloc(sizeof(t_scene));
	if (!scene)
		return (NULL);
	scene->ambient = NULL;
	scene->camera = NULL;
	scene->light = NULL;
	scene->obj = NULL;
	return (scene);
}

t_ambient	*init_ambient2(void)
{
	t_ambient	*ambient;

	ambient = (t_ambient *)malloc(sizeof(t_ambient));
	if (!ambient)
		return (NULL);
	ambient->ratio = 0;
	ambient->rgb = (t_rgb *)malloc(sizeof(t_rgb));
	if (!ambient->rgb)
	{
		if (ambient)
			free(ambient);
		return (NULL);
	}
	ambient->rgb->r = 0;
	ambient->rgb->g = 0;
	ambient->rgb->b = 0;
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
	scene->ambient->rgb->r = ft_atof(rgb[0]);
	scene->ambient->rgb->g = ft_atof(rgb[1]);
	scene->ambient->rgb->b = ft_atof(rgb[2]);
	if (scene->ambient->rgb->r < 0 || scene->ambient->rgb->r > 255)
		error_input(line, split, scene);
	if (scene->ambient->rgb->g < 0 || scene->ambient->rgb->g > 255)
		error_input(line, split, scene);
	if (scene->ambient->rgb->b < 0 || scene->ambient->rgb->b > 255)
		error_input(line, split, scene);
	free_split(rgb);
}

void	init_ambient(char **split, t_scene *scene, char *line)
{
	if (scene->ambient)
		free_double_config(split, scene, line);
	scene->ambient = init_ambient2();
	if (!scene->ambient || !split[1] || !split[2])
		error_input(line, split, scene);
	scene->ambient->ratio = ft_atof(split[1]);
	if (scene->ambient->ratio < 0 || scene->ambient->ratio > 1)
		error_input(line, split, scene);
	init_rgb(scene, line, split);
}
