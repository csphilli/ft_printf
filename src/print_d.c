/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_d.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csphilli <csphilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 10:15:00 by cphillip          #+#    #+#             */
/*   Updated: 2020/03/05 08:45:43 by csphilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"




// GET NUMBER COULD BE COMBINED WITH O AS WELL

static intmax_t	get_nbr(t_struct *csp)
{	
	intmax_t nbr;

	if (ft_strcmp(csp->len_flags, "h") == 0)
		nbr = (short)va_arg(csp->args, long long int);
	else if (ft_strcmp(csp->len_flags, "hh") == 0)
		nbr = (signed char)va_arg(csp->args, long long int);
	else if (ft_strcmp(csp->len_flags, "l") == 0)
		nbr = (long)va_arg(csp->args, long long int);
	else if (ft_strcmp(csp->len_flags, "ll") == 0)
		nbr = (long long)va_arg(csp->args, long long int);
	else
		nbr = (int)va_arg(csp->args, long long int);
	nbr = (intmax_t)nbr;
	return (nbr);
}

int negativity(t_struct *csp, intmax_t nbr)
{
	if (nbr >= 0)
	{
		if (csp->c_flags[1] == '+')
			return ('+');
		else if (csp->c_flags[2] == ' ')
			return (' ');
	}
	return ('\0');
}

static int nbr_size(intmax_t nbr)
{
	int len;

	if (nbr < 0)
		nbr *= -1;
	len = 1;
	while ((nbr /= 10) > 0)
		len++;
	return (len);
}

// HAVENT HANDLED LENGTH YET

t_struct		*do_basic_d(t_struct *csp, intmax_t nbr, int get_negative)
{
	if (nbr == 0 && csp->prec == 0)
	{
		if (get_negative != '\0')
			csp->width--;
		if (csp->c_flags[0] != '-')
			print_alt(csp, csp->width, ' ');
		if (csp->c_flags[1] == '+')
			write(1, "+", 1);
		else if (csp->c_flags[2] == ' ')
			write(1, " ", 1);
		if (csp->c_flags[0] == '-')
			print_alt(csp, csp->width, ' ');
	}
	return (csp);
}

t_struct			*print_d(t_struct *csp)
{
	intmax_t	nbr;
	int			n_blank;
	int			is_neg;
	int			get_negative;

	nbr = get_nbr(csp);
	is_neg = (nbr < 0) ? 1 : 0;
	get_negative = negativity(csp, nbr);
	do_basic_d(csp, nbr, get_negative);
	csp->s_len = nbr == 0 ? 1 : nbr_size(nbr);
	nbr *= (is_neg && nbr != (-9223372036854775807 -1)) ? -1 : 1;	
	n_blank = csp->s_len;
	if (csp->c_flags[4] == '0' && csp->prec == -1 && csp->c_flags[3] != '-')
	{
		csp->prec = csp->width;
		if (is_neg || csp->c_flags[1] == '+' || csp->c_flags[2] == ' ')
			csp->prec--;
	}
	if (csp->s_len <= csp->prec && csp->prec > 0)
		n_blank = csp->prec;
	if (is_neg || get_negative != '\0')
		n_blank++;
	if (csp->c_flags[0] != '-')
		print_alt(csp, csp->width - n_blank, ' ');
	if (is_neg)
		write(1, "-", 1);
	if (get_negative != '\0')
		write(1, &get_negative, 1);
	print_alt(csp, csp->prec - csp->s_len, '0');
	ft_putnbrmax(nbr);
	if (csp->c_flags[0] == '-')
		print_alt(csp, csp->width - n_blank, ' ');
	return (csp);
}