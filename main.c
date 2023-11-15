/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buntakansirikamonthip <buntakansirikamonth +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 01:21:10 by bsirikam          #+#    #+#             */
/*   Updated: 2023/11/16 03:42:54 by buntakansirikamo ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	free_scene(t_scene *scene)
{
	t_obj	*tmp;

	if (scene->ambient)
	{
		if (scene->ambient->rgb)
			free(scene->ambient->rgb);
		free(scene->ambient);
	}
	if (scene->camera)
	{
		if (scene->camera->cord)
			free(scene->camera->cord);
		if (scene->camera->normal)
			free(scene->camera->normal);
		free(scene->camera);
	}
	if (scene->light)
	{
		if (scene->light->cord)
			free(scene->light->cord);
		if (scene->light->rgb)
			free(scene->light->rgb);
		free(scene->light);
	}
	while (scene->obj)
	{
		tmp = scene->obj->next;
		free_obj(scene->obj);
		scene->obj = tmp;
	}
	free(scene);
}

void	error_input(char *line, char **split_line, t_scene *scene)
{
	free(line);
	free_split(split_line);
	free_scene(scene);
	printf("Error\n");
	exit(1);
}

void	check_line(char *line, t_scene *scene)
{
	char	**split_line;

	split_line = ft_split_space(line);
	if (split_line[0] && ft_strncmp("A", split_line[0], 2) == 0)
		init_ambient(split_line, scene, line);
	else if (split_line[0] && ft_strncmp("C", split_line[0], 2) == 0)
		init_camera(split_line, scene, line);
	else if (split_line[0] && ft_strncmp("L", split_line[0], 2) == 0)
		init_light(split_line, scene, line);
	else if (split_line[0] && (ft_strncmp("pl", split_line[0], 3) == 0 || \
	ft_strncmp("sp", split_line[0], 3) == 0 || \
	ft_strncmp("cy", split_line[0], 3) == 0))
		init_obj(split_line, scene, line);
	else
		error_input(line, split_line, scene);
	free_split(split_line);
}

void	run(char *filename)
{
	int		fd;
	char	*line;
	t_scene	*scene;

	scene = init_struct();
	if (!scene)
	{
		printf("Error\n");
		exit(1);
	}
	fd = open(filename, O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		check_line(line, scene);
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	close(fd);
}

int	main(int ac, char **av)
{
	if (ac != 2)
		return (1);
	if (!ft_check(av[1]))
	{
		printf("Error\n");
		return (1);
	}
	run(av[1]);
	return (0);
}
