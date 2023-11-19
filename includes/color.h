/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksaelim <ksaelim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 11:03:26 by ksaelim           #+#    #+#             */
/*   Updated: 2023/10/20 11:04:40 by ksaelim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLOR_H
# define COLOR_H

# define RED_PIXEL 0xFF0000
# define GREEN_PIXEL 0x00FF00
# define BLUE_PIXEL 0x0000FF
# define YELLOW_PIXEL 0xFFFF00
# define ORANGE_PIXEL 0xFF8000
# define PINK_PIXEL 0xFF00FF
# define CYAN_PIXEL 0x00FFFF
# define PURPLE_PIXEL 0x7F00FF
# define KRAM_PIXEL 0x3333FF
# define WHITE_PIXEL 0xFFFFFF
# define BLACK_PIXEL 0x000000
# define TRAN_PIXEL 0xD000FF00

# include "coordinate.h"

typedef struct s_rgb
{
	int	r;
	int g;
	int b;
}	t_rgb;

t_rgb	new_rgb(int r, int g, int b);
t_rgb	vec_to_rgb(t_vec3f vec);
t_rgb	clamp_clr(t_rgb clr);
int	rgb_to_clr(t_rgb clr);
void write_color(t_vec3f pixel_color);
t_rgb	ray_color(t_ray ray);

#endif