/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_movement.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsirikam <bsirikam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 23:24:25 by bsirikam          #+#    #+#             */
/*   Updated: 2023/12/01 20:59:22 by bsirikam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	handlerotate(char *print, t_param *param)
{
	if (print)
		printf("%s\n", print);
	init_viewport(&param->viewport, param->scene.camera);
	render_scene(param);
}

void	ft_mov(int keycode, t_param *param)
{
	if (keycode == KEY_W)
	{
		param->scene.camera.origin.z -= 0.1;
		handlerotate("W", param);
	}
	else if (keycode == KEY_S)
	{
		param->scene.camera.origin.z += 0.1;
		handlerotate("S", param);
	}
	else if (keycode == KEY_A)
	{
		param->scene.camera.origin.x -= 0.1;
		handlerotate("A", param);
	}
	else if (keycode == KEY_D)
	{
		param->scene.camera.origin.x += 0.1;
		handlerotate("D", param);
	}
}

void	rotate_camera(int keycode, t_param *param)
{
	if (keycode == KEY_W || keycode == KEY_S || keycode == KEY_A || \
	keycode == KEY_D)
		ft_mov(keycode, param);
	else if (keycode == KEY_SPACE)
	{
		param->scene.camera.origin.y += 0.01;
		handlerotate(NULL, param);
	}
	else if (keycode == KEY_R)
	{
		param->scene.camera.origin.y -= 0.01;
		handlerotate(NULL, param);
	}
}

int	key_hook(int keycode, t_param *param)
{
	if (keycode == KEY_ESC)
		close_win(param);
	return (0);
}
