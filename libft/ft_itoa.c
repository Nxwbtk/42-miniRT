/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsirikam <bsirikam@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 18:50:31 by bsirikam          #+#    #+#             */
/*   Updated: 2022/08/09 23:50:49 by bsirikam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	find_long(int n)
{
	int	count;

	count = 0;
	while (n > 0)
	{
		n = n / 10;
		count++;
	}
	return (count);
}

char	*oh_flag(int i, int flag)
{
	char	*res;

	if (flag == 1)
	{
		res = (char *)malloc(sizeof(char) * (i + 2));
		if (!res)
			return (NULL);
		res[0] = '-';
	}
	else
	{
		res = (char *)malloc(sizeof(char) * (i + 1));
		if (!res)
			return (NULL);
	}
	return (res);
}

char	*let_to_a(int n, int i, char *res)
{
	while (n > 0 && i > 0)
	{
		res[i - 1] = '0' + (n % 10);
		n = n / 10;
		i--;
	}
	return (res);
}

char	*ft_itoa(int n)
{
	char	*res;
	int		i;
	int		flag;

	flag = 0;
	if (n < 0)
	{
		n = -n;
		flag = 1;
	}
	if (n == 0)
		return (ft_strdup("0"));
	else if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	i = find_long(n);
	res = oh_flag(i, flag);
	if (!res)
		return (NULL);
	if (flag == 1)
		i++;
	res[i] = '\0';
	res = let_to_a(n, i, res);
	return (res);
}
