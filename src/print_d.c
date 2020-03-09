/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_d.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csphilli <csphilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 10:15:00 by cphillip          #+#    #+#             */
/*   Updated: 2020/03/09 17:24:47 by csphilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

t_struct 		*negativity(t_struct *csp, intmax_t nbr)
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
	return (csp);
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

void		do_d(t_struct *csp, int zeroes, int is_neg)
{
	if (csp->c_flags[0] != '-')
		print_alt(csp, csp->width - zeroes - csp->s_len, ' ');
	if (is_neg)
		write(1, "-", 1);
		// print_alt(csp, 1, '-');
	if (csp->get_plus != '\0')
		write(1, &csp->get_plus, 1);
		// print_alt(csp, 1, csp->get_plus);
	print_alt(csp, zeroes, '0');
}

int		get_zeroes(t_struct *csp, int is_neg)
{
	int			zeroes;

	zeroes = 0;
	if (csp->c_flags[4] == '0' && csp->c_flags[0] != '-')
	{
		if (csp->prec >= 0 && csp->prec >= csp->s_len)
			zeroes = csp->prec - csp->s_len;
		else if (csp->prec >= 0 && csp->prec < csp->s_len)
			zeroes = 0;
		else if (csp->prec == -1)
		{
			zeroes = csp->width - csp->s_len;
			zeroes -= is_neg ? 1 : 0;
			if (csp->c_flags[2] == ' ' && csp->c_flags[1] != '+' && !is_neg)
				zeroes -= 1;
		}
		if (csp->c_flags[1] == '+' && !is_neg && csp->prec == -1)
			zeroes -= 1;
	}
	else if (csp->c_flags[0] == '-' || csp->c_flags[4] != '0')
	{
		if (csp->prec > 0 && csp->prec > csp->s_len)
			zeroes = csp->prec - csp->s_len;
	}
	return (zeroes);
}

t_struct	*print_d(t_struct *csp)
{
	// intmax_t	nbr;
	long long	nbr;
	int			zeroes;
	int			is_neg;

	nbr = get_d_nbr(csp);
	negativity(csp, nbr);
	if (nbr == 0 && csp->prec == 0)
	{
		do_basic_d(csp, nbr);
		return (csp);
	}
	// printf("\nnbr size ONE:%d\n", csp->s_len);
	// printf("\ncsp len ONE:%d\n", csp->len);
	is_neg = (nbr < 0) ? 1 : 0;
	csp->s_len = nbr == 0 ? 1 : ft_nbr_size(nbr);
	// printf("\nnbr size TWO:%d\n", csp->s_len);
	// printf("\ncsp len TWO:%d\n", csp->len);
	
	nbr *= (is_neg && nbr != (-9223372036854775807 -1)) ? -1 : 1;
	// printf("\nnbr:%lld\n", nbr);
	zeroes = get_zeroes(csp, is_neg);
	// printf("\nnbr size TWO:%d\n", csp->s_len);
	csp->s_len += csp->get_plus != '\0' || is_neg ? 1 : 0;	
	do_d(csp, zeroes, is_neg);
	if (nbr == -9223372036854775807 - 1)
	{
		do_max();
		csp->s_len += 18;
	}
	else
		ft_putnbrmax(nbr);	
	if (csp->c_flags[0] == '-')
		print_alt(csp, csp->width - zeroes - csp->s_len, ' ');
	// printf("\nnbr size THREE:%d\n", csp->s_len);
	// printf("\ncsp len THREE:%d\n", csp->len);
	csp->len += csp->s_len;
	return (csp);
}
