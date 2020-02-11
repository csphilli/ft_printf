/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   x_padding.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cphillip <cphillip@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 10:38:49 by cphillip          #+#    #+#             */
/*   Updated: 2020/02/11 10:54:24 by cphillip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

t_struct	*x_padding(t_struct *csp, int m_z, int mod, uintmax_t nbr)
{
	if (!nbr)
		csp->padding = csp->width - csp->s_len - m_z;
	else if (csp->c_flags[4] != '0' && csp->prec == -1)
		csp->padding = csp->width - csp->s_len - mod;
	else if (csp->c_flags[4] == '0' && csp->prec != -1 && csp->prec < csp->s_len)
		csp->padding = csp->width - csp->s_len - mod;
	else if (csp->c_flags[4] != '0' && csp->prec != -1)
		csp->padding = csp->width - csp->s_len - mod - m_z;
	else if (csp->c_flags[4] == '0' && csp->prec && csp->prec > csp->s_len)
		csp->padding = csp->width - csp->prec - mod;
	else
		csp->padding = 0;
	csp->len += csp->padding;
	return (csp);
}