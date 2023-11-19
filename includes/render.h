/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksaelim <ksaelim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 11:24:47 by ksaelim           #+#    #+#             */
/*   Updated: 2023/10/24 11:55:58 by ksaelim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_H
#define	RENDER_H

#include "img.h"

typedef struct s_param
{
	void		*mlx;
	void		*win;
	t_img		img;
	int		width;
	int		height;
	double	aspect_ratio;
}				t_param;

#endif