/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_sphere1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsirikam <bsirikam@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 01:30:59 by bsirikam          #+#    #+#             */
/*   Updated: 2023/11/16 02:53:03 by bsirikam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_obj	*new_obj_sp(t_sphere *sphere)
{
	t_obj	*new_obj;

	new_obj = (t_obj *)malloc(sizeof(t_obj));
	if (!new_obj)
		return (NULL);
	new_obj->type = 2;
	new_obj->obj = (void *)sphere;
	new_obj->next = NULL;
	return (new_obj);
}

int	check_arg_sphere(char **split)
{
	char	**check_split;

	if (!split[1] || !split[2] || !split[3])
		return (0);
	check_split = ft_split(split[1], ',');
	if (!check_split[0] || !check_split[1] || !check_split[2])
	{
		free_split(check_split);
		return (0);
	}
	free_split(check_split);
	check_split = ft_split(split[3], ',');
	if (!check_split[0] || !check_split[1] || !check_split[2] \
	|| (atof(check_split[0]) < 0 || atof(check_split[0]) > 255 \
	|| atof(check_split[1]) < 0 || atof(check_split[1]) > 255 \
	|| atof(check_split[2]) < 0 || atof(check_split[2]) > 255))
	{
		free_split(check_split);
		return (0);
	}
	free_split(check_split);
	return (1);
}

t_sphere	*new_sphere(char **split)
{
	t_sphere	*sphere;

	if (!check_arg_sphere(split))
		return (NULL);
	sphere = (t_sphere *)malloc(sizeof(t_sphere));
	if (!sphere)
		return (NULL);
	sphere->cord = put_cord(split[1]);
	sphere->rgb = put_rgb(split[3]);
	sphere->diameter = ft_atof(split[2]);
	if (!sphere->cord || !sphere->rgb)
	{
		if (sphere->cord)
			free(sphere->cord);
		if (sphere->rgb)
			free(sphere->rgb);
		free(sphere);
		return (NULL);
	}
	return (sphere);
}