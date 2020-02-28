/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_f.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cphillip <cphillip@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 10:15:00 by cphillip          #+#    #+#             */
/*   Updated: 2020/02/28 13:25:50 by cphillip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"




// GET NUMBER COULD BE COMBINED WITH O AS WELL

static long double	get_float(t_struct *csp)
{
	long double nbr;

	if (ft_strcmp(csp->len_flags, "L") == 0)
		nbr = (long double)va_arg(csp->args, long double);
	else
		nbr = (double)va_arg(csp->args, double);
	return (nbr);
}
/*
int plus_space(t_struct *csp, long double nbr)
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



char		*get_decimal(long double nbr, int prec, char dot)
{
	char *res;
	int i;

	i = 0;
	if (!(res = (char*)malloc(sizeof(char) * prec + 2)))
		return (NULL);
	res[i++] = dot;
	nbr = precision > 0 ? 
	printf("nbr%Lf", nbr);
	return (res);

}

*/
static long double	rounding(long double nbr, int prec)
{
	long double rounding;
	int			i;

	i = 0;
	rounding = 0.5;
	if (nbr < 0)
		rounding *= -1;
	while (i++ < prec)
		rounding /= 10.0;
	return (rounding);
}



char		*ft_ftoa(long double nbr, int prec, char dot)
{
	char				*joint;
	char 				*whole;
	char				*dec_part;
	unsigned long long 	dec;
	int i;

	i = 0;
	prec = prec == -1 ? 6 : prec;
	nbr += prec > 0 ? rounding(nbr, prec) : 0;
	nbr < 0 ? nbr *= -1 : nbr * 1;
	whole = ft_itoa_uintmax(nbr);
	dec = nbr;
	nbr = prec > 0 ? nbr - dec : 0;
	dec_part = ft_strnew(prec + 1);
	dec_part[i++] = (dot && prec > 0) ? '.' : '\0';
	while (prec-- > 0)
		{
			nbr *= 10;
			dec = nbr;
			nbr -= dec;
			dec_part[i++] = dec + '0';
		}
	joint = ft_strjoin(whole, dec_part);
	free(whole);
	free(dec_part);
	return(joint);
}

char	*ft_itoa_uintmax(uintmax_t n)
{
	char			*new;
	int		len;

	len = ft_intlen_max(n) + 1;
	if (!(new = ft_strnew(len + 1)))
		return (NULL);
	new[len] = '\0';
	len--;
	while (n >= 10)
	{
		new[--len] = (char)(n % 10 + '0');
		n /= 10;
	}
	new[--len] = (char)(n + '0');
	return (new);
}

// HAVENT HANDLED LENGTH YET

t_struct			*print_f(t_struct *csp)
{
	long double	nbr;
	char		*flt;
	int			not_blank;
	int			blank;

	nbr = get_float(csp);
	flt = ft_ftoa(nbr, csp->prec, '.');
	not_blank = ft_strlen(flt);
	if (nbr < 0 && csp->width > not_blank)
		not_blank++;
	blank = csp->width - not_blank;
	
	if (csp->c_flags[1] == '+' || csp->c_flags[2] == ' ')
		blank--;

// IF ZEROES
	// printf("blank:%d\n", blank);
	// Look at nbr 86 and 87. They are similar in input yet one impacts the other differently.

	if (!csp->c_flags[0] && !csp->c_flags[4])
		print_alt(csp, csp->width - not_blank, ' ');

	//I have to also print the ' '. So perhaps that can be a separate function?
	if (nbr < 0)
		print_alt(csp, 1, '-');
	if (nbr >= 0 && csp->c_flags[1] == '+')
		print_alt(csp, 1, '+');
	
	if (csp->c_flags[4] == '0' && blank > 0 && csp->prec <= 0)
		print_alt(csp, blank, '0');
	

	ft_putstr(flt);
	if (csp->c_flags[3] && csp->prec == 0)
		print_alt(csp, 1, '.');
	if (csp->c_flags[0] == '-')
		print_alt(csp, blank, ' ');
	csp->len += not_blank;
	return (csp);
}