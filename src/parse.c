/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cphillip <cphillip@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 13:23:05 by cphillip          #+#    #+#             */
/*   Updated: 2020/02/06 13:32:53 by cphillip         ###   ########.fr       */
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
