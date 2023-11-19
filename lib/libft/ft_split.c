/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsirikam <bsirikam@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 18:37:42 by bsirikam          #+#    #+#             */
/*   Updated: 2022/08/10 00:54:21 by bsirikam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	word_count(char const *s, char c)
{
	int	count;

	count = 0;
	while (*s)
	{
		if (*s == c && *s)
			s++;
		else
		{
			while (*s != c && *s)
				s++;
			count++;
		}
	}
	return (count);
}

int	word_len(char const *s, char c)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (s[i] != c && s[i])
	{
		count++;
		i++;
	}
	return (count);
}

char	*let_split(char const *s, char c, char **split, int i)
{
	int	wlen;
	int	j;

	while (*s == c)
			s++;
	wlen = word_len(s, c);
	split[i] = (char *)malloc(sizeof(char) * (wlen + 1));
	if (!(split[i]))
		return (0);
	j = 0;
	while (*s != c && *s)
	{
		split[i][j] = *s;
		j++;
		s++;
	}
	split[i][j] = '\0';
	return (split[i]);
}

char	**ft_split(char const *s, char c)
{
	int		count;
	char	**split;
	int		i;

	if (!s)
		return (0);
	i = 0;
	count = word_count(s, c);
	split = (char **)malloc(sizeof(char *) * (count + 1));
	if (!split)
		return (0);
	while (i < count && *s)
	{
		split[i] = let_split(s, c, split, i);
		while (*s == c && *s)
			s++;
		s += ft_strlen(split[i]);
		i++;
	}
	split[count] = NULL;
	return (split);
}
