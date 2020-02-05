/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cphillip <cphillip@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 13:23:05 by cphillip          #+#    #+#             */
/*   Updated: 2020/02/05 12:27:54 by cphillip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	parse(t_struct *csp)
{
	if (ft_strcmp(csp->c_fmt, "%") == 0)
		return (0);
	while (csp->c_fmt[csp->i] != '\0')
	{
		if (csp->c_fmt[csp->i] == '%')
		{
			re_init(csp);
			pre_staging(csp);
		}
		else
		{
			write(1, &csp->c_fmt[csp->i], 1);
			csp->len++;
		}
		csp->i++;
	}
	return (csp->len);
}

/*

OLD VERSION

int	parse(t_struct *csp)
{
	while (csp->c_fmt[csp->i] != '\0')
	{
		if (csp->c_fmt[csp->i] == '%' && csp->c_fmt[csp->i + 1] == '%')
		{
			write(1, &csp->c_fmt[csp->i], 1);
			csp->len++;
			csp->i++;
		}
		else if (csp->c_fmt[csp->i] == '%')
		{
			re_init(csp);
			pre_staging(csp);
		}
		else
		{
			write(1, &csp->c_fmt[csp->i], 1);
			csp->len++;
		}
		csp->i++;
	}
	return (csp->len);
}
*/