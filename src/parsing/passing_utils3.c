/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   passing_utils3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsirikam <bsirikam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 22:02:31 by bsirikam          #+#    #+#             */
/*   Updated: 2023/12/01 20:56:43 by bsirikam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

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

t_atof	init_atof(void)
{
	t_atof	atof;

	atof.res = 0.0;
	atof.sign = 1;
	atof.factor = 1.0;
	return (atof);
}

void	handle_loop(t_atof *atof, char *str)
{
	while (ft_isdigit(*str))
	{
		atof->factor /= 10.0;
		atof->res += (*str - '0') * atof->factor;
		str++;
	}
}

float	ft_atof(char *str)
{
	t_atof	atof;

	atof = init_atof();
	while (ft_isspace(*str))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			atof.sign = -1;
		str++;
	}
	while (ft_isdigit(*str))
	{
		atof.res = atof.res * 10.0 + (*str - '0');
		str++;
	}
	if (*str == '.')
	{
		str++;
		handle_loop(&atof, str);
	}
	return (atof.res * atof.sign);
}
