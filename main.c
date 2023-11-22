/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buntakansirikamonthip <buntakansirikamonth +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 19:03:43 by buntakansirikamo  #+#    #+#             */
/*   Updated: 2023/11/21 02:59:05 by buntakansirikamo ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parsing.h"

int	main(int ac, char **av)
{
	t_scene	*scene;

	scene = init_struct();
	// scene = (t_scene *)malloc(sizeof(t_scene));
	// scene->obj = NULL;
	if (!scene)
	{
		printf("Error\n");
		exit(1);
	}
	if (parsing(ac, av, scene))
		return (1);
	return (0);
}
