/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cphillip <cphillip@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 20:55:36 by cphillip          #+#    #+#             */
/*   Updated: 2020/02/10 12:41:56 by cphillip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

t_struct	*get_padding(t_struct *csp, long int s_len)
{
	if (csp->precision > -1 && csp->precision < s_len)
		csp->padding = csp->width - csp->precision;
	else if (csp->precision > -1 && csp->precision > s_len)
		csp->padding = csp->width - s_len;
	else if (csp->precision == -1 && csp->width > s_len)
		csp->padding = csp->width - s_len;
	else
		csp->padding = 0;
	csp->len += csp->padding;
	return (csp);
}

int			update_len(t_struct *csp, int s_len)
{
	long int	prec;
	int			j;

	j = 0;
	prec = csp->precision;
	if (csp->conv_flags[3] == '#')
		j = 2;
	if ((prec > -1 || prec == -1) && (prec > s_len || s_len != 0))
		s_len = s_len + j;
	else if (prec > -1 && prec < s_len)
		s_len = prec + j;
	csp->len += s_len;
	return (s_len);
}

t_struct	*align_print(t_struct *csp, char *str, int s_len)
{
	if (csp->conv_flags[0] == '-' && csp->precision != -1 && str)
		print_s_la_p(csp, str, s_len);
	else if (csp->conv_flags[0] == '-' && csp->precision == -1 && str)
		print_s_la_no_p(csp, str, s_len);
	else if (csp->conv_flags[0] != '-' && csp->precision == -1 && str)
		print_s_ra_no_p(csp, str, s_len);
	else if (!str)
		print_alt(csp, csp->width - s_len, ' ');
	else
		print_s_ra_p(csp, str, s_len);
	return (csp);
}
