/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsirikam <bsirikam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 00:31:27 by ksaelim           #+#    #+#             */
/*   Updated: 2023/12/02 23:08:36 by bsirikam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	close_win(t_param *param)
{
	if (param)
	{
		if (param->img.img)
			mlx_destroy_image(param->mlx, param->img.img);
		if (param->win)
			mlx_destroy_window(param->mlx, param->win);
		if (param->mlx)
			free(param->mlx);
	}
	free_scene(&param->scene);
	exit (0);
	return (0);
}

void	create_img(t_param *param)
{
	param->mlx = mlx_init();
	param->win = mlx_new_window(param->mlx, WD_WIDTH, WD_HEIGHT, "miniRT ja!");
	param->img.img = mlx_new_image(param->mlx, WD_WIDTH, WD_HEIGHT);
	param->img.addr = mlx_get_data_addr(param->img.img, &param->img.bpp, \
	&param->img.line_len, &param->img.endian);
	param->img.bpp /= 8;
}
