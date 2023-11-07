/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksaelim <ksaelim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 10:09:51 by ksaelim           #+#    #+#             */
/*   Updated: 2023/11/07 10:20:50 by ksaelim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef CAMERA_H
# define CAMERA_H

typedef struct s_camera
{
	t_vec	*orig;
	t_vec	*dir;
	float	fov;
}	t_camera;

t_camera	*new_camera(t_vec *orig, t_vec *dir, float fov);

#endif