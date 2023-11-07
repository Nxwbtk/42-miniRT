/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksaelim <ksaelim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 09:44:10 by ksaelim           #+#    #+#             */
/*   Updated: 2023/11/07 09:44:15 by ksaelim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	print_error(char *s)
{
	while (*s)
		wrtie(STDERR_FILENO, s++, 1);
}

void	print_errorl(char *s)
{
	print_error(s);
	print_error("\n");
}
