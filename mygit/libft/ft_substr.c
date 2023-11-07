/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsirikam <bsirikam@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 09:10:21 by bsirikam          #+#    #+#             */
/*   Updated: 2022/08/10 00:51:37 by bsirikam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	s_len;
	char	*res;
	char	*sc;

	if (!s)
		return (0);
	s_len = ft_strlen(s);
	if (len == 0 || (start + 1 > s_len))
		return (ft_strdup("\0"));
	if (len >= s_len)
		len = s_len - start;
	res = malloc((sizeof(char)) * (len + 1));
	if (res == NULL || !s)
		return (NULL);
	sc = (char *)s;
	i = 0;
	while (sc[start + i] && i < len)
	{
		res[i] = sc[start + i];
		i++;
	}
	res[i] = '\0';
	return (res);
}
