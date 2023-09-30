/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsirikam <bsirikam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 13:33:17 by bsirikam          #+#    #+#             */
/*   Updated: 2023/10/01 05:11:23 by bsirikam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*free_line(char *line)
{
	if (line)
		free(line);
	return (NULL);
}

char	*teelua(char *line)
{
	char	*tmp;
	ssize_t	i;

	if (!line && !line[0])
	{
		line = free_line(line);
		return (NULL);
	}
	if (!(ft_strlen_gnl(line) - ft_piset_len(line)))
	{
		line = free_line(line);
		return (NULL);
	}
	tmp = (char *)malloc(sizeof(char) * ((ft_strlen_gnl(line) - \
		ft_piset_len(line)) + 2));
	if (!tmp)
		return (NULL);
	i = -1;
	while (++i < (ft_strlen_gnl(line) - ft_piset_len(line)))
		tmp[i] = line[i + ft_piset_len(line)];
	if (line[i + ft_piset_len(line)] == '\n')
		tmp[i] = line[i + ft_piset_len(line)];
	tmp[i] = '\0';
	line = free_line(line);
	return (tmp);
}

char	*find_result(char *s)
{
	char	*result;
	int		i;

	i = 0;
	if (!s[0])
		return (NULL);
	result = (char *)malloc(sizeof(char) * (ft_piset_len(s) + 1));
	if (!result)
		return (NULL);
	while (s[i])
	{
		result[i] = s[i];
		if (s[i] == '\n')
		{
			i++;
			break ;
		}
		i++;
	}
	result[i] = '\0';
	return (result);
}

char	*arn(int fd, char *buff, char *line)
{
	int			khanhad;

	khanhad = read(fd, buff, BUFFER_SIZE);
	while (khanhad)
	{
		buff[khanhad] = '\0';
		line = ft_strjoin(line, buff);
		if ((khanhad < BUFFER_SIZE && khanhad > 0) || ha_nee(line, '\n'))
			break ;
		khanhad = read(fd, buff, BUFFER_SIZE);
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*line;
	char		*res;
	char		*buff;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, NULL, 0) < 0)
		return (NULL);
	if (!line)
	{
		line = malloc(1);
		if (!line)
			return (NULL);
		*line = '\0';
	}
	buff = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
	{
		free (line);
		return (NULL);
	}
	line = arn(fd, buff, line);
	if (buff)
		free (buff);
	res = find_result(line);
	line = teelua(line);
	return (res);
}
