/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   x_padding.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cphillip <cphillip@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 10:38:49 by cphillip          #+#    #+#             */
/*   Updated: 2020/02/11 10:39:12 by cphillip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

t_struct	*x_padding(t_struct *csp, int m_z, int mod, uintmax_t nbr)
{
	if (!nbr)
		csp->padding = csp->width - csp->s_len - m_z;
	else if (csp->conv_flags[4] != '0' && csp->precision == -1)
		csp->padding = csp->width - csp->s_len - mod;
	else if (csp->conv_flags[4] == '0' && csp->precision != -1 && csp->precision < csp->s_len)
		csp->padding = csp->width - csp->s_len - mod;
	else if (csp->conv_flags[4] != '0' && csp->precision != -1)
		csp->padding = csp->width - csp->s_len - mod - m_z;
	else if (csp->conv_flags[4] == '0' && csp->precision && csp->precision > csp->s_len)
		csp->padding = csp->width - csp->precision - mod;
	else
		csp->padding = 0;
	csp->len += csp->padding;
	return (csp);
}