/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksaelim <ksaelim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 01:21:35 by bsirikam          #+#    #+#             */
/*   Updated: 2023/10/24 11:52:13 by ksaelim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include <unistd.h>
# include <stdio.h>
# include "parsing.h"
# include "mlx.h"
# include "render.h"
# include "maths.h"

# if defined(__linux__)
#  include "keycode_linux.h"
#  define LINUX_OS 1
# else
#  include "keycode_macos.h"
#  define LINUX_OS 0
# endif

# define FRACTIONAL_BIT 16
# define WD_WIDTH 1280
# define WD_HEIGHT 720
# define KEY_ESC 53

typedef struct s_viewport
{
	t_vec3f	origin;
	t_vec3f	pixel_delta_x;
	t_vec3f pixel_delta_y;
	t_vec3f pixel_upper_left;
	int		width;
	int		height;
}	t_viewport;

typedef struct s_param
{
	t_scene		*scene;
	t_img		img;
	void		*mlx;
	void		*win;
	t_obj		*obj;
	t_viewport	*viewport;
	t_select	*select;
}

// typedef struct s_vec280
// {
// 	int		x;
// 	int		y;
// 	int		z;
// }	t_vec3f;

// void	input_coord(t_coord *coord, float x, float y, float z) {
// 	coord->x = x;
// 	coord->y = y;
// 	coord->z = z;
// }

void	ft_init(t_param *param);
void	create_img(t_param *param);

#endif