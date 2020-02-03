/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cphillip <cphillip@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 20:55:36 by cphillip          #+#    #+#             */
/*   Updated: 2020/02/03 21:24:22 by cphillip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		get_padding(t_struct *csp, int s_len)
{
	int		padding;
	int		stp;

	stp = '\0';
	if (csp->precision == -1)
		stp = s_len;
	if (csp->conv_flags[3] == '#')
		stp = s_len + 2;
	else if (csp->precision != -1 && csp->precision > s_len)
		stp = s_len;
	else if (csp->precision != -1 && csp->precision <= s_len)
		stp = csp->precision;
	if (csp->width > stp)
		padding = csp->width - stp;
	else
		padding = 0;
	return (padding);
}

int		update_len(t_struct *csp, int padding, int s_len)
{
	if (csp->width < s_len)
		csp->len += csp->width;
	else if (csp->precision != -1 && s_len != 0)
		csp->len += (csp->precision % s_len) + padding;
	else
		csp->len += s_len + padding;
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

t_struct	*align_print(t_struct *csp, int padding, char *str)
{
	if (csp->conv_flags[0] == '-' && csp->precision != -1 && str)
		print_s_la_p(csp, padding, str);
	else if (csp->conv_flags[0] == '-' && csp->precision == -1 && str)
		print_s_la_no_p(csp, padding, str);
	else if (csp->conv_flags[0] != '-' && csp->precision == -1 && str)
		print_s_ra_no_p(csp, padding, str);
	else if (!str)
		print_blank_s(padding);
	else
		print_s_ra_p(csp, padding, str);
	return (csp);
}

