/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pre_staging.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cphillip <cphillip@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 12:11:29 by cphillip          #+#    #+#             */
/*   Updated: 2020/12/16 13:54:43 by cphillip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
**	Running through each check. Yes, the protection for each function
**	is necessary because within the checking functions, srch_fmt
**	is iterated. Protection at each stage prevents putting unwanted values
**	where they don't belong.
*/

t_struct		*pre_staging(t_struct *csp)
{
	csp->i++;
	if (csp->srch_fmt[csp->i] != '\0')
		chk_conv_flags(csp);
	if (csp->srch_fmt[csp->i] != '\0')
		chk_width(csp);
	if (csp->srch_fmt[csp->i] != '\0')
		chk_precision(csp);
	if (csp->srch_fmt[csp->i] != '\0')
		chk_arg_flags(csp);
	if (csp->srch_fmt[csp->i] != '\0')
		chk_specifier(csp);
	if (csp->srch_fmt[csp->i] != '\0')
		staging(csp);
	return (csp);
}
