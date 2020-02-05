/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cphillip <cphillip@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 20:36:59 by cphillip          #+#    #+#             */
/*   Updated: 2020/02/05 08:31:12 by cphillip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

// if "(null)" and s_len < prec, currently printing parts of "(null)" - should be blank
// as long as s_len < prec.

// make a strNcmp so that i can use that comparison with the strndup i should use on the print_s
// file.

void		print_s_la_p(t_struct *csp, int padding, char *tmp, int s_len)
{
	/*
	printf("1: ");
	printf("padding %d\n", padding);
	printf("s_len %d\n", s_len);
	printf("prec: %ld\n", csp->precision);
	printf("tmp: %s\n", tmp);
	*/
	if (csp->conv_flags[3] == '#' && csp->specifier == 'X')
		ft_putstr("0X");
	else if (csp->conv_flags[3] == '#' && csp->specifier == 'x')
		ft_putstr("0x");
	if (ft_strcmp(tmp, "(null)") == 0 && csp->precision < csp->width)
	{
		while(s_len--)
			ft_putchar(32);
	}
	else
	{
		while (s_len--)
			ft_putchar(*(tmp++));
	}
	while ((padding--) > 0)
	{
		if (csp->conv_flags[4] == '0')
			ft_putchar('0');
		else
			ft_putchar(32);
	}
}

void		print_s_ra_p(t_struct *csp, int padding, char *tmp, int s_len)
{
	/*
	printf("2: ");
	printf("padding %d\n", padding);
	printf("s_len %d\n", s_len);
	printf("prec: %ld\n", csp->precision);
	printf("tmp: %s\n", tmp);
	printf("test cmp: %d\n", ft_strcmp(tmp, "(null)"));
	*/
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
	if (ft_strcmp(tmp, "(null)") == 0 && csp->precision < csp->width)
	{
		while(s_len--)
			ft_putchar(32);
	}
	else
	{
		while (s_len--)
			ft_putchar(*(tmp++));
	}
}

void		print_s_la_no_p(t_struct *csp, int padding, char *tmp)
{
	/*
	printf("3: ");
	printf("padding %d\n", padding);
	*/

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
	/*
	printf("4: ");
	printf("padding %d\n", padding);
	*/
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

void	print_blank_s(int padding)
{
	while ((padding--) > 0)
		ft_putchar(32);
}
