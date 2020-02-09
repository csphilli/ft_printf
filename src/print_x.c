/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_x.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cphillip <cphillip@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 11:49:10 by cphillip          #+#    #+#             */
/*   Updated: 2020/02/09 14:18:15 by cphillip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

t_struct	*print_zero(t_struct *csp, char spec, uintmax_t nbr);


static uintmax_t	get_nbr(t_struct *csp)
{
	uintmax_t nbr;
	if (ft_strcmp(csp->len_flags, "h") == 0)
		nbr = (unsigned short)va_arg(csp->args, unsigned int);
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



t_struct	*print_x(t_struct *csp)
{
	char		*tmp;
	long int			s_len;
	uintmax_t	nbr;
	int			left;
	long int		new_l;
	long int		m_z;
	long int		padding;
	long int		mod;


	m_z = 0;
	new_l = 0;
	left = 0;
	nbr = get_nbr(csp);
	if (nbr == 0 && csp->precision == 0)
	{
		print_alt(csp, csp->width, ' ');
		return (csp);
	}
	tmp = convert_nbr(nbr, 16);
	left = csp->conv_flags[0] == '-' ? 1 : 0;
	mod = csp->conv_flags[3] == '#' ? 2 : 0;

	s_len = ft_strlen(tmp);

	new_l = (csp->conv_flags[3] == '#' && nbr) ? s_len + 2 : s_len;










//leading zeroes
	if (csp->conv_flags[4] == '0' && csp->precision == -1 && !nbr)
		m_z = csp->width - s_len;
	else if (!nbr && csp->precision == -1)
		m_z = 1;
	else if (csp->conv_flags[4] == '0' && csp->precision == -1)
	{
		//printf("1st\n");
		m_z = csp->width - new_l;
	}
	else if (csp->conv_flags[4] == '0' && csp->conv_flags[3] == '#' && csp->precision != -1)
	{
		//printf("1A\n");
		m_z = csp->precision - s_len;
	}
	else if (csp->conv_flags[4] != '0' && csp->precision && csp->precision > s_len)
	{
		//printf("2nd\n");
		m_z = csp->precision - s_len;
	}
	else if (csp->conv_flags[4] != '0' && csp->precision == -1 && nbr)
	{
		//printf("3rd\n");
		m_z = 0;
	}
	else
	{
		//printf("4th\n");
		m_z = csp->precision - new_l;
	}

	m_z = m_z < 0 ? 0 : m_z;
	//printf("m_z:%ld\t", m_z);











//padding calcs
	if (!nbr)
		padding = csp->width - s_len - m_z;
	else if (csp->conv_flags[4] != '0' && csp->precision == -1)
	{
		
		padding = csp->width - new_l;
		/*
		printf("pad1\n");
		printf("mz:%ld\n", m_z);
		printf("new_l:%ld\n", new_l);
		printf("width:%ld\n", csp->width);
		*/
	}
	else if (csp->conv_flags[4] == '0' && csp->precision != -1 && csp->precision < s_len)
	{
		
		padding = csp->width - new_l;
		/*
		printf("pad2\n");
		printf("mz:%ld\n", m_z);
		printf("new_l:%ld\n", new_l);
		printf("width:%ld\n", csp->width);
		*/
	}
	else if (csp->conv_flags[4] != '0' && csp->precision != -1)
	{
		
		padding = csp->width - new_l - m_z;
		/*
		printf("pad3\n");
		printf("mz:%ld\n", m_z);
		printf("new_l:%ld\n", new_l);
		printf("width:%ld\n", csp->width);
		*/
	}
	else if (csp->conv_flags[4] == '0' && csp->precision && csp->precision > s_len)
	{
		
		padding = csp->width - csp->precision - mod;
		/*
		printf("pad4\n");
		printf("mz:%ld\n", m_z);
		printf("new_l:%ld\n", new_l);
		printf("width:%ld\n", csp->width);
		*/
	}
	else
	{
		
		padding = 0;
		/*
		printf("pad5\n"); 
		printf("mz:%ld\n", m_z);
		printf("new_l:%ld\n", new_l);
		printf("width:%ld\n", csp->width);
		*/
	}
	//printf("padding:%ld\n", padding);

	
	if(!left)
		print_alt(csp, padding, ' ');
	print_zero(csp, csp->specifier, nbr);
	print_alt(csp, m_z, '0');

	ft_putstr(tmp);
	if (left)
		print_alt(csp, padding, ' ');
	
	return (csp);
}

t_struct	*print_zero(t_struct *csp, char spec, uintmax_t nbr)
{
	if (nbr && csp->conv_flags[3] == '#')
	{
		if (spec == 'X')
			write(1, "0X", 2);
		if (spec == 'x')
			write(1, "0x", 2);
	}
	csp->len += 2;
	return(csp);
}
