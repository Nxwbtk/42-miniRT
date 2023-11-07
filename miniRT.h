/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsirikam <bsirikam@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 01:21:35 by bsirikam          #+#    #+#             */
/*   Updated: 2023/11/08 00:32:30 by bsirikam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include <unistd.h>
# include <stdio.h>
# include "./libft/libft.h"

typedef struct s_rgb
{
	float	r;
	float	g;
	float	b;
}				t_rgb;

typedef struct s_cord
{
	double	x;
	double	y;
	double	z;
}				t_cord;

typedef struct s_ambient
{
	double	ratio;
	t_rgb	*rgb;
}				t_ambient;

typedef struct s_camera
{
	t_cord	*cord;
	float	normal[3];
	float	fov;
}				t_camera;

typedef struct s_light
{
	t_cord	*cord;
	float	ratio;
	t_rgb	*rgb;
}				t_light;

typedef struct s_sphere
{
	t_cord	*cord;
	double	diameter;
	t_rgb	*rgb;
}				t_sphere;

typedef struct s_plane
{
	t_cord	*cord;
	float	normal[3];
	t_rgb	*rgb;
}				t_plane;

typedef struct s_cylinder
{
	t_cord	*cord;
	float	normal[3];
	double	diameter;
	double	height;
	t_rgb	*rgb;
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
char	**ft_split_space(char *line);
void	init_ambient(char **line);
void	init_camera(char **line);

#endif