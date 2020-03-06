/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pre_staging.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cphillip <cphillip@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 12:11:29 by cphillip          #+#    #+#             */
/*   Updated: 2020/03/06 10:42:11 by cphillip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include <stdint.h>

int			pre_staging(t_struct *csp)
{
	csp->i++;	
	chk_conv_flags(csp);
	chk_width(csp);
	chk_precision(csp);
	chk_arg_flags(csp);
	chk_specifier(csp);	
	staging(csp);
	return (csp->len);
}
