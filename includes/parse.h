/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksaelim <ksaelim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 15:26:50 by ksaelim           #+#    #+#             */
/*   Updated: 2023/10/24 11:53:07 by ksaelim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

# define FRACTIONAL_BIT 16

# include "libft.h"
# include "maths.h"


typedef struct s_cam
{
	t_vec	orig;
	t_vec	dir;
	double	fov;
}	t_cam;


// typedef struct s_sc

#endif