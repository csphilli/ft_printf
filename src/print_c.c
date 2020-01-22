/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_c.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cphillip <cphillip@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 20:38:27 by cphillip          #+#    #+#             */
/*   Updated: 2020/01/17 20:39:01 by cphillip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

t_struct	*print_c(t_struct *csp)
{
	csp->len += csp->width;
	if (csp->conv_flags[0] == '-' && csp->width > 0 && \
		(csp->conv_flags[4] == 0 || csp->conv_flags[4] != '\0'))
	{
		ft_putchar(va_arg(csp->args, int));
		while ((csp->width--) - 1 >= 1)
			ft_putchar(' ');
	}
	else
	{
		while ((csp->width--) - 1 > 0)
			ft_putchar(' ');
		ft_putchar(va_arg(csp->args, int));
	}
	return (csp);
}
