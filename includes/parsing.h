/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksaelim <ksaelim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 15:26:50 by ksaelim           #+#    #+#             */
/*   Updated: 2023/10/24 11:53:07 by ksaelim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

# define FRACTIONAL_BIT 16

# include "libft.h"
# include <maths.h>
# include <stdio.h>
# include <unistd.h>
# include "vector.h"
# include "ray.h"
# include "pixel.h"
# include "color.h"


// typedef struct s_rgb
// {
// 	float	r;
// 	float	g;
// 	float	b;
// }				t_rgb;

typedef t_vec3f	t_cord3f;

// typedef struct s_vec3f
// {
// 	float	x;
// 	float	y;
// 	float	z;
// }				t_vec3f;

typedef struct s_ambient
{
	double	ratio;
	t_rgb	*rgb;
}				t_ambient;

typedef struct s_camera
{
	t_cord3f		*origin;
	t_vec3f	*dir;
	float		fov;
}				t_camera;

typedef struct s_light
{
	t_cord3f	*origin;
	float	ratio;
	t_rgb	*rgb;
}				t_light;

typedef struct s_sphere
{
	t_cord3f	*origin;
	double	diameter;
	t_rgb	*rgb;
}				t_sphere;

typedef struct s_plane
{
	t_cord3f		*origin;
	t_vec3f	*dir;
	t_rgb		*rgb;
}				t_plane;

typedef struct s_cylinder
{
	t_cord3f		*origin;
	t_vec3f	*dir;
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

int			parsing(int ac, char **av, t_scene *scene);
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
t_cord3f		*put_cord3f(char *cord);
t_rgb		*put_rgb(char *cord);
t_scene		*init_struct(void);
t_vec3f	*put_vec3f(char *cord);
t_plane		*new_plane(char **split);
t_sphere	*new_sphere(char **split);
t_cylinder	*new_cylinder(char **split);

// typedef struct s_vec
// {
// 	float	x;
// 	float	y;
// 	float	z;
// }	t_vec3f;

// typedef	struct s_rgb
// {
// 	int	r;
// 	int g;
// 	int b;
// }	t_rgb;

// typedef struct s_ray
// {
// 	t_vec3f	orig;
// 	t_vec3f	dir;
// }	t_ray;

// typedef struct s_cam
// {
// 	t_vec3f	orig;
// 	t_vec3f	dir;
// 	double	fov;
// }	t_cam;


// typedef struct s_sc

#endif