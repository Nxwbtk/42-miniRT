/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksaelim <ksaelim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 01:21:10 by bsirikam          #+#    #+#             */
/*   Updated: 2023/10/24 11:58:24 by ksaelim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	create_img(t_param *data)
{
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, 1600, 900, "RT ja!");
	data->img.img = mlx_new_image(data->mlx, 1600, 900);
	data->img.addr = mlx_get_data_addr(data->img.img, &data->img.bpp, \
	&data->img.line, &data->img.endian);
}

int	main(void)
{
    t_param par;

    par.width = 400;
    par.aspect_ratio = 16 / 9;
    par.height = par.width / par.aspect_ratio;
    if (par.height < 1)
        par.height = 1;
    
    create_img(&par);
    return 0;
}