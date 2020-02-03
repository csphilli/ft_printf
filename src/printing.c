/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cphillip <cphillip@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 20:36:59 by cphillip          #+#    #+#             */
/*   Updated: 2020/02/03 16:39:02 by cphillip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

// So far this printing file handles strings and pointers.

void		print_s_la_p(t_struct *csp, int padding, char *tmp)
{
	//printf("1: ");
	//printf("padding %d\n", padding);

	if (csp->conv_flags[3] == '#' && csp->specifier == 'X')
		ft_putstr("0X");
	else if (csp->conv_flags[3] == '#' && csp->specifier == 'x')
		ft_putstr("0x");
	while (csp->precision--)
		ft_putchar(*(tmp++));
	while ((padding--) > 0)
	{
		if (csp->conv_flags[4] == '0')
			ft_putchar('0');
		else
			ft_putchar(32);
	}
}

void		print_s_ra_p(t_struct *csp, int padding, char *tmp)
{
	//printf("2: ");
	//printf("padding %d\n", padding);
	while ((padding--) > 0)
	{
		if (csp->conv_flags[4] == '0')
			ft_putchar('0');
		else
			ft_putchar(32);
	}
	if (csp->conv_flags[3] == '#' && csp->specifier == 'X')
		ft_putstr("0X");
	else if (csp->conv_flags[3] == '#' && csp->specifier == 'x')
		ft_putstr("0x");
	while (csp->precision--)
		ft_putchar(*(tmp++));
}

void		print_s_la_no_p(t_struct *csp, int padding, char *tmp)
{
	//printf("3: ");
	//printf("padding %d\n", padding);

	if (csp->conv_flags[3] == '#' && csp->specifier == 'X')
		ft_putstr("0X");
	else if (csp->conv_flags[3] == '#' && csp->specifier == 'x')
		ft_putstr("0x");
	while (*tmp)
		ft_putchar(*(tmp++));
	while ((padding--) > 0)
	{
		if (csp->conv_flags[4] == '0')
			ft_putchar('0');
		else
			ft_putchar(32);
	}
}

void		print_s_ra_no_p(t_struct *csp, int padding, char *tmp)
{
	//printf("4: ");
	char t;
	char *mod;

	mod = NULL;
	t = 32;
	mod = csp->conv_flags[3] == '#' ? "0x" : mod;
	mod = csp->conv_flags[3] == '#' && csp->specifier == 'X' ? "0X" : mod;
	t = csp->conv_flags[4] == '0' ? '0' : t;
	if (mod != NULL && t == '0')
		ft_putstr(mod);
	while ((padding--) > 0)
		ft_putchar(t);
	if (mod != NULL && t != '0')
		ft_putstr(mod);
	while (*tmp)
		ft_putchar(*(tmp++));
}
