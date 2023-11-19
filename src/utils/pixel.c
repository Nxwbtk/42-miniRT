
#include "pixel.h"
#include "miniRT.h"

t_pixel	new_pixel(int x, int y, int color)
{
	t_pixel	pixel;

	pixel.x = x;
	pixel.y = y;
	pixel.color = color;
	return (pixel);
}

void	put_pixel_to_image(t_img *img, t_pixel pixel)
{
	unsigned int	*dst;

	if (pixel.x >= 0 && pixel.x < WD_WIDTH && pixel.y >= 0 && pixel.y < WD_HEIGHT)
	{
		dst = img->addr + ((int)pixel.y * img->line_len + (int)pixel.x * img->bpp);
		*dst = (unsigned int)pixel.color;
	}
}