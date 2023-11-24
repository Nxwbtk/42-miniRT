/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsirikam <bsirikam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 00:31:27 by ksaelim           #+#    #+#             */
/*   Updated: 2023/11/24 23:46:58 by bsirikam         ###   ########.fr       */
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
		// if (LINUX_OS)
		// 	mlx_destroy_display(param->mlx);
		if (param->mlx)
			free(param->mlx);
	}
	exit (0);
	return (0);
}

void	rotate_camera(int keycode, t_param *param)
{
	if (keycode == KEY_W)
	{
		printf("W\n");
		param->scene.camera.origin.z -= 0.1;
		init_viewport(&param->viewport, param->scene.camera);
		render_scene(param);
	}
	else if (keycode == KEY_S)
	{
		printf("S\n");
		param->scene.camera.origin.z += 0.1;
		init_viewport(&param->viewport, param->scene.camera);
		render_scene(param);
	}
	else if (keycode == KEY_A)
	{
		printf("A\n");
		param->scene.camera.origin.x -= 0.1;
		init_viewport(&param->viewport, param->scene.camera);
		render_scene(param);
	}
	else if (keycode == KEY_D)
	{
		printf("D\n");
		param->scene.camera.origin.x += 0.1;
		init_viewport(&param->viewport, param->scene.camera);
		render_scene(param);
	}
	else if (keycode == KEY_SPACE)
	{
		param->scene.camera.origin.y += 0.01;
		init_viewport(&param->viewport, param->scene.camera);
		render_scene(param);
	}
	else if (keycode == KEY_R)
	{
		param->scene.camera.origin.y -= 0.01;
		init_viewport(&param->viewport, param->scene.camera);
		render_scene(param);
	}
}

int	key_hook(int keycode, t_param *param)
{
	if (keycode == KEY_ESC)
		close_win(param);
	if (param->mode == 0)
		rotate_camera(keycode, param);
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
