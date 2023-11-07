/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksaelim <ksaelim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 10:18:29 by ksaelim           #+#    #+#             */
/*   Updated: 2023/11/07 11:37:33 by ksaelim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCENE_H
# define SCENE_H

typedef struct s_scene
{
	t_camera	*cam;
	t_sphere	*sphere;
	float		width;
	float		hight;
}	t_scene;

t_scene	*new_scene(t_camera *cam, t_sphere *sphere);

#endif