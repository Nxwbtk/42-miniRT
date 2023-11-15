/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsirikam <bsirikam@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 01:21:35 by bsirikam          #+#    #+#             */
/*   Updated: 2023/11/16 03:29:14 by bsirikam         ###   ########.fr       */
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

typedef struct s_normal
{
	float	x;
	float	y;
	float	z;
}				t_normal;

typedef struct s_ambient
{
	double	ratio;
	t_rgb	*rgb;
}				t_ambient;

typedef struct s_camera
{
	t_cord		*cord;
	t_normal	*normal;
	float		fov;
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
	t_cord		*cord;
	t_normal	*normal;
	t_rgb		*rgb;
}				t_plane;

typedef struct s_cylinder
{
	t_cord		*cord;
	t_normal	*normal;
	double		diameter;
	double		height;
	t_rgb		*rgb;
}				t_cylinder;

typedef struct s_obj
{
	void			*obj;
	int				type;
	struct s_obj	*next;
}				t_obj;

typedef struct s_scene
{
	t_ambient	*ambient;
	t_camera	*camera;
	t_light		*light;
	t_obj		*obj;
}				t_scene;

int			ft_check(char *str);
int			ft_isopenable(char *str);
int			ft_isfile(char *str);
int			ft_isspace(char c);
int			isel_valid(t_plane *plane);
char		**ft_split_space(char *line);
void		free_split(char **split);
void		init_ambient(char **split, t_scene *scene, char *line);
void		init_camera(char **split, t_scene *scene, char *line);
void		init_obj(char **split, t_scene *scene, char *line);
void		free_scene(t_scene *scene);
void		free_double_config(char **split, t_scene *scene, char *line);
void		error_input(char *line, char **split_line, t_scene *scene);
void		init_light(char **split, t_scene *scene, char *line);
void		free_obj(t_obj *obj);
void		obj_addback(t_scene *scene, t_obj *new_obj);
double		ft_atof(char *str);
t_obj		*new_obj_pl(t_plane *plane);
t_obj		*new_obj_sp(t_sphere *sphere);
t_obj		*new_obj_cy(t_cylinder *cylinder);
t_cord		*put_cord(char *cord);
t_rgb		*put_rgb(char *cord);
t_scene		*init_struct(void);
t_normal	*put_normal(char *cord);
t_plane		*new_plane(char **split);
t_sphere	*new_sphere(char **split);
t_cylinder	*new_cylinder(char **split);

#endif