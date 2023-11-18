/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_plane1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsirikam <bsirikam@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 22:20:18 by bsirikam          #+#    #+#             */
/*   Updated: 2023/11/16 03:17:41 by bsirikam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	check_arg_plane(char **split)
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
	check_split = ft_split(split[2], ',');
	if (!check_split[0] || !check_split[1] || !check_split[2] || \
	(atof(check_split[0]) < -1 || atof(check_split[0]) > 1 || \
	atof(check_split[1]) < -1 || atof(check_split[1]) > 1 || \
	atof(check_split[2]) < -1 || atof(check_split[2]) > 1))
	{
		free_split(check_split);
		return (0);
	}
	free_split(check_split);
	check_split = ft_split(split[3], ',');
	if (!check_split[0] || !check_split[1] || !check_split[2])
	{
		free_split(check_split);
		return (0);
	}
	free_split(check_split);
	return (1);
}

t_cord	*put_cord(char *cord)
{
	char	**xyz;
	t_cord	*new_cord;

	xyz = ft_split(cord, ',');
	new_cord = (t_cord *)malloc(sizeof(t_cord));
	if (!new_cord)
		return (NULL);
	new_cord->x = ft_atof(xyz[0]);
	new_cord->y = ft_atof(xyz[1]);
	new_cord->z = ft_atof(xyz[2]);
	free_split(xyz);
	return (new_cord);
}

t_normal	*put_normal(char *cord)
{
	t_normal	*new_normal;
	char		**xyz;

	new_normal = (t_normal *)malloc(sizeof(t_normal));
	if (!new_normal)
		return (NULL);
	xyz = ft_split(cord, ',');
	new_normal->x = ft_atof(xyz[0]);
	new_normal->y = ft_atof(xyz[1]);
	new_normal->z = ft_atof(xyz[2]);
	free_split(xyz);
	return (new_normal);
}

t_rgb	*put_rgb(char *cord)
{
	t_rgb	*new_rgb;
	char	**rgb;

	new_rgb = (t_rgb *)malloc(sizeof(t_rgb));
	if (!new_rgb)
		return (NULL);
	rgb = ft_split(cord, ',');
	new_rgb->r = ft_atof(rgb[0]);
	new_rgb->g = ft_atof(rgb[1]);
	new_rgb->b = ft_atof(rgb[2]);
	free_split(rgb);
	return (new_rgb);
}

t_plane	*new_plane(char **split)
{
	t_plane	*plane;

	if (check_arg_plane(split) == 0)
		return (NULL);
	plane = (t_plane *)malloc(sizeof(t_plane));
	if (!plane)
		return (NULL);
	plane->cord = put_cord(split[1]);
	plane->normal = put_normal(split[2]);
	plane->rgb = put_rgb(split[3]);
	if (isel_valid(plane) == 0)
		return (NULL);
	return (plane);
}
