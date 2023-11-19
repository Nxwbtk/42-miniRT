#ifndef PIXEL_H
# define PIXEL_H

#include "img.h"

typedef struct s_pixel
{
	int		x;
	int		y;
	int		color;
}	t_pixel;

t_pixel	new_pixel(int x, int y, int color);
void	put_pixel_to_image(t_img *img, t_pixel pixel);

#endif