/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_other.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cphillip <cphillip@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 12:13:08 by cphillip          #+#    #+#             */
/*   Updated: 2020/02/11 10:56:12 by cphillip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

t_struct	*print_pcent(t_struct *csp)
{
	if (csp->c_flags[4] == '0' && !csp->c_flags[0] && csp->prec <= 0)
	{
		csp->prec = csp->width;
		csp->width = 0;
	}
	if (csp->c_flags[0] != '-')
		print_alt(csp, csp->width - 1, ' ');
	if (csp->c_flags[4] == '0')
		print_alt(csp, csp->prec - 1, '0');
	write(1, "%", 1);
	if (csp->c_flags[0] == '-')
		print_alt(csp, csp->width - 1, ' ');
	csp->len += 1;
	return (csp);
}

void		print_other(t_struct *csp)
{
	if (csp->c_fmt[csp->i] == '%')
		print_pcent(csp);
	else
		print_alt(csp, csp->width - 1, ' ');
}
