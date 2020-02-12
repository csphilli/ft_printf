/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_u.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cphillip <cphillip@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 10:15:00 by cphillip          #+#    #+#             */
/*   Updated: 2020/02/12 16:50:17 by cphillip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void	print_u_zero(uintmax_t nbr)
{
	if (nbr && nbr == 0)
		write(1, "0", 1);
}

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

t_struct			*print_u(t_struct *csp)
{
	char		*tmp;
	uintmax_t	nbr;
	int			n_blank;

	nbr = get_nbr(csp);	
	if (nbr == 0 && csp->prec == 0)
	{
		print_alt(csp, csp->width, ' ');
		return (csp);
	}
	if (nbr == 0)
		tmp = ft_strdup("0");
	else
		tmp = cvt_nbr(csp, nbr, 10);
	tmp = nbr == 0 ? ft_strdup("0") : cvt_nbr(csp, nbr, 10);
	csp->s_len = nbr == 0 ? 1 : ft_strlen(tmp);
	n_blank = csp->s_len;
	if (csp->c_flags[4] == '0' && csp->prec == -1 && csp->c_flags[3] != '-')
		csp->prec = csp->width;	
	if (csp->s_len <= csp->prec && csp->prec > 0)
		n_blank = csp->prec;
	if (csp->c_flags[0] != '-')
		print_alt(csp, csp->width - n_blank, ' ');
	print_u_zero(nbr);
	print_alt(csp, csp->prec - csp->s_len, '0');
	ft_putstr(tmp);
	if (csp->c_flags[0] == '-')
		print_alt(csp, csp->width - n_blank, ' ');
	free(tmp);
	return (csp);
}