/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_other.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cphillip <cphillip@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 12:13:08 by cphillip          #+#    #+#             */
/*   Updated: 2020/02/10 12:32:58 by cphillip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

t_struct	*print_pcent(t_struct *csp)
{
	if (csp->conv_flags[4] == '0' && !csp->conv_flags[0] && csp->precision <= 0)
	{
		csp->precision = csp->width;
		csp->width = 0;
	}
	if (csp->conv_flags[0] != '-')
		print_alt(csp, csp->width - 1, ' ');
	if (csp->conv_flags[4] == '0')
		print_alt(csp, csp->precision - 1, '0');
	write(1, "%", 1);
	if (csp->conv_flags[0] == '-')
		print_alt(csp, csp->width - 1, ' ');
	return (csp);
}

void		print_other(t_struct *csp)
{
	if (csp->c_fmt[csp->i] == '%')
		print_pcent(csp);
	else
		print_alt(csp, csp->width - 1, ' ');
}
