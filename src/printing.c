/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cphillip <cphillip@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 20:36:59 by cphillip          #+#    #+#             */
/*   Updated: 2020/02/10 12:15:56 by cphillip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

t_struct	*print_s_la_p(t_struct *csp, char *tmp, int s_len)
{
	if (csp->precision < s_len && csp->specifier == 's')
		while (csp->precision--)
			ft_putchar(*(tmp++));
	else
		while (s_len--)
			ft_putchar(*(tmp++));
	if (csp->conv_flags[4] == '0')
		print_alt(csp, csp->width - s_len, '0');
	else
		print_alt(csp, csp->width - s_len, ' ');
	return (csp);
}

t_struct	*print_s_ra_p(t_struct *csp, char *tmp, int s_len)
{
	if (csp->conv_flags[4] == '0')
		print_alt(csp, csp->width - s_len, '0');
	else
		print_alt(csp, csp->width - s_len, ' ');
	if (csp->precision < s_len && csp->specifier == 's')
		while (csp->precision--)
			ft_putchar(*(tmp++));
	else
		while (s_len--)
			ft_putchar(*(tmp++));
	return (csp);
}

t_struct	*print_s_la_no_p(t_struct *csp, char *tmp, int s_len)
{
	ft_putstr(tmp);
	if (csp->conv_flags[4] == '0')
		print_alt(csp, csp->width - s_len, '0');
	else
		print_alt(csp, csp->width - s_len, ' ');
	return (csp);
}

t_struct	*print_s_ra_no_p(t_struct *csp, char *tmp, int s_len)
{
	if (csp->conv_flags[4] == '0')
		print_alt(csp, csp->width - s_len, '0');
	else
		print_alt(csp, csp->width - s_len, ' ');
	ft_putstr(tmp);
	return (csp);
}
