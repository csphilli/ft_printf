/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_c.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cphillip <cphillip@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 20:38:27 by cphillip          #+#    #+#             */
/*   Updated: 2020/12/16 13:54:43 by cphillip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
**	Handles the printing of char values
*/

t_struct	*print_c(t_struct *csp)
{
	if (csp->c_flags[0] == '-' && csp->width > 0 && \
		(csp->c_flags[4] == 0 || csp->c_flags[4] != '\0'))
	{
		ft_putchar(va_arg(csp->args, int));
		csp->len += 1;
		while (csp->width - 1 >= 1)
		{
			print_alt(csp, 1, 32);
			csp->width--;
		}
	}
	else
	{
		while ((csp->width - 1) > 0)
		{
			print_alt(csp, 1, 32);
			csp->width--;
		}
		ft_putchar(va_arg(csp->args, int));
		csp->len += 1;
	}
	return (csp);
}
