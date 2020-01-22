/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   staging.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cphillip <cphillip@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 13:19:47 by cphillip          #+#    #+#             */
/*   Updated: 2020/01/21 19:39:04 by cphillip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include <stdint.h>

int		pre_staging(t_struct *csp)
{

	csp->i++;
	chk_conv_flags(csp);
	chk_width(csp);
	chk_precision(csp);
	chk_len_flags(csp);
	chk_specifier(csp);
	staging(csp);
	return (csp->len);
}

/*		REMOVE BEFORE SUBMITTING       */

void	print_specifiers(t_struct *csp)
{
	printf("width: '%ld'\n", csp->width);
	printf("len flag[0]: '%c'\n", csp->len_flags[0]);
	printf("len flag[1]: '%c'\n", csp->len_flags[1]);
	printf("convert flag[0]: '%c'\n", csp->conv_flags[0]);
	printf("convert flag[1]: '%c'\n", csp->conv_flags[1]);
	printf("convert flag[2]: '%c'\n", csp->conv_flags[2]);
	printf("convert flag[3]: '%c'\n", csp->conv_flags[3]);
	printf("convert flag[4]: '%c'\n", csp->conv_flags[4]);
	printf("precision: '%ld'\n", csp->precision);
	printf("specifier: '%c'\n", csp->specifier);
}

t_struct	*staging(t_struct *csp)
{
	char	*spec;
	//print_specifiers(csp);
	spec = &csp->specifier;
	if (*spec == 'c')
		print_c(csp);
	if (*spec == 's')
		print_s_staging(csp);
	if (*spec == 'p')
		print_p(csp);
	return (csp);
}

uintmax_t 	print_p(t_struct *csp)
{
	uintmax_t nbr;
	nbr = (unsigned long)va_arg(csp->args, unsigned long int);
	nbr = (uintmax_t)nbr;
	printf("%ld\n", nbr);
	return (0);
}



