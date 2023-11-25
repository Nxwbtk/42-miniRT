/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsirikam <bsirikam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 01:21:35 by bsirikam          #+#    #+#             */
/*   Updated: 2023/11/26 00:41:10 by bsirikam         ###   ########.fr       */
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
#define MIN 0.0001

# define PI 3.141592653589793
// main
int		parsing(int ac, char **av, t_scene *scene);
t_scene	init_struct(void);
void	init_viewport(t_viewport *viewport, t_camera camera);
void	create_img(t_param *param);
int		render_scene(t_param *param);
int		close_win(t_param *param);
int		key_hook(int keycode, t_param *param);

// print
void	print_sphere(t_sp *sphere);
void	print_plane(t_plane *plane);
void	print_obj(t_obj *obj);
void	print_camera(t_camera *camera);
t_cor	print_cor(char *point_name, t_cor vec);
void	print_topic(char *topic);
void	print_light(t_light *light);
void print_hitPoint(t_hitpoint *hitPoint);
void print_ray(t_ray *ray);

#endif