/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_d.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csphilli <csphilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 10:15:00 by cphillip          #+#    #+#             */
/*   Updated: 2020/03/06 21:49:21 by csphilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void 		negativity(t_struct *csp, intmax_t nbr)
{
	if (nbr >= 0)
	{
		if (csp->c_flags[1] == '+')
			csp->get_plus = '+';
		else if (csp->c_flags[2] == ' ')
			csp->get_plus = ' ';
		else
			csp->get_plus = '\0';
	}
}

void		do_basic_d(t_struct *csp, intmax_t nbr)
{
	if (nbr == 0 && csp->prec == 0)
	{
		if (csp->get_plus != '\0')
			csp->width--;
		if (csp->c_flags[0] != '-')
			print_alt(csp, csp->width, ' ');
		if (csp->c_flags[1] == '+')
			print_alt(csp, 1, '+');
		else if (csp->c_flags[2] == ' ')
			print_alt(csp, 1, ' ');
		if (csp->c_flags[0] == '-')
			print_alt(csp, csp->width, ' ');
	}
}

static int	collect_d(t_struct *csp, int is_neg)
{
	int n_blank;

	n_blank = csp->s_len;
	if (csp->c_flags[4] == '0' && csp->prec == -1 && csp->c_flags[3] != '-')
	{
		csp->prec = csp->width;
		if (is_neg || csp->c_flags[1] == '+' || csp->c_flags[2] == ' ')
			csp->prec--;
	}
	if (csp->s_len <= csp->prec && csp->prec > 0)
		n_blank = csp->prec;
	if (is_neg || csp->get_plus != '\0')
		n_blank++;
	return (n_blank);
}

void		do_d(t_struct *csp, int n_blank, int is_neg)
{
	if (csp->c_flags[0] != '-')
		print_alt(csp, csp->width - n_blank, ' ');
	if (is_neg)
		print_alt(csp, 1, '-');
	if (csp->get_plus != '\0')
		print_alt(csp, 1, csp->get_plus);
	print_alt(csp, csp->prec - csp->s_len, '0');
}

t_struct	*print_d(t_struct *csp)
{
	intmax_t	nbr;
	int			n_blank;
	int			is_neg;

	nbr = get_d_nbr(csp);
	negativity(csp, nbr);
	if (nbr == 0 && csp->prec == 0)
	{
		do_basic_d(csp, nbr);
		return (csp);
	}
	is_neg = (nbr < 0) ? 1 : 0;
	csp->s_len = nbr == 0 ? 1 : ft_nbr_size(nbr);
	nbr *= (is_neg && nbr != (-9223372036854775807 -1)) ? -1 : 1;
	n_blank = collect_d(csp, is_neg);
	do_d(csp, n_blank, is_neg);
	ft_putnbrmax(nbr);
	if (csp->c_flags[0] == '-')
		print_alt(csp, csp->width - n_blank, ' ');
	return (csp);
}
