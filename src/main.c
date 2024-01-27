/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsirikam <bsirikam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 01:21:10 by bsirikam          #+#    #+#             */
/*   Updated: 2023/12/03 00:27:47 by bsirikam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	main(int ac, char **av)
{
	t_param	param;

	if (ac != 2)
	{
		printf("Error\n");
		return (1);
	}
	param.scene = init_struct();
	if (parsing(ac, av, &param.scene))
		return (1);
	param.mode = 0;
	init_viewport(&param.viewport, param.scene.camera);
	create_img(&param);
	render_scene(&param);
	mlx_hook(param.win, 2, 1L << 0, key_hook, &param);
	mlx_hook(param.win, 17, 0, close_win, &param);
	mlx_loop(param.mlx);
	return (0);
}
