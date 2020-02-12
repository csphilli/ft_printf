/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_mz.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cphillip <cphillip@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 10:34:42 by cphillip          #+#    #+#             */
/*   Updated: 2020/02/12 14:07:17 by cphillip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		get_mz(t_struct *csp, uintmax_t nbr, int s_len, int mod)
{
	int		m_z;
	int		prec;

	prec = csp->prec;

	//printf("\n");
	//print_specifiers(csp);
	//printf("\n");
	if (csp->c_flags[4] == '0' && prec == -1 && !nbr)
	{
		//printf("mz1\n");
		m_z = csp->width - s_len;
	}
	else if (!nbr && (prec == 0 || prec == -1))
	{
		//printf("mz2\n");
		m_z = 1;
	}
	else if (csp->c_flags[4] == '0' && prec == -1)
	{
		//printf("mz3\n");
		m_z = csp->width - s_len - mod;
	}
	else if (csp->c_flags[4] == '0' && csp->c_flags[3] == '#' && prec != -1)
	{
		//printf("mz4\n");
		m_z = prec - s_len;
	}
	else if (csp->c_flags[4] != '0' && prec && prec > s_len)
	{
		//printf("mz5\n");
		m_z = prec - s_len;
	}
	else if (csp->c_flags[4] != '0' && prec == -1 && nbr)
	{
		//printf("mz6\n");
		m_z = 0;
	}
	else
	{
		//printf("mz7\n");
		m_z = prec - s_len - mod;
	}
	return (m_z = m_z < 0 ? 0 : m_z);
}
