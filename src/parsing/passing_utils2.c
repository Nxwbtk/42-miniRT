/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   passing_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buntakansirikamonthip <buntakansirikamonth +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 00:00:20 by bsirikam          #+#    #+#             */
/*   Updated: 2023/11/21 17:54:10 by buntakansirikamo ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parsing.h"

int	ft_isspaces(char c)
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
		while (ft_isspaces(line[i]))
			i++;
		while (!ft_isspaces(line[i]) && line[i])
			split[j][k++] = line[i++];
		split[j][k] = '\0';
		j++;
	}
	split[j] = NULL;
	return (split);
}
