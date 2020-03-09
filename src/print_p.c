/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_p.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csphilli <csphilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 14:58:08 by cphillip          #+#    #+#             */
/*   Updated: 2020/03/09 21:59:45 by csphilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/*
**	Handles the alt printing of whitespaces and zero fillers
*/

static void		do_p(t_struct *csp, int s_len, int zeroes)
{
	if (csp->c_flags[0] != '-' && csp->c_flags[4] != '0')
		print_alt(csp, csp->width - s_len - zeroes, ' ');
	else if (csp->c_flags[0] != '-' && csp->c_flags[4] == '0' && csp->prec > 0)
		print_alt(csp, csp->width - s_len - zeroes, ' ');
	csp->specifier == 'X' ? write(1, "0X", 2) : write(1, "0x", 2);
	if (csp->c_flags[0] != '-' && csp->c_flags[4] == '0' && csp->prec == -1)
		print_alt(csp, csp->width - s_len, '0');
	print_alt(csp, zeroes, '0');
}

/*
**	Printing P
*/

t_struct	*print_p(t_struct *csp)
{
	char		*tmp;
	int			s_len;
	uintmax_t	nbr;
	int			zeroes;

	zeroes = 0;
	nbr = (unsigned long)va_arg(csp->args, unsigned long int);
	nbr = (uintmax_t)nbr;
	tmp = ft_itoa_base(nbr, 16);
	s_len = ft_strlen(tmp);
	s_len += (tmp == NULL || nbr == 0) ? 1 : 0;
	if (!csp->prec && !csp->c_flags[0] && csp->c_flags[4] == '0')
		zeroes = csp->width - s_len;
	else if (csp->prec && csp->prec > s_len && csp->c_flags[4] == '0')
		zeroes = csp->prec - s_len;
	s_len += 2;
	do_p(csp, s_len, zeroes);
	ft_putstr(tmp);
	csp->len += ft_strlen(tmp);
	if (tmp == NULL || nbr == 0)
		print_alt(csp, (csp->prec != -1 ? csp->prec : 1), '0');
	if (csp->c_flags[0] == '-')
		print_alt(csp, csp->width - s_len - zeroes, ' ');
	free(tmp);
	return (csp);
}
