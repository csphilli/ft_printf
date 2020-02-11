/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_x.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cphillip <cphillip@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 11:49:10 by cphillip          #+#    #+#             */
/*   Updated: 2020/02/11 10:45:08 by cphillip         ###   ########.fr       */
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
		nbr = (unsigned char)va_arg(csp->args, unsigned int);
	else if (ft_strcmp(csp->len_flags, "l") == 0)
		nbr = (unsigned long)va_arg(csp->args, unsigned long int);
	else if (ft_strcmp(csp->len_flags, "ll") == 0)
		nbr = (unsigned long long)va_arg(csp->args, unsigned long long int);
	else
		nbr = (unsigned int)va_arg(csp->args, unsigned int);
	nbr = (uintmax_t)nbr;
	return (nbr);
}

t_struct	*print_x(t_struct *csp)
{
	char		*tmp;
	uintmax_t	nbr;
	int			m_z;
	int			mod;

	m_z = 0;
	nbr = get_nbr(csp);
	if (nbr == 0 && csp->precision == 0)
	{
		print_alt(csp, csp->width, ' ');
		return (csp);
	}
	tmp = cvt_nbr(csp, nbr, 16);
	mod = (csp->conv_flags[3] == '#' && nbr) ? 2 : 0;
	csp->s_len = ft_strlen(tmp);
	m_z = get_mz(csp, nbr, csp->s_len, mod);
	x_padding(csp, m_z, mod, nbr);	
	if(csp->conv_flags[0] != '-')
		print_alt(csp, csp->padding, ' ');
	print_zero(csp, csp->specifier, nbr);
	print_alt(csp, m_z, '0');
	ft_putstr(tmp);
	if (csp->conv_flags[0] == '-')
		print_alt(csp, csp->padding, ' ');
	csp->len += csp->s_len;
	free(tmp);
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
