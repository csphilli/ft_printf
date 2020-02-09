/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_x.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cphillip <cphillip@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 11:49:10 by cphillip          #+#    #+#             */
/*   Updated: 2020/02/09 14:59:23 by cphillip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

t_struct	*print_zero(t_struct *csp, char spec, uintmax_t nbr);
static int	get_mz(t_struct *csp, uintmax_t nbr, int s_len, int mod);


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
// too many declarations for norm.
	char		*tmp;
	int			s_len;
	uintmax_t	nbr;
	int			m_z;
	int			padding;
	int			mod;

	m_z = 0;
	nbr = get_nbr(csp);
	if (nbr == 0 && csp->precision == 0)
	{
		print_alt(csp, csp->width, ' ');
		return (csp);
	}
	tmp = convert_nbr(nbr, 16);
	mod = (csp->conv_flags[3] == '#' && nbr) ? 2 : 0;
	s_len = ft_strlen(tmp);
	m_z = get_mz(csp, nbr, s_len, mod);

// middle zeroes


// add s_len, padding to struct
//padding
	if (!nbr)
		padding = csp->width - s_len - m_z;
	else if (csp->conv_flags[4] != '0' && csp->precision == -1)
		padding = csp->width - s_len - mod;
	else if (csp->conv_flags[4] == '0' && csp->precision != -1 && csp->precision < s_len)
		padding = csp->width - s_len - mod;
	else if (csp->conv_flags[4] != '0' && csp->precision != -1)
		padding = csp->width - s_len - mod - m_z;
	else if (csp->conv_flags[4] == '0' && csp->precision && csp->precision > s_len)
		padding = csp->width - csp->precision - mod;
	else
		padding = 0;
	
	if(csp->conv_flags[0] != '-')
		print_alt(csp, padding, ' ');
	print_zero(csp, csp->specifier, nbr);
	print_alt(csp, m_z, '0');
	ft_putstr(tmp);
	if (csp->conv_flags[0] == '-')
		print_alt(csp, padding, ' ');	
	return (csp);
}

static int	get_mz(t_struct *csp, uintmax_t nbr, int s_len, int mod)
{
	int		m_z;
	int		prec;

	prec = csp->precision;
	
	if (csp->conv_flags[4] == '0' && prec == -1 && !nbr)
		m_z = csp->width - s_len;
	else if (!nbr && prec == -1)
		m_z = 1;
	else if (csp->conv_flags[4] == '0' && prec == -1)
		m_z = csp->width - s_len - mod;
	else if (csp->conv_flags[4] == '0' && csp->conv_flags[3] == '#' && prec != -1)
		m_z = prec - s_len;
	else if (csp->conv_flags[4] != '0' && prec && prec > s_len)
		m_z = prec - s_len;
	else if (csp->conv_flags[4] != '0' && prec == -1 && nbr)
		m_z = 0;
	else
		m_z = prec - s_len - mod;
	return(m_z = m_z < 0 ? 0 : m_z);
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
