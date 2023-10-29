/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsirikam <bsirikam@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 01:21:35 by bsirikam          #+#    #+#             */
/*   Updated: 2023/10/29 23:10:01 by bsirikam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include <unistd.h>
# include <stdio.h>
# include "./libft/libft.h"

typedef struct s_ambient
{
	double	ratio;
	float	rgb[3];
}				t_ambient;

typedef struct s_camera
{
	double	cord[3];
	float	normal[3];
	float	fov;
}				t_camera;

typedef struct s_light
{
	double	cord[3];
	float	ratio;
	float	rgb[3];
}				t_light;

typedef struct s_sphere
{
	double	cord[3];
	double	diameter;
	float	rgb[3];
}				t_sphere;

typedef struct s_plane
{
	double	cord[3];
	float	normal[3];
	float	rgb[3];
}				t_plane;

typedef struct s_cylinder
{
	double	cord[3];
	float	normal[3];
	double	diameter;
	double	height;
	float	rgb[3];
}				t_cylinder;

typedef struct s_obj
{
	void	*obj;
	int		type;
	void	*next;
}				t_obj;

typedef struct s_scene
{
	t_ambient	*ambient;
	t_camera	*camera;
	t_light		*light;
	t_obj		*obj;
}				t_scene;

int		ft_check(char *str);
int		ft_isopenable(char *str);
int		ft_isfile(char *str);
void	free_split(char **split);

#endif