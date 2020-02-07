/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_x.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cphillip <cphillip@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 11:49:10 by cphillip          #+#    #+#             */
/*   Updated: 2020/02/07 18:47:49 by cphillip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static uintmax_t	get_nbr(t_struct *csp)
{
	uintmax_t nbr;
	//print_specifiers(csp);
	if (ft_strcmp(csp->len_flags, "h") == 0)
	{
		nbr = (unsigned short)va_arg(csp->args, unsigned int);
		//printf("h: %ld\n", nbr);
	}
	else if (ft_strcmp(csp->len_flags, "hh") == 0)
	{
		nbr = (unsigned char)va_arg(csp->args, unsigned int);
		//printf("hh: %ld\n", nbr);
	}
	else if (ft_strcmp(csp->len_flags, "l") == 0)
	{
		nbr = (unsigned long)va_arg(csp->args, unsigned long int);
		//printf("l: %ld\n", nbr);
	}
	else if (ft_strcmp(csp->len_flags, "ll") == 0)
	{
		nbr = (unsigned long long)va_arg(csp->args, unsigned long long int);
		//printf("ll: %ld\n", nbr);
	}
	else
	{
		nbr = (unsigned int)va_arg(csp->args, unsigned int);
		//printf("no flag: %ld\n", nbr);
	}
	nbr = (uintmax_t)nbr;
	return (nbr);
}

// if precision , and greater than string length, csp->precision - s_len,  zeroes are added.
// if precision, and greater than string length and no #, csp->precision - s_len, zeroes are added.


t_struct	*print_x(t_struct *csp)
{
	char		*tmp;
	int			s_len;
	uintmax_t	nbr;
	int	zeroes;
	int	mod;
	//int	padding;
	int left;

	
	left = 0; // 0 == right; 1 == left
	nbr = get_nbr(csp);
	tmp = convert_nbr(nbr, 16);
	mod = 0;
	zeroes = 0;
	if (nbr == 0 && csp->precision == 0)
	{
		print_alt(csp, csp->width, ' ');
		return (csp);
	}	
	if (csp->conv_flags[3])
		mod = 2;
	if (csp->conv_flags[0] == '-')
		left = 1;
	if (csp->specifier == 'X')
		tmp = ft_s_toupper(tmp);
	s_len = ft_strlen(tmp);
	

	//printf("csp->prec:%ld\n", csp->precision);
	//printf("s_len:%d\n", s_len);
	if (csp->conv_flags[4] && !csp->precision)
		zeroes = csp->width - s_len;
	else if ((!csp->conv_flags[4] || csp->conv_flags[4]) && csp->precision > s_len)
		zeroes = csp->precision - s_len;
	//else if (csp->conv_flags[4] && csp->precision > s_len)
		//zeroes = csp->precision - s_len;
	//printf("zeroes:%d\n", zeroes);

	if (!left && !csp->conv_flags[4])
		print_alt(csp, csp->width - zeroes - s_len - mod, ' ');

	//else if (!csp->conv_flags[4] && !align)
		//print_alt(csp, csp->width - zeroes - s_len - mod, ' ');
		
		
	if (csp->conv_flags[3])
		write(1, "0x", 2);
	if (csp->conv_flags[4] && csp->precision == -1)
		print_alt(csp, csp->width - s_len, '0');
	else
		print_alt(csp, zeroes, '0');
	/*
	if (csp->conv_flags[4] && csp->precision == -1)
		print_alt(csp, csp->width - s_len, '0');
	else if (csp->precision && csp->precision > s_len && !csp->conv_flags[4])
		print_alt(csp, csp->precision - s_len, '0');
	else if (csp->conv_flags[4] && !csp->precision)
		print_alt(csp, csp->width - s_len, '0');
	*/
	ft_putstr(tmp);
	if (left)
		print_alt(csp, csp->width - zeroes - s_len - mod, ' ');
	

		
	csp->len += s_len;
	//padding = get_padding(csp, s_len);
	//align_print(csp, tmp, s_len);
	return (csp);
}


