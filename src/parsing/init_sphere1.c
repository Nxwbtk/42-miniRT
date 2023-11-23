/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_sphere1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksaelim <ksaelim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 01:30:59 by bsirikam          #+#    #+#             */
/*   Updated: 2023/11/23 22:46:00 by ksaelim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parsing.h"

t_obj	*new_obj_sp(t_sp *sphere)
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

void	ft_putel_sp(char **split, t_sp *sphere)
{
	char	**xyz;

	xyz = ft_split(split[1], ',');
	(*sphere).origin = new_vec_parsing(ft_atof(xyz[0]), ft_atof(xyz[1]), \
	ft_atof(xyz[2]));
	free_split(xyz);
	(*sphere).clr = put_rgb(split[3]);
	(*sphere).diameter = ft_atof(split[2]);
	sphere->radius = sphere->diameter / 2;

}

t_sp	*new_sphere(char **split)
{
	t_sp	*sphere;

	if (!check_arg_sphere(split))
		return (NULL);
	sphere = (t_sp *)malloc(sizeof(t_sp));
	if (!sphere)
		return (NULL);
	ft_putel_sp(split, sphere);
	return (sphere);
}
