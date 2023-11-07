/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsirikam <bsirikam@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 01:21:10 by bsirikam          #+#    #+#             */
/*   Updated: 2023/11/08 00:33:02 by bsirikam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	check_line(char *line)
{
	char	**split_line;

	split_line = ft_split_space(line);
	if (split_line[0] && ft_strncmp('A',split_line[0], 2) == 0)
		init_ambient(split_line);
	else if (split_line[0] && ft_strncmp('C', split_line[0], 2) == 0)
		init_camera(split_line);
	else
	{
		free_split(split_line);
		printf("Error\n");
		exit(1);
	}
	exit(0);
}

void	run(char *filename)
{
	int		fd;
	char	*line;

	fd = open(filename, O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		check_line(line);
		free(line);
		line = get_next_line(fd);
	}
	free(line);
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
