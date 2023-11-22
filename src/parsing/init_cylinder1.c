/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_cylinder1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksaelim <ksaelim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 02:28:26 by bsirikam          #+#    #+#             */
/*   Updated: 2023/11/22 19:35:26 by ksaelim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parsing.h"

t_obj	*new_obj_cy(t_cy *cylinder)
{
	t_obj	*new_obj;

	new_obj = (t_obj *)malloc(sizeof(t_obj));
	if (!new_obj)
		return (NULL);
	new_obj->type = 3;
	new_obj->obj = (void *)cylinder;
	new_obj->next = NULL;
	return (new_obj);
}

int	check_min_max(char **check_split, int min, int max)
{
	if (!check_split[0] || !check_split[1] || !check_split[2] || \
	ft_atof(check_split[0]) < min || ft_atof(check_split[0]) > max || \
	ft_atof(check_split[1]) < min || ft_atof(check_split[1]) > max || \
	ft_atof(check_split[2]) < min || ft_atof(check_split[2]) > max)
		return (0);
	return (1);
}

int	check_arg_cylinder(char **split)
{
	char	**check_split;

	if (!split[1] || !split[2] || !split[3] || !split[4] || !split[5])
		return (0);
	check_split = ft_split(split[1], ',');
	if (!check_split[0] || !check_split[1] || !check_split[2])
	{
		free_split(check_split);
		return (0);
	}
	free_split(check_split);
	check_split = ft_split(split[2], ',');
	if (check_min_max(check_split, -1, 1) == 0)
		return (0);
	free_split(check_split);
	check_split = ft_split(split[5], ',');
	if (check_min_max(check_split, 0, 255) == 0)
		return (0);
	free_split(check_split);
	return (1);
}

t_cor	init_cor(char *cord)
{
	char	**xyz;
	t_cor	new_cord;

	xyz = ft_split(cord, ',');
	new_cord = new_vec_parsing(ft_atof(xyz[0]), ft_atof(xyz[1]), ft_atof(xyz[2]));
	free_split(xyz);
	return (new_cord);
}

t_cy	*new_cylinder(char **split)
{
	t_cy	*cylinder;

	if (!check_arg_cylinder(split))
		return (NULL);
	cylinder = (t_cy *)malloc(sizeof(t_cy));
	if (!cylinder)
		return (NULL);
	(*cylinder).origin = init_cor(split[1]);
	(*cylinder).dir = init_cor(split[2]);
	cylinder->diameter = ft_atof(split[3]);
	cylinder->radius = cylinder->diameter / 2;
	cylinder->height = ft_atof(split[4]);
	(*cylinder).clr = put_rgb(split[5]);
	return (cylinder);
}
