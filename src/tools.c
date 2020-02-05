/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cphillip <cphillip@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 20:55:36 by cphillip          #+#    #+#             */
/*   Updated: 2020/02/05 16:25:50 by cphillip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		get_padding(t_struct *csp, long int s_len)
{
	int			padding;
	int	j;
	//long int	prec;
	j = 0;
	//prec = csp->precision;

	if (csp->conv_flags[3] == '#')
		j = 2;
	if (csp->precision > -1 && csp->precision < s_len)
		padding = csp->width - csp->precision - j;
	else if (csp->precision > -1 && csp->precision > s_len)
		padding = csp->width - s_len - j;
	else if (csp->precision == -1 && csp->width > s_len)
		padding = csp->width - s_len - j;
	else
		padding = 0;
	//printf("padding: %d\n", padding);
	//printf("s_len: %ld\n", s_len);
	csp->len += padding;
	return (padding);
}

int		update_len(t_struct *csp, int s_len)
{
	long int	prec;
	int	j;

	j = 0;
	prec = csp->precision;
	if (csp->conv_flags[3] == '#')
		j = 2;
	if ((prec > -1 || prec == -1) && (prec > s_len || s_len != 0))
		s_len = s_len + j;
	else if (prec > -1 && prec < s_len)
		s_len = prec + j;
	csp->len += s_len;
	//printf("len:%d\n", s_len);
	return (s_len);
}

char	*convert_nbr(long long unsigned int nbr, int base)
{
	char			*str;
	char			*symbols;
	unsigned int	i;
	int				j;

	j = 0;
	symbols = "0123456789abcdef";
	if (!(str = (char*)malloc(sizeof(ft_nbr_size_base(nbr, base) * (char)+1))))
		exit(-1);
	while (nbr != 0)
	{
		i = 0;
		while (symbols[i])
		{
			if (i == nbr % base)
			{
				str[j] = symbols[i];
				j++;
				break ;
			}
			i++;
		}
		nbr /= base;
	}
	str[j] = '\0';
	return (ft_revstr(str));
}

t_struct	*align_print(t_struct *csp, int padding, char *str, int s_len)
{
	//printf("3rd:%s", str);
	//write(1, "A:", 2);
	//printf("\n");
	if (csp->conv_flags[0] == '-' && csp->precision != -1 && str)
		print_s_la_p(csp, padding, str, s_len);
	else if (csp->conv_flags[0] == '-' && csp->precision == -1 && str)
		print_s_la_no_p(csp, padding, str);
	else if (csp->conv_flags[0] != '-' && csp->precision == -1 && str)
		print_s_ra_no_p(csp, padding, str);
	else if (!str)
		print_blank_s(padding);
	else
		print_s_ra_p(csp, padding, str, s_len);
	return (csp);
}

// OLD VERSION
/*
int		get_padding(t_struct *csp, int s_len)
{
	int		padding;
	int		stp;

	stp = '\0';
	if (csp->precision == -1)
		stp = s_len;
	else if (csp->precision > -1)
		stp = csp->precision;
	if (csp->conv_flags[3] == '#')
		stp = s_len + 2;
	else if (csp->precision != -1 && (csp->precision > s_len && s_len > 0))
	{
		//printf("1\n");
		stp = s_len;
	}
	else if (csp->precision != -1 && csp->precision <= s_len)
	{
		//printf("2\n");
		stp = csp->precision;
	}
	else if (csp->precision != -1 && s_len == 0)
	{
		//printf("3\n");
		stp = csp->precision;
	}
	if (csp->width > stp)
		padding = csp->width - stp;
	else
		padding = 0;
	//printf("stp: %d\n", stp);
	return (padding);
}

int		update_len(t_struct *csp, int padding, int s_len)
{
	if (csp->width < s_len)
		csp->len += csp->width;
	else if (csp->precision > -1 && s_len != 0)
		csp->len += (csp->precision % s_len) + padding;
	else if (csp->precision > -1 && s_len == 0)
		csp->len += csp->width;
	else
		csp->len += s_len + padding;
	return (s_len);
}
*/
