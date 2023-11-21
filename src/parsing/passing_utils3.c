/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   passing_utils3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsirikam <bsirikam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 22:02:31 by bsirikam          #+#    #+#             */
/*   Updated: 2023/11/21 22:16:16 by bsirikam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parsing.h"

void	free_obj(t_obj *obj)
{
	t_plane		*plane;
	t_sp		*sphere;
	t_cy		*cylinder;

	if (obj && obj->type == 1)
	{
		plane = (t_plane *)obj->obj;
		free(plane);
	}
	if (obj && obj->type == 2)
	{
		sphere = (t_sp *)obj->obj;
		free(sphere);
	}
	if (obj && obj->type == 3)
	{
		cylinder = (t_cy *)obj->obj;
		free(cylinder);
	}
	free(obj);
}

void	free_double_config(char **split, t_scene *scene, char *line)
{
	printf("Error Double Config\n");
	free(line);
	free_split(split);
	free_scene(scene);
	exit(1);
}

float	ft_atof(char *str)
{
	float	res;
	int		sign;
	float	factor;

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
