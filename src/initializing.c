/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initializing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cphillip <cphillip@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 13:10:49 by cphillip          #+#    #+#             */
/*   Updated: 2020/02/06 12:02:36 by cphillip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

t_struct	*initialize(t_struct *csp)
{
	csp->i = 0;
	csp->len = 0;
	csp->format_flags = "#0-+ ";
	csp->a_flags = "lhL";
	csp->spec_flags = "cspdiouxXf%";
	csp->c_fmt = (char *)csp->fmt;
	csp->srch_fmt = (char *)csp->fmt;
	return (csp);
}

t_struct	*re_init(t_struct *csp)
{
	csp->specifier = '\0';
	csp->precision = -1;
	csp->width = 0;
	csp->conv_flags[0] = '\0';
	csp->conv_flags[1] = '\0';
	csp->conv_flags[2] = '\0';
	csp->conv_flags[3] = '\0';
	csp->conv_flags[4] = '\0';
	csp->conv_flags[5] = '\0';
	csp->len_flags[0] = '\0';
	csp->len_flags[1] = '\0';
	return (csp);
}
