/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsirikam <bsirikam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 01:21:35 by bsirikam          #+#    #+#             */
/*   Updated: 2023/11/23 22:02:49 by bsirikam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <math.h>

# include "render.h"
# include "mlx.h"
# include "key.h"

# define FRACTIONAL_BIT 16
# define WD_WIDTH 1280
# define WD_HEIGHT 720

int		close_win(t_param *param);
int		key_hook(int keycode, t_param *param);
void	ft_init(t_param *param);
void	create_img(t_param *param);

// viewports
void	init_viewport(t_viewport *viewport, t_camera camera);
// void	create_img(t_param *param);

#endif