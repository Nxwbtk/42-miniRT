/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsirikam <bsirikam@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 20:48:20 by bsirikam          #+#    #+#             */
/*   Updated: 2022/08/10 22:48:19 by bsirikam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	front(const char *s1, const char *set)
{
	size_t	begin;

	begin = 0;
	while (s1[begin] && ft_strrchr(set, s1[begin]))
		begin++;
	return (begin);
}

size_t	last(const char *s1, const char *set)
{
	size_t	finish;

	finish = ft_strlen(s1);
	while (ft_strrchr(set, s1[finish]) && finish)
		finish--;
	return (finish);
}

char	*m_des(size_t size, char *dest, char const *s1, size_t first)
{
	size_t	i;

	i = 0;
	dest = malloc(sizeof(char) * (size + 1));
	if (!dest)
		return (NULL);
	while (i < size)
		dest[i++] = s1[first++];
	return (dest);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	first;
	size_t	finish;
	size_t	size;
	char	*dest;

	if (!s1 || !set)
		return (NULL);
	dest = NULL;
	first = front(s1, set);
	finish = last(s1, set);
	if (first > finish || (finish == 0 && first == 0))
	{
		dest = malloc(1);
		if (!dest)
			return (0);
		dest[0] = 0;
		return (dest);
	}
	size = finish - first + 1;
	dest = m_des(size, dest, s1, first);
	if (!dest)
		return (NULL);
	dest[size] = '\0';
	return (dest);
}

//int	main(void)
//{
//	char	*s = ft_strtrim("          ", " ");
//	printf("%s\n", s);
//}
