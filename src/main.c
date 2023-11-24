/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksaelim <ksaelim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 01:21:10 by bsirikam          #+#    #+#             */
/*   Updated: 2023/11/24 15:15:37 by ksaelim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	main(int ac, char **av)
{
	t_param	param;

	param.scene = init_struct();
	if (parsing(ac, av, &param.scene))
		return (1);
	(void)ac;
	(void)av;
	init_viewport(&param.viewport, param.scene.camera);
	create_img(&param);
	render_scene(&param);
	// mlx_loop_hook(param.mlx, &render_scene, &param);
	mlx_hook(param.win, 2, 1L << 0, key_hook, &param);
	mlx_hook(param.win, 17, 0, close_win, &param);
	mlx_loop(param.mlx);
	return (0);
}
