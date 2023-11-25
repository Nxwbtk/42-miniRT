/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsirikam <bsirikam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 23:46:32 by bsirikam          #+#    #+#             */
/*   Updated: 2023/11/25 21:16:20 by bsirikam         ###   ########.fr       */
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

t_rgb	shade_clr(t_rgb clr, t_rgb shade)
{
	clr.r = (clr.r * shade.r) >> 8;
	clr.g = (clr.g * shade.g) >> 8;
	clr.b = (clr.b * shade.b) >> 8;
	return (clr);
}
