/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   staging.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cphillip <cphillip@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 13:19:47 by cphillip          #+#    #+#             */
/*   Updated: 2020/02/24 16:17:58 by cphillip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include <stdint.h>

/*		REMOVE  PRINT_SPECIFIERS BEFORE SUBMITTING       */

void		print_specifiers(t_struct *csp)
{
	printf("width: '%ld'\n", csp->width);
	printf("len flag[0]: '%c'\n", csp->len_flags[0]);
	printf("len flag[1]: '%c'\n", csp->len_flags[1]);
	printf("convert flag[0]: '%c'\n", csp->c_flags[0]);
	printf("convert flag[1]: '%c'\n", csp->c_flags[1]);
	printf("convert flag[2]: '%c'\n", csp->c_flags[2]);
	printf("convert flag[3]: '%c'\n", csp->c_flags[3]);
	printf("convert flag[4]: '%c'\n", csp->c_flags[4]);
	printf("precision: '%ld'\n", csp->prec);
	printf("specifier: '%c'\n", csp->specifier);
}

t_struct	*staging(t_struct *csp)
{
	char	*spec;

	spec = &csp->specifier;
	if (*spec == 'c')
		print_c(csp);
	else if (*spec == 's')
		print_s(csp);
	else if (*spec == 'p')
		print_p(csp);
	else if (*spec == 'x' || *spec == 'X')
		print_x(csp);
	else if (*spec == 'o')
		print_o(csp);
	else if (*spec == 'u')
		print_u(csp);
	else if (*spec == 'd' || *spec == 'i' || *spec == 'D')
		print_d(csp);
	else
		print_other(csp);
	return (csp);
}
