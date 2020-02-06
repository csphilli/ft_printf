/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_s.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cphillip <cphillip@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 14:08:21 by cphillip          #+#    #+#             */
/*   Updated: 2020/02/06 13:37:51 by cphillip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

t_struct	*print_s(t_struct *csp)
{
	char	*tmp;
	int		s_len;

	tmp = va_arg(csp->args, char *);
	if (csp->precision == -1 && tmp)
		tmp = ft_strdup(tmp);
	else if (csp->precision == -1 && !tmp)
		tmp = ft_strdup("(null)");
	else if (csp->precision > -1 && tmp)
		tmp = ft_strndup(tmp, csp->precision);
	else if (csp->precision > -1 && !tmp)
		tmp = ft_strndup("(null)", csp->precision);
	s_len = ft_strlen(tmp);
	if (csp->conv_flags[0] != '-' && csp->conv_flags[4] == '0')
		print_alt(csp, csp->width - s_len, '0');
	else if (csp->conv_flags[0] != '-')
		print_alt(csp, csp->width - s_len, ' ');
	ft_putstr(tmp);
	if (csp->conv_flags[0] == '-')
		print_alt(csp, csp->width - s_len, ' ');
	free(tmp);
	return (csp);
}
