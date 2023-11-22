/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksaelim <ksaelim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 01:21:35 by bsirikam          #+#    #+#             */
/*   Updated: 2023/11/22 08:38:50 by ksaelim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
#define MINIRT_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <math.h>


# include "render.h"
# include "parsing.h"

#if defined(__linux__)
#include "keycode_linux.h"
#define LINUX_OS 1
#else
#include "keycode_macos.h"
#define LINUX_OS 0
#endif

#define FRACTIONAL_BIT 16
#define WD_WIDTH 1280
#define WD_HEIGHT 720
#define KEY_ESC 53

void ft_init(t_param *param);
void create_img(t_param *param);
int close_win(t_param *param);
int key_hook(int keycode, t_param *param);

// viewports
void init_viewport(t_viewport *viewport, t_camera camera);
// void	create_img(t_param *param);

#endif