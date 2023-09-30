/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsirikam <bsirikam@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 21:24:10 by bsirikam          #+#    #+#             */
/*   Updated: 2022/06/04 21:24:10 by bsirikam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

size_t	ft_strlcpy(char *dest, char *src, size_t n)
{
	size_t	i;
	size_t	s_len;

	s_len = ft_strlen(src);
	if (n == 0)
		return (s_len);
	i = 0;
	while (i < n - 1 && src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (s_len);
}

// int	main(void)
// {
// 	char src[] = "coucou";
// 	char dest[10]; memset(dest, 'A', 10);
// 	printf("%lu\n", strlen(src));
// 	printf("%zu\n", ft_strlcpy(dest, src, 2));
// 	printf("%c\n", dest[2]);
// }