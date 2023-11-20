/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buntakansirikamonthip <buntakansirikamonth +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 15:04:24 by ksaelim           #+#    #+#             */
/*   Updated: 2023/11/20 19:31:15 by buntakansirikamo ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parsing.h"
// #include <stdio.h>
// #include <math.h>

// int		ft_strlen_mode(char *str, char c)
// {
// 	int	i;

// 	i = 0;
// 	while (str[i] && str[i] != c)
// 		i++;
// 	return (i);
// }

// float	ft_pow(float base, int expo)
// {
// 	float	result;

// 	result = 1;
// 	while (expo > 0)
// 	{
// 		result *= base;
// 		expo--;
// 	}
// 	return (result);
// }

double	ft_atof(char *str)
{
	double	integer;
	double	decimal;

	integer = (double)ft_atoi(str);
	str += ft_strlen_mode(str, '.') + 1;
	decimal = (double)ft_atoi(str);
	return (integer + (decimal / pow((double)10, (double)ft_strlen(str))));
}

// int	main(int ac, char **av) {
// 	if (ac == 2) {
// 		printf("%f\n", ft_atof(av[1]));
// 	}
// 	return (0);
// }