/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsirikam <bsirikam@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 05:48:53 by bsirikam          #+#    #+#             */
/*   Updated: 2022/06/06 05:48:53 by bsirikam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	d_len;
	size_t	sc_len;
	size_t	result;
	size_t	i;

	result = 0;
	i = 0;
	d_len = ft_strlen(dst);
	sc_len = ft_strlen(src);
	if (!size)
		return (sc_len);
	if (size > d_len)
		result = sc_len + d_len;
	else
		return (sc_len + size);
	while (src[i] && i < size - d_len - 1)
	{
		dst[d_len + i] = src[i];
		i++;
	}
	dst[d_len + i] = '\0';
	return (result);
}
