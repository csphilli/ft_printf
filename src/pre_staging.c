/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pre_staging.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csphilli <csphilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 12:11:29 by cphillip          #+#    #+#             */
/*   Updated: 2020/03/06 19:33:11 by csphilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int			pre_staging(t_struct *csp)
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
	return (csp->len);
}
