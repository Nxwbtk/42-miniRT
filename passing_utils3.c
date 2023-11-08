/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   passing_utils3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsirikam <bsirikam@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 22:02:31 by bsirikam          #+#    #+#             */
/*   Updated: 2023/11/09 00:41:13 by bsirikam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	free_double_config(char **split, t_scene *scene, char *line)
{
	printf("Error Double Config\n");
	free(line);
	free_split(split);
	free_scene(scene);
	exit(1);
}

double	ft_atof(char *str)
{
	double	res;
	int		sign;
	double	factor;

	res = 0.0;
	sign = 1;
	factor = 1.0;
	while (ft_isspace(*str))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (ft_isdigit(*str))
	{
		res = res * 10.0 + (*str - '0');
		str++;
	}
	if (*str == '.')
	{
		str++;
		while (ft_isdigit(*str))
		{
			factor /= 10.0;
			res += (*str - '0') * factor;
			str++;
		}
	}
	return (res * sign);
}
