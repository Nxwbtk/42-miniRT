/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsirikam <bsirikam@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 21:54:59 by bsirikam          #+#    #+#             */
/*   Updated: 2022/06/15 21:54:59 by bsirikam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void	check_gern(long result)
{
	if (result > 2147483647 || result < -2147483648)
	{
		ft_putstr_fd("Error\n", 2);
		exit(EXIT_SUCCESS);
	}
}

int	ft_isspace(char c)
{
	if (c == '\t' || c == ' ' || c == '\f' || c == '\n' || c == '\r' \
	|| c == '\v')
		return (1);
	return (0);
}

int	ft_atoi(const char *chnb)
{
	int		i;
	long	count;
	long	result;

	i = 0;
	result = 0;
	count = 1;
	while (ft_isspace(chnb[i]))
		i++;
	if (chnb[i] == '-' || chnb[i] == '+')
	{
		if (chnb[i] == '-')
			count = count * -1;
		i++;
	}
	while (chnb[i] >= '0' && chnb[i] <= '9')
	{
		result = result * 10 + (chnb[i] - '0');
		i++;
	}
	check_gern(result * count);
	return (result * count);
}
