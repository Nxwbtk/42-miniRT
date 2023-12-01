/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pass.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsirikam <bsirikam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 01:21:10 by bsirikam          #+#    #+#             */
/*   Updated: 2023/12/01 20:23:20 by bsirikam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	free_scene(t_scene *scene)
{
	t_obj	*tmp;

	while (scene->obj)
	{
		tmp = scene->obj->next;
		free_obj(scene->obj);
		scene->obj = tmp;
	}
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

void	run(char *filename, t_scene *scene)
{
	int		fd;
	char	*line;

	fd = open(filename, O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		if (ft_strncmp(line, "\n", 2) == 0)
		{
			free(line);
			line = get_next_line(fd);
			continue ;
		}
		check_line(line, scene);
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	close(fd);
}

int	parsing(int ac, char **av, t_scene *scene)
{
	if (ac != 2)
		return (1);
	if (!ft_check(av[1]))
	{
		printf("Error\n");
		return (1);
	}
	run(av[1], scene);
	return (0);
}
