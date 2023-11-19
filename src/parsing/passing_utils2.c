/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsirikam <bsirikam@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 00:00:20 by bsirikam          #+#    #+#             */
/*   Updated: 2023/11/08 00:18:50 by bsirikam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	ft_isspace(char c)
{
	if (c == 32 || (c >= 9 && c <= 13))
		return (1);
	return (0);
}

char	**ft_split_space(char *line)
{
	char	**split;
	int		i;
	int		j;
	int		k;

	if (!line)
		return (NULL);
	split = (char **)malloc(sizeof(char *) * 255);
	if (!split)
		return (NULL);
	i = 0;
	j = 0;
	while (line[i])
	{
		k = 0;
		split[j] = (char *)malloc(sizeof(char) * 255);
		if (!split[j])
			return (NULL);
		while (ft_isspace(line[i]))
			i++;
		while (!ft_isspace(line[i]) && line[i])
			split[j][k++] = line[i++];
		split[j][k] = '\0';
		j++;
	}
	split[j] = NULL;
	return (split);
}
