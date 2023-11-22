/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_vector.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksaelim <ksaelim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 00:51:51 by ksaelim           #+#    #+#             */
/*   Updated: 2023/11/20 18:29:15 by ksaelim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_cor print_cor(char *point_name, t_cor vec)
{
	printf("%s (%f, %f, %f)\n", point_name, vec.x, vec.y, vec.z);
	return (vec);
}
