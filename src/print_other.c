/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_other.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cphillip <cphillip@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 12:13:08 by cphillip          #+#    #+#             */
/*   Updated: 2020/02/05 12:55:51 by cphillip         ###   ########.fr       */
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
	align_print(csp, padding, tmp, s_len);
	return (csp);
}


void	print_other(t_struct *csp)
{
	if (csp->c_fmt[csp->i] == '%')
		print_pcent(csp);
	//printf("%ld", csp->precision);
}