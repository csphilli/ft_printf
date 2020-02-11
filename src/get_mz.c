/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_mz.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cphillip <cphillip@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 10:34:42 by cphillip          #+#    #+#             */
/*   Updated: 2020/02/11 10:45:31 by cphillip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		get_mz(t_struct *csp, uintmax_t nbr, int s_len, int mod)
{
	int		m_z;
	int		prec;

	prec = csp->precision;
	if (csp->conv_flags[4] == '0' && prec == -1 && !nbr)
		m_z = csp->width - s_len;
	else if (!nbr && prec == -1)
		m_z = 1;
	else if (csp->conv_flags[4] == '0' && prec == -1)
		m_z = csp->width - s_len - mod;
	else if (csp->conv_flags[4] == '0' && csp->conv_flags[3] == '#' && prec != -1)
		m_z = prec - s_len;
	else if (csp->conv_flags[4] != '0' && prec && prec > s_len)
		m_z = prec - s_len;
	else if (csp->conv_flags[4] != '0' && prec == -1 && nbr)
		m_z = 0;
	else
		m_z = prec - s_len - mod;
	return(m_z = m_z < 0 ? 0 : m_z);
}
