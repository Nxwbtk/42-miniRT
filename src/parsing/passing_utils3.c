/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   passing_utils3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsirikam <bsirikam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 22:02:31 by bsirikam          #+#    #+#             */
/*   Updated: 2023/11/11 01:08:39 by bsirikam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	free_obj(t_obj *obj)
{
	t_plane		*plane;
	t_sphere	*sphere;
	t_cylinder	*cylinder;

	if (obj && obj->type == 1)
	{
		plane = (t_plane *)obj->obj;
		if (plane->origin)
			free(plane->origin);
		if (plane->dir)
			free(plane->dir);
		if (plane->rgb)
			free(plane->rgb);
		free(plane);
	}
	if (obj && obj->type == 2)
	{
		sphere = (t_sphere *)obj->obj;
		if (sphere->origin)
			free(sphere->origin);
		if (sphere->rgb)
			free(sphere->rgb);
		free(sphere);
	}
	if (obj && obj->type == 3)
	{
		cylinder = (t_cylinder *)obj->obj;
		if (cylinder->origin)
			free(cylinder->origin);
		if (cylinder->dir)
			free(cylinder->dir);
		if (cylinder->rgb)
			free(cylinder->rgb);
		free(cylinder);
	}
}

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
