/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksaelim <ksaelim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 11:24:47 by ksaelim           #+#    #+#             */
/*   Updated: 2023/10/26 09:40:17 by ksaelim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_H
#define	RENDER_H

#include "parse.h"

typedef struct	s_img
{
	void		*img;
	char		*addr;
	int			bpp;
	int			line;
	int			endian;
}				t_img;

typedef struct s_param
{
	void		*mlx;
	void		*win;
	t_img		img;
	t_cam		cam;
	int		width;
	int		height;
	int		focal_len;
	int		viewplane_width;
	int		viewplane_height;
	double	aspect_ratio;
}				t_param;


#endif