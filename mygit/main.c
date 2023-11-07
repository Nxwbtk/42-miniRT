/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksaelim <ksaelim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 01:21:10 by bsirikam          #+#    #+#             */
/*   Updated: 2023/11/07 11:50:18 by ksaelim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/miniRT.h"

void	create_img(t_param *data)
{
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, WD_WIDTH, WD_HEIGHT, "RT ja!");
	data->img.img = mlx_new_image(data->mlx, WD_WIDTH, WD_HEIGHT);
	data->img.addr = mlx_get_data_addr(data->img.img, &data->img.bpp, \
	&data->img.line, &data->img.endian);
}

int	main(void)
{
    void    *mlx;
    void *win;

    t_vec *sphere_center = new_vec(3, 2, -32);
    t_sphere    *sphere = new_sphere(sphere_center, 12/2);
    t_vec   *cam_orig = new_vec(0, 0, 0);
    t_vec   *cam_dir = new_vec(0, 0, -1);
    t_camera    *cam = new_camera(cam_orig, cam_dir, 70);
    t_scene     *scene =  new_scene(cam, sphere);
    scene->width = WD_WIDTH;
    scene->hight = WD_HEIGHT;
	win = mlx_new_window(mlx, scene->width, scene->hight, "RT ja!");
    ray_tracing(mlx, window, scene);
    mlx_loop(mlx);
    return 0;
}