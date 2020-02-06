/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_other.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cphillip <cphillip@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 12:13:08 by cphillip          #+#    #+#             */
/*   Updated: 2020/02/06 12:01:53 by cphillip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

t_struct	*print_pcent(t_struct *csp)
{
	char	*tmp;
	int		s_len;
	int		padding;

	tmp = "%";
	s_len = ft_strlen(tmp);
	s_len = update_len(csp, s_len);
	padding = get_padding(csp, s_len);
	if(csp->conv_flags[0] != '-' && csp->conv_flags[4] == '0')
		print_alt(padding, '0');
	else if(csp->conv_flags[0] != '-')
		print_alt(padding, ' ');
	ft_putstr(tmp);
	if(padding > 0)
		print_alt(padding, ' ');
	//align_print(csp, padding, tmp, s_len);
	return (csp);
}


void	print_other(t_struct *csp)
{
	if (csp->c_fmt[csp->i] == '%')
		print_pcent(csp);
	//printf("%ld", csp->precision);
}