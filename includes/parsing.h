/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buntakansirikamonthip <buntakansirikamonth +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 15:26:50 by ksaelim           #+#    #+#             */
/*   Updated: 2023/11/21 17:49:11 by buntakansirikamo ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# define FRACTIONAL_BIT 16

# include "../lib/libft/libft.h"
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>

typedef struct s_cor
{
	float	x;
	float	y;
	float	z;
	float	len;
}				t_cor;

typedef struct s_rgb
{
	int	r;
	int	g;
	int	b;
}				t_rgb;

typedef struct s_ambient
{
	t_rgb	clr;
	float	ratio;
	int		is_init;
}				t_ambient;

typedef struct s_camera
{
	t_cor	origin;
	t_cor	dir;
	float	fov;
	int		is_init;
}				t_camera;

typedef struct s_light
{
	t_cor	origin;
	float	ratio;
	t_rgb	clr;
	int		is_init;
}				t_light;

typedef struct s_plane
{
	// t_axis	axis;
	t_cor	origin;
	t_cor	dir;
	t_rgb	clr;
}				t_plane;

typedef struct s_sphere
{
	t_cor	origin;
	t_rgb	clr;
	float	diameter;
	float	radius;
}				t_sp;

// radius = diameter / 2

typedef struct s_cy
{
	t_cor	origin;
	t_cor	dir;
	t_rgb	clr;
	float	height;
	float	diameter;
	float	radius;
}				t_cy;

typedef struct s_obj
{
	void			*obj;
	int				type;
	struct s_obj	*next;
}				t_obj;

typedef struct s_scene
{
	t_ambient	ambient;
	t_camera	camera;
	t_light		light;
	t_obj		*obj; // t_obj is
}				t_scene;



int		parsing(int ac, char **av, t_scene *scene);
int		ft_check(char *str);
int		ft_isopenable(char *str);
int		ft_isfile(char *str);
int		ft_isspace(char c);
char	**ft_split_space(char *line);
void	free_split(char **split);
void	init_ambient(char **split, t_scene *scene, char *line);
void	init_camera(char **split, t_scene *scene, char *line);
void	init_obj(char **split, t_scene *scene, char *line);
void	free_scene(t_scene *scene);
void	free_double_config(char **split, t_scene *scene, char *line);
void	error_input(char *line, char **split_line, t_scene *scene);
void	init_light(char **split, t_scene *scene, char *line);
void	free_obj(t_obj *obj);
void	obj_addback(t_scene *scene, t_obj *new_obj);
float	ft_atof(char *str);
t_obj	*new_obj_pl(t_plane *plane);
t_obj	*new_obj_sp(t_sp *sphere);
t_obj	*new_obj_cy(t_cy *cylinder);
t_cor	*put_cor(char *cord);
t_rgb	put_rgb(char *cord);
t_scene	*init_struct(void);
t_cor	*put_cor(char *cord);
t_plane	*new_plane(char **split);
t_sp	*new_sphere(char **split);
t_cy	*new_cylinder(char **split);

// typedef struct s_vec
// {
// 	float	x;
// 	float	y;
// 	float	z;
// }	t_cor;

// typedef	struct s_rgb
// {
// 	int	r;
// 	int g;
// 	int b;
// }	t_rgb;

// typedef struct s_ray
// {
// 	t_cor	oringin;
// 	t_cor	dir;
// }	t_ray;

// typedef struct s_cam
// {
// 	t_cor	oringin;
// 	t_cor	dir;
// 	double	fov;
// }	t_cam;

// typedef struct s_sc

// vector

t_cor	new_vec(float x, float y, float z);
t_cor	new_vec1(float x, float y, float z);
t_cor	new_vec_parsing(float x, float y, float z);
t_cor	vec_norm(t_cor vec);
t_cor	vec_add(t_cor vec1, t_cor vec2);
t_cor	vec_sub(t_cor vec1, t_cor vec2);
t_cor	vec_multi_scalar(t_cor vec, float t);
t_cor	vec_div(t_cor vec, float t);
float	vec_dot_product(t_cor vec1, t_cor vec2);
t_cor	vec_cross(t_cor vec1, t_cor vec2);
t_cor	print_cor(char *point_name, t_cor vec);

// color
t_rgb	new_rgb(int r, int g, int b);
t_rgb	vec_to_rgb(t_cor vec);
t_rgb	clamp_clr(t_rgb clr);
int		rgb_to_clr(t_rgb clr);
void	write_color(t_cor pixel_color);
// t_rgb ray_color(t_ray ray);

#endif