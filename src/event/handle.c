/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksaelim <ksaelim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 11:38:26 by ksaelim           #+#    #+#             */
/*   Updated: 2023/11/20 22:22:12 by ksaelim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

// void	free_all(t_data *data)
// {
// 	if (data)
// 	{
// 		if (data->img.img)
// 			mlx_destroy_image(data->mlx, data->img.img);
// 		if (data->win)
// 			mlx_destroy_window(data->mlx, data->win);
// 		if (data->mlx)
// 			free (data->mlx);
// 	}
// 	free(data);
// }

// int	ft_close(t_data *data, char *s)
// {
// 	// ft_putstr_fd(s, 1);
// 	(void)s;
// 	free_all(data);
// 	exit(0);
// }

// int	handle_keycode(int keycode, t_data *data)
// {
// 	if (keycode == 53)
// 		ft_close(data, "Close by ESC\n");
// 	return (0);
// }

// int	handle_cross(t_data *data)
// {
// 	ft_close(data, "Close by Cross\n");
// 	return (0);
// }
