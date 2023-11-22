/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksaelim <ksaelim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 11:24:47 by ksaelim           #+#    #+#             */
/*   Updated: 2023/11/22 08:44:06 by ksaelim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_H
# define RENDER_H

#include "parsing.h"
#include <stdbool.h>

// typedef struct s_param
// {
// 	void		*mlx;
// 	void		*win;
// 	t_img		img;
// 	int		width;
// 	int		height;
// 	double	aspect_ratio;
// }				t_param;

typedef struct s_viewport
{
	t_cor origin;
	t_cor pixel_delta_x;
	t_cor pixel_delta_y;
	t_cor pixel_upper_left;
	t_axis axis;
	int width;
	int height;
} t_viewport;

typedef struct	s_img
{
	void		*img;
	void		*addr;
	int			bpp;
	int			line_len;
	int			endian;
}				t_img;

typedef struct s_param
{
	t_scene scene;
	t_img img;
	void *mlx;
	void *win;
	t_obj *obj;
	t_viewport viewport;
	// t_select	*select;
} t_param;

typedef struct s_pixel
{
	int x;
	int y;
	int color;
} t_pixel;

typedef struct s_ray
{
	t_cor oringin;
	t_cor dir;
} t_ray;

// ray
t_ray new_ray(t_cor oringin, t_cor dir);
t_cor ray_point(t_ray ray, float t);
int	ray_color(t_ray ray, t_sphere sphere, t_plane plane);
t_ray	ray_to_pixel(t_viewport *viewport, t_pixel pixel);

// pixel
t_pixel new_pixel(int x, int y, int color);
void put_pixel_to_image(t_img *img, t_pixel pixel);

// render
int render_scene(t_param *param);

//sphere
float	hit_sphere(t_cor center, float radius, t_ray r);

#endif