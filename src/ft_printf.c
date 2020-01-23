/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cphillip <cphillip@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 18:33:46 by cphillip          #+#    #+#             */
/*   Updated: 2020/01/19 16:29:14 by cphillip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_printf(const char *format, ...)
{
	t_struct *csp;
	if (!(csp = (t_struct*)malloc(sizeof(t_struct))))
		return (-1);
	csp->fmt = format;
	csp = initialize(csp);
	if (format)
	{
		va_start(csp->args, format);
		csp->len = parse(csp);
		va_end(csp->args);
	}
	/* MEMCHECK
	while(1)
	{

	}
	*/
	free(csp);
	return (csp->len);
}
