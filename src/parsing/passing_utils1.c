/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   passing_utils1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsirikam <bsirikam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 20:06:54 by bsirikam          #+#    #+#             */
/*   Updated: 2023/11/23 11:23:54 by bsirikam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parsing.h"

void	free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

int	ft_isfile(char *str)
{
	char	**split;
	int		i;

	split = NULL;
	i = 0;
	split = ft_split(str, '.');
	while (split[i])
		i++;
	if (i != 2)
	{
		free_split(split);
		return (0);
	}
	if (ft_strncmp(split[1], "rt", 3) != 0)
	{
		free_split(split);
		return (0);
	}
	free_split(split);
	return (1);
}

int	ft_isopenable(char *str)
{
	int	fd;

	fd = open(str, O_RDONLY);
	if (fd == -1)
		return (0);
	close(fd);
	return (1);
}

int	ft_check(char *str)
{
	char	**split;
	int		i;

	split = NULL;
	// if (ft_isfile(str) == 0)
	// 	return (0);
	i = 0;
	split = ft_split(str, ' ');
	while (split[i])
		i++;
	if (i != 1)
	{
		free_split(split);
		return (0);
	}
	free_split(split);
	if (ft_isopenable(str) == 0)
		return (0);
	return (1);
}
