/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_d.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cphillip <cphillip@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 10:15:00 by cphillip          #+#    #+#             */
/*   Updated: 2020/02/18 13:26:48 by cphillip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
/*
static void	print_zeros(uintmax_t nbr);

static void	print_zeros(uintmax_t nbr)
{
	if (nbr && nbr == 0)
		write(1, "0", 1);
}
*/




// GET NUMBER COULD BE COMBINED WITH O AS WELL

static intmax_t	get_nbr(t_struct *csp)
{
	intmax_t nbr;

	if (ft_strcmp(csp->len_flags, "h") == 0)
		nbr = (short)va_arg(csp->args, int);
	else if (ft_strcmp(csp->len_flags, "hh") == 0)
		nbr = (signed char)va_arg(csp->args, int);
	else if (ft_strcmp(csp->len_flags, "l") == 0)
		nbr = (long)va_arg(csp->args, long int);
	else if (ft_strcmp(csp->len_flags, "ll") == 0)
		nbr = (long long)va_arg(csp->args, long long int);
	else
		nbr = (int)va_arg(csp->args, int);
	nbr = (intmax_t)nbr;
	return (nbr);
}

int negativity(t_struct *csp, intmax_t nbr)
{
	if (nbr && nbr >= 0)
	{
		if (csp->c_flags[1] == '+')
			return ('+');
		else if (csp->c_flags[2] == ' ')
			return (' ');
	}
	return ('\0');
}

// HAVENT HANDLED LENGTH YET

t_struct			*print_d(t_struct *csp)
{
	char		*tmp;
	intmax_t	nbr;
	int			n_blank;
	int		is_neg;
	int	get_negative;
	int	toggle;

	

	toggle = 0;
	nbr = get_nbr(csp);
	is_neg = negativity(csp, nbr) != '\0' ? 1 : 0;
	get_negative = negativity(csp, nbr);
	if (nbr == 0 && csp->prec == 0)
	{
		if (csp->c_flags[1] == '+')
			write(1, "+", 1);
		else if (csp->c_flags[0] == '-')
			write(1, "-", 1);
		else if (csp->c_flags[2] == ' ')
			write(1, " ", 1);
		print_alt(csp, csp->width, ' ');
		return (csp);
	}
	if (nbr == 9223372036854775807)
		tmp = ft_strdup("9223372036854775807");
	else
		tmp = nbr == 0 ? ft_strdup("0") : ft_itoa(nbr);

	// WHAT IMPACTS THE N_BLANK?
	// print_specifiers(csp);
	csp->s_len = nbr == 0 ? 1 : ft_strlen(tmp);
	n_blank = csp->s_len;
//printf("n_blank1:%d\n", n_blank);
	if (csp->c_flags[4] == '0' && csp->prec == -1 && csp->c_flags[3] != '-')
	{
		toggle = 1;
		csp->prec = csp->width;
		// printf("prec1:%ld\n", csp->prec);
	}
	if (toggle && csp->c_flags[1] == '+')// && csp->prec == -1)
	{		
		csp->prec--;
		// printf("prec2:%ld\n", csp->prec);
	}


	if (csp->s_len <= csp->prec && csp->prec > 0)
		n_blank = csp->prec;
	if (is_neg)
		n_blank++;


// printf("negativity:\n:%c:\n", get_negative);
// printf("n_blank2:%d\n", n_blank);
	// PRINTING
	if (csp->c_flags[0] != '-')
		print_alt(csp, csp->width - n_blank, ' ');
	if (is_neg)
		write(1, &get_negative, 1);
	print_alt(csp, csp->prec - csp->s_len, '0');
	ft_putstr(tmp);
	if (csp->c_flags[0] == '-')
		print_alt(csp, csp->width - n_blank, ' ');
	free(tmp);
	return (csp);
}