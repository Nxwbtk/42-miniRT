/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsirikam <bsirikam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 11:24:47 by ksaelim           #+#    #+#             */
/*   Updated: 2023/11/24 18:24:36 by bsirikam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_H
# define RENDER_H

# include "parsing.h"
# include <stdbool.h>

// typedef struct s_param
// {
// 	void		*mlx;
// 	void		*win;
// 	t_img		img;
// 	int		width;
// 	int		height;
// 	double	aspect_ratio;
// }				t_param;

typedef struct s_axis
{
	t_cor x;
	t_cor y;
	t_cor z;
} t_axis;

typedef struct s_viewport
{
	t_cor	origin;
	t_cor	pixel_delta_x;
	t_cor	pixel_delta_y;
	t_cor	pixel_upper_left;
	t_axis	axis;
	float	width;
	float	height;
}				t_viewport;

typedef struct s_img
{
	void		*img;
	void		*addr;
	int			bpp;
	int			line_len;
	int			endian;
}				t_img;

typedef struct s_param
{
	t_scene		scene;
	t_img		img;
	void		*mlx;
	void		*win;
	t_obj		*obj;
	t_viewport	viewport;
	int			mode;
	// t_select	*select;
}				t_param;

typedef struct s_hitpoint
{
	t_cor	origin;
	t_cor	obj_origin;
	t_cor	dir;
	t_rgb	clr;
}	t_hitpoint;

typedef struct s_pixel
{
	int	x;
	int	y;
	int	color;
}				t_pixel;

typedef struct s_ray
{
	t_cor oringin;
	t_cor dir;
	t_cor point;
	t_rgb clr;
	float t;
} t_ray;


// ray
t_ray new_ray(t_cor oringin, t_cor dir);
t_cor ray_point(t_ray ray);

//object
bool	hit_object(t_ray *ray, t_obj *obj, t_hitpoint *hitPoint);
bool	isHitSphere(t_ray *ray, t_sp **sphere);
bool	isHitPlane(t_ray *ray, t_plane *plane);
void	hitPointSphere(t_ray *ray, t_sp *sphere, t_hitpoint *hitPoint);
void	hitPointPlane(t_ray *ray, t_plane *plane, t_hitpoint *hitPoint);

#endif