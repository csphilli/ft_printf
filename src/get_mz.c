/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_mz.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csphilli <csphilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 10:34:42 by cphillip          #+#    #+#             */
/*   Updated: 2020/03/05 08:40:17 by csphilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		get_mz(t_struct *csp, uintmax_t nbr, int s_len, int mod)
{
	int		m_z;
	int		prec;

	prec = csp->prec;
	if (csp->c_flags[4] == '0' && prec == -1 && !nbr)
		m_z = csp->width - s_len;
	else if (!nbr && (prec == 0 || prec == -1))
		m_z = 1;
	else if (csp->c_flags[4] == '0' && prec == -1)
		m_z = csp->width - s_len - mod;
	else if (csp->c_flags[4] == '0' && csp->c_flags[3] == '#' && prec != -1)
		m_z = prec - s_len;
	else if (csp->c_flags[4] != '0' && prec && prec > s_len)
		m_z = prec - s_len;
	else if (csp->c_flags[4] != '0' && prec == -1 && nbr)
		m_z = 0;
	else
		m_z = prec - s_len - mod;
	return (m_z = m_z < 0 ? 0 : m_z);
}
