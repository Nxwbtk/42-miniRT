/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   passing_utils3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsirikam <bsirikam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 22:02:31 by bsirikam          #+#    #+#             */
/*   Updated: 2023/11/11 00:54:44 by bsirikam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	free_obj(t_obj *obj)
{
	t_plane		*plane;
	t_sphere	*sphere;
	t_cylinder	*cylinder;

	if (obj->type == 1)
	{
		plane = (t_plane *)obj->obj;
		if (plane->cord)
			free(plane->cord);
		if (plane->normal)
			free(plane->normal);
		if (plane->rgb)
			free(plane->rgb);
		free(plane);
	}
	if (obj->type == 2)
	{
		sphere = (t_sphere *)obj->obj;
		if (sphere->cord)
			free(sphere->cord);
		if (sphere->rgb)
			free(sphere->rgb);
		free(sphere);
	}
	if (obj->type == 3)
	{
		cylinder = (t_cylinder *)obj->obj;
		if (cylinder->cord)
			free(cylinder->cord);
		if (cylinder->normal)
			free(cylinder->normal);
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
