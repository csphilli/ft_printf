/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_s_stage.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cphillip <cphillip@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 14:08:21 by cphillip          #+#    #+#             */
/*   Updated: 2020/01/18 15:37:20 by cphillip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

t_struct	*print_s_staging(t_struct *csp)
{
	char 	*tmp;
	int		s_len;
	int		padding;

	tmp = ft_strdup(va_arg(csp->args, char *));
	s_len = ft_strlen(tmp);
	padding = get_padding(csp, s_len);
	update_len(csp, padding, s_len);
	if (csp->conv_flags[0] == '-' && csp->precision != -1)
		print_s_la_p(csp, padding, tmp);
	else if (csp->conv_flags[0] == '-' && csp->precision == -1)
		print_s_la_no_p(padding, tmp);
	else if (csp->conv_flags[0] != '-' && csp->precision == -1)
		print_s_ra_no_p(padding, tmp);
	else
		print_s_ra_p(csp, padding, tmp);
	return (csp);
}
