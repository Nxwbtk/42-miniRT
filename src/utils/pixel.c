/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksaelim <ksaelim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 22:24:30 by ksaelim           #+#    #+#             */
/*   Updated: 2023/11/21 15:33:51 by ksaelim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	// printf("(%d, %d)\n", pixel.x, pixel.y);
	if (pixel.x >= 0 && pixel.x < WD_WIDTH && pixel.y >= 0 && pixel.y < WD_HEIGHT)
	{
		dst = img->addr + ((int)pixel.y * img->line_len + (int)pixel.x * img->bpp);
		// printf("pixel.color: %d\n", pixel.color);
		*dst = (unsigned int)pixel.color;
	// printf("world\n");
	// exit(0);
	}
}