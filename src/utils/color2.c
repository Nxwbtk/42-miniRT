/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsirikam <bsirikam@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 23:15:37 by bsirikam          #+#    #+#             */
/*   Updated: 2023/11/30 23:16:06 by bsirikam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	rgb_to_clr(t_rgb clr)
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
