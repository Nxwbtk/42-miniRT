/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksaelim <ksaelim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 23:46:32 by bsirikam          #+#    #+#             */
/*   Updated: 2023/11/26 13:38:35 by ksaelim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_rgb new_rgb(int r, int g, int b)
{	
	t_rgb rgb;

	rgb.r = r;
	rgb.g = g;
	rgb.b = b;
	return (rgb);
}
t_rgb add_clr(t_rgb a, t_rgb b)
{
	t_rgb rgb;

	rgb.r = a.r + b.r;
	rgb.g = a.g + b.g;
	rgb.b = a.b + b.b;
	return (rgb);
}
t_rgb multi_clr(t_rgb a, t_rgb b)
{
	t_rgb rgb;

	rgb.r = (a.r * b.r) / 255;
	rgb.g = (a.g * b.g) / 255;
	rgb.b = (a.b * b.b) / 255;
	return (rgb);
}

t_rgb clamp_clr(t_rgb clr)
{
	if (clr.r > 255)
		clr.r = 255;
	if (clr.g > 255)
		clr.g = 255;
	if (clr.b > 255)
		clr.b = 255;
	return (clr);
}

int rgb_to_clr(t_rgb clr)
{
	clr = clamp_clr(clr);
	return ((clr.r << 16) + (clr.g << 8) + clr.b);
}

t_rgb	ratio_clr(t_rgb light, float ratio)
{
	if (ratio < 0)
		ratio = 0;
	light.r *= ratio;
	light.g *= ratio;
	light.b *= ratio;
	return (clamp_clr(light));
}
