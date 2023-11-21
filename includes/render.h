/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buntakansirikamonthip <buntakansirikamonth +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 11:24:47 by ksaelim           #+#    #+#             */
/*   Updated: 2023/11/21 03:09:28 by buntakansirikamo ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_H
# define RENDER_H

# include "parsing.h"

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

// pixel
t_pixel new_pixel(int x, int y, int color);
void put_pixel_to_image(t_img *img, t_pixel pixel);

// render
int render_scene(t_param *param);

#endif