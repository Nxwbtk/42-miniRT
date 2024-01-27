/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsirikam <bsirikam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 01:21:35 by bsirikam          #+#    #+#             */
/*   Updated: 2023/12/02 22:56:39 by bsirikam         ###   ########.fr       */
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
# define MIN 0.001

# define PI 3.141592653589793

typedef struct s_abc
{
	float	a;
	float	b;
	float	c;
}				t_abc;

// main
int		parsing(int ac, char **av, t_scene *scene);
t_scene	init_struct(void);
void	init_viewport(t_viewport *viewport, t_camera camera);
void	create_img(t_param *param);
int		render_scene(t_param *param);
int		close_win(t_param *param);
int		key_hook(int keycode, t_param *param);
float	ft_pow(float num);

#endif