/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsirikam <bsirikam@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 01:21:10 by bsirikam          #+#    #+#             */
/*   Updated: 2023/10/28 20:53:50 by bsirikam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	run(char *filename)
{
	int		fd;
	char	*line;

	fd = open(filename, O_RDONLY);
	line = get_next_line(fd);
	if (line)
		printf("%s\n", line);
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
