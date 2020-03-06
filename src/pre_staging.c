/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pre_staging.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cphillip <cphillip@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 12:11:29 by cphillip          #+#    #+#             */
/*   Updated: 2020/03/06 14:20:26 by cphillip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int			pre_staging(t_struct *csp)
{
	csp->i++;
	if (csp->srch_fmt[csp->i] != '\0')
	{
		printf("test1\n");
		chk_conv_flags(csp);
	}
	if (csp->srch_fmt[csp->i] != '\0')
	{
		printf("test2\n");
		chk_width(csp);
	}
	if (csp->srch_fmt[csp->i] != '\0')
	{
		printf("test3\n");
		chk_precision(csp);
	}
	if (csp->srch_fmt[csp->i] != '\0')
	{
		printf("test4\n");
		chk_arg_flags(csp);
	}
	if (csp->srch_fmt[csp->i] != '\0')
	{
		printf("test5\n");
		chk_specifier(csp);
	}
	if (csp->srch_fmt[csp->i] != '\0')
	{
		printf("test6\n");
		staging(csp);
	}
	return (csp->len);
}
