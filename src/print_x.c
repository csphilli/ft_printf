/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_x.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cphillip <cphillip@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 11:49:10 by cphillip          #+#    #+#             */
/*   Updated: 2020/02/08 18:02:12 by cphillip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

t_struct	*print_zero(t_struct *csp, char spec);


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
	int			left;
	int		filler;
	int	u_l;

	u_l = 0;

	filler = 0;
	left = 0;
	nbr = get_nbr(csp);
	tmp = convert_nbr(nbr, 16);
	if (nbr == 0 && csp->precision == 0)
	{
		print_alt(csp, csp->width, ' ');
		return (csp);
	}
	if (csp->conv_flags[0] == '-')
		left = 1;
	s_len = ft_strlen(tmp);
	//printf("slenA:%d\n", s_len);
	
	if (csp->conv_flags[4] == '0' && csp->conv_flags[3] == '#' && csp->width && nbr)
		u_l = s_len + 2;
	else if (csp->conv_flags[3] == '#' && nbr)
		csp->width -= 2;
	//printf("slenB:%d\n", s_len);
	//printf("width:%ld\n", csp->width);
	//printf("precA:%ld\n", csp->precision);
	if (!left && csp->conv_flags[4] == '0' && csp->precision == -1)
		csp->precision = csp->width;
	//printf("precB:%ld\n", csp->precision);
	filler = (u_l <= csp->precision && csp->precision > 0) ? csp->precision : u_l;

	//printf("s_len:%d\n", s_len);
	//printf("filler:%d\n", filler);
	if (!left)
		print_alt(csp, csp->width - filler, ' ');
	print_zero(csp, csp->specifier);
	print_alt(csp, csp->precision - u_l, '0');
	ft_putstr(tmp);
	if (left)
		print_alt(csp, csp->width - filler, ' ');
	
	return (csp);
}

t_struct	*print_zero(t_struct *csp, char spec)
{
	if (csp->conv_flags[3] == '#')
	{
		if (spec == 'X')
			write(1, "0X", 2);
		if (spec == 'x')
			write(1, "0x", 2);
	}
	csp->len += 2;
	return(csp);
}

/*
	

// 2ND ITERATION

l_n = 0;

	t_len = 0;
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
	printf("conv[0]:%c\n", csp->conv_flags[0]);
	printf("csp->prec:%ld\n", csp->precision);
	printf("s_len:%d\n", s_len);
	printf("mod:%d\n", mod);

	//if (csp->conv_flags[4] && !csp->conv_flags[0] && !csp->precision)
		//csp->precision = csp->width;
	
	if (csp->conv_flags[4] && !csp->precision)
		zeroes = csp->width - s_len - mod;
	else if ((!csp->conv_flags[4] || csp->conv_flags[4]) && csp->precision > s_len)
		zeroes = csp->precision - s_len - mod;
	printf("zeroes:%d\n", zeroes);
	t_len = csp->width - zeroes - s_len - mod;
	printf("t_len:%d\n", t_len);
	printf("left:%d\n", left);
	printf("\n:");
	
	if (!left && !csp->conv_flags[4])
		print_alt(csp, csp->width - zeroes - s_len, ' ');
	else if (!left && csp->conv_flags[4] && csp->precision < s_len)
		print_alt(csp, t_len, ' ');

	//else if (!csp->conv_flags[4] && !align)
		//print_alt(csp, csp->width - zeroes - s_len - mod, ' ');
		
		
	if (csp->conv_flags[3])
		write(1, "0x", 2);
	if (csp->conv_flags[4] && (csp->precision == -1 || (csp->precision && csp->precision < s_len)))
		print_alt(csp, zeroes, '0');
	else if (csp->conv_flags[4] && csp->precision && csp->precision < s_len)
		print_alt(csp, t_len, ' ');
	else
		print_alt(csp, zeroes, '0');
	
	ft_putstr(tmp);
	if (left)
		print_alt(csp, csp->width - zeroes - s_len - mod, ' ');
	

		
	csp->len += s_len;


THIRD ITERATION -- GETTING FRUSTRATED


	if (csp->precision != -1 && csp->precision > s_len)
		m_z = csp->precision - s_len;
	if (csp->width == 0 && csp->precision > -1)
		filler = 0;
	else
		filler = csp->width - m_z - s_len - mod;
	//printf("filler:%d\n", filler);
	//printf("\n:");
	//printf("left:%d\n", left);
// im off where:

	//printf("lz:%d\n", filler);
// Start off by printing a hex value if 0 and #
	if (!left)
		print_alt(csp, csp->width - )
	if (csp->conv_flags[3] && m_z == 0)
		write(1, "0x", 2);
	if (!left && csp->conv_flags[4] == '0' && csp->precision == -1)
		print_alt(csp, filler, '0');

// Next, print either the zeros or empty space.
	if (csp->conv_flags[3] && m_z != 0)
		write(1, "0x", 2);
	

// Now if there wasn't 0 but #, print that.

	if (m_z > 0)
		print_alt(csp, m_z, '0');
	
	ft_putstr(tmp);

	if (csp->conv_flags[0] == '-')
		print_alt(csp, filler, ' ');
	
	//printf("s_len:%d\n", s_len);
	//printf("\n:");
	
	*/

