/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cphillip <cphillip@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 20:55:36 by cphillip          #+#    #+#             */
/*   Updated: 2020/01/19 17:21:36 by cphillip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

// s_len = 9;
// :%-20.25s:

int		get_padding(t_struct *csp, int s_len)
{
	int		padding;
	int		stp;

	if (csp->precision == -1)
		stp = s_len;
	else if (csp->precision != -1 && csp->precision > s_len)
		stp = s_len;
	else if (csp->precision != -1 && csp->precision <= s_len)
		stp = csp->precision;
	if (csp->width > stp)
		padding = csp->width - stp;
	else
		padding = 0;
	return (padding);
}

int		update_len(t_struct *csp, int padding, int s_len)
{
	if (csp->width < s_len)
		csp->len += csp->width;
	else if (csp->precision != -1)
		csp->len += (csp->precision % s_len) + padding;
	else
		csp->len += s_len + padding;
	return (s_len);
}
