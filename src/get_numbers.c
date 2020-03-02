/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_numbers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cphillip <cphillip@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 13:25:08 by cphillip          #+#    #+#             */
/*   Updated: 2020/03/02 13:27:13 by cphillip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

long double	get_float(t_struct *csp)
{
	long double nbr;

	if (ft_strcmp(csp->len_flags, "L") == 0)
		nbr = (long double)va_arg(csp->args, long double);
	else
		nbr = (double)va_arg(csp->args, double);
	return (nbr);
}