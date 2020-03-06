/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cphillip <cphillip@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 13:23:05 by cphillip          #+#    #+#             */
/*   Updated: 2020/03/06 14:49:14 by cphillip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

// static int	test_validity(t_struct *csp)
// {
// 	csp->i++;
// 	while (!ft_strchr("cspdiouxXfF%", csp->c_fmt[csp->i]))
// 		csp->i++;
// 	printf("current char:%c:\n", csp->c_fmt[csp->i + 1]);
// 	return (0);
// }

// Need checker that uses and independent integar that parces ahead to verify there is actually a proper specifier in the parce.

int	parse(t_struct *csp)
{
	if (ft_strcmp(csp->c_fmt, "%") == 0)
		return (0);
	// printf("c_fmt_string:%s", csp->c_fmt);
	while (csp->c_fmt[csp->i] != '\0')
	{
		if (csp->c_fmt[csp->i] == '%')
		{
			// test_validity(csp);
			// printf("inside %% area\n");
			re_init(csp);
			pre_staging(csp);
			// printf("\n");
			printf("c_fmt_string:%s:\n", csp->c_fmt);
			// printf("specifier:%c:\n", csp->specifier);
		}
		else
		{
			write(1, &csp->c_fmt[csp->i], 1);
			// printf("\n");
			csp->len++;
		}
		csp->i++;
	}
	return (csp->len);
}
