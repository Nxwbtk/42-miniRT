/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsirikam <bsirikam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 01:21:10 by bsirikam          #+#    #+#             */
/*   Updated: 2023/10/01 05:59:08 by bsirikam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	ft_check(char *str)
{
	char	**split;
	int		i;

	split = NULL;
	i = 0;
	split = ft_split(str, '.');
	while (split[i])
		i++;
	if (i != 2)
		return (0);
	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
	return (1);
}

void	run(char *filename)
{
}

int	main(int ac, char **av)
{
	if (ac != 2)
		return (1);
	if (!ft_check(av[1]))
		return (1);
	run(av[1]);
	return (0);
}